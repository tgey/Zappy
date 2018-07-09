/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handler.c
*/

#include "client.h"

char	*epur_str(char *line)
{
	char	*tmp;

	tmp = my_strcat(&line[2], "");
	tmp[strlen(tmp) - 2] = '\0';
	return (tmp);
}

void	get_connection_line(t_client *cli, char *line, int n)
{
	char	**tab;

	printf("%s\n", line);
	if (strcmp(line, "WELCOME") == 0) {
		free(line);
		line = my_strcat(cli->name, "\n");
		send(cli->serv_fd, line, strlen(line), 0);
	}
	free(line);
	line = get_next_line(cli->events[n].data.fd);
	cli->player->id = atoi(line);
	free(line);
	line = get_next_line(cli->events[n].data.fd);
	tab = my_str_to_wordtab(line, ' ');
	cli->map_x = atoi(tab[0]);
	cli->map_y = atoi(tab[1]);
	free_tab(tab);
	printf("%i\n%i %i\n", cli->player->id, cli->map_x, cli->map_y);
	free(line);
	cli->is_connected = true;
}

void	server_handler(t_client *cli, int n)
{
	char	*line = NULL;

	line = get_next_line(cli->events[n].data.fd);
	if (!line) {
		cli->running = false;
		return ;
	}
	if (!cli->is_connected) {
		get_connection_line(cli, line, n);
		return ;
	}
	if (line) {
		printf("%s\n", line);
		if (strcmp(line, "dead") == 0)
			cli->running = false;
		if (cli->running)
			analyse_line(cli, line);
		free(line);
	}
}
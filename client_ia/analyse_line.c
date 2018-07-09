/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** analyse_line
*/

#include "client.h"

const resp_serv_t	resp[] = {
	{"Fork", &my_fork},
	{"Incantation2", &my_incant2},
	{"Inventory", &fill_struct_inventory},
	{"Look", &check_look},
	{NULL, NULL}
};

void	check_look(t_client *cli, char *line)
{
	char	*tmp;

	tmp = epur_str(line);
	cli->is_waiting = false;
	if (find_stones(cli, tmp) == 2) {
		free(tmp);
		return ;
	}
	if (find_food(cli, tmp, NULL) == 1) {
		free(tmp);
		return ;
	}
	free(tmp);
}

void	incanting_player(t_client *cli)
{
	if (cli->queue[0] && strcmp(cli->queue[0], "Incantation2") == 0) {
		cli->is_waiting = false;
		free(cli->save_id);
		cli->save_id = malloc(sizeof(int));
		cli->len_id = 0;
		cli->queue = pop_last(cli, cli->queue);
	}
}

int	check_line_receive(t_client *cli, char *line)
{
	if (strncmp(line, "message", strlen("message")) == 0) {
		listen_broadcast(cli, line);
		return (1);
	}
	if (strncmp(line, "Elevation", strlen("Elevation")) == 0) {
		if (cli->queue[0] &&
			strcmp(cli->queue[0], "Incantation") == 0)
			cli->queue[0] = my_strcat2(cli->queue[0], "2");
		return (1);
	}
	if (strncmp(line, "Current", strlen("Current")) == 0) {
		incanting_player(cli);
		cli->is_listening = false;
		cli->is_incanting = false;
		cli->player->lvl++;
		return (1);
	}
	return (0);
}

void	my_incant2(t_client *cli, UNUSED char *line)
{
	cli->is_waiting = false;
	cli->is_listening = false;
	cli->is_incanting = false;
	free(cli->save_id);
	cli->save_id = malloc(sizeof(int));
	cli->len_id = 0;
}

void	analyse_line(t_client *cli, char *line)
{
	int	i = 0;

	if (check_line_receive(cli, line) == 1)
		return ;
	if (strcmp(cli->queue[0], "Incantation") == 0) {
		cli->queue[0] = my_strcat2(cli->queue[0], "2");
		return ;
	}
	while (resp[i].name) {
		if (strcmp(cli->queue[0], resp[i].name) == 0) {
			resp[i].func(cli, line);
			break ;
		}
		i++;
	}
	cli->queue = pop_last(cli, cli->queue);
}
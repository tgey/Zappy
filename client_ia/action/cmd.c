/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fork
*/

#include "client.h"

void	inventory(t_client *cli)
{
	qsend(cli, "Inventory\n");
	cli->is_waiting = true;
}

void	look(t_client *cli)
{
	qsend(cli, "Look\n");
	cli->is_waiting = true;
}

void	my_fork(t_client *cli, UNUSED char *line)
{
	char	*str;
	char	**tab;
	int	pid;

	pid = fork();
	if (pid == 0) {
		str = my_strcat("./zappy_ai ", " -p ");
		str = my_strcat2(str, cli->port);
		str = my_strcat2(str, " -h ");
		str = my_strcat2(str, cli->host);
		str = my_strcat2(str, " -n ");
		str = my_strcat2(str, cli->name);
		tab = my_str_to_wordtab(str, ' ');
		execvp(tab[0], tab);
		free_tab(tab);
		free(str);
		exit(0);
	}
}
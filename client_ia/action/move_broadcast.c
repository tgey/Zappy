/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** move_broadcast
*/

#include "client.h"

int	move_to_3(t_client *cli)
{
	qsend(cli, "Left\n");
	qsend(cli, "Forward\n");
	return (3);
}

int	move_to_2(t_client *cli)
{
	qsend(cli, "Forward\n");
	qsend(cli, "Left\n");
	qsend(cli, "Forward\n");
	return (2);
}

int	move_to_incant(t_client *cli, int dir)
{
	switch (dir) {
	case 1:
		return (qsend(cli, "Forward\n"));
	case 2:
		return (move_to_2(cli));
	case 3:
		return (move_to_3(cli));
	case 4:
		return (move_to_4(cli));
	case 5:
		return (move_to_5(cli));
	case 6:
		return (move_to_6(cli));
	case 7:
		return (move_to_7(cli));
	case 8:
		return (move_to_8(cli));
	}
	return (0);
}

void	react_to_broadcast(t_client *cli, char **tab)
{
	char	*msg;

	if (move_to_incant(cli, atoi(tab[1])) == 0) {
		asprintf(&msg, "Broadcast %s Arrived %i\n",
			cli->name, cli->player->id);
		qsend(cli, msg);
		free(msg);
		return ;
	}
	look(cli);
}

int	invit_player(t_client *cli, char **tab)
{
	if (strcmp(tab[3], "UP") == 0 && atoi(tab[1]) == 0 &&
		atoi(tab[4]) != cli->player->lvl) {
		qsend(cli, "Forward");
		qsend(cli, "Forward");
	}
	if (strcmp(tab[3], "UP") == 0 && atoi(tab[4]) == cli->player->lvl) {
		if (!cli->is_listening)
			cli->is_listening = true;
		if (cli->queue[0] == NULL)
			react_to_broadcast(cli, tab);
		free_tab(tab);
		return (-1);
	}
	free_tab(tab);
	return (0);
}
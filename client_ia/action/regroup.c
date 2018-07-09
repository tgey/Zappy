/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** regroup
*/

#include "client.h"

int	nb_player_needed(t_client *cli)
{
	switch (cli->player->lvl) {
	case 1:
		return (1);
	case 2:
		return (2);
	case 3:
		return (2);
	case 4:
		return (4);
	case 5:
		return (4);
	case 6:
		return (6);
	case 7:
		return (6);
	}
	return (0);
}

int	send_end(t_client *cli)
{
	char	*msg;

	asprintf(&msg, "Broadcast %s END %i\n", cli->name, cli->player->lvl);
	qsend(cli, msg);
	free(msg);
	return (1);
}

int	check_cell_players(t_client *cli)
{
	char	*msg;

	if (cli->c_players > nb_player_needed(cli)) {
		asprintf(&msg, "Broadcast %s Move %i\n", cli->name,
			cli->save_id[cli->len_id]);
		qsend(cli, msg);
		free(msg);
	}
	else if (cli->player->lvl > 1 &&
		cli->c_players < nb_player_needed(cli)) {
		asprintf(&msg, "Broadcast %s UP %i\n",
			cli->name, cli->player->lvl);
		qsend(cli, msg);
		free(msg);
	}
	else
		return (send_end(cli));
	return (0);
}


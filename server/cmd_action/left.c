/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** left
*/

#include "server.h"

int	serv_left(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	char		message[17];
	t_player	*team_player = get_player_by_fd(
		get_team_by_name(serv->teams,
		(get_player_by_fd(serv->players, cli_fd))->team->name)
		->players, cli_fd);

	team_player->dir = team_player->dir - 1;
	if (team_player->dir == 0)
		team_player->dir = 4;
	send(cli_fd, "ok\n", 3, 0);
	sprintf(message, "ppo %i %i %i %i\n",
	team_player->id, team_player->x, team_player->y, team_player->dir);
	printf("%s", message);
	if (serv->graph_fd != -1)
		send(serv->graph_fd, message, strlen(message), 0);
	return (0);
}
/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** connect_nbr
*/

#include "server.h"

int	serv_connect(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	char	message[3];
	int	i = get_team_by_name(serv->teams, (get_player_by_fd(
		serv->players, cli_fd))->team->name)->clientNb;

	sprintf(message, "%i\n", i);
	send(cli_fd, message, strlen(message), 0);
	return (0);
}
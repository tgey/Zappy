/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** inventory
*/

#include "server.h"

int	serv_inventory(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	t_player	*players = get_player_by_fd(serv->players, cli_fd);
	char		*message = malloc(sizeof(char) * 90);

	sprintf(message, "[food %d,linemate %d,deraumere %d,sibur %d,"\
		"mendiane %d,phiras %d,thystame %d]\n",
		players->food, players->stones->linemate,
		players->stones->deraumere,
		players->stones->sibur, players->stones->mendiane,
		players->stones->phiras, players->stones->thystame);
	send(cli_fd, message, strlen(message), 0);
	free(message);
	return (0);
}
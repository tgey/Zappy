/*
** EPITECH PROJECT, 2018
** server func
** File description:
** zappy
*/

#include "server.h"

int	take_mendiane(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->stones->mendiane > 0) {
		serv->map->map[players->y][players->x]->stones->mendiane--;
		players->stones->mendiane++;
		return (0);
	}
	return (-1);
}

int	take_phiras(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->stones->phiras > 0) {
		serv->map->map[players->y][players->x]->stones->phiras--;
		players->stones->phiras++;
		return (0);
	}
	return (-1);
}
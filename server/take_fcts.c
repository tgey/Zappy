/*
** EPITECH PROJECT, 2018
** first stone
** File description:
** zappy project
*/

#include "server.h"

int	take_food(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->food > 0) {
		serv->map->map[players->y][players->x]->food--;
		players->food++;
		return (0);
	}
	return (-1);
}

int	take_linemate(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->stones->linemate > 0) {
		serv->map->map[players->y][players->x]->stones->linemate--;
		players->stones->linemate++;
		return (0);
	}
	return (-1);
}

int	take_deraumere(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->stones->deraumere > 0) {
		serv->map->map[players->y][players->x]->stones->deraumere--;
		players->stones->deraumere++;
		return (0);
	}
	return (-1);
}

int	take_sibur(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->stones->sibur > 0) {
		serv->map->map[players->y][players->x]->stones->sibur--;
		players->stones->sibur++;
		return (0);
	}
	return (-1);
}
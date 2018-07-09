/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** set_fcts
*/

#include "server.h"

int	set_linemate(t_player *players, t_serv *serv)
{
	if (players->stones->linemate > 0) {
		serv->map->map[players->y][players->x]->stones->linemate++;
		players->stones->linemate--;
		return (0);
	}
	return (-1);
}

int	set_deraumere(t_player *players, t_serv *serv)
{
	if (players->stones->deraumere > 0) {
		serv->map->map[players->y][players->x]->stones->deraumere++;
		players->stones->deraumere--;
		return (0);
	}
	return (-1);
}

int	set_sibur(t_player *players, t_serv *serv)
{
	if (players->stones->sibur > 0) {
		serv->map->map[players->y][players->x]->stones->sibur++;
		players->stones->sibur--;
		return (0);
	}
	return (-1);
}

int	set_mendiane(t_player *players, t_serv *serv)
{
	if (players->stones->mendiane > 0) {
		serv->map->map[players->y][players->x]->stones->mendiane++;
		players->stones->mendiane--;
		return (0);
	}
	return (-1);
}

int	set_phiras(t_player *players, t_serv *serv)
{
	if (players->stones->phiras > 0) {
		serv->map->map[players->y][players->x]->stones->phiras++;
		players->stones->phiras--;
		return (0);
	}
	return (-1);
}
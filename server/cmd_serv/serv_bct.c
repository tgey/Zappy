/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_bct
*/

#include "server.h"

int	serv_bct(int cli_fd, t_serv *serv, char **tab)
{
	char	str[512];
	int	x = atoi(tab[2]);
	int	y = atoi(tab[1]);
	int	food = serv->map->map[x][y]->food;
	int	linemate = serv->map->map[x][y]->stones->linemate;
	int	deraumere = serv->map->map[x][y]->stones->deraumere;
	int	sibur = serv->map->map[x][y]->stones->sibur;
	int	mendiane = serv->map->map[x][y]->stones->mendiane;
	int	phiras = serv->map->map[x][y]->stones->phiras;
	int	thystame = serv->map->map[x][y]->stones->thystame;

	sprintf(str, "bct %s %s %i %i %i %i %i %i %i\n",
	tab[1], tab[2], food, linemate, deraumere, sibur,
	mendiane, phiras, thystame);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}
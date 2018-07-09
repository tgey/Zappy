/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_mct
*/

#include "server.h"


void	get_mct(t_serv *serv, int y, int x, int cli_fd)
{
	char str[512];
	int food = serv->map->map[y][x]->food;
	int linemate = serv->map->map[y][x]->stones->linemate;
	int deraumere = serv->map->map[y][x]->stones->deraumere;
	int sibur = serv->map->map[y][x]->stones->sibur;
	int mendiane = serv->map->map[y][x]->stones->mendiane;
	int phiras = serv->map->map[y][x]->stones->phiras;
	int thystame = serv->map->map[y][x]->stones->thystame;

	sprintf(str, "bct %i %i %i %i %i %i %i %i %i\n",
	x, y, food, linemate, deraumere, sibur,
	mendiane, phiras, thystame);
	send(cli_fd, str, strlen(str), 0);
}

int serv_mct(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	int i = 0;
	int j = 0;

	while (i < serv->map->height) {
		while (j < serv->map->width) {
			get_mct(serv, i, j, cli_fd);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
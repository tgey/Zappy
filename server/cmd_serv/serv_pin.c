/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** serv_pin
*/

#include "server.h"

int	serv_pin(int cli_fd, t_serv *serv, char **tab)
{
	char	str[512];
	t_player *player = get_player_by_fd(serv->players, atoi(tab[1]));
	int	fd = player->fd;
	int	x = player->x;
	int	y = player->y;
	int	food = player->food;
	int	linemate = player->stones->linemate;
	int	deraumere = player->stones->deraumere;
	int	sibur = player->stones->sibur;
	int	mendiane = player->stones->mendiane;
	int	phiras = player->stones->phiras;
	int	thystame = player->stones->thystame;

	sprintf(str, "pin %i %i %i %i %i %i %i %i %i %i\n",
	fd, x, y, food, linemate, deraumere, sibur,
	mendiane, phiras, thystame);
	send(cli_fd, str, strlen(str), 0);
	return (0);
}
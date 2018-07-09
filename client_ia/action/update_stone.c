/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** update_stone
*/

#include "client.h"

void	increase_stone(t_client *cli)
{
	char	*tmp = my_strcat(&cli->queue[0][5], "");

	if (strcmp(tmp, "linemate") == 0)
		cli->player->stones->linemate++;
	else if (strcmp(tmp, "deraumere") == 0)
		cli->player->stones->deraumere++;
	if (strcmp(tmp, "sibur") == 0)
		cli->player->stones->sibur++;
	else if (strcmp(tmp, "mendiane") == 0)
		cli->player->stones->mendiane++;
	if (strcmp(tmp, "phiras") == 0)
		cli->player->stones->phiras++;
	else if (strcmp(tmp, "thystame") == 0)
		cli->player->stones->thystame++;
	free(tmp);
}

void	decrease_stone(t_client *cli)
{
	char	*tmp = my_strcat(&cli->queue[0][4], "");

	if (strcmp(tmp, "linemate") == 0)
		cli->player->stones->linemate--;
	else if (strcmp(tmp, "deraumere") == 0)
		cli->player->stones->deraumere--;
	if (strcmp(tmp, "sibur") == 0)
		cli->player->stones->sibur--;
	else if (strcmp(tmp, "mendiane") == 0)
		cli->player->stones->mendiane--;
	if (strcmp(tmp, "phiras") == 0)
		cli->player->stones->phiras--;
	else if (strcmp(tmp, "thystame") == 0)
		cli->player->stones->thystame--;
	free(tmp);
}
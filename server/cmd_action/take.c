/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** take
*/

#include "server.h"

const item_t	a_take[] = {
	{"food", &take_food},
	{"linemate", &take_linemate},
	{"deraumere", &take_deraumere},
	{"sibur", &take_sibur},
	{"mendiane", &take_mendiane},
	{"phiras", &take_phiras},
	{"thystame", &take_thystame},
	{NULL, NULL}
};

int	take_thystame(t_player *players, t_serv *serv)
{
	if (serv->map->map[players->y][players->x]->stones->thystame > 0) {
		serv->map->map[players->y][players->x]->stones->thystame--;
		players->stones->thystame++;
		return (0);
	}
	return (-1);
}

void	send_take(t_player *player, UNUSED t_serv *serv, int ressource)
{
	char	message[11];

	sprintf(message, "pgt %i %i\n", player->id, ressource);
	printf("%s", message);
	if (serv->graph_fd != -1)
		send(serv->graph_fd, message, strlen(message), 0);
}

int	serv_take(int cli_fd, t_serv *serv, char **tab)
{
	int		i = 0;
	t_player	*players = get_player_by_fd(serv->players, cli_fd);

	if (tab_len(tab) != 2) {
		send(cli_fd, "ko\n", strlen("ko\n"), 0);
		return (-1);
	}
	while (a_take[i].name) {
		if (tab[1] && strcmp(tab[1], a_take[i].name) == 0) {
			if (a_take[i].func(players, serv) == 0) {
				send_take(players, serv, i);
				send(cli_fd, "ok\n", strlen("ok\n"), 0);
				return (0);
			}
			else {
				send(cli_fd, "ko\n", strlen("ko\n"), 0);
				return (-1);
			}
		}
		i++;
	}
	send(cli_fd, "ko\n", strlen("ko\n"), 0);
	return (-1);
}
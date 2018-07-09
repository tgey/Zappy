/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** set
*/

#include "server.h"

const item_t	a_set[] = {
	{"linemate", &set_linemate},
	{"deraumere", &set_deraumere},
	{"sibur", &set_sibur},
	{"mendiane", &set_mendiane},
	{"phiras", &set_phiras},
	{"thystame", &set_thystame},
	{NULL, NULL}
};

int	set_thystame(t_player *players, t_serv *serv)
{
	if (players->stones->thystame > 0) {
		serv->map->map[players->y][players->x]->stones->thystame++;
		players->stones->thystame--;
		return (0);
	}
	return (-1);
}

void	send_set(t_player *player, UNUSED t_serv *serv, int ressource)
{
	char	message[11];

	sprintf(message, "pdr %i %i\n", player->id, ressource);
	printf("%s", message);
	if (serv->graph_fd != -1)
		send(serv->graph_fd, message, strlen(message), 0);
}

int	serv_set(int cli_fd, t_serv *serv, char **tab)
{
	int		i = 0;
	t_player	*players = get_player_by_fd(serv->players, cli_fd);

	if (tab_len(tab) != 2) {
		send(cli_fd, "ko\n", strlen("ko\n"), 0);
		return (-1);
	}
	while (a_set[i].name) {
		if (tab[1] && strcmp(tab[1], a_set[i].name) == 0) {
			if (a_set[i].func(players, serv) == 0) {
				send_set(players, serv, i);
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
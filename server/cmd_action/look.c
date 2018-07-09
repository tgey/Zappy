/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look
*/

#include "server.h"

int	check_neg(int value, t_serv *serv, int i)
{
	if (i == 0 && value < 0)
		return (serv->map->height);
	else if (i == 1 && value < 0)
		return (serv->map->width);
	return (value);
}

t_cell	*get_cell_look(t_player *player, t_serv *serv, int j)
{
	int	posy = check_neg(player->y - j, serv, 0);
	int	posx = check_neg(player->x - j, serv, 1);

	switch (player->dir) {
		case(1):
			return (serv->map->map[posy %
			serv->map->height][posx % serv->map->width]);
		case(2):
			return (serv->map->map[posy %
			serv->map->height][(player->x + j) % serv->map->width]);
		case(3):
			return (serv->map->map[(player->y + j) %
			serv->map->height][(player->x + j) % serv->map->width]);
		case(4):
			return (serv->map->map[(player->y + j) %
			serv->map->height][posx % serv->map->width]);
	}
	return (NULL);
}

t_cell	*get_cell2_look(t_player *pl, t_serv *sv, int j, int i)
{
	int	posy = check_neg(pl->y - j, sv, 0);
	int	posx = check_neg(pl->x - j + i, sv, 1);

	switch (pl->dir) {
		case(1):
			return (sv->map->map[posy %
			sv->map->height][posx % sv->map->width]);
		case(2):
			return (sv->map->map[check_neg(pl->y - j + i, sv, 0) %
			sv->map->height][(pl->x + j) % sv->map->width]);
		case(3):
			posx = check_neg(pl->x - j - i, sv, 1);
			return (sv->map->map[(pl->y + j) %
			sv->map->height][posx % sv->map->width]);
		case(4):
			posx = check_neg(pl->x - j, sv, 1);
			return (sv->map->map[check_neg(pl->y + j - i, sv, 0) %
			sv->map->height][posx % sv->map->width]);
	}
	return (NULL);
}

char	*look_loop(t_player *player, t_serv *serv, char *message)
{
	int	i = 0;
	int	j = 1;
	t_cell	*xcell;

	xcell = serv->map->map[player->y][player->x];
	message = look_global(xcell, message);
	message = my_strcat2(message, ",");
	while (j <= player->lvl) {
		xcell = get_cell_look(player, serv, j);
		while (i <= 3 * j - 1) {
			xcell = get_cell2_look(player, serv, j, i);
			message = look_global(xcell, message);
			if (i <= 3 * j - 2)
				message = my_strcat2(message, ",");
			i++;
		}
		i = 0;
		if (j <= player->lvl - 1)
			message = my_strcat2(message, ",");
		j++;
	}
	return (message);
}

int	serv_look(int cli_fd, UNUSED t_serv *serv, UNUSED char **tab)
{
	t_player	*player = get_player_by_fd(serv->players, cli_fd);
	char		*message = "";

	message = my_strcat(message, "[");
	message = look_loop(player, serv, message);
	message = my_strcat2(message, " ]\n");
	send(cli_fd, message, strlen(message), 0);
	free(message);
	return (0);
}
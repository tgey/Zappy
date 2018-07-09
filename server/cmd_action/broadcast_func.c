/*
** EPITECH PROJECT, 2018
** broadcast func
** File description:
** zappy
*/

#include "server.h"

int	diago_x(t_player *rv_pl, t_player *sd_pl, t_serv *serv)
{
	int	x = sd_pl->x - rv_pl->x;
	int	y = sd_pl->y - rv_pl->y;
	int	dir;

	if (y > 0)
		dir = (x > serv->map->width / 2 ||
			-x > serv->map->width / 2 ||
			y > serv->map->height / 2 ||
			-y > serv->map->width / 2) ?
		(2 + rv_pl->dir * 2) % 8 : (4 + rv_pl->dir * 2) % 8;
	else
		dir = (x > serv->map->width / 2 ||
			-x > serv->map->width / 2 ||
			y > serv->map->height / 2 ||
			-y > serv->map->width / 2) ?
		(4 + rv_pl->dir * 2) % 8 : (6 + rv_pl->dir * 2) % 8;
	return (dir == 0 ? 8 : dir);
}

int	diago_y(t_player *rv_pl, t_player *sd_pl, t_serv *serv)
{
	int	x = sd_pl->x - rv_pl->x;
	int	y = sd_pl->y - rv_pl->y;
	int	dir;

	if (y > 0)
		dir = (x > serv->map->width / 2 ||
			-x > serv->map->width / 2 ||
			y > serv->map->height / 2 ||
			-y > serv->map->width / 2) ?
		(0 + rv_pl->dir * 2) % 8 : (2 + rv_pl->dir * 2) % 8;
	else
		dir = (x > serv->map->width / 2 ||
			-x > serv->map->width / 2 ||
			y > serv->map->height / 2 ||
			-y > serv->map->width / 2) ?
		(6 + rv_pl->dir * 2) % 8 : (0 + rv_pl->dir * 2) % 8;
	return (dir == 0 ? 8 : dir);
}

char	*all_in_tab(char **tab, char *message)
{
	int i = 1;

	while (tab[i]) {
		message = my_strcat2(message, tab[i]);
		message = my_strcat2(message, " ");
		i++;
	}
	message = my_strcat2(message, "\n");
	return (message);
}

int	serv_broadcast(int cli_fd, t_serv *serv, char **tab)
{
	t_chained	*current = ((t_chained_list *)serv->players)->first;
	char		*message;
	t_player	*pl = get_player_by_fd(serv->players, cli_fd);
	int		dir = 0;

	while (!current->last) {
		if (((t_player *)current->data)->fd != cli_fd) {
			dir = get_broad_dir(((t_player *)
				current->data), pl, serv);
			asprintf(&message, "message %i, ", dir);
			message = all_in_tab(tab, message);
			send(((t_player *)current->data)->fd,
			message, strlen(message), 0);
			free(message);
		}
		current = current->next;
	}
	send(cli_fd, "ok\n", 3, 0);
	send_broad(get_player_by_fd(serv->players, cli_fd), serv, tab[1]);
	return (0);
}

void	send_forward(t_player *team_player, t_serv *serv, int cli_fd)
{
	char		message[17];

	send(cli_fd, "ok\n", 3, 0);
	sprintf(message, "ppo %i %i %i %i\n",
	team_player->id, team_player->x, team_player->y, team_player->dir);
	send(serv->graph_fd, message, strlen(message), 0);
}
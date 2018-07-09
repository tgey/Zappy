/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** forward
*/

#include "server.h"

void	forward_north(t_player *team_player, t_serv *serv)
{
	delete_player_fd(serv->map->map[team_player->y]
		[team_player->x]->players, &team_player->fd);
	if (team_player->y == 0) {
		team_player->y = serv->map->height - 1;
	}
	else
		team_player->y--;
	insert_chained_list(serv->map->map[team_player->y]
		[team_player->x]->players, team_player);
}

void	forward_west(t_player *team_player, t_serv *serv)
{
	delete_player_fd(serv->map->map[team_player->y]
		[team_player->x]->players, &team_player->fd);
	if (team_player->x == 0)
		team_player->x = serv->map->width - 1;
	else
		team_player->x--;
	insert_chained_list(serv->map->map[team_player->y]
		[team_player->x]->players, team_player);
}

void	forward_est(t_player *team_player, t_serv *serv)
{
	delete_player_fd(serv->map->map[team_player->y]
		[team_player->x]->players, &team_player->fd);
	if (team_player->x == serv->map->width - 1)
		team_player->x = 0;
	else
		team_player->x++;
	insert_chained_list(serv->map->map[team_player->y]
		[team_player->x]->players, team_player);
}

void	forward_south(t_player *team_player, t_serv *serv)
{
	delete_player_fd(serv->map->map[team_player->y]
		[team_player->x]->players, &team_player->fd);
	if (team_player->y == serv->map->height - 1)
		team_player->y = 0;
	else
		team_player->y++;
	insert_chained_list(serv->map->map[team_player->y]
		[team_player->x]->players, team_player);
}

int	serv_forward(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	t_player	*team_player = get_player_by_fd(get_team_by_name(
	serv->teams, (get_player_by_fd(serv->players, cli_fd))->team->
		name)->players, cli_fd);

	switch(team_player->dir) {
		case(1):
			forward_north(team_player, serv);
			break;
		case(2):
			forward_est(team_player, serv);
			break;
		case(3):
			forward_south(team_player, serv);
			break;
		case(4):
			forward_west(team_player, serv);
			break;
	}
	send_forward(team_player, serv, cli_fd);
	return (0);
}
/*
** EPITECH PROJECT, 2018
** client
** File description:
** client
*/

#include "server.h"

void	create_team(t_serv *serv, char *team)
{
	t_team *new_team;

	new_team = empty_team(team);
	new_team->clientNb = serv->clientNb;
	insert_chained_list(serv->teams, new_team);
}

void add_in_team(t_serv *serv, char *team_name, t_player *player)
{
	t_team *team = get_team_by_name(serv->teams, team_name);
	t_team *new_team;

	if (team && !get_player_by_fd(team->players, player->fd)) {
		insert_chained_list(team->players, player);
		player->team = team;
	}
	else if (!team) {
		new_team = empty_team(team_name);
		insert_chained_list(new_team->players, player);
		insert_chained_list(serv->teams, new_team);
		player->team = new_team;
	}
}

void add_player(int client_fd, t_serv *serv, char *team_name,
		t_player *player)
{
	t_player *new_player = empty_player();

	if (!player) {
		new_player->fd = client_fd;
		new_player->id = serv->cid;
		serv->cid++;
		new_player->x = rand() % serv->map->width;
		new_player->y = rand() % serv->map->height;
		check_if_egg(client_fd, serv, team_name, new_player);
		insert_chained_list(serv->map->map[new_player->y]
			[new_player->x]->players, new_player);
		add_in_team(serv, team_name, new_player);
		insert_chained_list(serv->players, new_player);
	}
	else
		free(new_player);
}

void player_connection(int client_fd, t_serv *serv, char *team_name)
{
	add_player(client_fd, serv, team_name, NULL);
}
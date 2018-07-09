/*
** EPITECH PROJECT, 2018
** free file
** File description:
** PSU_zappy_2017
*/

#include "server.h"


void	free_all(t_serv *serv, t_opt *opt, t_map *map)
{
	free_map(map);
	free(serv);
	free_opt(opt);
}

void	free_server(t_serv *serv, t_opt *opt)
{
	close_fd(serv->serv_fd);
	destroy_team_list(serv->teams);
	free_map(serv->map);
	destroy_player_list(serv->players);
	free(serv);
	free_opt(opt);
}
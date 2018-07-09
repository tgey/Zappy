/*
** EPITECH PROJECT, 2018
** calculs stones
** File description:
** zappy project
*/

#include "server.h"

int	get_nbr_teams(t_serv *serv)
{
	int		i = 0;
	t_chained	*list = serv->teams->first;

	while (!list->last) {
		list = list->next;
		i++;
	}
	destroy_team_list(list);
	return (i);
}

void	add_obj(UNUSED t_stones *stones, t_map *map, int x, int j)
{
	int	rand_stones;
	int	i = 0;

	while (i < 3) {
		rand_stones = rand() % 100 + 1;
		init_food(rand_stones, map, x, j);
		i++;
	}
}

void	re_generation(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		while (j < map->width) {
			add_obj(map->map[i][j]->stones, map, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** EPITECH PROJECT, 2018
** map
** File description:
** PSU_zappy_2017
*/

#include "server.h"

void	init_server_stones(t_stones *stones)
{
	stones->linemate = 0;
	stones->deraumere = 0;
	stones->sibur = 0;
	stones->mendiane = 0;
	stones->phiras = 0;
	stones->thystame = 0;
}

void	init_server_cells(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		while (j < map->width) {
			map->map[i][j] = malloc(sizeof(t_cell));
			map->map[i][j]->stones = malloc(sizeof(t_stones));
			map->map[i][j]->food = 0;
			init_server_stones(map->map[i][j]->stones);
			init_obj(map->map[i][j]->stones, map, i, j);
			map->map[i][j]->players = init_chained_list(
				&delete_player_fd, &destroy_player_list2);
			map->map[i][j]->eggs = init_chained_list(
				&delete_egg_id, &destroy_egg_list);
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_server_map(t_map *map, t_opt *opt)
{
	int	i = 0;

	map->width = opt->width;
	map->height = opt->height;
	map->map = malloc(sizeof(t_cell *) * (map->height + 1));
	while (i < map->height) {
		map->map[i] = malloc(sizeof(t_cell) * (map->width + 1));
		i++;
	}
	init_server_cells(map);
}

void	free_map(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		while (j < map->width) {
			destroy_player_list2(map->map[i][j]->players);
			free(map->map[i][j]->stones);
			destroy_egg_list(map->map[i][j]->eggs);
			free(map->map[i][j]);
			j++;
		}
		j = 0;
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
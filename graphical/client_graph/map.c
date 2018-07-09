/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map
*/

#include "graph.h"

void init_stones_lists(stones_t *stones)
{
	stones->linemate = init_chained_list(&delete_place_by_place,
		&destroy_place_list);
	stones->deraumere = init_chained_list(&delete_place_by_place,
		&destroy_place_list);
	stones->sibur = init_chained_list(&delete_place_by_place,
		&destroy_place_list);
	stones->mendiane = init_chained_list(&delete_place_by_place,
		&destroy_place_list);
	stones->phiras = init_chained_list(&delete_place_by_place,
		&destroy_place_list);
	stones->thystame = init_chained_list(&delete_place_by_place,
		&destroy_place_list);
}

void init_map_cells(map_t *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		while (j < map->width) {
			map->map[i][j] = malloc(sizeof(cell_t));
			map->map[i][j]->stones = malloc(sizeof(stones_t));
			map->map[i][j]->players = init_chained_list(
				&delete_player_fd, &destroy_player_list);
			map->map[i][j]->eggs = init_chained_list(
				&delete_egg_id, &destroy_egg_list);
			init_stones_lists(map->map[i][j]->stones);
			map->map[i][j]->food = init_chained_list(
				&delete_place_by_place,
				&destroy_place_list);
			j++;
		}
		j = 0;
		i++;
	}
}

void init_map_graph(map_t *map, int width, int height)
{
	int	i = 0;

	map->width = width;
	map->height = height;
	map->map = malloc(sizeof(cell_t *) * map->height);
	while (i < map->height) {
		map->map[i] = malloc(sizeof(cell_t) * map->width);
		i++;
	}
	init_map_cells(map);
}

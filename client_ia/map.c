/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** map
*/

#include "client.h"

void	init_client_stones(t_stones *stones)
{
	stones->linemate = 0;
	stones->deraumere = 0;
	stones->sibur = 0;
	stones->mendiane = 0;
	stones->phiras = 0;
	stones->thystame = 0;
}

void	init_client_cells(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		while (j < map->width) {
			map->map[i][j] = malloc(sizeof(t_cell));
			map->map[i][j]->stones = malloc(sizeof(t_stones));
			init_client_stones(map->map[i][j]->stones);
			map->map[i][j]->food = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_client_map(t_map *map, int width, int height)
{
	int	i = 0;

	map->width = width;
	map->height = height;
	map->map = malloc(sizeof(t_cell *) * map->height);
	while (i < map->height) {
		map->map[i] = malloc(sizeof(t_cell) * map->width);
		i++;
	}
	init_client_cells(map);
}

void	free_client_map(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		while (j < map->width) {
			free(map->map[i][j]->stones);
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
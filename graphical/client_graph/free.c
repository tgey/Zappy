/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** free
*/

#include "graph.h"

void	free_map_data(map_t *map)
{
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			free(map->map[y][x]);
		}
	}
	free(map);
}

void	free_graph_data(graph_t *graph)
{
	if (graph->map)
		free_map_data(graph->map);
	free(graph);
}

void	free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}
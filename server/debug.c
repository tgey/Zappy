/*
** EPITECH PROJECT, 2018
** debug functions
** File description:
** zappy project
*/

#include "server.h"

void	print_value(t_map *map, int i, int j)
{
	printf("cell[%i][%i]\n", i, j);
	printf("food: %i\n", map->map[i][j]->food);
	printf("linemate: %i\n", map->map[i][j]->stones->linemate);
	printf("deraumere: %i\n", map->map[i][j]->stones->deraumere);
	printf("sibur: %i\n", map->map[i][j]->stones->sibur);
	printf("mendiane: %i\n", map->map[i][j]->stones->mendiane);
	printf("phiras: %i\n", map->map[i][j]->stones->phiras);
	printf("thystame: %i\n", map->map[i][j]->stones->thystame);
}

void	print_map(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height) {
		j = 0;
		while (j < map->width) {
			print_value(map, i, j);
			printf("\n");
			j++;
		}
		i++;
	}
}
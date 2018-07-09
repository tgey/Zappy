/*
** EPITECH PROJECT, 2018
** random
** File description:
** zappy.c
*/

#include "server.h"

int	gen_a_rdm_number(int max)
{
	return (rand() % max);
}

void	init_food(int rand_stones, t_map *map, int i, int j)
{
	if (rand_stones > 82 && rand_stones <= 92)
		map->map[i][j]->food += 1;
	else
		map->map[i][j]->food += 0;
}

void	init_stone_first(int rand_stones, t_stones *stones)
{
	if (rand_stones <= 30)
		stones->linemate += 1;
	else if (rand_stones > 30 && rand_stones <= 50)
		stones->deraumere += 1;
	else
		stones->sibur += 1;
}

void	init_stone_second(int rand_stones, t_stones *stones)
{
	if (rand_stones > 65 && rand_stones <= 75)
		stones->mendiane += 1;
	else if (rand_stones > 75 && rand_stones <= 80)
		stones->phiras += 1;
	else
		stones->thystame += 1;
}

void	init_obj(t_stones *stones, t_map *map, int x, int j)
{
	int	rand_stones;
	int	i = 0;

	while (i < 3) {
		rand_stones = rand() % 100 + 1;
		if (rand_stones <= 65)
			init_stone_first(rand_stones, stones);
		else if (rand_stones > 65 && rand_stones <= 82)
			init_stone_second(rand_stones, stones);
		else
			init_food(rand_stones, map, x, j);
		i++;
	}
}
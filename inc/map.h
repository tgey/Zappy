/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "game.h"

typedef struct	s_cell
{
	int		food;
	t_stones	*stones;
	t_chained_list	*players;
	t_chained_list	*eggs;
}		t_cell;

typedef struct	s_map
{
	int	width;
	int	height;
	t_cell	***map;
}		t_map;

#endif /* !MAP_H_ */

/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fill place
*/

#include "graph.h"

void fill_place(graph_t *graph, t_chained_list *list, int nb)
{
	int len = chained_list_len(list);
	place_t *place;

	while (len > nb) {
		pop_front_place_list(list);
		len--;
	}
	while (len < nb) {
		place = empty_place();
		place->x = rand() % (int)(100 - graph->map->percent_x);
		place->y = rand() % (int)(100 - graph->map->percent_y);
		insert_chained_list(list, place);
		len++;
	}
}

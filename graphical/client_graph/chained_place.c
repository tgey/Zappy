/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** chained place
*/

#include "graph.h"

place_t *empty_place(void)
{
	place_t *place = malloc(sizeof(place_t));

	return (place);
}

void destroy_place_list(void *list)
{
	t_chained_list *ptr = ((t_chained_list *)list);
	t_chained *current = ptr->first;
	place_t *place;

	while (!current->last) {
		place = ((place_t *)current->data);
		if (place)
			free(place);
		delete_chained_list(list, 0);
		current = ptr->first;
	}
	free(ptr->first);
	free(ptr);
}

void pop_front_place_list(void *list)
{
	t_chained *current = ((t_chained_list *)list)->first;
	place_t *place;

	if (!current->last) {
		place = ((place_t *)current->data);
		if (place)
			free(place);
		delete_chained_list(list, 0);
	}
}

void delete_place_by_place(UNUSED void *list, UNUSED void *fd)
{
}

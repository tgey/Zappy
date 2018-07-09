/*
** EPITECH PROJECT, 2018
** chained list egg
** File description:
** chained_list_egg
*/

#include "server.h"

t_egg	*empty_egg(void)
{
	t_egg	*egg = malloc(sizeof(t_egg));

	egg->x = 0;
	egg->y = 0;
	egg->id = 0;
	egg->team = NULL;
	egg->is_forked = false;
	return (egg);
}

t_egg	*get_egg_by_id(void *list, int id)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (!current->last) {
		if (id == ((t_egg *)current->data)->id)
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

void	delete_egg_ptr(void *list, void *ptr)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->last) {
		if (((t_egg *)current->data)->id &&
		(((t_egg *)current->data)->id == *(int *)ptr)) {
			delete_chained_list(list, i);
			break;
		}
		current = current->next;
		i += 1;
	}
}

void	destroy_egg_list(void *list)
{
	t_chained_list	*ptr = ((t_chained_list *)list);
	t_chained	*current = ptr->first;

	while (!current->last) {
		delete_chained_list(list, 0);
		current = ptr->first;
	}
	free(ptr->first);
	free(ptr);
}

void	delete_egg_id(void *list, void *id)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->last) {
		if (((t_egg *)current->data)->id == *((int *)id)) {
			delete_chained_list(list, i);
			break;
		}
		current = current->next;
		i += 1;
	}
}
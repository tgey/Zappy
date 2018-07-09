/*
** EPITECH PROJECT, 2018
** chained list players
** File description:
** chained_list_players
*/

#include "server.h"

int	chained_list_len(t_chained_list *list)
{
	t_chained	*current = list->first;
	int	i = 0;

	while (!current->last) {
		current = current->next;
		i += 1;
	}
	return (i);
}

t_chained_list	*init_chained_list(void (*del)(void *, void *),
	void (*destroy)(void *))
{
	t_chained_list	*list = malloc(sizeof(*list));
	t_chained	*first = malloc(sizeof(*first));

	first->data = NULL;
	first->next = NULL;
	first->last = true;
	list->first = first;
	list->del = del;
	list->destroy = destroy;
	return (list);
}

void	insert_chained_list(t_chained_list *list, void *data)
{
	t_chained	*new = malloc(sizeof(*new));

	new->next = list->first;
	new->data = data;
	new->last = false;
	list->first = new;
}

void	delete_chained_list(t_chained_list *list, int index)
{
	int		i = 1;
	t_chained	*current = list->first;
	t_chained	*tmp = NULL;

	if (index == 0 && list->first != NULL) {
		tmp = list->first;
		list->first = list->first->next;
	}
	while (!current->last) {
		if (i == index && current != NULL && current->next != NULL) {
			tmp = current->next;
			current->next = current->next->next;
			break;
		}
		current = current->next;
		i += 1;
	}
	if (tmp)
		free(tmp);
}
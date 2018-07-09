/*
** EPITECH PROJECT, 2018
** chained list queue
** File description:
** chained_queue
*/

#include "server.h"

t_queue	*get_queue_by_player(void *list, char **cmd)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (!current->last) {
		if (!strcmp(cmd[0], ((t_queue *)current->data)->cmd[0]))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

t_queue	*get_last_queue(void *list)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (current->next && !current->next->last) {
		current = current->next;
	}
	if (current->last)
		return (NULL);
	return (current->data);
}

void	destroy_queue_list(void *list)
{
	t_chained_list	*ptr = ((t_chained_list *)list);
	t_chained	*current = ptr->first;

	while (!current->last) {
		free_tab(((t_queue *)current->data)->cmd);
		free((t_queue *)current->data);
		delete_chained_list(list, 0);
		current = ptr->first;
	}
	free(ptr->first);
	free(ptr);
}

void	delete_queue_ptr(void *list, void *ptr)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->last) {
		if (((t_queue *)current->data)->cmd[0] &&
		!strcmp(((t_queue *)current->data)->cmd[0], (char *)ptr)) {
			delete_chained_list(list, i);
			break;
		}
		current = current->next;
		i += 1;
	}
}

void	delete_last_queue(void *list)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->next->last) {
		current = current->next;
		i += 1;
	}
	free_tab(((t_queue *)current->data)->cmd);
	free(((t_queue *)current->data));
	delete_chained_list(list, i);
}
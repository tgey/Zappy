/*
** EPITECH PROJECT, 2018
** chained player functions
** File description:
** zappy project
*/

#include "server.h"

void	destroy_player_list2(void *list)
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

void	delete_player_fd(void *list, void *fd)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->last) {
		if (((t_player *)current->data)->fd == *((int *)fd)) {
			delete_chained_list(list, i);
			break;
		}
		current = current->next;
		i += 1;
	}
}
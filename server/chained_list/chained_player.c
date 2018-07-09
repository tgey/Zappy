/*
** EPITECH PROJECT, 2018
** chained list player
** File description:
** chained_list_player
*/

#include "server.h"

t_player	*empty_player(void)
{
	t_player	*player = malloc(sizeof(t_player));

	player->stones = malloc(sizeof(t_stones));
	init_server_stones(player->stones);
	player->id = 0;
	player->x = 0;
	player->y = 0;
	player->lvl = 1;
	player->dir = North;
	player->team = NULL;
	player->is_egg = false;
	player->incantation = 0;
	player->food = 10;
	gettimeofday(&(player->timer), NULL);
	player->queue = init_chained_list(&delete_queue_ptr,
		&destroy_queue_list);
	return (player);
}

t_player	*get_player_by_id(void *list, int id)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (!current->last) {
		if (id == ((t_player *)current->data)->id)
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

t_player	*get_player_by_lvl(void *list, int lvl)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (!current->last) {
		if (lvl == ((t_player *)current->data)->lvl)
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

t_player	*get_player_by_fd(void *list, int fd)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (!current->last) {
		if (fd == ((t_player *)current->data)->fd)
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

void	destroy_player_list(void *list)
{
	t_chained_list	*ptr = ((t_chained_list *)list);
	t_chained	*current = ptr->first;

	while (!current->last) {
		if ((t_player *)current->data) {
			if (((t_player *)current->data)->fd != -1) {
				close(((t_player *)current->data)->fd);
				((t_player *)current->data)->fd = -1;
			}
			((t_chained_list *)((t_player *)current->data)->
			queue)->destroy((t_chained_list *)
			((t_player *)current->data)->queue);
			free(((t_player *)current->data)->stones);
			free((t_player *)current->data);
		}
		delete_chained_list(list, 0);
		current = ptr->first;
	}
	free(ptr->first);
	free(ptr);
}
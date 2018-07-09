/*
** EPITECH PROJECT, 2018
** chained list team
** File description:
** chained_team
*/

#include "server.h"

t_team	*empty_team(char *name)
{
	t_team	*team = malloc(sizeof(t_team));
	team->name = my_strcat(name, "");
	team->players = init_chained_list(&delete_player_fd,
	&destroy_player_list2);
	team->eggs = init_chained_list(&delete_egg_id,
	&destroy_egg_list);
	return (team);
}

t_team	*get_team_by_name(void *list, char *name)
{
	t_chained	*current = ((t_chained_list *)list)->first;

	while (!current->last) {
		if (!strcmp(name, ((t_team *)current->data)->name))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

void	destroy_team_list(void *list)
{
	t_chained_list	*ptr = ((t_chained_list *)list);
	t_chained	*current = ptr->first;
	t_team	*team;

	while (!current->last) {
		((t_chained_list *)((t_team *)current->data)->players)
		->destroy(((t_chained_list *)((t_team *)current
		->data)->players));
		((t_chained_list *)((t_team *)current->data)->eggs)
		->destroy(((t_chained_list *)((t_team *)current
		->data)->eggs));
		team = ((t_team *)current->data);
		if (team->name)
			free(team->name);
		free(team);
		delete_chained_list(list, 0);
		current = ptr->first;
	}
	free(ptr->first);
	free(ptr);
}

void	delete_team_ptr(void *list, void *ptr)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->last) {
		if (((t_team *)current->data)->name &&
		!strcmp(((t_team *)current->data)->name, (char *)ptr)) {
			delete_chained_list(list, i);
			break;
		}
		current = current->next;
		i += 1;
	}
}
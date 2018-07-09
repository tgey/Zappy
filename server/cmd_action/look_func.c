/*
** EPITECH PROJECT, 2018
** look function
** File description:
** zappy
*/

#include "server.h"

char	*look_player(t_cell *cell, char *message)
{
	t_chained	*list_player = ((t_chained_list *)
				cell->players)->first;

	while (list_player && !((t_chained *)list_player)->last) {
		message = my_strcat2(message, " player");
		list_player = list_player->next;
	}
	return (message);
}

char	*look_food(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->food) {
		message = my_strcat2(message, " food");
		i++;
	}
	return (message);
}

char	*look_linemate(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->stones->linemate) {
		message = my_strcat2(message, " linemate");
		i++;
	}
	return (message);
}

char	*look_deraumere(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->stones->deraumere) {
		message = my_strcat2(message, " deraumere");
		i++;
	}
	return (message);
}

char	*look_sibur(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->stones->sibur)	{
		message = my_strcat2(message, " sibur");
		i++;
	}
	return (message);
}
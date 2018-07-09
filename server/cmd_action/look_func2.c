/*
** EPITECH PROJECT, 2018
** look functions server
** File description:
** zappy
*/

#include "server.h"

char	*look_mendiane(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->stones->mendiane) {
		message = my_strcat2(message, " mendiane");
		i++;
	}
	return (message);
}

char	*look_phiras(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->stones->phiras) {
		message = my_strcat2(message, " phiras");
		i++;
	}
	return (message);
}

char	*look_thystame(t_cell *cell, char *message)
{
	int	i = 0;

	while (i < cell->stones->thystame) {
		message = my_strcat2(message, " thystame");
		i++;
	}
	return (message);
}

char	*look_global(t_cell *cell, char *message)
{
	message = look_player(cell, message);
	message = look_food(cell, message);
	message = look_linemate(cell, message);
	message = look_deraumere(cell, message);
	message = look_sibur(cell, message);
	message = look_mendiane(cell, message);
	message = look_phiras(cell, message);
	message = look_thystame(cell, message);
	return (message);
}
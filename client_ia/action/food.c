/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** food
*/

#include "client.h"

void	take_all_food(t_client *cli, int x, int n)
{
	go_take(cli, "food", n);
	while (x > 1) {
		qsend(cli, "Take food\n");
		x--;
	}
}

int	check_is_food(t_client *cli, char *str, char **cell, int n)
{
	char	**entities;
	int	i = 0;

	entities = my_str_to_wordtab(cell[n], ' ');
	cli->w_food = 0;
	while (entities[i]) {
		if (strcmp(entities[i], "food") == 0)
			cli->w_food++;
		i++;
	}
	if (cli->w_food > 0) {
		free_tab(entities);
		return (check_food(cli, str, cli->w_food, n));
	}
	free_tab(entities);
	return (0);
}

int	find_food(t_client *cli, char *line, char *str)
{
	char	**cell = my_str_to_wordtab(line, ',');
	int	n = 0;
	int	res = 0;

	while (cell[n]) {
		res = check_is_food(cli, str, cell, n);
		if (res != 0) {
			free_tab(cell);
			return (res);
		}
		n++;
	}
	if (cli->player->food < 20) {
		go_to_random(cli);
		free_tab(cell);
		return (1);
	}
	free_tab(cell);
	return (0);
}
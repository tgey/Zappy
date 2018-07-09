/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** stone
*/

#include "client.h"

int	check_all_entities(t_client *cli, char **cell, int n)
{
	char	**entities;
	int	i = 0;

	entities = my_str_to_wordtab(cell[n], ' ');
	while (entities[i]) {
		if (strcmp(entities[i], cli->needed) == 0) {
			cli->wanted = n;
			free_tab(entities);
			return (1);
		}
		i++;
	}
	free_tab(entities);
	return (0);
}

int	begin_incantation(t_client *cli, char *line)
{
	char		*msg;

	take_all(cli, line);
	asprintf(&msg, "Broadcast %s UP %i\n", cli->name, cli->player->lvl);
	if (cli->player->lvl > 1)
		qsend(cli, msg);
	free(msg);
	cli->is_waiting = false;
	cli->is_incanting = true;
	return (0);
}

int	prepare_incantation(t_client *cli, char *line, char **cell)
{
	int	n = 0;

	n = find_food(cli, line, "Incantation");
	free_tab(cell);
	if (cli->player->food < 10)
		return (2);
	if (n == 2)
		begin_incantation(cli, line);
	return (2);
}

int	find_stones(t_client *cli, char *line)
{
	char	**cell = my_str_to_wordtab(line, ',');
	int	n = 0;

	if (find_missing_stones(cli) == 0) {
		return (prepare_incantation(cli, line, cell));
	}
	while (cell[n]) {
		if (check_all_entities(cli, cell, n) == 1) {
			free_tab(cell);
			return (1);
		}
		n++;
	}
	free_tab(cell);
	return (0);
}

void	take_all(t_client *cli, char *line)
{
	char	**cell = my_str_to_wordtab(line, ',');
	char	**entities = my_str_to_wordtab(cell[0], ' ');
	char	*msg;
	int	i = 0;

	cli->c_players = 0;
	while (entities[i]) {
		if (strcmp(entities[i], "player") != 0) {
			msg = my_strcat("Take ", entities[i]);
			msg = my_strcat2(msg, "\n");
			qsend(cli, msg);
			free(msg);
		}
		else
			cli->c_players++;
		i++;
	}
	free_tab(entities);
	free_tab(cell);
}
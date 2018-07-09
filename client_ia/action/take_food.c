/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** take_food
*/

#include "client.h"

int	check_food_incantation(t_client *cli, char *str, int x, int n)
{
	if (cli->is_listening) {
		if (n == 0) {
			take_all_food(cli, x, n);
			return (1);
		}
		return (1);
	}
	if (str && cli->player->food <
		(cli->map_x > cli->map_y ? cli->map_x : cli->map_y) &&
		strcmp("Incantation", str) == 0) {
		take_all_food(cli, x, n);
		return (1);
	}
	else if (str && strcmp("Incantation", str) == 0)
		return (2);
	return (0);
}

int	take_it(t_client *cli, char *str, int n)
{
	char	*msg;

	if (cli->wanted == n && !str) {
		msg = my_strcat("Take ", cli->needed);
		msg = my_strcat2(msg, "\n");
		qsend(cli, msg);
		free(msg);
		return (1);
	}
	return (0);
}

int	normal_taking(t_client *cli, char *str, int x, int n)
{
	int	res = 0;
	char	*msg;

	if (cli->wanted == 0 && !str) {
		msg = my_strcat("Take ", cli->needed);
		msg = my_strcat2(msg, "\n");
		qsend(cli, msg);
		free(msg);
		res = 1;
	}
	else if (cli->player->food < 20 && !str) {
		take_all_food(cli, x, n);
		res = 1;
	}
	if (take_it(cli, str, n) == 1)
		res = 1;
	return (res);
}

int	check_food(t_client *cli, char *str, int x, int n)
{
	int	res = 0;

	res = check_food_incantation(cli, str, x, n);
	if (res != 0)
		return (res);
	return (normal_taking(cli, str, x, n));
}
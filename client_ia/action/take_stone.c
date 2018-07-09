/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** take_stone.c
*/

#include "client.h"

void	go_to_random(t_client *cli)
{
	int	random = rand() % 4;

	if (random == 0)
		qsend(cli, "Forward\n");
	else if (random == 1) {
		qsend(cli, "Left\n");
		qsend(cli, "Forward\n");
	}
	else {
		qsend(cli, "Right\n");
		qsend(cli, "Forward\n");
	}
}

int	find_missing_stones(t_client *cli)
{
	check_missing_stones(cli);
	cli->wanted = -1;
	for (int i = 0; i < 6; i++) {
		if (cli->req[i] > 0) {
			found_stones(cli, i);
			return (1);
		}
	}
	return (0);
}

int	find_dir(t_client *cli, int n, int x)
{
	int	y = 0;

	if (x > ((n * n) + ((2 * n + 1) / 2))) {
		qsend(cli, "Right\n");
		while ((n * n) + ((2 * n + 1) / 2) + y != x) {
			qsend(cli, "Forward\n");
			y++;
		}
	}
	else if (x < ((n * n) + ((2 * n + 1) / 2))) {
		qsend(cli, "Left\n");
		while ((n * n) + ((2 * n + 1) / 2) - y != x) {
			qsend(cli, "Forward\n");
			y++;
		}
	}
	return (0);
}

void	take_this(t_client *cli, char *str)
{
	char	*msg = "";

	msg = my_strcat("Take ", "");
	msg = my_strcat2(msg, str);
	msg = my_strcat2(msg, "\n");
	qsend(cli, msg);
	free(msg);
}

void	go_take(t_client *cli, char *str, int x)
{
	int	y = 0;
	int	n = 0;

	while (y <= x) {
		y = n + 1;
		y = y * y;
		n++;
	}
	n--;
	y = 0;
	while (y < n) {
		qsend(cli, "Forward\n");
		y++;
	}
	find_dir(cli, n, x);
	take_this(cli, str);
}
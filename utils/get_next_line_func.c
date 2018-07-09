/*
** EPITECH PROJECT, 2018
** func gnl
** File description:
** zappy project
*/

#include "server.h"

int	check_number(char *s)
{
	int i = 0;

	while (s[i]) {
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (84);
	}
	return (0);
}

int	nb_lines(char **arr)
{
	int i = 0;

	while (arr[i])
		i++;
	return (i);
}
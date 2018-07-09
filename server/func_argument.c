/*
** EPITECH PROJECT, 2018
** check argument and assign
** File description:
** Zappy
*/

#include "server.h"

int	fill_struct_arg(t_arg *a, t_opt *opt)
{
	a->i++;
	a->n = 1;
	opt->nameX = malloc(sizeof(char *) * 1);
	if (!opt->nameX)
		return (84);
	opt->nameX[0] = NULL;
	return (0);
}

int	my_names(char **arr, t_opt *opt, t_arg *a)
{
	int	c = 0;

	if (strcmp(arr[a->i], "-n") != 0)
		return (0);
	if (!arr[a->i + 1])
		return (84);
	if (fill_struct_arg(a, opt) == 84)
		return (84);
	while (arr[a->i] && arr[a->i][0] != '-') {
		opt->nameX = realloc_tab(opt->nameX);
		opt->nameX[c] = my_strcat(arr[a->i], "");
		c++;
		if (arr[a->i + 1][0] == '-')
			break;
		a->i++;
	}
	opt->nameX[c] = NULL;
	return (0);
}

void	my_help(void)
{
}
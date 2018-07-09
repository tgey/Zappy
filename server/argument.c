/*
** EPITECH PROJECT, 2018
** check argument and assign
** File description:
** Zappy
*/

#include "server.h"

const parse_t prs[] = {
	{"-p", my_p},
	{"-x", my_x},
	{"-y", my_y},
	{"-c", my_c},
	{"-f", my_f},
	{"-n", my_names},
	{NULL, NULL}
};

void	fill_struct_args(t_arg *a)
{
	a->p = 0;
	a->x = 0;
	a->y = 0;
	a->n = 0;
	a->c = 0;
	a->f = 0;
	a->i = 1;
}

int	all_args(t_arg *a)
{
	if (a->p == 1 && a->x == 1 && a->y == 1 &&
		a->n == 1 && a->c == 1 && a->f == 1)
		return (0);
	else
		return (84);
}

int	find_arg(char **arr, t_opt *opt, t_arg *a)
{
	int	i = 0;

	while (prs[i].name) {
		if (strcmp(arr[a->i], prs[i].name) == 0)
			return (prs[i].func(arr, opt, a));
		i++;
	}
	printf("%s: Not an option\n", arr[a->i]);
	return (84);
}


int	check_args(char **av, t_opt *opt)
{
	t_arg	*a = malloc(sizeof(t_arg));

	if (!a)
		return (my_perror("malloc()"));
	fill_struct_args(a);
	while (av[a->i]) {
		if (find_arg(av, opt, a) != 0) {
			free_a(a);
			return (84);
		}
		a->i++;
	}
	if (all_args(a) == 84) {
		free_a(a);
		return (my_error("Missing some argument"));
	}
	free_a(a);
	return (0);
}
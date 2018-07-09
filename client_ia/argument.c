/*
** EPITECH PROJECT, 2018
** argument function
** File description:
** zappy project
*/

#include "client.h"

const par_t arg[] = {
	{"-p", my_p_cl},
	{"-n", my_n_cl},
	{"-h", my_h_cl},
	{NULL, NULL}
};

int	my_perror(char *s)
{
	perror(s);
	return (84);
}

void	fill_struct_args(t_arg *a)
{
	a->p = 0;
	a->n = 0;
	a->h = -1;
	a->i = 1;
}

int	all_args(t_arg *a)
{
	if (a->p == 1 && a->n == 1 && (a->h == 1 || a->h == -1))
		return (0);
	else
		return (84);
}

int	find_arg(char **arr, t_client *cl, t_arg *a)
{
	int	i = 0;

	while (arg[i].name) {
		if (strcmp(arr[a->i], arg[i].name) == 0)
			return (arg[i].func(arr, cl, a));
		i++;
	}
	printf("%s: Not an option\n", arr[a->i]);
	return (84);
}


int	check_args(char **av, t_client *cl)
{
	t_arg	*a = malloc(sizeof(t_arg));

	if (!a)
		return (my_perror("malloc()"));
	fill_struct_args(a);
	while (av[a->i]) {
		if (find_arg(av, cl, a) != 0) {
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
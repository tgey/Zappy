/*
** EPITECH PROJECT, 2018
** my args function
** File description:
** zappy project
*/

#include "server.h"

int	my_p(char **arr, t_opt *opt, t_arg *a)
{
	if (a->p == 1)
		return (my_error("Option 'p': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'p': No value"));
	a->i++;
	if (check_number(arr[a->i]) == 84)
		return (my_error("Argument 'p' is not a numeric"));
	a->p = 1;
	opt->port = atoi(arr[a->i]);
	return (0);
}

int	my_x(char **arr, t_opt *opt, t_arg *a)
{
	if (a->x == 1)
		return (my_error("Option 'x': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'x': No value"));
	a->i++;
	if (check_number(arr[a->i]) == 84)
		return (my_error("Argument 'x' is not a numeric"));
	a->x = 1;
	opt->width = atoi(arr[a->i]);
	return (0);
}

int	my_y(char **arr, t_opt *opt, t_arg *a)
{
	if (a->y == 1)
		return (my_error("Option 'y': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'y': No value"));
	a->i++;
	if (check_number(arr[a->i]) == 84)
		return (my_error("Argument 'y' is not a numeric"));
	a->y = 1;
	opt->height = atoi(arr[a->i]);
	return (0);
}

int	my_c(char **arr, t_opt *opt, t_arg *a)
{
	if (a->c == 1)
		return (my_error("Option 'c': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'c': No value"));
	a->i++;
	if (check_number(arr[a->i]) == 84)
		return (my_error("Argument 'c' is not a numeric"));
	a->c = 1;
	opt->clientsNb = atoi(arr[a->i]);
	return (0);
}

int	my_f(char **arr, t_opt *opt, t_arg *a)
{
	if (a->f == 1)
		return (my_error("Option 'f': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'f': No value"));
	a->i++;
	if (check_number(arr[a->i]) == 84)
		return (my_error("Argument 'f' is not a numeric"));
	a->f = 1;
	opt->freq = atoi(arr[a->i]);
	return (0);
}
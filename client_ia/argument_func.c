/*
** EPITECH PROJECT, 2018
** argument function
** File description:
** zappy project
*/

#include "client.h"

int	my_error(char *s)
{
	write(1, s, strlen(s));
	write(1, "\n", strlen("\n"));
	return (84);
}

void	free_a(t_arg *a)
{
	if (a)
		free(a);
}

int	my_p_cl(char **arr, t_client *cl, t_arg *a)
{
	if (a->p == 1)
		return (my_error("Option 'p': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'p': No value"));
	a->i++;
	if (check_number(arr[a->i]) == 84)
		return (my_error("Argument 'p' is not a numeric"));
	a->p = 1;
	cl->port = strdup(arr[a->i]);
	if (!cl->port)
		return (84);
	return (0);
}

int	my_n_cl(char **arr, t_client *cl, t_arg *a)
{
	if (a->n == 1)
		return (my_error("Option 'n': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'n': No value"));
	a->i++;
	a->n = 1;
	cl->name = strdup(arr[a->i]);
	if (!cl->name)
		return (84);
	return (0);
}

int	my_h_cl(char **arr, t_client *cl, t_arg *a)
{
	if (a->h == 1)
		return (my_error("Option 'h': double flag"));
	if (!arr[a->i + 1])
		return (my_error("Option 'h': No value"));
	a->i++;
	a->h = 1;
	cl->host = strdup(arr[a->i]);
	if (!cl->host)
		return (84);
	return (0);
}
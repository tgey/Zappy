/*
** EPITECH PROJECT, 2018
** chrono functions
** File description:
** zappy project
*/

#include "server.h"

long int	get_ftime(struct timeval start)
{
	struct timeval	end;
	long int	res;

	gettimeofday(&end, NULL);
	res = (end.tv_sec * 1000000 + end.tv_usec) -
		(start.tv_sec * 1000000 + start.tv_usec);
	return (res);
}
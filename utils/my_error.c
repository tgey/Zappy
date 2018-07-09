/*
** EPITECH PROJECT, 2018
** my_error
** File description:
** Zappy
*/

#include "server.h"

int	close_fd(int fd)
{
	if (close(fd) == -1)
		return (my_perror("close()"));
	return (0);
}

int	my_perror(char *str)
{
	perror(str);
	return (84);
}

int	my_error(char *str)
{
	write(1, "Error: ", strlen("Error: "));
	write(1, str, strlen(str));
	write(1, "\n", strlen("\n"));
	return (84);
}
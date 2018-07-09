/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** zappy project
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "gnl.h"

int	my_stlen(char *str, int a)
{
	int	i = 0;

	if (a == 0) {
		while (str[i] != '\0')
			i += 1;
		return (i);
	}
	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (1);
		i += 1;
	}
	return (0);
}

char	*end_line(char *str, int b)
{
	int	i = 0;
	char	*end;

	if (b == 1) {
		b = 0;
		if ((end = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
			return (NULL);
		while (str[i] != '\n' && str[i] != '\0' && (i = i + 1));
		i += 1;
		while (str[i] != '\0')
			end[b++] = str[i++];
		end[b] = 0;
		return (end);
	}
	if ((end = malloc(sizeof(char) * (my_stlen(str, 0) + 1))) == NULL)
		return (NULL);
	end = copy_last_chars(end, str, i);
	return (end);
}

int	lel(t_gnl *z, int fd)
{
	if ((z->size = read(fd, z->buffer, READ_SIZE)) == -1)
		return (1);
	z->buffer[z->size] = '\0';
	z->line = my_strcat(z->line, z->buffer);
	return (0);
}

t_gnl 	*init_gnl(t_gnl *z, int fd)
{
	if (G)
		return (NULL);
	if (H)
		return (NULL);
	if ((z->buffer = malloc(sizeof(char) *
		(READ_SIZE + 1))) == NULL)
		return (NULL);
	z->line[0] = '\0';
	return (z);
}

char		*get_next_line(const int fd)
{
	static char	*extra;
	static int	a = 0;
	t_gnl		*z;

	if ((z = init_gnl(z, fd)) == NULL || (A && E && F))
		return (NULL);
	if (a > 0)
		z->line = my_strcat(z->line, extra);
	while (my_stlen(z->line, 1) == 0) {
		if (lel(z, fd) == 1)
			return (NULL);
		if (B && C)
			return (my_strcat(z->cpy, z->line));
		if (z->size == 0 && my_stlen(extra, 0) == 0)
			return (NULL);
	}
	extra = end_line(z->line, 1);
	z->line = end_line(z->line, 0);
	a += 1;
	return (z->line);
}
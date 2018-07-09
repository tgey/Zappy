/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** my_irc
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	**tab_add_line(char **tab, char *str)
{
	char	**new = malloc(sizeof(char *) * (tab_len(tab) + 2));
	int	i = 0;

	while (tab[i]) {
		new[i] = calloc(sizeof(char), le(tab[i]) + 1);
		new[i] = strcat(new[i], tab[i]);
		free(tab[i]);
		i += 1;
	}
	new[i] = calloc(sizeof(char), le(str) + 1);
	new[i] = strcat(new[i], str);
	new[i + 1] = NULL;
	free(tab);
	return (new);
}

char	*my_ccat(char *src, char *dest)
{
	char	*ret = calloc(sizeof(char), strlen(src) + strlen(dest) + 2);
	int	i = 0;
	int	j = 0;

	if (ret == NULL)
		return (NULL);
	while (src[i]) {
		ret[i] = src[i];
		i += 1;
	}
	while (dest[j]) {
		ret[i + j] = dest[j];
		j += 1;
	}
	free(src);
	return (ret);
}

char	*get_next_line2(int fd)
{
	char	*str = calloc(sizeof(char), 1);
	char	buf[2];
	int	len = 1;

	buf[0] = 0;
	buf[1] = 0;
	while (len > 0 && buf[0] != '\n') {
		len = read(fd, buf, 1);
		if (len > 0 && buf[0] != '\n')
			str = my_ccat(str, buf);
	}
	if (strlen(str) == 0 && len == 0) {
		free(str);
		return (NULL);
	}
	return (str);
}

char	*re_alloc(char *str)
{
	char	*str2;
	int	i;

	i = 0;
	if ((str2 = malloc((strlen(str) + 2) * sizeof(char))) == NULL)
		return (NULL);
	while (str[i]) {
		str2[i] = str[i];
		i++;
	}
	str2[i + 1] = '\0';
	free(str);
	return (str2);
}

char	*get_next_line(const int fd)
{
	int	i = 0;
	int	size = 0;
	static char	buf[READ_SIZE];
	char	*str;

	if ((str = malloc(sizeof(char))) == NULL)
		return (NULL);
	str[0] = '\0';
	while ((size = read(fd, buf, READ_SIZE)) > 0 &&
		(buf[0] != '\r' && buf[0] != '\n')) {
		str = re_alloc(str);
		str[i++] = buf[0];
	}
	if (size == 0 && i == 0) {
		if (str)
			free(str);
		return (NULL);
	}
	return (str);
}

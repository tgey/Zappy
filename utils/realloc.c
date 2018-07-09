/*
** EPITECH PROJECT, 2018
** realloc
** File description:
** zappy project
*/

#include "server.h"

char	*my_strcat2(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int size = strlen(dest) + strlen(src);
	char *str3 = malloc(sizeof(char) * (size + 1));

	while (dest[i])	{
		str3[i] = dest[i];
		i++;
	}
	while (src[j])
		str3[i++] = src[j++];
	str3[i] = '\0';
	free(dest);
	return (str3);
}

char	*my_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int size = strlen(dest) + strlen(src);
	char *str3 = malloc(sizeof(char) * (size + 1));

	while (dest[i])	{
		str3[i] = dest[i];
		i++;
	}
	while (src[j])
		str3[i++] = src[j++];
	str3[i] = '\0';
	return (str3);
}

char	**realloc_tab(char **arr)
{
	int size = nb_lines(arr);
	int i = 0;
	char **tmp = malloc(sizeof(char *) * (size + 2));

	while (arr[i]) {
		tmp[i] = my_strcat(arr[i], "");
		i++;
	}
	tmp[i] = NULL;
	tmp[i + 1] = NULL;
	free_tab(arr);
	return (tmp);
}

void	free_tab(char **arr)
{
	int	i = 0;

	while (arr[i]) {
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_a(t_arg *a)
{
	if (a)
		free(a);
}
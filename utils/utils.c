/*
** EPITECH PROJECT, 2018
** IRC
** File description:
** PSU_myIRC_2017
*/

#include "utils.h"

int	le(char *str)
{
	return (strlen(str));
}

bool	crlf(char *str)
{
	return (str[le(str) - 1] == '\n' || str[le(str) - 1] == '\r');
}

char	*clear_crlf(char *str)
{
	while (le(str) > 0 && crlf(str))
		str[le(str) - 1] = 0;
	return (str);
}

int	tab_len(char **tab)
{
	int	i = 0;

	while (tab[i] != NULL)
		i++;
	return (i);
}
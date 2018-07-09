/*
** EPITECH PROJECT, 2018
** new gnl func
** File description:
** zappy project
*/

#include "server.h"

char	*copy_last_chars(char *end, char *str, int i)
{
	while (str[i] != '\n' && str[i] != '\0') {
		end[i] = str[i];
		i += 1;
	}
	end[i] = 0;
	return (end);
}
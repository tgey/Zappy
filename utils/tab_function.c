/*
** EPITECH PROJECT, 2018
** all array functions
** File description:
** Zappy project
*/

#include "utils.h"

void	show_word_tab(char **arr)
{
	int	i = 0;

	while (arr[i]) {
		write(1, arr[i], strlen(arr[i]));
		write(1, "\n", strlen("\n"));
		i++;
	}
}

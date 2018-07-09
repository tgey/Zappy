/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fill_inventory
*/

#include "client.h"

void	fill_the_struct_bis(t_player *players, char **tab, int n)
{
	char	**res = my_str_to_wordtab(tab[n++], ' ');

	players->stones->mendiane = atoi(res[1]);
	free_tab(res);
	res = my_str_to_wordtab(tab[n++], ' ');
	players->stones->phiras = atoi(res[1]);
	free_tab(res);
	res = my_str_to_wordtab(tab[n++], ' ');
	players->stones->thystame = atoi(res[1]);
	free_tab(res);
}

void	fill_the_struct(t_player *players, char **tab)
{
	char	**res = my_str_to_wordtab(tab[0], ' ');
	int	n = 1;

	players->food = atoi(res[1]);
	free_tab(res);
	res = my_str_to_wordtab(tab[n++], ' ');
	players->stones->linemate = atoi(res[1]);
	free_tab(res);
	res = my_str_to_wordtab(tab[n++], ' ');
	players->stones->deraumere = atoi(res[1]);
	free_tab(res);
	res = my_str_to_wordtab(tab[n++], ' ');
	players->stones->sibur = atoi(res[1]);
	free_tab(res);
	fill_the_struct_bis(players, tab, n);
}
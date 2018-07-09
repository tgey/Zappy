/*
** EPITECH PROJECT, 2018
** str to wordtab
** File description:
** zappy (ia side)
*/

#include "client.h"

int	nb_words3(char *s, char c)
{
	int	i = 0;
	int	nb = 0;

	while (s[i]) {
		if ((s[i] == c) && i > 0) {
			nb += 1;
			while (s[i] == c)
				i += 1;
		}
		if (s[i])
			i += 1;
	}
	if (s[i - 1] != c)
		nb += 1;
	return (nb);
}

int	nb_char3(char *s, char c)
{
	int	i = 0;

	while (s[i] != '\0' && s[i] != c)
		i += 1;
	return (i);
}

char	**put_in3(char *s, char **tab, char c)
{
	int	i = 0;
	int	j = 1;

	while (i < nb_words3(s, c)) {
		if (s[j] == c)
			while (s[j] == c)
				j += 1;
		free(tab[i]);
		tab[i] = strndup(&s[j], nb_char3(&s[j], c));
		j += nb_char3(&s[j], c);
		i += 1;
	}
	tab[i - 1][strlen(tab[i - 1]) - 1] = 0;
	tab[i] = NULL;
	return (tab);
}

void	fill_struct_inventory(t_client *cli, char *s)
{
	int	i = 0;
	int	j = 0;
	char	**tab;

	if ((tab = malloc(sizeof(char *) * 8)) == NULL)
		return ;
	while (i < 7) {
		if (s[j] == ',')
			while (s[j] == ',')
				j += 1;
		if ((tab[i] = malloc(sizeof(char) *
				(nb_char3(&s[j], ',') + 1))) == NULL)
			return ;
		j += nb_char3(&s[j], ',');
		i += 1;
	}
	tab = put_in3(s, tab, ',');
	fill_the_struct(cli->player, tab);
	free_tab(tab);
}
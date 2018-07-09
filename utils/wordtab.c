/*
** EPITECH PROJECT, 2018
** str to wordtab
** File description:
** my irc (client side)
*/

#include "server.h"

void	my_show_wordtab(char **tab)
{
	int	i = 0;

	while (tab[i]) {
		printf("%s\n", tab[i]);
		i++;
	}
}

int	nb_words2(char *s, char c)
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
	if (i != 0 && s[i - 1] != c)
		nb += 1;
	return (nb);
}

int	nb_char2(char *s, char c)
{
	int	i = 0;

	while (s[i] != '\0' && s[i] != c)
		i += 1;
	return (i);
}

char	**put_in2(char *s, char **tab, char c)
{
	int	i = 0;
	int	j = 0;

	while (i < nb_words2(s, c)) {
		if (s[j] == c)
			while (s[j] == c)
				j += 1;
		tab[i] = my_strncpy(tab[i], &s[j], nb_char2(&s[j], c));
		j += nb_char2(&s[j], c);
		i += 1;
	}
	tab[i] = NULL;
	return (tab);
}

char	**my_str_to_wordtab(char *s, char c)
{
	int	i = 0;
	int	j = 0;
	char	**tab;

	if ((tab = malloc(sizeof(char *) * (nb_words2(s, c) + 1))) == NULL)
		return (NULL);
	while (i < nb_words2(s, c)) {
		if (s[j] == c)
			while (s[j] == c)
				j += 1;
		if ((tab[i] = malloc(sizeof(char) *
				(nb_char2(&s[j], c) + 1))) == NULL)
			return (NULL);
		j += nb_char2(&s[j], c);
		i += 1;
	}
	tab = put_in2(s, tab, c);
	return (tab);
}

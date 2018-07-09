/*
** EPITECH PROJECT, 2018
** irc
** File description:
** str_to_wordtab
*/

#include "utils.h"

char	*my_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	while (i < n && src[i]) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = 0;
	return (dest);
}

int	nb_words(char *s, char c)
{
	int	i = 0;
	int	nb = 0;

	while (s[i]) {
		if (s[i] && (s[i] == c) && i > 0)
			nb += 1;
		while (s[i] && s[i] == c && i > 0)
			i += 1;
		if (s[i])
			i += 1;
	}
	if (i > 0 && s[i - 1] != c)
		nb += 1;
	return (nb);
}

int	nb_char(char *s, char c)
{
	int	i = 0;

	while (s[i] && s[i] != c)
		i += 1;
	return (i);
}

char	**put_in(char *s, char **tab, char c, int a)
{
	int	i = 0;
	int	j = 0;

	while (i < a) {
		while (s[j] == c)
			j += 1;
		my_strncpy(tab[i], &s[j], nb_char(&s[j], c));
		j += nb_char(&s[j], c);
		i += 1;
	}
	tab[i] = NULL;
	return (tab);
}

char	**my_str_to_wordtab2(char *s, char c)
{
	int	i;
	int	j;
	char	**tab;
	int	a;

	i = 0;
	j = 0;
	if (strlen(s) < 1)
		return (NULL);
	a = nb_words(s, c);
	tab = malloc(sizeof(char *) * (a + 1));
	while (i < a) {
		while (s[j] == c)
			j += 1;
		tab[i] = calloc(sizeof(char), (nb_char(&s[j], c) + 1));
		j += nb_char(&s[j], c);
		i += 1;
	}
	tab = put_in(s, tab, c, a);
	return (tab);
}

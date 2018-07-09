/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//utils.c
int	le(char *);
bool	crlf(char *);
char	*clear_crlf(char *);
int	tab_len(char **);

//My_str_to_wordtab.c
char	*my_strncpy(char *, char *, int);
int	nb_words(char *, char);
int	nb_char(char *, char);
char	**put_in(char *, char **, char, int);
char	**my_str_to_wordtab(char *, char);

//tab_function.c
void	show_word_tab(char **);
char	*copy_last_chars(char *end, char *str, int i);

//help.c
void	server_usage();
void	ia_usage();

#endif /* !UTILS_H_ */

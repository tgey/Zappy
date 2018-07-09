/*
** EPITECH PROJECT, 2018
** chained list .h
** File description:
** chained_list
*/

#ifndef CHAINED_LIST_H_
#define CHAINED_LIST_H_

#include <stdbool.h>

typedef struct	s_chained
{
	void			*data;
	bool			last;
	struct s_chained	*next;
}		t_chained;

typedef struct	s_chained_list
{
	t_chained	*first;
	void	(*del)(void *list, void *);
	void	(*destroy)(void *list);
}		t_chained_list;

#endif /* !CHAINED_LIST_H_ */

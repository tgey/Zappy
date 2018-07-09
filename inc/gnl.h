/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** zappy project
*/

#ifndef	READ_SIZE
#define	READ_SIZE (4096)
#endif

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

typedef struct	s_gnl
{
	int		size;
	char		*buffer;
	char		*line;
	char		cpy[1];
	char		*str;
}		t_gnl;

#endif

#ifndef A
#define A (a == 0)
#endif

#ifndef B
#define B (my_stlen(z->line, 1) == 0 && z->size == 0 && (extra[0] = 0) == 0)
#endif

#ifndef C
#define C (my_stlen(z->line, 0) > 0 && (z->cpy[0] = 0) == 0)
#endif

#ifndef E
#define E ((extra = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
#endif

#ifndef F
#define F ((extra[0] = 0) == 0)
#endif

#ifndef G
#define G (fd == -1 || READ_SIZE <= 0 || (z = malloc(sizeof(t_gnl))) == NULL)
#endif

#ifndef H
#define H ((z->line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
#endif

/*
** EPITECH PROJECT, 2018
** game
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include <sys/time.h>
#include "chained_list.h"

typedef struct s_player	t_player;

typedef enum
{
	North = 1,
	Est,
	South,
	West
}	e_dir;

typedef struct	s_team
{
	char		*name;
	int		clientNb;
	t_chained_list	*players;
	t_chained_list	*eggs;
}		t_team;

typedef struct	s_coor
{
	int	x;
	int	y;
}		t_coor;

typedef struct	s_stones
{
	int	linemate;
	t_coor	**line_coor;
	int	deraumere;
	t_coor	**dera_coor;
	int	sibur;
	t_coor	**sibu_coor;
	int	mendiane;
	t_coor	**mend_coor;
	int	phiras;
	t_coor	**phir_coor;
	int	thystame;
	t_coor	**thys_coor;
}		t_stones;

typedef struct s_queue
{
	char		**cmd;
	int		timing;
	struct timeval	timer;
}		t_queue;

typedef struct	s_egg
{
	struct timeval	timer;
	bool		is_forked;
	int		id;
	int		x;
	int		y;
	char		*team;
}		t_egg;

struct	s_player
{
	t_stones	*stones;
	int		x;
	int		y;
	int		id;
	int		fd;
	int		lvl;
	e_dir		dir;
	t_team		*team;
	int		incantation;
	int		food;
	struct timeval	timer;
	t_chained_list	*queue;
	bool		is_egg;
	char		*broadcast;
	bool new_one;
	bool died;
	bool changed;
	int anim;
};

#endif /* !GAME_H_ */

/*
** EPITECH PROJECT, 2018
** client
** File description:
** client
*/

#define _GNU_SOURCE
#ifndef CLIENT_H_
#define CLIENT_H_

#ifndef	UNUSED
#define UNUSED	__attribute__((unused))
#endif

#include <poll.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "game.h"
#include "map.h"
#include "utils.h"
#include "time.h"

typedef struct	s_client
{
	t_player		*player;
	char			*port;
	char			*name;
	char			*host;
	int			serv_fd;
	int			epoll_fd;
	int			connected;
	struct epoll_event	events[2];
	bool			running;
	int			req[6];
	char			*needed;
	int			wanted;
	int			w_food;
	char			**queue;
	char			**w_queue;
	int			n;
	bool			is_waiting;
	int			freq;
	struct timeval		start;
	bool			is_connected;
	bool			is_listening;
	int			c_players;
	int			map_x;
	int			map_y;
	bool			is_coming;
	bool			is_incanting;
	int			*save_id;
	int			len_id;
}		t_client;

typedef struct	s_get_stones
{
	int	index;
	char	*name;
}		get_stones_t;

typedef struct	resp_serv_s
{
	char	*name;
	void	(*func)(t_client *, char *);
}		resp_serv_t;

typedef struct	s_cmd
{
	char	*name;
	int	(*func)(t_client *, char **);
}		t_cmd;

// typedef struct	s_resp
// {
// 	char	*name;
// 	int	(*func)(t_client *, char *);
// }		t_resp;

typedef struct	s_arg
{
	int	p;
	int	n;
	int	h;
	int	i;
}		t_arg;

typedef struct	par_s
{
	char	*name;
	int	(*func)(char **, t_client *, t_arg *);
}		par_t;

extern	const	t_client	*cli_gbl;

//main.c
int	iterate_epoll(t_client *, int);
int	loop_epoll(t_client *);

//init graph data
int	iterate_epoll_get(t_client *cli, int n, char *line);
int	iterate_epoll_post(t_client *cli, char *line);
int	init_loop_epoll(t_client *cli, int init_count,
	int event_count, int ret);
void	malloc_resources_coor(t_client *client);

//sig.c
void	init_sig(void);
void	sig_handler(int);

//argument_func.c
int	my_p_cl(char **arr, t_client *cl, t_arg *a);
int	my_n_cl(char **arr, t_client *cl, t_arg *a);
int	my_h_cl(char **arr, t_client *cl, t_arg *a);
void	free_a(t_arg *a);
int	my_error(char *s);

//queue.c
int	qsend(t_client *, char *);
char	**pop_last(t_client *, char **);
char	**pop_last_w_queue(char **tab);

//survive.c
int	find_missing_stones(t_client *cli);
void	check_missing_stones(t_client *cli);

//realloc.c
char	*my_strcat(char *, char *);
char	*my_strcat2(char *, char *);

//handler.c
void	server_handler(t_client *cli, int n);
int	algo_handler(t_client *cli);

//argument.c
int	check_args(char **av, t_client *cl);

//parse_inventory.c
void	fill_struct_inventory(t_client *cli, char *s);

//init.c
void	init_epoll(t_client *);
void	init_new_client(t_client *);

//get_next_line.c
int	check_number(char *);
int	nb_lines(char **);
char	*re_alloc(char *);
char	*get_next_line(const int);

//client.c
int	check_if_connected(t_client *);
void	set_epoll_on_connect(t_client *);
void	try_connect(char *, const char *, t_client *);

//str_cmd.c
int	launch_command(t_client *, char **, int);
int	launch_response(t_client *, char **, int);
char	*clear_ending_spaces(char *);
int	my_command(t_client *, char *);
void	get_response(t_client *, char *);

//map.c
void	init_client_map(t_map *, int, int);
void	init_client_cells(t_map *);
void	init_client_stones(t_stones *);
void	free_client_map(t_map *map);


//free.c
void	free_t_client(t_client *client);
void	free_tab(char **tab);

//bct.c
int	fct_bct(t_client *, char **);
void	resp_bct(t_client *, char **);

//mct.c
int	fct_mct(t_client *, char **);

//msz.c
int	fct_msz(t_client *, char **);
void	resp_msz(t_client *, char **);

//pin.c
int	fct_pin(t_client *, char **);
void	resp_pin(t_client *, char **);

//plv.c
int	fct_plv(t_client *, char **);
void	resp_plv(t_client *, char **);

//ppo.c
int	fct_ppo(t_client *, char **);
void	resp_ppo(t_client *, char **);

//sgt.c
int	fct_sgt(t_client *, char **);
void	resp_sgt(t_client *, char **);

//sst.c
int	fct_sst(t_client *, char **);
void	resp_sst(t_client *, char **);

//tna.c
int	fct_tna(t_client *, char **);
void	resp_tna(t_client *, char **);

//cmd.c
void	inventory(t_client *cli);
void	look(t_client *cli);
int	found_stones(t_client *cli, int n);
void	my_fork(t_client *cli, char *line);

//serv_handler.c
void	server_handler(t_client *cli, int n);

//stone.c
int	find_stones(t_client *cli, char *line);
void	take_all(t_client *cli, char *line);
void	increase_stone(t_client *cli);
void	decrease_stone(t_client *cli);

//take_stone.c
void	go_take(t_client *cli, char *str, int x);
void	drop_stones(t_client *cli);

//fill_req.c
int	*get_req(t_client *cli);
int	*fill_req_lvl_1();
int	*fill_req_lvl_2();
int	*fill_req_lvl_3();
int	*fill_req_lvl_4();
int	*fill_req_lvl_5();
int	*fill_req_lvl_6();
int	*fill_req_lvl_7();

//regroup.c
int	check_cell_players(t_client *cli);
int	nb_player_needed(t_client *cli);

//broadcast.c
int	listen_broadcast(t_client *cli, char *line);

//algo.c
int	algo(t_client *cli);
void	go_to_random(t_client *cli);

//food.c
int	check_food(t_client *cli, char *str, int x, int n);
int	find_food(t_client *cli, char *line, char *str);

//serv_hanler.c
void	my_incant2(t_client *cli, UNUSED char *line);
void	check_look(t_client *cli, char *line);

//analyse.c
void	analyse_line(t_client *cli, char *line);
char	*epur_str(char *line);

//fill_inventory.c
void	fill_the_struct(t_player *players, char **tab);

//take_food.c
int	check_food(t_client *cli, char *str, int x, int n);
void	take_all_food(t_client *cli, int x, int n);

//move_broadcast.c
int	invit_player(t_client *cli, char **tab);
int	move_to_4(t_client *cli);
int	move_to_5(t_client *cli);
int	move_to_6(t_client *cli);
int	move_to_7(t_client *cli);
int	move_to_8(t_client *cli);

#endif /* !CLIENT_H_ */

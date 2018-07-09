/*
** EPITECH PROJECT, 2018
** Zappy .h
** File description:
** PSU_zappy_2017
*/

#define _GNU_SOURCE
#define READ_SIZE 1

#ifndef SERVER_H_
#define SERVER_H_

#ifndef	UNUSED
#define UNUSED	__attribute__((unused))
#endif

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <poll.h>
#include <time.h>
#include <sys/epoll.h>
#include <signal.h>

#include "chained_list.h"
#include "game.h"
#include "utils.h"
#include "map.h"

typedef struct	s_arg
{
	int	p;
	int	x;
	int	y;
	int	n;
	int	c;
	int	f;
	int	i;
	char	**names;
}		t_arg;

typedef struct	s_opt
{
	int	port;
	int	width;
	int	height;
	char	**nameX;
	int	clientsNb;
	int	freq;
}		t_opt;


typedef struct	s_serv
{
	struct epoll_event	events[32];
	struct sockaddr_in	sin;
	int			serv_fd;
	int			graph_fd;
	int			freq;
	int			clientNb;
	t_map			*map;
	int			cid;
	socklen_t		serv_size;
	time_t			start;
	bool			running;
	t_chained_list		*teams;
	t_chained_list		*players;
}		t_serv;

typedef struct	cmd_serv_s
{
	char	*name;
	int	(*func)(int, t_serv *, char **);
}		cmd_serv_t;

typedef struct	item_s
{
	char	*name;
	int	(*func)(t_player *, t_serv *);
}		item_t;

typedef struct	parse_s
{
	char	*name;
	int	(*func)(char **, t_opt *, t_arg *);
}		parse_t;

typedef struct	timing_s
{
	char	*name;
	int	(*func)(void);
}		timing_t;

extern	const	t_serv	*serv_gbl;
extern	const	t_opt	*opt_gbl;

//init.c
int	init_server_socket(t_serv *, t_opt *);
void	init_server_struct(t_serv *);
void	init_teams(t_serv *, t_opt *);
void	init_global(t_serv *, t_opt *);

//calc_stones.c
void	re_generation(t_map *map);
void	add_obj(t_stones *stones, t_map *map, int x, int j);
int	get_nbr_teams(t_serv *serv);
void	init_food(int rand_stones, t_map *map, int i, int j);

//opt.c
void	init_default_opt(t_opt *);
void	init_server_opt(t_opt *);
void	free_opt(t_opt *);

//incantation_switch.c
int	req_case_1(t_player *players, t_serv *serv, int cli_fd, int *req);
int	req_case_2(t_player *players, t_serv *serv, int cli_fd, int *req);
int	req_case_3(t_player *players, t_serv *serv, int cli_fd, int *req);
int	req_case_4(t_player *players, t_serv *serv, int cli_fd, int *req);
int	req_case_5(t_player *players, t_serv *serv, int cli_fd, int *req);
int	req_case_6(t_player *players, t_serv *serv, int cli_fd, int *req);
int	req_case_7(t_player *players, t_serv *serv, int cli_fd, int *req);
int	send_all_cell(t_serv *serv, t_player *players, char *msg);
int	send_all_cell2(t_serv *serv, t_player *players, char *msg);

//incantation_switch_res.c
void	p_free(char **ptr);
int	req_case_1_res(t_player *players, t_serv *serv,
	int cli_fd, int *req);
int	req_case_2_res(t_player *players, t_serv *serv, int cli_fd,
	int *req);
int	req_case_3_res(t_player *players, t_serv *serv, int cli_fd,
	int *req);
int	req_case_4_res(t_player *players, t_serv *serv, int cli_fd,
	int *req);
int	req_case_5_res(t_player *players, t_serv *serv, int cli_fd,
	int *req);
int	req_case_6_res(t_player *players, t_serv *serv, int cli_fd,
	int *req);
int	req_case_7_res(t_player *players, t_serv *serv, int cli_fd,
	int *req);


//take_fcts.c
int	take_food(t_player *players, t_serv *serv);
int	take_linemate(t_player *players, t_serv *serv);
int	take_deraumere(t_player *players, t_serv *serv);
int	take_sibur(t_player *players, t_serv *serv);
int	take_mendiane(t_player *players, t_serv *serv);
int	take_phiras(t_player *players, t_serv *serv);

//set_fcts.c
int	set_linemate(t_player *players, t_serv *serv);
int	set_deraumere(t_player *players, t_serv *serv);
int	set_sibur(t_player *players, t_serv *serv);
int	set_mendiane(t_player *players, t_serv *serv);
int	set_phiras(t_player *players, t_serv *serv);

//map.c
void	init_server_map(t_map *, t_opt *);
void	init_server_cells(t_map *);
void	init_server_stones(t_stones *);
void	free_map(t_map *);

//timing_func.c
int	time_seven(void);
int	time_one(void);
int	time_forty_two(void);
int	time_three_hundred(void);
int	time_instant(void);

//argument.c
int	check_args(char **, t_opt *);
void	fill_struct_args(t_arg *);
int	find_arg(char **, t_opt *, t_arg *);
int	all_args(t_arg *);

//func_argument.c
int	my_pxycf(char **, int);
int	my_names(char **, t_opt *, t_arg *);

//option_arg.c
int	my_x(char **arr, t_opt *opt, t_arg *a);
int	my_p(char **arr, t_opt *opt, t_arg *a);
int	my_y(char **arr, t_opt *opt, t_arg *a);
int	my_c(char **arr, t_opt *opt, t_arg *a);
int	my_f(char **arr, t_opt *opt, t_arg *a);

//epoll_func.c
char	*my_asprintf_epoll(t_player *pl);
char	*my_asprintf_epoll2(t_player *pl);

//get_next_line.c
int	check_number(char *);
int	nb_lines(char **);
char	*re_alloc(char *);
char	*get_next_line(const int);

//chrono.c
void	print_chrono_now(t_serv *srv);
void	init_chrono(t_serv *srv);
long int	get_ftime(struct timeval start);

//sig.c
void	sig_handler(int);
void	init_sig(void);

//realloc.c
char	*my_strcat(char *, char *);
char	*my_strcat2(char *dest, char *src);
char	**realloc_tab(char **);
void	free_tab(char **);
void	free_a(t_arg *);

//my_error.c
int	my_error(char *);
int	my_perror(char *);
int	close_fd(int);

//epoll_handling.c
void	loop_zappy(t_serv *);
void	epoll_handling(t_serv *, int);
void	epoll_loop(t_serv *, int, int);
void	incoming_player(t_serv *, int);
int	loop_player(t_serv *, char *, int);

//cmd_action.c
void	loop_command_act(int, t_serv *, char *);
int     check_player_queue(t_serv *serv);

//cmd_graphic.c
void	loop_graphic(int, t_serv *, char *);
char	**empty_command(char **);
int     get_cmd_graph(int, t_serv *, char *, char **);

//free.c
void	free_all(t_serv *, t_opt *, t_map *);
void	free_server(t_serv *, t_opt *);

//chained_team.c
t_team	*empty_team(char *);
t_team	*get_team_by_name(void *, char *);
void	destroy_team_list(void *);
void	delete_team_ptr(void *, void *);

//debug.c
void	print_map(t_map *map);

//chained_player.c
t_player	*empty_player(void);
t_player	*get_player_by_id(void *, int);
t_player	*get_player_by_fd(void *, int);
t_player	*get_player_by_lvl(void *, int);
void		destroy_player_list(void *);
void		destroy_player_list2(void *);
void		delete_player_fd(void *, void *);

//queue.c
void		destroy_queue_list(void *);
void		delete_queue_ptr(void *, void *);
void		delete_last_queue(void *list);
t_queue		*get_queue_by_player(void *list, char **cmd);
t_queue		*get_last_queue(void *list);

//eggs.c
int	check_eggs_queue(t_serv *serv);
void	delete_last_egg(void *list);
void	delete_egg_ptr(void *list, void *ptr);
void	destroy_egg_list(void *list);
void	check_if_egg(int, t_serv *serv, char *team_name, t_player *player);

//food.c
void	check_player_food(t_serv *serv);

//chained_list.c
int	chained_list_len(t_chained_list *);
t_chained_list	*init_chained_list(void (*del)(void *, void *),
	void (*destroy)(void *));
void	insert_chained_list(t_chained_list *, void *);
void	delete_chained_list(t_chained_list *, int);

//chained_player.c
t_egg	*empty_egg(void);
t_egg	*get_egg_by_id(void *, int);
void	destroy_egg_list(void *);
void	delete_egg_id(void *, void *);

//client.c
void	add_player(int, t_serv *, UNUSED char *, t_player *);
void	add_in_team(t_serv *, char *, t_player *);
void	player_connection(int, t_serv *, char *);
void	create_team(t_serv *serv, char *team);

//remove_player.c
void	delete_player_all(t_serv *, int);
bool	removing_player(t_serv *, int, int);
int	remove_player(t_serv *, int);

//connection.c
void	loop_connection(int, t_serv *, char *);

//serv_bct.c
int	serv_bct(int cli_fd, t_serv *serv, char **tab);

//serv_ebo.c
int	serv_ebo(int cli_fd, t_serv *serv, char **tab);

//serv_edi.c
int	serv_edi(int cli_fd, t_serv *serv, char **tab);

//serv_eht.c
int	serv_eht(int cli_fd, t_serv *serv, char **tab);

//serv_enw.c
int	serv_enw(int cli_fd, t_serv *serv, char **tab);

//serv_msz.c
int	serv_msz(int cli_fd, t_serv *serv, char **tab);

//serv_pbc.c
int	serv_pbc(int cli_fd, t_serv *serv, char **tab);

//serv_pdi.c
int	serv_pdi(int cli_fd, t_serv *serv, char **tab);

//serv_pdr.c
int	serv_pdr(int cli_fd, t_serv *serv, char **tab);

//serv_pex.c
int	serv_pex(int cli_fd, t_serv *serv, char **tab);

//serv_pfk.c
int	serv_pfk(int cli_fd, t_serv *serv, char **tab);

//serv_pgt.c
int	serv_pgt(int cli_fd, t_serv *serv, char **tab);

//serv_pic.c
int	serv_pic(int cli_fd, t_serv *serv, char **tab);

//serv_pie.c
int	serv_pie(int cli_fd, t_serv *serv, char **tab);

//serv_pin.c
int	serv_pin(int cli_fd, t_serv *serv, char **tab);

//serv_plv.c
int	serv_plv(int cli_fd, t_serv *serv, char **tab);

//serv_pnw.c
int	serv_pnw(int cli_fd, t_serv *serv, char **tab);

//serv_ppo.c
int	serv_ppo(int cli_fd, t_serv *serv, char **tab);

//serv_sbp.c
int	serv_sbp(int cli_fd, t_serv *serv, char **tab);

//serv_seg.c
int	serv_seg(int cli_fd, t_serv *serv, char **tab);

//serv_sgt.c
int	serv_sgt(int cli_fd, t_serv *serv, char **tab);

//serv_smg.c
int	serv_smg(int cli_fd, t_serv *serv, char **tab);

//serv_sst.c
int	serv_sst(int cli_fd, t_serv *serv, char **tab);

//serv_suc.c
int	serv_suc(int cli_fd, t_serv *serv, char **tab);

//serv_tna.c
int	serv_tna(int cli_fd, t_serv *serv, char **tab);

//serv_mct.c
int	serv_mct(int cli_fd, t_serv *serv, char **tab);

//broadcast.c
int	serv_broadcast(int cli_fd, t_serv *serv, char **tab);
int	diago_x(t_player *rv_pl, t_player *sd_pl, t_serv *serv);
int	diago_y(t_player *rv_pl, t_player *sd_pl, t_serv *serv);
int	get_broad_dir(t_player *recv_pl, t_player *send_pl, t_serv *serv);
int	get_cardinaux(t_player *recv_pl, t_player *send_pl);
int	get_diagonals(t_player *recv_pl, t_player *send_pl, t_serv *serv);
void	send_broad(t_player *player, UNUSED t_serv *serv, char *msg);

//connect_nbr.c
int	serv_connect(int cli_fd, t_serv *serv, char **tab);

//eject.c
int	serv_eject(int cli_fd, t_serv *serv, char **tab);

//fork.c
int	serv_fork(int cli_fd, t_serv *serv, char **tab);

//forward.c
int	serv_forward(int cli_fd, t_serv *serv, char **tab);
void	forward_north(t_player *, t_serv *);
void	forward_west(t_player *, t_serv *);
void	forward_est(t_player *, t_serv *);
void	forward_south(t_player *, t_serv *);
void	send_forward(t_player *team_player, t_serv *serv, int cli_fd);

//incantation.c
int	serv_incantation(int cli_fd, t_serv *serv, char **tab);

//incantation_func.c
int	my_send_err(int fd, char *s);
int	my_send(int fd, char *s);
int	check_level_stone_end(t_player *players, t_serv *srv,
	int *req, int nb);
int	serv_incantation_end(int cli_fd, UNUSED t_serv *serv,
	UNUSED char **tab);

//inventory.c
int	serv_inventory(int cli_fd, t_serv *serv, char **tab);
int	*fill_req(int *req, int a, int b, int c, int nb);
int	check_level_stone(t_player *players, t_serv *srv, int *req, int nb);
int	check_players_on_cell(t_player *pl, t_serv *srv);

//left.c
int	serv_left(int cli_fd, t_serv *serv, char **tab);

//look.c
int	serv_look(int cli_fd, t_serv *serv, char **tab);
char	*look_player(t_cell *cell, char *message);
char	*look_food(t_cell *cell, char *message);
char	*look_linemate(t_cell *cell, char *message);
char	*look_deraumere(t_cell *cell, char *message);
char	*look_thystame(t_cell *cell, char *message);
char	*look_phiras(t_cell *cell, char *message);
char	*look_mendiane(t_cell *cell, char *message);
char	*look_sibur(t_cell *cell, char *message);
char	*look_global(t_cell *cell, char *message);

//right.c
int	serv_right(int cli_fd, t_serv *serv, char **tab);

//set.c
int	serv_set(int cli_fd, t_serv *serv, char **tab);
int	set_thystame(t_player *players, t_serv *serv);

//take.c
int	serv_take(int cli_fd, t_serv *serv, char **tab);
int	take_thystame(t_player *players, t_serv *serv);

//random.c
int	gen_a_rdm_number(int max);
void	init_obj(t_stones *stones, t_map *map, int i, int j);

#endif /* !SERVER_H_ */

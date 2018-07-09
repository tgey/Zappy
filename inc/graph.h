/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** graphical header
*/

#ifndef GRAPH_H_
#define GRAPH_H_

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

typedef struct graph_s graph_t;
typedef struct cmd_s cmd_t;
typedef struct resp_s resp_t;

typedef struct map_s map_t;
typedef struct cell_s cell_t;
typedef struct stones_s stones_t;
typedef struct place_s place_t;

struct place_s
{
	int x;
	int y;
};

struct stones_s
{
	t_chained_list *linemate;
	t_chained_list *deraumere;
	t_chained_list *sibur;
	t_chained_list *mendiane;
	t_chained_list *phiras;
	t_chained_list *thystame;
};

struct cell_s
{
	t_chained_list *food;
	stones_t *stones;
	t_chained_list	*players;
	t_chained_list	*eggs;
};

struct map_s
{
	int width;
	int height;
	float percent_x;
	float percent_y;
	cell_t ***map;
};

struct graph_s
{
	map_t *map;
	int serv_fd;
	int epoll_fd;
	struct epoll_event events[2];
	t_chained_list *players;
	t_chained_list *eggs;
	int frequency;
	bool running;
	bool new_player;
	bool player_died;
};

struct cmd_s
{
	char *name;
	void (*func)(graph_t *, char **);
};

struct resp_s
{
	char *name;
	void (*func)(graph_t *, char **);
};

extern const graph_t *graph_gbl;

//chained_list.c
int chained_list_len(t_chained_list *);
t_chained_list *init_chained_list(void (*del)(void *, void *),
	void (*destroy)(void *));
void insert_chained_list(t_chained_list *, void *);
void delete_chained_list(t_chained_list *, int);

//chained_player.c
t_player *empty_player(void);
t_player *get_player_by_id(void *, int);
t_player *get_player_by_fd(void *, int);
t_player *get_player_by_lvl(void *, int);
void destroy_player_list(void *);
void delete_player_fd(void *, void *);

//chained_egg.c
t_egg *empty_egg(void);
t_egg *get_egg_by_id(void *, int);
void delete_egg_ptr(void *list, void *ptr);
void destroy_egg_list(void *);
void delete_egg_id(void *, void *);

//connect.c
bool set_epoll_on_connect_graphical(graph_t *graph);
bool try_connect_graphical(graph_t *, const char *, const char *);
void identify_to_server(graph_t *graph);

//sig.c
void init_sig(void);

//init.c
bool init_epoll_graphical(graph_t *);
void init_graphical_data(graph_t *);
graph_t *graph_init(const char *, const char *);

//on_start.c
char *clendsp(char *cmd);
bool graph_send_command(graph_t *graph, const char *cmd);
bool graph_rcv_command(graph_t *graph, char *cmd);

char *get_next_line(int);
void free_tab(char **);

//receiver.c
int rcv_command(graph_t *graph);

//fct_ptr
void resp_pdr(graph_t *graph, char **args);
void resp_pgt(graph_t *graph, char **args);
void resp_pic(graph_t *graph, char **args);
void resp_pie(graph_t *graph, char **args);

//functions
void sgt_send_g(graph_t *, char **);
void msz_send_g(graph_t *, char **);
void mct_send_g(graph_t *, char **);
void bct_send_g(graph_t *, char **);
void sst_send_g(graph_t *, char **);
void tna_send_g(graph_t *graph, UNUSED char **args);
void ppo_send_g(graph_t *graph, char **args);
void plv_send_g(graph_t *graph, char **args);
void pin_send_g(graph_t *graph, char **args);

void sgt_recv_g(graph_t *, char **);
void msz_recv_g(graph_t *, char **);
void bct_recv_g(graph_t *, char **);
void pnw_recv_g(graph_t *, char **);
void sst_recv_g(graph_t *, char **);
void pbc_recv_g(graph_t *graph, char **args);
void pdr_recv_g(graph_t *graph, char **args);
void pgt_recv_g(graph_t *graph, char **args);
void pic_recv_g(graph_t *graph, char **args);
void pie_recv_g(graph_t *graph, char **args);
void tna_recv_g(UNUSED graph_t *graph, char **args);
void ppo_recv_g(UNUSED graph_t *graph, char **args);
void plv_recv_g(UNUSED graph_t *graph, char **args);
void pin_recv_g(UNUSED graph_t *graph, char **args);
void seg_recv_g(graph_t *graph, UNUSED char **args);
void pex_recv_g(graph_t *graph, UNUSED char **args);
void pfk_recv_g(graph_t *graph, UNUSED char **args);
void pdi_recv_g(graph_t *graph, UNUSED char **args);
void enw_recv_g(graph_t *graph, UNUSED char **args);
void eht_recv_g(graph_t *graph, UNUSED char **args);
void ebo_recv_g(graph_t *graph, UNUSED char **args);
void edi_recv_g(graph_t *graph, UNUSED char **args);

void init_client_map(t_map *map, int width, int height);

//map.c
void init_stones_lists(stones_t *stones);
void init_map_cells(map_t *map);
void init_map_graph(map_t *map, int width, int height);

//chained_place.c
place_t *empty_place(void);
void destroy_place_list(void *list);
void pop_front_place_list(void *list);
void delete_place_by_place(UNUSED void *list, UNUSED void *fd);

//fill_place.c
void fill_place(graph_t *graph, t_chained_list *list, int nb);

//free.c
void	free_graph_data(graph_t *graph);

#endif /* GRAPH_H_ */

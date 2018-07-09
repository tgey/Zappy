/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init graph client
*/

#include "graph.h"

const graph_t *graph_gbl;

bool init_epoll_graphical(graph_t *graph)
{
	struct epoll_event event;

	graph->epoll_fd = epoll_create(2);
	memset(&event, 0, sizeof(struct epoll_event));
	event.events = POLLIN;
	event.data.fd = 0;
	if (epoll_ctl(graph->epoll_fd, EPOLL_CTL_ADD, 0, &event)) {
		fprintf(stderr, "Failed to add file descriptor to epoll\n");
		close(graph->epoll_fd);
		return (false);
	}
	graph->running = true;
	return (true);
}

void init_graphical_data(graph_t *graph)
{
	graph->serv_fd = -1;
	graph->map = malloc(sizeof(map_t));
	graph->map->width = -1;
	graph->map->height = -1;
	graph->map->map = NULL;
	graph->frequency = -1;
	graph->new_player = false;
	graph->player_died = false;
	graph->players = init_chained_list(&delete_player_fd,
	&destroy_player_list);
	graph->eggs = init_chained_list(&delete_egg_id,
	&destroy_egg_list);
	graph->running = false;
}

graph_t *graph_init(const char *port, const char *hostname)
{
	graph_t *graph = malloc(sizeof(graph_t));

	if (!graph)
		return (NULL);
	graph_gbl = graph;
	init_sig();
	if (!init_epoll_graphical(graph))
		return (NULL);
	init_graphical_data(graph);
	printf("Welcome on our Zappy, connect to a server !\n");
	if (!try_connect_graphical(graph, port, hostname))
		return (NULL);
	return (graph);
}
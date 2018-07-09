/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** msz
*/

#include "graph.h"

void msz_send_g(graph_t *graph, UNUSED char **args)
{
	send(graph->serv_fd, "msz\n", 4, 0);
}

void msz_recv_g(graph_t *graph, char **args)
{
	if (tab_len(args) == 3)
		init_map_graph(graph->map, atoi(args[1]), atoi(args[2]));
}
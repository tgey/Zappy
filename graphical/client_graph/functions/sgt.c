/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** sgt
*/

#include "graph.h"

void sgt_send_g(graph_t *graph, UNUSED char **args)
{
	send(graph->serv_fd, "sgt\n", 4, 0);
}

void sgt_recv_g(graph_t *graph, char **args)
{
	if (tab_len(args) == 2) {
		graph->frequency = atoi(args[1]);
		printf("Time Unit = %s\n", args[1]);
	}
}

/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** mct
*/

#include "graph.h"

void mct_send_g(graph_t *graph, UNUSED char **args)
{
	send(graph->serv_fd, "mct\n", 4, 0);
}
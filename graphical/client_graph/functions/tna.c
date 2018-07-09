/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** tna
*/

#include "graph.h"

void	tna_send_g(graph_t *graph, UNUSED char **args)
{
	send(graph->serv_fd, "tna\n", 4, 0);
}

void	tna_recv_g(UNUSED graph_t *graph, char **args)
{
	printf("Team \"%s\"\n", args[1]);
}
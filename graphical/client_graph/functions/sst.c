/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** sst
*/

#include "graph.h"

void sst_send_g(graph_t *graph, char **args)
{
	char	str[512];

	if (tab_len(args) == 2) {
		sprintf(str, "sst %s\n", args[1]);
		send(graph->serv_fd, str, strlen(str), 0);
	} else
		printf("sst: bad arguments\n");
}

void sst_recv_g(graph_t *graph, char **args)
{
	if (tab_len(args) == 2) {
		printf("Time Unit modified = %s\n", args[1]);
		graph->frequency = atoi(args[1]);
	}
}
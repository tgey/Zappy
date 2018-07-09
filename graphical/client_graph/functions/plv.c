/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** plv
*/

#include "graph.h"

void	plv_send_g(graph_t *graph, char **args)
{
	char	str[512];

	if (tab_len(args) > 1) {
		sprintf(str, "plv %s\n", args[1]);
		send(graph->serv_fd, str, strlen(str), 0);
	} else
		printf("pin: missing arguments\n");
}

void	plv_recv_g(UNUSED graph_t *graph, char **args)
{
	printf("player %s is level %s\n", args[1], args[2]);
}
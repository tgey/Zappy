/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** pin
*/

#include "graph.h"

void	pin_send_g(graph_t *graph, char **args)
{
	char	str[512];

	if (tab_len(args) > 1) {
		sprintf(str, "pin %s\n", args[1]);
		send(graph->serv_fd, str, strlen(str), 0);
	} else
		printf("pin: missing arguments\n");
}

void	pin_recv_g(UNUSED graph_t *graph, char **args)
{
	printf("player %s X:%s Y:%s food:%s q1:%s q2:%s q3:%s \
	q4:%s q5:%s q6:%s\n",
	args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8],
	args[9], args[10]);
}
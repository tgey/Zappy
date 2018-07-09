/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** rcv command
*/

#include "graph.h"

int rcv_command(graph_t *graph)
{
	int event_count;
	char *line = NULL;

	event_count = epoll_wait(graph->epoll_fd, graph->events, 2, 0);
	for (int n = 0; n < event_count; n++) {
		line = get_next_line(graph->events[n].data.fd);
		if (line) {
			printf("SERV: %s\n", line);
			graph_rcv_command(graph, line);
		}
		free(line);
	}
	return event_count;
}
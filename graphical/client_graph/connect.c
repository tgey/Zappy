/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** connection
*/

#include "graph.h"

void identify_to_server(graph_t *graph)
{
	char *str = "graphical_client\n";

	send(graph->serv_fd, str, le(str), 0);
}

bool set_epoll_on_connect_graphical(graph_t *graph)
{
	struct epoll_event event;

	memset(&event, 0, sizeof(struct epoll_event));
	event.events = POLLIN;
	event.data.fd = graph->serv_fd;
	if (epoll_ctl(graph->epoll_fd, EPOLL_CTL_ADD,
	graph->serv_fd, &event) != 0) {
		fprintf(stderr, "Failed to add file descriptor to epoll\n");
		close(graph->epoll_fd);
		return false;
	}
	printf("Connected\n");
	return true;
}

bool try_connect_graphical(graph_t *graph,
	const char *port, const char *hostname)
{
	struct addrinfo c_in = {0};
	struct addrinfo *fill;

	c_in.ai_family = AF_UNSPEC;
	c_in.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(hostname, port ? port : "6667", &c_in, &fill))
		return false;
	graph->serv_fd = socket(fill->ai_family, fill->ai_socktype,
	fill->ai_protocol);
	if (!(graph->serv_fd != -1 &&
	connect(graph->serv_fd, fill->ai_addr, fill->ai_addrlen) != -1)) {
		printf("error connect\n");
		close(graph->serv_fd);
		freeaddrinfo(fill);
		return false;
	}
	freeaddrinfo(fill);
	return set_epoll_on_connect_graphical(graph);
}

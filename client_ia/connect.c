/*
** EPITECH PROJECT, 2018
** connection to the server
** File description:
** connect
*/

#include "client.h"

int	check_if_connected(t_client *cli)
{
	if (cli->connected != 1)
	{
		printf("You aren't connected to any server !\n");
		return (-1);
	}
	return (0);
}

void	set_epoll_on_connect(t_client *cli)
{
	struct epoll_event	event;

	memset(&event, 0, sizeof(struct epoll_event));
	event.events = POLLIN;
	event.data.fd = cli->serv_fd;
	if (epoll_ctl(cli->epoll_fd, EPOLL_CTL_ADD,
	cli->serv_fd, &event) != 0) {
		fprintf(stderr, "Failed to add file descriptor to epoll\n");
		close(cli->epoll_fd);
		return;
	}
}

void	try_connect(char *port, const char *ip, t_client *cli)
{
	struct	addrinfo	c_in = {0};
	struct	addrinfo	*fill;

	c_in.ai_family = AF_UNSPEC;
	c_in.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(ip, port ? port : "6667", &c_in, &fill))
		return;
	cli->serv_fd = socket(fill->ai_family, fill->ai_socktype,
	fill->ai_protocol);
	if (cli->serv_fd == -1 ||
	connect(cli->serv_fd, fill->ai_addr, fill->ai_addrlen) == -1)
	{
		printf("error connect\n");
		close(cli->serv_fd);
		freeaddrinfo(fill);
		return;
	}
	freeaddrinfo(fill);
	set_epoll_on_connect(cli);
}
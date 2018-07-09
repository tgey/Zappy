/*
** EPITECH PROJECT, 2018
** epoll function
** File description:
** zappy project
*/

#include "server.h"

void	incoming_player(t_serv *serv, int epoll_fd)
{
	struct	sockaddr_in	s_in_c;
	socklen_t		s_in_s = sizeof(struct sockaddr_in);
	struct	epoll_event	ev;
	int			client_fd = accept(serv->serv_fd,
	(struct sockaddr *)&s_in_c, &s_in_s);

	if (client_fd == -1) {
		perror("accept()");
		return;
	}
	memset(&ev, 0, sizeof(struct epoll_event));
	ev.events = EPOLLIN | EPOLLERR;
	ev.data.fd = client_fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev) == -1) {
		perror("epoll_ctl()");
		return;
	}
	re_generation(serv->map);
	send(client_fd, "WELCOME\n", strlen("WELCOME\n"), 0);
}

int	loop_player(t_serv *serv, char *buf, int client_fd)
{
	if (!buf)
		remove_player(serv, client_fd);
	else {
		buf = clear_crlf(buf);
		loop_command_act(client_fd, serv, buf);
		free(buf);
	}
	return (0);
}

char	*my_asprintf_epoll(t_player *pl)
{
	char *msg;

	asprintf(&msg, "pin %i %i %i %i %i %i %i %i %i %i\n",
			pl->id, pl->x, pl->y, pl->food, pl->stones->linemate,
			pl->stones->deraumere, pl->stones->sibur,
			pl->stones->mendiane, pl->stones->phiras,
			pl->stones->thystame);
	return (msg);
}

char	*my_asprintf_epoll2(t_player *pl)
{
	char *msg;

	asprintf(&msg, "pnw %i %i %i %i %i %s\n",
		pl->id, pl->x, pl->y, pl->dir, pl->lvl, pl->team->name);
	return (msg);
}
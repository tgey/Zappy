/*
** EPITECH PROJECT, 2018
** epoll
** File description:
** PSU_zappy_2017
*/

#include "server.h"

int	check_if_graph(int fd, char *buf, t_serv *serv)
{
	t_chained 	*current = ((t_chained_list *)serv->players)->first;
	char		*msg;
	t_player	*pl = NULL;

	if (buf && strcmp(buf, "graphical_client") == 0) {
		while (!current->last) {
			pl = ((t_player *)current->data);
			msg = my_asprintf_epoll2(pl);
			send(fd, msg, strlen(msg), 0);
			free(msg);
			msg = my_asprintf_epoll(pl);
			send(fd, msg, strlen(msg), 0);
			free(msg);
			current = current->next;
			free(msg);
		}
		serv->graph_fd = fd;
		return (0);
	}
	return (-1);
}
void	epoll_loop(t_serv *serv, int event_count, int epoll_fd)
{
	char	*buf = NULL;

	for (int n = 0; n < event_count; n++) {
		if (serv->events[n].data.fd == serv->serv_fd) {
			incoming_player(serv, epoll_fd);
			continue;
		}
		buf = get_next_line(serv->events[n].data.fd);
		if (!buf && serv->events[n].data.fd != serv->graph_fd)
			remove_player(serv, serv->events[n].data.fd);
		if (check_if_graph(serv->events[n].data.fd, buf, serv) == 0)
			continue;
		if (serv->events[n].data.fd == serv->graph_fd)
			loop_graphic(serv->events[n].data.fd, serv, buf);
		else
			loop_player(serv, buf, serv->events[n].data.fd);
	}
	check_eggs_queue(serv);
	check_player_queue(serv);
	check_player_food(serv);
}

void	epoll_handling(t_serv *serv, int epoll_fd)
{
	int	event_count;

	serv->running = true;
	while (serv->running) {
		event_count = epoll_wait(epoll_fd, serv->events, 32, 0);
		if (event_count == -1)
			break;
		epoll_loop(serv, event_count, epoll_fd);
	}
}

void	loop_zappy(t_serv *serv)
{
	struct epoll_event	event;
	int			epoll_fd = epoll_create(32);

	if (epoll_fd == -1) {
		fprintf(stderr, "Failed to create epoll file descriptor\n");
		return ;
	}
	memset(&event, 0, sizeof(struct epoll_event));
	event.events = EPOLLIN;
	event.data.fd = serv->serv_fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, serv->serv_fd, &event)) {
		fprintf(stderr, "Failed to add file descriptor to epoll\n");
		close(epoll_fd);
		return ;
	}
	epoll_handling(serv, epoll_fd);
	if (close(epoll_fd))
		fprintf(stderr, "Failed to close epoll file descriptor\n");

}
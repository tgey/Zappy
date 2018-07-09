/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "client.h"

void	init_epoll(t_client *client)
{
	struct epoll_event	event;

	client->epoll_fd = epoll_create(2);
	memset(&event, 0, sizeof(struct epoll_event));
	event.events = EPOLLIN;
	event.data.fd = 0;
	if (epoll_ctl(client->epoll_fd, EPOLL_CTL_ADD, 0, &event) != 0) {
		fprintf(stderr, "Failed to add file descriptor to epoll\n");
		close(client->epoll_fd);
		return ;
	}
}

void	init_client_bis(t_client *client)
{
	client->needed = NULL;
	client->queue = malloc(sizeof(char *) * (11));
	client->queue[0] = NULL;
	client->w_queue = malloc(sizeof(char *) * (51));
	client->w_queue[0] = NULL;
	client->n = 0;
	client->w_food = -1;
	client->is_waiting = false;
	client->is_connected = false;
	client->is_listening = false;
	client->is_coming = false;
	client->is_incanting = false;
	client->freq = -1;
	client->map_x = -1;
	client->map_y = -1;
	client->save_id = malloc(sizeof(int));
	client->len_id = 0;
}

void	init_new_client(t_client *client)
{
	client->player = malloc(sizeof(t_player));
	client->player->stones = malloc(sizeof(t_stones));
	init_client_stones(client->player->stones);
	client->serv_fd = -1;
	client->player->x = 0;
	client->player->y = 0;
	client->connected = 0;
	client->player->fd = 0;
	client->player->id = 0;
	client->player->incantation = 0;
	client->player->lvl = 1;
	client->player->food = 0;
	client->player->dir = North;
	client->player->team = NULL;
	client->port = NULL;
	client->host = strdup("0");
	client->name = NULL;
	client->running = true;
	client->wanted = -1;
	init_client_bis(client);
}
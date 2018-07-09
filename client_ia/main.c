/*
** EPITECH PROJECT, 2018
** client main
** File description:
** main
*/

#include "client.h"

const	t_client	*cli_gbl;

int	ai_iterate_epoll(t_client *cli, int n)
{
	if (cli->events[n].data.fd == cli->serv_fd) {
		server_handler(cli, n);
	}
	if (algo(cli) == -1)
		return (-1);
	return (1);
}

int	ai_loop_epoll(t_client *cli)
{
	int	event_count;
	int	ret = 1;

	setbuf(stdout, NULL);
	while (cli->running) {
		event_count = epoll_wait(cli->epoll_fd, cli->events, 2, 0);
		for (int n = 0; n < event_count && ret == 1; n++) {
			ret = ai_iterate_epoll(cli, n);
		}
		if (ret != 1)
			return (ret);
	}
	return (0);
}

void	free_cl(t_client *client)
{
	if (client->player->stones)
		free(client->player->stones);
	if (client->player)
		free(client->player);
	if (client->host)
		free(client->host);
	if (client->port)
		free(client->port);
	if (client->name)
		free(client->name);
	if (client->queue)
		free_tab(client->queue);
	if (client->w_queue)
		free_tab(client->w_queue);
	if (client->needed)
		free(client->needed);
	if (client->save_id)
		free(client->save_id);
	free(client);
}

int	main(UNUSED int ac, char **av)
{
	t_client	*client;

	client = malloc(sizeof(t_client));
	cli_gbl = client;
	init_sig();
	init_epoll(client);
	init_new_client(client);
	if (check_args(av, client) == 84) {
		free_cl(client);
		return (84);
	}
	try_connect(client->port, client->host, client);
	if (ai_loop_epoll(client) == -1) {
		free_cl(client);
		return (-1);
	}
	free_cl(client);
	return (0);
}
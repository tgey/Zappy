/*
** EPITECH PROJECT, 2018
** remove a client
** File description:
** remove_client
*/

#include "server.h"

void	delete_player_all(t_serv *serv, int fd)
{
	t_chained	*current = ((t_chained_list *)serv->teams)->first;
	t_chained	*tmp;
	int	i = 0;

	while (!current->last) {
		tmp = current;
		((t_team *)tmp->data)->
		players->del(((t_team *)tmp->data)->players, &fd);
		current = current->next;
		i += 1;
	}
	serv->players->del(serv->players, &fd);
}

bool	removing_player(t_serv *serv, int player_fd, int i)
{
	char		message[60];
	t_player	*player;

	if (serv->events[i].data.fd == player_fd) {
		if ((player =
			get_player_by_fd(serv->players, player_fd)) == NULL)
			return (false);
		delete_player_all(serv, player_fd);
		close(serv->events[i].data.fd);
		sprintf(message, "pdi %i\n", player->id);
		send(serv->graph_fd, message, strlen(message), 0);
		serv->events[i].events = 0;
		printf("Removing client fd %d\n", serv->events[i].data.fd);
		serv->events[i].data.fd = -1;
		return (true);
	}
	return (false);
}

int	remove_player(t_serv *serv, int client_fd)
{
	int	i = 0;
	bool	rem = false;

	if (client_fd == -1)
		return (0);
	if (errno != EWOULDBLOCK) {
		while (i < 32 && !rem) {
			rem = removing_player(serv, client_fd, i);
			i++;
		}
	}
	return (0);
}
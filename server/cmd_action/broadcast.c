/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** broadcast
*/

#include "server.h"

void	send_broad(t_player *player, UNUSED t_serv *serv, char *msg)
{
	char	message[512];

	bzero(message, 512);
	sprintf(message, "pbc %i %s\n", player->id, msg);
	send(serv->graph_fd, message, strlen(message), 0);
}

int	get_diagonals(t_player *recv_pl, t_player *send_pl, t_serv *serv)
{
	int	x = send_pl->x - recv_pl->x;

	if (x > 0)
		return (diago_x(recv_pl, send_pl, serv));
	else
		return (diago_y(recv_pl, send_pl, serv));
}

int	get_cardinaux(t_player *recv_pl, t_player *send_pl)
{
	if (send_pl->x == recv_pl->x  && send_pl->y == recv_pl->y)
		return (0);
	if (send_pl->x == recv_pl->x)
		return (send_pl->y > recv_pl->y ?
		(3 + recv_pl->dir * 2) % 8 : (1 + recv_pl->dir * 2) % 8);
	if (send_pl->y == recv_pl->y)
		return (send_pl->x > recv_pl->x ?
		(5 + recv_pl->dir * 2) % 8 : (7 + recv_pl->dir * 2) % 8);
	return (-1);
}
int	get_broad_dir(t_player *recv_pl, t_player *send_pl, t_serv *serv)
{
	int	dir;

	if ((dir = get_cardinaux(recv_pl, send_pl)) != -1)
		return (dir);
	return (get_diagonals(recv_pl, send_pl, serv));
}
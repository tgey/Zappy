/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** queue.c
*/

#include "server.h"

const cmd_serv_t	act[] = {
	{"Forward", &serv_forward},
	{"Broadcast", &serv_broadcast},
	{"Connect_nbr", &serv_connect},
	{"Eject", &serv_eject},
	{"Fork", &serv_fork},
	{"Incantation", &serv_incantation_end},
	{"Inventory", &serv_inventory},
	{"Left", &serv_left},
	{"Look", &serv_look},
	{"Right", &serv_right},
	{"Set", &serv_set},
	{"Take", &serv_take},
	{NULL, NULL}
};

void	exec_queue_cmd(t_serv *serv, t_chained *player, t_queue *queue)
{
	int	i = 0;

	while (act[i].name) {
		if (strcmp(queue->cmd[0], act[i].name) == 0) {
			act[i].func(((t_player*)player->data)->fd,
				serv, queue->cmd);
			delete_last_queue(((t_player*)player->data)->queue);
			return ;
		}
		i++;
	}
}

void	check_cmd_end(t_serv *serv, t_chained *player, t_queue *queue)
{
	long int	fst;
	long int	snd;

	if (queue->timer.tv_usec == 0) {
		gettimeofday(&(queue->timer), NULL);
		if (strcmp(queue->cmd[0], "Incantation") == 0)
			serv_incantation(((t_player*)player->data)->fd,
				serv, queue->cmd);
	}
	fst = get_ftime(queue->timer);
	snd = (float)((float)queue->timing / serv->freq) * 1000000;
	if (fst >= snd)
		exec_queue_cmd(serv, player, queue);
}

int	check_player_queue(t_serv *serv)
{
	t_chained	*player = serv->players->first;
	t_queue		*queue;

	while (!player->last) {
		if (((t_player*)player->data)->is_egg)
			player = player->next;
		queue = get_last_queue(((t_player*)player->data)->queue);
		if (queue != NULL)
			check_cmd_end(serv, player, queue);
		player = player->next;
	}
	return (0);
}

void	send_dead(t_player *player, t_serv *serv)
{
	char	message[60];

	sprintf(message, "pdi %i\n", player->id);
	send(serv->graph_fd, message, strlen(message), 0);
}

void	check_player_food(t_serv *serv)
{
	t_chained	*player = serv->players->first;
	long int	fst;
	long int	snd;

	while (!player->last) {
		fst = get_ftime(((t_player*)player->data)->timer);
		snd = (float)((float)126 / serv->freq) * 1000000;
		if (fst >= snd) {
			gettimeofday(&((t_player*)player->data)->timer, NULL);
			((t_player*)player->data)->food--;
			if (((t_player*)player->data)->food <= 0) {
				my_send(((t_player*)player->data)->fd,
					"dead\n");
				send_dead(((t_player*)player->data), serv);
			}
		}
		player = player->next;
	}
}

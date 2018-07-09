/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** eggs
*/

#include "server.h"

void	send_egg_end(t_egg *egg, t_serv *serv)
{
	char	message[60];

	sprintf(message, "eht %i\n", egg->id);
	send(serv->graph_fd, message, strlen(message), 0);
}

void	check_egg_end(t_serv *serv, t_team *team, t_egg *egg)
{
	t_player	*player;
	long int	fst;
	long int	snd;

	fst = get_ftime(egg->timer);
	snd = (600 * 1000000) / serv->freq;
	if (fst >= snd) {
		player = get_player_by_fd(serv->players, egg->id);
		if (egg->is_forked)
			player->is_egg = false;
		delete_last_egg(team->eggs);
		send_egg_end(egg, serv);
	}
}

t_egg	*get_last_egg(t_chained_list *eggs)
{
	t_chained	*egg = eggs->first;

	if (egg->last)
		return (NULL);
	while (!egg->next->last) {
		egg = egg->next;
	}
	return (egg->data);
}

int	check_eggs_queue(t_serv *serv)
{
	t_egg	*egg;
	t_chained	*queue = serv->teams->first;

	while (!queue->last) {
		egg = get_last_egg(((t_team *)queue->data)->eggs);
		if (egg != NULL)
			check_egg_end(serv, ((t_team *)queue->data), egg);
		queue = queue->next;
	}
	return (0);
}
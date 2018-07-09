/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fork
*/

#include "server.h"

void	delete_last_egg(void *list)
{
	t_chained	*current = ((t_chained_list *)list)->first;
	int	i = 0;

	while (!current->next->last) {
		current = current->next;
		i += 1;
	}
	free(((t_egg *)current->data)->team);
	free(((t_egg *)current->data));
	delete_chained_list(list, i);
}


void	check_if_egg(int fd, t_serv *serv, char *team_name,
			t_player *player)
{
	t_team		*team = get_team_by_name(serv->teams, team_name);
	t_chained	*queue = ((t_chained_list *)team->eggs)->first;

	while (queue->next && !queue->next->last) {
		queue = queue->next;
	}
	if (!queue->last && !((t_egg *)queue->data)->is_forked) {
		player->x = ((t_egg *)queue->data)->x;
		player->y = ((t_egg *)queue->data)->y;
		player->is_egg = true;
		((t_egg *)queue->data)->is_forked = true;
		((t_egg *)queue->data)->id = fd;
	}
}


void	send_fork(t_egg *egg, t_player *current, t_serv *serv)
{
	char message[60];

	sprintf(message, "enw %i %i %i %i\n",
	egg->id, current->id, egg->x, egg->y);
	send(serv->graph_fd, message, strlen(message), 0);
}

int	serv_fork(int cli_fd, t_serv *serv, UNUSED char **tab)
{
	t_egg		*egg;
	t_player	*player = get_player_by_fd(serv->players, cli_fd);

	egg = empty_egg();
	memset(&egg->timer, 0, sizeof(struct timeval));
	egg->team = my_strcat(player->team->name, "");
	egg->x = player->x;
	egg->y = player->y;
	gettimeofday(&(egg->timer), NULL);
	insert_chained_list(player->team->eggs, egg);
	send(cli_fd, "ok\n", 3, 0);
	send_fork(egg, player, serv);
	return (0);
}
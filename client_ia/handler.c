/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handler.c
*/

#include "client.h"

const get_stones_t	a_g_stones[] = {
	{0, "linemate"},
	{1, "deraumere"},
	{2, "sibur"},
	{3, "mendiane"},
	{4, "phiras"},
	{5, "thystame"},
};

void	eject_or_incant(t_client *cli)
{
	char	*str;

	if (cli->len_id > nb_player_needed(cli)) {
		asprintf(&str, "Broadcast %s Move %i\n", cli->name,
			cli->save_id[cli->len_id]);
		qsend(cli, str);
		free(str);
	}
	else {
		qsend(cli, "Incantation\n");
		free(cli->needed);
		cli->needed = NULL;
		cli->is_waiting = true;
	}
}

void	drop_stones(t_client *cli)
{
	char	*str;
	int	*req;

	req = get_req(cli);
	for (int i = 0; i < 6; i++) {
		while (req[i] > 0) {
			str = my_strcat("Set ", a_g_stones[i].name);
			str = my_strcat2(str, "\n");
			req[i]--;
			qsend(cli, str);
			free(str);
		}
	}
	free(req);
	eject_or_incant(cli);
}

int	found_stones(t_client *cli, int n)
{
	if (cli->needed)
		free(cli->needed);
	cli->needed = my_strcat(a_g_stones[n].name, "");
	return (0);
}

int	algo(t_client *cli)
{
	if (cli->n < 10 && cli->w_queue[0] != NULL) {
		qsend(cli, cli->w_queue[0]);
		cli->w_queue = pop_last_w_queue(cli->w_queue);
	}
	if (cli->is_waiting || cli->is_listening)
		return (0);
	if (cli->is_incanting && check_cell_players(cli) == 1) {
		drop_stones(cli);
		return (0);
	}
	inventory(cli);
	look(cli);
	return (0);
}
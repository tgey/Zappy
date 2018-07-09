/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** cmd_action
*/

#include "server.h"

const timing_t	a_tim[] = {
	{"Forward", &time_seven},
	{"Broadcast", &time_seven},
	{"Connect_nbr", &time_instant},
	{"Eject", &time_seven},
	{"Fork", &time_forty_two},
	{"Incantation", &time_three_hundred},
	{"Inventory", &time_one},
	{"Left", &time_seven},
	{"Look", &time_seven},
	{"Right", &time_seven},
	{"Set", &time_seven},
	{"Take", &time_seven},
	{NULL, NULL}
};

t_queue	*empty_cmd(void)
{
	t_queue	*queue = malloc(sizeof(t_queue));

	queue->timing = 0;
	return (queue);
}

int	add_cmd_in_queue(t_player *players, char **token, t_queue *queue)
{
	t_queue *new_cmd = empty_cmd();
	int	n = 0;

	if (!queue)
	{
		if (chained_list_len(players->queue) < 10) {
			new_cmd->cmd = malloc(sizeof(char *) *
				(tab_len(token) + 1));
			while (token[n] != NULL) {
				new_cmd->cmd[n] = my_strcat(token[n], "");
				n++;
			}
			new_cmd->cmd[n] = NULL;
			memset(&new_cmd->timer, 0, sizeof(struct timeval));
			insert_chained_list(players->queue, new_cmd);
		}
		else
			free(new_cmd);
	}
	return (0);
}

int     get_cmd_time(int cli_fd, t_serv *serv, char **tab)
{
	t_player	*pl;
	t_queue		*queue;
	int		i = 0;

	while (a_tim[i].name) {
		if (strcmp(tab[0], a_tim[i].name) == 0) {
			pl = get_player_by_fd(serv->players, cli_fd);
			if (add_cmd_in_queue(pl, tab, NULL) == -1)
				return (-1);
			queue = get_queue_by_player(pl->queue,
				tab);
			queue->timing = a_tim[i].func();
			return (0);
		}
		i++;
	}
	return (-1);
}

void	loop_command_act(int client_fd, t_serv *serv, char *buf)
{
	char	**tab = my_str_to_wordtab(buf, ' ');

	printf("received by client %i : \"%s\"\n", client_fd, buf);
	tab = empty_command(tab);
	if (tab && !get_player_by_fd(serv->players, client_fd)) {
		loop_connection(client_fd, serv, buf);
	}
	else if (tab && get_cmd_time(client_fd, serv, tab) == -1)
		send(client_fd, "ko\n", 3, 0);
	if (tab)
		free_tab(tab);
}
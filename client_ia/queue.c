/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** queue.c
*/

#include "client.h"

void	add_in_w_queue(t_client *cli, char *msg)
{
	int	n = 0;

	while (cli->w_queue[n]) {
		n++;
	}
	cli->w_queue[n] = my_strcat(msg, "");
	cli->w_queue[n + 1] = NULL;
}

int	qsend(t_client *cli, char *msg)
{
	if (cli->n >= 10) {
		add_in_w_queue(cli, msg);
		return (-1);
	}
	send(cli->serv_fd, msg, strlen(msg), 0);
	cli->queue[cli->n] = my_strcat(msg, "");
	cli->queue[cli->n][strlen(cli->queue[cli->n]) - 1] = '\0';
	cli->queue[cli->n + 1] = NULL;
	cli->n++;
	return (0);
}

char	**pop_last_w_queue(char **tab)
{
	char	**res = malloc(sizeof(char *) * (51));
	int	n = 0;

	free(tab[n]);
	while (tab[n + 1] != NULL) {
		res[n] = my_strcat2(tab[n + 1], "");
		n++;
	}
	res[n] = NULL;
	free(tab);
	return (res);
}

char	**pop_last(t_client *cli, char **tab)
{
	char	**res = malloc(sizeof(char *) * (11));
	int	n = 0;

	if (tab[0] == NULL) {
		free_tab(tab);
		res[0] = NULL;
		return (res);
	}
	free(tab[n]);
	while (tab[n + 1] != NULL) {
		res[n] = my_strcat2(tab[n + 1], "");
		n++;
	}
	res[n] = NULL;
	cli->n--;
	free(tab);
	return (res);
}
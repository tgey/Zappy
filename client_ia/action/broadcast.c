/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** broadcast
*/

#include "client.h"

int	*insert_id(t_client *cli, int new_id)
{
	int	*tmp = malloc(sizeof(int) * (cli->len_id + 1));
	int	n = 0;

	while (n != cli->len_id) {
		tmp[n] = cli->save_id[n];
		n++;
	}
	tmp[n] = new_id;
	cli->len_id++;
	if (cli->save_id)
		free(cli->save_id);
	return (tmp);
}

int	is_in_tab(t_client *cli, int nb)
{
	int	n = 0;

	while (n != cli->len_id) {
		if (cli->save_id[n] == nb)
			return (1);
		n++;
	}
	cli->save_id = insert_id(cli, nb);
	return (0);
}

int	player_is_here(t_client *cli, char **tab)
{
	if (cli->is_incanting && strcmp(tab[3], "Arrived") == 0
		&& atoi(tab[1]) == 0) {
		is_in_tab(cli, atoi(tab[4]));
		free_tab(tab);
		return (-1);
	}
	if (cli->is_listening && strcmp(tab[3], "END") == 0
		&& atoi(tab[1]) != 0) {
		cli->is_listening = false;
		free_tab(tab);
		return (-1);
	}
	if (strcmp(tab[3], "Move") == 0
		&& atoi(tab[4]) == cli->player->id) {
		qsend(cli, "Forward\n");
		cli->is_listening = false;
		free_tab(tab);
		return (-1);
	}
	return (0);
}

int	check_b_msg(t_client *cli, char **tab)
{
	if (player_is_here(cli, tab) == -1)
		return (0);
	if (invit_player(cli, tab) == -1)
		return (0);
	return (0);
}

int	listen_broadcast(t_client *cli, char *line)
{
	char	**tab = my_str_to_wordtab(line, ' ');

	if (strcmp(tab[2], cli->name) == 0) {
		return (check_b_msg(cli, tab));
	}
	return (0);
}
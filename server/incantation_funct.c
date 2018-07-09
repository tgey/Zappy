/*
** EPITECH PROJECT, 2018
** incantation funct
** File description:
** zappy project
*/

#include "server.h"

int	switch_case_end_inc(t_serv *serv, int cli_fd,
		int *req, t_player *players)
{
	switch (players->lvl) {
	case (1):
		return (req_case_1_res(players, serv, cli_fd, req));
	case (2):
		return (req_case_2_res(players, serv, cli_fd, req));
	case (3):
		return (req_case_3_res(players, serv, cli_fd, req));
	case (4):
		return (req_case_4_res(players, serv, cli_fd, req));
	case (5):
		return (req_case_5_res(players, serv, cli_fd, req));
	case (6):
		return (req_case_6_res(players, serv, cli_fd, req));
	case (7):
		return (req_case_7_res(players, serv, cli_fd, req));
	}
	return (my_send_err(cli_fd, "ko\n"));
}

int	serv_incantation_end(int cli_fd, UNUSED t_serv *serv,
				UNUSED char **tab)
{
	int		*req = malloc(sizeof(int *) * 6);
	t_player	*players = get_player_by_fd(serv->players, cli_fd);

	if (tab_len(tab) != 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (switch_case_end_inc(serv, cli_fd, req, players));
}
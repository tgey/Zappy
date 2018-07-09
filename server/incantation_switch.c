/*
** EPITECH PROJECT, 2018
** incantation switch case
** File description:
** zappy
*/

#include "server.h"

int	req_case_1(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 1;
	req[1] = 0;
	req[2] = 0;
	req[3] = 0;
	req[4] = 0;
	req[5] = 0;
	if (check_level_stone(players, serv, req, 1) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}

int	req_case_2(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 1;
	req[1] = 1;
	req[2] = 1;
	req[3] = 0;
	req[4] = 0;
	req[5] = 0;
	if (check_level_stone(players, serv, req, 2) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}

int	req_case_3(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 2;
	req[1] = 0;
	req[2] = 1;
	req[3] = 0;
	req[4] = 2;
	req[5] = 0;
	if (check_level_stone(players, serv, req, 2) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}

int	req_case_4(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 1;
	req[1] = 2;
	req[2] = 1;
	req[3] = 0;
	req[4] = 1;
	req[5] = 0;
	if (check_level_stone(players, serv, req, 4) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}

int	req_case_5(t_player *players, t_serv *serv, int cli_fd, int *req)
{
	req[0] = 1;
	req[1] = 2;
	req[2] = 1;
	req[3] = 3;
	req[4] = 0;
	req[5] = 0;
	if (check_level_stone(players, serv, req, 4) == 1)
		return (my_send_err(cli_fd, "ko\n"));
	return (send_all_cell(serv, players, "Elevation underway\n"));
}
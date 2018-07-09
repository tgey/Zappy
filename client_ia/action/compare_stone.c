/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** survive.c
*/

#include "client.h"

void	fill_req(t_client *cli, int a, int b, int nb)
{
	if (nb == 0) {
		cli->req[0] = a - cli->player->stones->linemate;
		cli->req[1] = b - cli->player->stones->deraumere;
	}
	else if (nb == 1) {
		cli->req[2] = a - cli->player->stones->sibur;
		cli->req[3] = b - cli->player->stones->mendiane;
	}
	else {
		cli->req[4] = a - cli->player->stones->phiras;
		cli->req[5] = b - cli->player->stones->thystame;
	}
}

void	check_missing_stones2(t_client *cli)
{
	switch (cli->player->lvl) {
	case (4):
		fill_req(cli, 1, 2, 0);
		fill_req(cli, 1, 0, 1);
		fill_req(cli, 1, 0, 2);
		break ;
	case (5):
		fill_req(cli, 1, 2, 0);
		fill_req(cli, 1, 3, 1);
		fill_req(cli, 0, 0, 2);
		break ;
	}
}

void	check_missing_stones3(t_client *cli)
{
	switch (cli->player->lvl) {
	case (6):
		fill_req(cli, 1, 2, 0);
		fill_req(cli, 3, 0, 1);
		fill_req(cli, 1, 0, 2);
		break ;
	case (7):
		fill_req(cli, 2, 2, 0);
		fill_req(cli, 2, 2, 1);
		fill_req(cli, 2, 1, 2);
		break ;
	}
}

void	check_missing_stones(t_client *cli)
{
	switch (cli->player->lvl) {
	case (1):
		fill_req(cli, 1, 0, 0);
		fill_req(cli, 0, 0, 1);
		fill_req(cli, 0, 0, 2);
		break ;
	case (2):
		fill_req(cli, 1, 1, 0);
		fill_req(cli, 1, 0, 1);
		fill_req(cli, 0, 0, 2);
		break ;
	case (3):
		fill_req(cli, 2, 0, 0);
		fill_req(cli, 1, 0, 1);
		fill_req(cli, 2, 0, 2);
		break ;
	}
	check_missing_stones2(cli);
	check_missing_stones3(cli);
}
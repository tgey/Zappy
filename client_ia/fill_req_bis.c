/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fill_req
*/

#include "client.h"

int	*fill_req_lvl_6(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 1;
	req[1] = 2;
	req[2] = 3;
	req[3] = 0;
	req[4] = 1;
	req[5] = 0;
	return (req);
}

int	*fill_req_lvl_7(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 2;
	req[1] = 2;
	req[2] = 2;
	req[3] = 2;
	req[4] = 2;
	req[5] = 1;
	return (req);
}

int	*get_req(t_client *cli)
{
	switch (cli->player->lvl) {
	case (1):
		return (fill_req_lvl_1());
	case (2):
		return (fill_req_lvl_2());
	case (3):
		return (fill_req_lvl_3());
	case (4):
		return (fill_req_lvl_4());
	case (5):
		return (fill_req_lvl_5());
	case (6):
		return (fill_req_lvl_6());
	case (7):
		return (fill_req_lvl_7());
	}
	return (0);
}
/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fill_req
*/

#include "client.h"

int	*fill_req_lvl_1(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 1;
	req[1] = 0;
	req[2] = 0;
	req[3] = 0;
	req[4] = 0;
	req[5] = 0;
	return (req);
}

int	*fill_req_lvl_2(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 1;
	req[1] = 1;
	req[2] = 1;
	req[3] = 0;
	req[4] = 0;
	req[5] = 0;
	return (req);
}

int	*fill_req_lvl_3(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 2;
	req[1] = 0;
	req[2] = 1;
	req[3] = 0;
	req[4] = 2;
	req[5] = 0;
	return (req);
}

int	*fill_req_lvl_4(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 1;
	req[1] = 2;
	req[2] = 1;
	req[3] = 0;
	req[4] = 1;
	req[5] = 0;
	return (req);
}

int	*fill_req_lvl_5(void)
{
	int	*req = malloc(sizeof(int) * 6);

	req[0] = 1;
	req[1] = 2;
	req[2] = 1;
	req[3] = 3;
	req[4] = 0;
	req[5] = 0;
	return (req);
}
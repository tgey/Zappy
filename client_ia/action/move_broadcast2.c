/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** move_broadcast
*/

#include "client.h"

int	move_to_8(t_client *cli)
{
	qsend(cli, "Forward\n");
	qsend(cli, "Right\n");
	qsend(cli, "Forward\n");
	return (8);
}

int	move_to_7(t_client *cli)
{
	qsend(cli, "Right\n");
	qsend(cli, "Forward\n");
	return (7);
}

int	move_to_6(t_client *cli)
{
	qsend(cli, "Right\n");
	qsend(cli, "Forward\n");
	qsend(cli, "Right\n");
	qsend(cli, "Forward\n");
	return (6);
}

int	move_to_5(t_client *cli)
{
	qsend(cli, "Left\n");
	qsend(cli, "Left\n");
	qsend(cli, "Forward\n");
	return (5);
}

int	move_to_4(t_client *cli)
{
	qsend(cli, "Left\n");
	qsend(cli, "Forward\n");
	qsend(cli, "Left\n");
	qsend(cli, "Forward\n");
	return (4);
}
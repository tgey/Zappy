/*
** EPITECH PROJECT, 2018
** help
** File description:
** help
*/

#include "utils.h"

void	server_usage(void)
{
	printf("USAGE: ./zappy_server -p port -x width -y");
	printf("height -n name1 name2 ... -c clientsNb\n");
	printf("-f freq\n");
	printf("\tport\t\tis the port number\n");
	printf("\twidth\t\tis the width of the world\n");
	printf("\theight\t\tis the height of the world\n");
	printf("\tnameX\t\tis the name of the team X\n");
	printf("\tclientsNb\tis the number of authorized clients per team\n");
	printf("\tfreq\t\t");
	printf("is the reciprocal of time unit for execution of actions\n");
}

void	ia_usage(void)
{
	printf("USAGE: ./zappy_ai -p port -n name -h machine\n");
	printf("\tport\t\tis the port number\n");
	printf("\tname\t\tis the name of the team\n");
	printf("\tmachine\t\tis the name of the machine; ");
	printf("localhost by default\n");
}
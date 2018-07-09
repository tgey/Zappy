/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** cmd with str
*/

#include "client.h"

char	*clear_ending_spaces(char *str)
{
	while (le(str) > 0 && str[le(str) - 1] == ' ')
		str[le(str) - 1] = 0;
	return (str);
}

int	my_command(t_client *cli, char *buf)
{
	char	*team;

	buf = clear_crlf(buf);
	buf = clear_ending_spaces(buf);
	team = malloc(sizeof(char) * strlen(buf) + 2);
	sprintf(team, "%s\n", buf);
	send(cli->serv_fd, team, strlen(team), 0);
	free(team);
	return (0);
}
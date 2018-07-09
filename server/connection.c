/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** connection
*/

#include "server.h"

void	send_graphic(int fd, UNUSED t_serv *serv, t_player *player)
{
	char		*str;

	asprintf(&str, "pnw #%i %i %i %i %i %s\n",
		player->id,
		player->x,
		player->y,
		player->dir,
		player->lvl,
		player->team->name);
	send(fd, str, strlen(str), 0);
	free(str);
}

void	loop_connection(int fd, t_serv *serv, char *line)
{
	t_player	*player;
	char	message[25];

	if (!get_team_by_name(serv->teams, line) ||
		get_team_by_name(serv->teams, line)->clientNb < 1) {
		send(fd, "ko\n", 3, 0);
		return ;
	}
	player_connection(fd, serv, line);
	player = get_player_by_fd(serv->players, fd);
	sprintf(message, "%i\n", get_team_by_name(serv->teams, line)->clientNb);
	printf("Send %s to %i\n", message, fd);
	send(fd, message, strlen(message), 0);
	get_team_by_name(serv->teams, line)->clientNb--;
	printf ("team : %i serv: %i\n",
		get_team_by_name(serv->teams, line)->clientNb, serv->clientNb);
	sprintf(message, "%i %i\n", serv->map->width, serv->map->height);
	printf("Send %s to %i\n", message, fd);
	send(fd, message, strlen(message), 0);
	send_graphic(serv->graph_fd, serv, player);
}
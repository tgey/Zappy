/*
** EPITECH PROJECT, 2018
** init all server
** File description:
** IRC
*/

#include "server.h"

int	init_server_socket(t_serv *serv, t_opt *opt)
{
	struct protoent	*pe = getprotobyname("TCP");

	if (!pe)
		return (my_perror("getprotobyname()"));
	serv->serv_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	serv->freq = opt->freq;
	if (serv->serv_fd == -1)
		return (my_perror("socket()"));
	serv->sin.sin_family = AF_INET;
	serv->sin.sin_port = htons(opt->port);
	serv->sin.sin_addr.s_addr = INADDR_ANY;
	if (bind(serv->serv_fd, (const struct sockaddr *)&serv->sin,
			sizeof(serv->sin)) == -1 ||
			listen(serv->serv_fd, 42) == -1) {
		if (close_fd(serv->serv_fd) == -1)
			return (84);
		my_perror("bind()");
		exit(84);
	}
	return (0);
}

void	init_server_struct(t_serv *serv)
{
	serv->map = malloc(sizeof(t_map));
	serv->players = init_chained_list(&delete_player_fd,
	&destroy_player_list);
	serv->teams = init_chained_list(&delete_team_ptr,
	&destroy_team_list);
	serv->graph_fd = 0;
	serv->cid = 1;
}

void	init_teams(t_serv *serv, t_opt *opt)
{
	int	i = 0;

	serv->clientNb = opt->clientsNb;
	while (i < tab_len(opt->nameX)) {
		create_team(serv, opt->nameX[i]);
		i++;
	}
}

void	init_global(t_serv *serv, t_opt *opt)
{
	init_sig();
	init_server_socket(serv, opt);
	init_server_struct(serv);
	init_server_map(serv->map, opt);
	init_teams(serv, opt);
}
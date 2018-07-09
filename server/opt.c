/*
** EPITECH PROJECT, 2018
** options
** File description:
** PSU_zappy_2017
*/

#include "server.h"

void	init_default_opt(t_opt *opt)
{
	opt->port = 4242;
	opt->width = 20;
	opt->height = 20;
	opt->clientsNb = 4;
	opt->freq = 100;
}

void	init_server_opt(t_opt *opt)
{
	init_default_opt(opt);
}

void	free_opt(t_opt *opt)
{
	free_tab(opt->nameX);
	free(opt);
}
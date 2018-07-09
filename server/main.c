/*
** EPITECH PROJECT, 2018
** main
** File description:
** Zappy Epitech
*/

#include "server.h"

const t_serv	*serv_gbl;
const t_opt	*opt_gbl;

int	main(UNUSED int ac, UNUSED char **av)
{
	t_serv	*serv;
	t_opt	*opt;

	serv = malloc(sizeof(t_serv));
	opt = malloc(sizeof(t_opt));
	opt_gbl = opt;
	serv_gbl = serv;
	srand(time(NULL));
	if (!serv || !opt)
		return (84);
	init_server_opt(opt);
	if (check_args(av, opt) == 84)
		return (84);
	init_global(serv, opt);
	loop_zappy(serv);
	close_fd(serv->serv_fd);
	free_all(serv, opt, serv->map);
	return (0);
}

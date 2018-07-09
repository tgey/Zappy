/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** sig handling
*/

#include "client.h"

void	sig_handler(int signal)
{
	switch (signal) {
	case SIGINT:
		printf("Sigint\n");
		break;
	case SIGQUIT:
		printf("Sigquit\n");
		break;
	case SIGTERM:
		printf("Sigterm\n");
		break;
	case SIGSEGV:
		printf("ErrorSigsegvError\nThere might be a problem here\n");
		break;
	default:
		printf("Other signal killing program");
		break;
	}
	free_t_client((t_client *)cli_gbl);
	exit(0);
}

void	init_sig(void)
{
	struct sigaction	sig;

	sig.sa_handler = &sig_handler;
	sig.sa_flags = 0;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGINT, &sig, 0);
	sigaction(SIGQUIT, &sig, 0);
	sigaction(SIGTERM, &sig, 0);
	sigaction(SIGSEGV, &sig, 0);
}

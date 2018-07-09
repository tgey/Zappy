/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** commands
*/

#include "server.h"

const cmd_serv_t	graph[] = {
	{"bct", &serv_bct},
	{"mct", &serv_mct},
	{"ebo", &serv_ebo},
	{"edi", &serv_edi},
	{"eht", &serv_eht},
	{"enw", &serv_enw},
	{"msz", &serv_msz},
	{"pbc", &serv_pbc},
	{"pdi", &serv_pdi},
	{"pdr", &serv_pdr},
	{"pex", &serv_pex},
	{"pfk", &serv_pfk},
	{"pgt", &serv_pgt},
	{"pic", &serv_pic},
	{"pie", &serv_pie},
	{"pin", &serv_pin},
	{"plv", &serv_plv},
	{"pnw", &serv_pnw},
	{"ppo", &serv_ppo},
	{"sbp", &serv_sbp},
	{"seg", &serv_seg},
	{"sgt", &serv_sgt},
	{"smg", &serv_smg},
	{"sst", &serv_sst},
	{"suc", &serv_suc},
	{"tna", &serv_tna},
	{NULL, NULL}
};

int     get_cmd_graph(int cli_fd, t_serv *serv, char *token, char **tab)
{
	int	i = 0;

	while (graph[i].name) {
		if (strcmp(token, graph[i].name) == 0) {
			graph[i].func(cli_fd, serv, tab);
			if (tab)
				free_tab(tab);
			return (0);
		}
		i++;
	}
	return (-1);
}

char	**empty_command(char **tab)
{
	if (tab && tab_len(tab) == 0) {
		free_tab(tab);
		tab = NULL;
	}
	return (tab);
}

void	loop_graphic(int client_fd, t_serv *serv, char *buf)
{
	char		**tab;

	if (!buf) {
		free(buf);
		return ;
	}
	buf = clear_crlf(buf);
	tab = my_str_to_wordtab(buf, ' ');
	printf("received by client : \"%s\"\n", buf);
	tab = empty_command(tab);
	if (tab && get_cmd_graph(client_fd, serv, tab[0], tab) == -1)
		printf("unknown command\n");
	free(buf);
}
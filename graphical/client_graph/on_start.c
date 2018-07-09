/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** initialize data on start
*/

#include "graph.h"

const cmd_t cmds[] = {
	{"bct", &bct_send_g},
	{"tna", &tna_send_g},
	{"ppo", &ppo_send_g},
	{"plv", &plv_send_g},
	{"pin", &pin_send_g},
	{"sgt", &sgt_send_g},
	{"msz", &msz_send_g},
	{"mct", &mct_send_g},
	{"sst", &sst_send_g},
	{"bct", &bct_send_g},
	{NULL, NULL}
};

const resp_t resps[] = {
	{"bct", &bct_recv_g},
	{"tna", &tna_recv_g},
	{"ppo", &ppo_recv_g},
	{"plv", &plv_recv_g},
	{"pin", &pin_recv_g},
	{"sgt", &sgt_recv_g},
	{"msz", &msz_recv_g},
	{"pnw", &pnw_recv_g},
	{"sst", &sst_recv_g},
	{"pdr", &pdr_recv_g},
	{"pgt", &pgt_recv_g},
	{"pic", &pic_recv_g},
	{"pie", &pie_recv_g},
	{"pbc", &pbc_recv_g},
	{"seg", &seg_recv_g},
	{"pex", &pex_recv_g},
	{"pfk", &pfk_recv_g},
	{"pdi", &pdi_recv_g},
	{"enw", &enw_recv_g},
	{"eht", &eht_recv_g},
	{"ebo", &ebo_recv_g},
	{"edi", &edi_recv_g},
	{NULL, NULL}
};

char *clendsp(char *cmd)
{
	while (le(cmd) > 0 && cmd[le(cmd) - 1] == ' ')
		cmd[le(cmd) - 1] = 0;
	return cmd;
}

bool graph_send_command(graph_t *graph, const char *cmd)
{
	char **tab;

	tab = my_str_to_wordtab((char *)cmd, ' ');
	if (!tab || tab_len(tab) == 0)
		return false;
	for (unsigned int i = 0; cmds[i].name; i++) {
		if (!strcmp(cmds[i].name, tab[0])) {
			cmds[i].func(graph, tab);
			free_tab(tab);
			return true;
		}
	}
	printf("\"%s\": Unknown Command\n", tab[0]);
	free_tab(tab);
	return false;
}

bool graph_rcv_command(graph_t *graph, char *cmd)
{
	char **tab;

	cmd = clear_crlf(cmd);
	cmd = clendsp(cmd);
	tab = my_str_to_wordtab(cmd, ' ');
	if (!tab || tab_len(tab) == 0)
		return false;
	for (unsigned int i = 0; resps[i].name; i++) {
		if (!strcmp(resps[i].name, tab[0])) {
			resps[i].func(graph, tab);
			free_tab(tab);
			return true;
		}
	}
	free_tab(tab);
	return false;
}

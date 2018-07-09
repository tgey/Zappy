/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** bct
*/

#include "graph.h"

void bct_send_g(graph_t *graph, char **args)
{
	char	str[512];

	if (tab_len(args) == 3
	&& atoi(args[1]) >= 0 && atoi(args[1]) < graph->map->width
	&& atoi(args[2]) >= 0 && atoi(args[2]) < graph->map->height) {
		sprintf(str, "bct %s %s\n", args[1], args[2]);
		send(graph->serv_fd, str, strlen(str), 0);
	} else
		printf("bct: bad arguments\n");
}

void bct_recv_g(graph_t *graph, char **args)
{
	int	x = atoi(args[1]);
	int	y = atoi(args[2]);
	int	q0 = atoi(args[3]);
	int	q1 = atoi(args[4]);
	int	q2 = atoi(args[5]);
	int	q3 = atoi(args[6]);
	int	q4 = atoi(args[7]);
	int	q5 = atoi(args[8]);
	int	q6 = atoi(args[9]);

	fill_place(graph, graph->map->map[y][x]->food, q0);
	fill_place(graph, graph->map->map[y][x]->stones->linemate, q1);
	fill_place(graph, graph->map->map[y][x]->stones->deraumere, q2);
	fill_place(graph, graph->map->map[y][x]->stones->sibur, q3);
	fill_place(graph, graph->map->map[y][x]->stones->mendiane, q4);
	fill_place(graph, graph->map->map[y][x]->stones->phiras, q5);
	fill_place(graph, graph->map->map[y][x]->stones->thystame, q6);
}
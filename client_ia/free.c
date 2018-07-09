/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** free
*/

#include "client.h"

char	*my_strcat2(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int size = strlen(dest) + strlen(src);
	char *str3 = malloc(sizeof(char) * (size + 1));

	while (dest[i])	{
		str3[i] = dest[i];
		i++;
	}
	while (src[j])
		str3[i++] = src[j++];
	str3[i] = '\0';
	free(dest);
	return (str3);
}

char	*my_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int size = strlen(dest) + strlen(src);
	char *str3 = malloc(sizeof(char) * (size + 1));

	while (dest[i])	{
		str3[i] = dest[i];
		i++;
	}
	while (src[j])
		str3[i++] = src[j++];
	str3[i] = '\0';
	return (str3);
}

void	free_t_client(t_client *client)
{
	free(client->player->stones);
	free(client->host);
	free(client->port);
	free(client->name);
	free(client->player);
	if (client->queue)
		free_tab(client->queue);
	if (client->w_queue)
		free_tab(client->w_queue);
	if (client->save_id)
		free(client->save_id);
	if (client->needed)
		free(client->needed);
	free(client);
}

void	free_tab(char **tab)
{
	int	i = 0;

	while (i < tab_len(tab))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
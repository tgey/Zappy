/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** ia
*/

#ifndef IA_H_
	#define IA_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//manage map
char ***init_map(int height, int width);
char ***create_malloc_map(int height, int width);
char ***fill_map_resources(char ***map, int height, int width, int stones_nb);
void show_tridimensional_tab(char ***tab);

//manage_resources
void select_resource(int rand_stones, char *ress);
char ***add_resource_in_map(char ***map, char ress, int rand_height,
	int rand_width);
int find_specific_stone(char ***map, char stone);
char ***add_specific_stone(char ***map, int height, int width, char stone);
char ***check_resource_in_map(char ***map, int height, int width);

#endif /* !IA_H_ */

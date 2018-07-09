/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** cmdhandler
*/

#pragma once

extern "C" {
	#include "graph.h"
}

class Manager;

class CommandHandler {
	public:
		CommandHandler(Manager &);
		~CommandHandler();
		int getDone() const;
		void run(graph_t *graph);
		void identify(graph_t *graph);
		void getFrequency(graph_t *graph);
		void getMapSize(graph_t *graph);
		void getMapContent(graph_t *graph);
		void commands(graph_t *);

	protected:
	private:
		Manager &_manager;
		int _inc;
		int _done;
		bool _sent;
};

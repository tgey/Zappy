/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** cmdhandler
*/

#include "CommandHandler.hpp"
#include "Manager.hpp"

CommandHandler::CommandHandler(Manager &manager) :
	_manager(manager), _inc(0), _done(0), _sent(false)
{
}

CommandHandler::~CommandHandler()
{
}

int CommandHandler::getDone() const
{
	return _done;
}

void CommandHandler::identify(graph_t *graph)
{
	identify_to_server(graph);
	_done++;
	_sent = false;
}

void CommandHandler::getFrequency(graph_t *graph)
{
	std::string str("sgt");

	if (!_sent)
		graph_send_command(graph, str.c_str());
	_sent = true;
	rcv_command(graph);
	if (graph->frequency != -1) {
		_done++;
		_sent = false;
	}
}

void CommandHandler::getMapSize(graph_t *graph)
{
	std::string str("msz");

	if (!_sent)
		graph_send_command(graph, str.c_str());
	_sent = true;
	rcv_command(graph);
	if (graph->map->width != -1 && graph->map->height != -1) {
		_done++;
		_sent = false;
		_manager.initMapData();
		_manager.setupPercents();
	}
}

void CommandHandler::getMapContent(graph_t *graph)
{
	std::string str("mct");

	if (!_sent)
		graph_send_command(graph, str.c_str());
	_sent = true;
	_inc += rcv_command(graph);
	if (_inc >= graph->map->width * graph->map->height) {
		_done++;
		_sent = false;
	}
}

void CommandHandler::commands(graph_t *graph)
{
	rcv_command(graph);
}

void CommandHandler::run(graph_t *graph)
{
	switch (_done) {
	case 0:
		identify(graph);
		break;
	case 1:
		getFrequency(graph);
		break;
	case 2:
		getMapSize(graph);
		break;
	case 3:
		getMapContent(graph);
		break;
	default:
		break;
	}
	if (_done >= 4)
		commands(graph);
}

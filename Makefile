##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -f

SERVER_NAME	=	zappy_server

IA_NAME		=	zappy_ai

LIB_NAME	=	libconnect.so

G_NAME		=	zappy_graphical

SERVER_SRC	=	server/main.c				\
			server/init.c				\
			server/client.c				\
			server/argument.c			\
			server/func_argument.c			\
			server/my_args.c			\
			server/queue.c				\
			server/free.c				\
			server/epoll_handling.c			\
			server/epoll_func.c			\
			server/map.c				\
			server/calc_stones.c			\
			server/take_fcts.c			\
			server/take_fcts_func.c			\
			server/set_fcts.c			\
			server/opt.c				\
			server/incantation_func.c		\
			server/incantation_funct.c		\
			server/incantation_switch.c		\
			server/incantation_switch2.c		\
			server/incantation_switch_res.c		\
			server/incantation_switch_res2.c	\
			server/random.c				\
			server/chrono.c				\
			server/remove_player.c			\
			server/sig.c				\
			server/eggs.c				\
			server/debug.c				\
			server/timing_func.c			\
			server/connection.c			\
			server/cmd_serv/serv_bct.c		\
			server/cmd_serv/serv_ebo.c		\
			server/cmd_serv/serv_edi.c		\
			server/cmd_serv/serv_eht.c		\
			server/cmd_serv/serv_enw.c		\
			server/cmd_serv/serv_msz.c		\
			server/cmd_serv/serv_pbc.c		\
			server/cmd_serv/serv_pdi.c		\
			server/cmd_serv/serv_pdr.c		\
			server/cmd_serv/serv_pex.c		\
			server/cmd_serv/serv_pfk.c		\
			server/cmd_serv/serv_pgt.c		\
			server/cmd_serv/serv_pic.c		\
			server/cmd_serv/serv_pie.c		\
			server/cmd_serv/serv_pin.c		\
			server/cmd_serv/serv_plv.c		\
			server/cmd_serv/serv_pnw.c		\
			server/cmd_serv/serv_ppo.c		\
			server/cmd_serv/serv_sbp.c		\
			server/cmd_serv/serv_seg.c		\
			server/cmd_serv/serv_sgt.c		\
			server/cmd_serv/serv_smg.c		\
			server/cmd_serv/serv_sst.c		\
			server/cmd_serv/serv_suc.c		\
			server/cmd_serv/serv_tna.c		\
			server/cmd_serv/serv_mct.c		\
			server/cmd_action/broadcast.c		\
			server/cmd_action/broadcast_func.c	\
			server/cmd_action/connect_nbr.c		\
			server/cmd_action/eject.c		\
			server/cmd_action/fork.c		\
			server/cmd_action/forward.c		\
			server/cmd_action/incantation.c		\
			server/cmd_action/inventory.c		\
			server/cmd_action/left.c		\
			server/cmd_action/look.c		\
			server/cmd_action/look_func.c		\
			server/cmd_action/look_func2.c		\
			server/cmd_action/right.c		\
			server/cmd_action/set.c			\
			server/cmd_action/take.c		\
			server/cmd_action.c			\
			server/cmd_graphic.c			\
			server/chained_list/chained_list.c	\
			server/chained_list/chained_player.c	\
			server/chained_list/chained_player_func.c	\
			server/chained_list/chained_team.c	\
			server/chained_list/chained_queue.c	\
			server/chained_list/chained_egg.c	\
			utils/utils.c				\
			utils/get_next_line.c			\
			utils/get_next_line_func.c		\
			utils/my_str_to_wordtab.c		\
			utils/wordtab.c				\
			utils/tab_function.c			\
			utils/realloc.c				\
			utils/my_error.c			\

SRC_CPP		=	graphical/main.cpp			\
			graphical/Starter.cpp			\
			graphical/Zappy.cpp			\
			graphical/Form.cpp			\
			graphical/Dame.cpp			\
			graphical/Manager.cpp			\
			graphical/Map.cpp			\
			graphical/MapRocks.cpp			\
			graphical/FrequencyScroller.cpp		\
			graphical/BannerRocks.cpp		\
			graphical/Player.cpp			\
			graphical/Animation.cpp			\
			graphical/Menu.cpp			\
			graphical/Cloud.cpp			\
			graphical/CommandHandler.cpp		\
			graphical/CommandInfo.cpp

SRC_C		=	utils/utils.c				\
			utils/wordtab.c				\
			utils/get_next_line_func.c		\
			utils/my_str_to_wordtab.c		\
			utils/get_next_line.c			\
			server/chained_list/chained_list.c	\
			server/chained_list/chained_egg.c	\
			server/chained_list/chained_player.c	\
			server/chained_list/chained_player_func.c	\
			server/chained_list/chained_queue.c	\
			server/map.c				\
			server/random.c				\
			graphical/client_graph/init.c		\
			graphical/client_graph/on_start.c	\
			graphical/client_graph/connect.c	\
			graphical/client_graph/receiver.c	\
			graphical/client_graph/map.c		\
			graphical/client_graph/fill_place.c	\
			graphical/client_graph/sig.c		\
			graphical/client_graph/free.c		\
			graphical/client_graph/chained_place.c	\
			graphical/client_graph/functions/sgt.c	\
			graphical/client_graph/functions/msz.c	\
			graphical/client_graph/functions/mct.c	\
			graphical/client_graph/functions/pnw.c	\
			graphical/client_graph/functions/bct.c	\
			graphical/client_graph/functions/sst.c	\
			graphical/client_graph/functions/pbc.c	\
			graphical/client_graph/functions/tna.c	\
			graphical/client_graph/functions/ppo.c	\
			graphical/client_graph/functions/plv.c	\
			graphical/client_graph/functions/pin.c	\
			graphical/client_graph/functions/pgt.c	\
			graphical/client_graph/functions/pic.c	\
			graphical/client_graph/functions/pie.c	\
			graphical/client_graph/functions/pdr.c	\
			graphical/client_graph/functions/seg.c	\
			graphical/client_graph/functions/pex.c	\
			graphical/client_graph/functions/pfk.c	\
			graphical/client_graph/functions/pdi.c	\
			graphical/client_graph/functions/enw.c	\
			graphical/client_graph/functions/eht.c	\
			graphical/client_graph/functions/ebo.c	\
			graphical/client_graph/functions/edi.c

IA_SRC		=	client_ia/main.c		\
			client_ia/connect.c		\
			client_ia/init.c		\
			client_ia/argument.c		\
			client_ia/argument_func.c	\
			client_ia/sig.c			\
			client_ia/str_cmd.c		\
			client_ia/parse_inventory.c	\
			client_ia/fill_inventory.c	\
			client_ia/handler.c		\
			client_ia/serv_handler.c	\
			client_ia/fill_req.c		\
			client_ia/fill_req_bis.c	\
			client_ia/queue.c		\
			client_ia/free.c		\
			client_ia/analyse_line.c	\
			client_ia/map.c			\
			client_ia/action/cmd.c		\
			client_ia/action/stone.c	\
			client_ia/action/broadcast.c	\
			client_ia/action/move_broadcast.c	\
			client_ia/action/move_broadcast2.c	\
			client_ia/action/food.c		\
			client_ia/action/take_food.c	\
			client_ia/action/regroup.c	\
			client_ia/action/take_stone.c	\
			client_ia/action/compare_stone.c	\
			utils/utils.c				\
			utils/get_next_line.c			\
			utils/my_str_to_wordtab.c		\
			utils/get_next_line_func.c		\
			utils/wordtab.c				\
			utils/tab_function.c			\

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
IA_OBJS		=	$(IA_SRC:.c=.o)
OBJ_CPP		=	$(SRC_CPP:.cpp=.o)
OBJ_C		=	$(SRC_C:.c=.o)

CPP		=	g++
CC		=	gcc

LIBS		=	-W -Wall -Wextra
FPICFLAGS	=	-fPIC
SHAREDFLAGS	=	-shared
LFLAGS		=	-lconnect -ldl

CFLAGS_LIB	=	-Iinc -fPIC
CFLAGS		=	-W -Wall -Wextra -I inc/ -g3 -fPIC
CXXFLAGS 	=	-Iinc -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -g3 -W -Wall -Wextra

all:		$(SERVER_NAME) $(IA_NAME) $(G_NAME)

$(SERVER_NAME):	$(SERVER_OBJS)
	$(CC) -o $(SERVER_NAME) $(SERVER_OBJS) $(CFLAGS)

$(IA_NAME):	$(IA_OBJS)
	$(CC) -o $(IA_NAME) $(IA_OBJS) $(CFLAGS)

$(G_NAME): $(OBJ_C) $(OBJ_CPP)
	$(CC) $(LIBS) $(CFLAGS_LIB) $(FPICFLAGS) $(OBJ_C) $(SHAREDFLAGS) -o $(LIB_NAME)
	$(CPP) $(OBJ_CPP) -o $(G_NAME) $(LIB_NAME) $(CXXFLAGS)

clean:
	$(RM) $(IA_OBJS) $(SERVER_OBJS) $(OBJ_CPP) $(OBJ_C)

fclean:	clean
	$(RM) $(IA_NAME) $(SERVER_NAME) $(G_NAME)

re:	fclean all

.PHONY:	all clean fclean re
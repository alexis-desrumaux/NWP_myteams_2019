##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

BIN_CLI	= myteams_cli

BIN_SERV = myteams_server

CC	= gcc -g

RM	= rm -f

SRC_CLI	= ./src/client/main.c \
		  ./src/client/display_help.c \
		  ./src/client/loop_client.c \
		  ./src/client/read.c \
		  ./src/client/create_commands.c \
		  ./src/client/clean_str.c \
		  ./src/client/compute.c \
		  ./src/client/compute2.c \
		  ./src/client/parse_command.c \
		  ./src/client/command/login/login.c \
		  ./src/client/command/login/login2.c \
		  ./src/client/command/users/users.c \
		  ./src/client/command/users/users2.c \
		  ./src/client/command/user/user.c \
		  ./src/client/command/user/user2.c \
		  ./src/client/command/send/send.c \
		  ./src/client/command/logout/logout.c \
		  ./src/client/command/tools.c \

SRC_SERV	= ./src/server/main.c \
			  ./src/server/display_help.c \
			  ./src/server/file_to_tab.c \
			  ./src/server/create_server.c \
			  ./src/server/loop_server.c \
			  ./src/server/watchers.c \
			  ./src/server/close.c \
			  ./src/server/compute.c \
			  ./src/server/read.c \
			  ./src/server/parse_command.c \
			  ./src/server/command/login/login.c \
			  ./src/server/command/login/login2.c \
			  ./src/server/command/users/users.c \
			  ./src/server/command/users/users2.c \
			  ./src/server/command/user/user.c \
			  ./src/server/command/user/user_print.c \
			  ./src/server/command/send/send.c \
			  ./src/server/command/send/send_msg.c \
			  ./src/server/command/send/send_msg_next.c \
			  ./src/server/command/logout/logout.c \
			  ./src/server/command/logout/logout2.c \
			  ./src/server/command/tools.c \

OBJS_CLI	= $(SRC_CLI:.c=.o)

OBJS_SERV	= $(SRC_SERV:.c=.o)

CFLAGS = -I ./include/lib/ -I ./include/server/ -I ./include/client -I ./include/general -I ./libs/myteams/
CFLAGS += -Wall -Wextra

all: makeLib $(BIN_CLI) $(BIN_SERV)

makeLib:
	make -C lib/my/

$(BIN_CLI): $(OBJS_CLI)
	$(CC) -L lib/my/ -L libs/myteams/ $(LDFLAGS) -o $(BIN_CLI) $(OBJS_CLI) -lmy -lmyteams -luuid

$(BIN_SERV): $(OBJS_SERV)
	$(CC) -L lib/my/ -L libs/myteams/ $(LDFLAGS) -o $(BIN_SERV) $(OBJS_SERV) -lmy -lmyteams -luuid

clean:
	$(RM) $(OBJS_CLI) $(OBJS_SERV)
	make clean -C lib/my/

fclean: clean
	$(RM) $(BIN_CLI) $(BIN_SERV)
	make fclean -C lib/my/

re: fclean all

.PHONY: all clean fclean re

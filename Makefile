CLIENT = client
SERVER = server
SERVERBONUS = server_bon
CLIENTBONUS = client_bon

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENTF = client.c 
SERVERF = server.c
CLIENTBONF = client_bonus.c
SERVERBONF = server_bonus.c

#PRINTF = libftprintf.a

CLIENTO = ${CLIENTF:.c=.o}

SERVERO = ${SERVERF:.c=.o}

CLIENTBONFO = ${CLIENTBONF:.c=.o}

SERVERBONFO = ${SERVERBONF:.c=.o}

all: $(CLIENT) $(SERVER)

$(SERVER): $(SERVERO) $(CLIENTO) minitalk.h Makefile
	@$(CC) $(CFLAGS) $(SERVERO) -o $(SERVER)

$(CLIENT): $(SERVERO) $(CLIENTO) minitalk.h Makefile
	@$(CC) $(CFLAGS) $(CLIENTO) -o $(CLIENT)

bonus: $(SERVERBONUS) $(CLIENTBONUS) 

$(SERVERBONUS): $(SERVERBONFO) $(CLIENTBONFO) minitalk.h Makefile
	@$(CC) $(CFLAGS) $(SERVERBONFO) -o $(SERVERBONUS)

$(CLIENTBONUS): $(CLIENTBONFO) $(SERVERBONFO) minitalk.h Makefile
	@$(CC) $(CFLAGS) $(CLIENTBONFO) -o $(CLIENTBONUS)

clean: 
	-rm -rf $(SERVERO) $(CLIENTO)

fclean: 
	-rm -rf $(SERVER) $(CLIENT) $(SERVERO) $(CLIENTO) $(CLIENTBONUS) $(SERVERBONUS) $(SERVERBONFO) $(CLIENTBONFO)

re: fclean all

.PHONY: all clean fclean re bonus
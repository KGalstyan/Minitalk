CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENTF = client.c 
SERVERF = server.c

CLIENTO = ${CLIENTF:.c=.o}

SERVERO = ${SERVERF:.c=.o}

all: $(CLIENT) $(SERVER)

$(SERVER): $(SERVERO) $(CLIENTO) minitalk.h Makefile
	@$(CC) $(CFLAGS) $(SERVERO) -o $(SERVER)

$(CLIENT): $(SERVERO) $(CLIENTO) minitalk.h Makefile
	@$(CC) $(CFLAGS) $(CLIENTO) -o $(CLIENT)

clean: 
	-rm -rf $(SERVERO) $(CLIENTO)

fclean: 
	-rm -rf $(SERVER) $(CLIENT) $(SERVERO) $(CLIENTO)

re: fclean all

.PHONY: all clean fclean re
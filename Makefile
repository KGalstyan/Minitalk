CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENTF = client.c 
SERVERF = server.c

PRINTF = ./Printf
PRINTFA = ./Printf/libftprintf.a

CLIENTO = ${CLIENTF:.c=.o}

SERVERO = ${SERVERF:.c=.o}

CLIENTO += $(PRINTFA)
SERVERO += $(PRINTFA)

all:  Printfmake $(CLIENT) $(SERVER)

$(SERVER): $(SERVERO) $(CLIENTO) minitalk.h Makefile
		@$(CC) $(CFLAGS) $(SERVERO) -o $(SERVER)

$(CLIENT): $(SERVERO) $(CLIENTO) minitalk.h Makefile
		@$(CC) $(CFLAGS) $(CLIENTO) -o $(CLIENT)

Printfmake : $(PRINTF)
	MAKE -C $(PRINTF)

clean:
	$(MAKE) -C $(PRINTF) clean
	-rm -rf $(SERVERO) $(CLIENTO)

fclean: clean
	$(MAKE) -C $(PRINTF) fclean
	-rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re Printfmake
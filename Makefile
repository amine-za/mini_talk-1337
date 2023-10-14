NAME = server client
NAME_BONUS = server_bonus client_bonus

CC = CC
CFLAGS = -Wextra -Werror -Wall

#SOURCES
SRCS = server.c client.c utils.c 
# UTL = 

SRCS_BNS = server_bonus.c client_bonus.c
UTL_BNS = utils_bonus.c

#OBJ
OBJ = $(SRCS:.c=.o)
# OBJ_UTL = $(UTL:.c=.o)

OBJ_BNS = $(SRCS_BNS:.c=.o)
OBJ_UTL_BNS = $(UTL_BNS:.c=.o)


all :	$(NAME)

bonus :	$(NAME_BONUS)

$(NAME) : $(OBJ)  
	$(CC) $(CFLAGS) utils.o server.o -o server
	$(CC) $(CFLAGS) $(OBJ_UTL) client.o -o client


$(NAME_BONUS) : $(OBJ_BNS) $(OBJ_UTL_BNS)
	$(CC) $(CFLAGS) $(OBJ_UTL_BNS) server_bonus.o -o server_bonus
	$(CC) $(CFLAGS) $(OBJ_UTL_BNS) client_bonus.o -o client_bonus


clean : 
	rm -f  *.o

fclean :  clean
	rm -f  $(NAME) $(NAME_BONUS)

re : fclean $(NAME)
###  EXECUTABLE ###
NAME = fdf

LIB = libft/libft.a

### COMPILATION ###
CC = gcc 
CFLAGS = -Wall -Wextra -Werror


### INCLUDES ###
LIBS = -lXext -lX11

### SOURCES ###
C_FILES = $(wildcard *.c)
H_FILES = -I . -I libft
OBJ = ${C_FILES:.c=.o} 

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

LIBFT_REPO = https://github.com/adesgran/libft_extended.git

.c.o:
	${CC} ${CFLAGS} ${H_FILES} -c $< -o ${<:.c=.o}

all: ${NAME}

${LIB}:
	if [ ! -d "./libft" ]; then git clone ${LIBFT_REPO} libft; fi
	make -C libft

${NAME}: ${LIB} ${OBJ}
	${CC} ${OBJ} -L libft -lft -L/usr/local/lib -lmlx_Linux -lm ${LIBS} -o ${NAME}

clean:
	make clean -C libft
	rm -r ${OBJ}

fclean: clean
	make fclean -C libft
	if [ -d "${NAME}" ]; then rm -r ${NAME}; fi

re: fclean all

test: clean all
	./fdf

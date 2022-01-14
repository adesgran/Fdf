###  EXECUTABLE ###
NAME = fdf

LIB = libft/libft.a
MLX = minilibx-linux/mlx.a

### COMPILATION ###
CC = gcc 
CFLAGS = -Wall -Wextra -Werror


### INCLUDES ###
LIBS = -lXext -lX11

### SOURCES ###
C_FILES = $(wildcard *.c)
H_FILES = -I . -I libft -I minilibx-linux
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
	make clean -C libft

${MLX}:
	git submodule init
	git submodule update
	make -C minilibx-linux

${NAME}: ${LIB} ${MLX} ${OBJ}
	${CC} ${OBJ} -L libft -lft -L minilibx-linux -lmlx_Linux -lm ${LIBS} -o ${NAME}

clean:
	rm -r ${OBJ}

fclean: clean
	if [ -d "${NAME}" ]; then rm -r ${NAME}; fi

re: fclean all

test: all
	./fdf maps/42.fdf

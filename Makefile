###  EXECUTABLE ###
NAME = fdf

LIB = libft/libft.a

### COMPILATION ###
CC = clang 
CFLAGS = -Wall -Wextra -Werror -lX11


### INCLUDES ###
CFLAGS += `pkg-config --cflags x11 xext` -lX11 -lXext
LIBS = `pkg-config --libs x11 xext` -lX11 -lXext

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

.c.o:
	${CC} ${CFLAGS} ${H_FILES} -c $< -o ${<:.c=.o}

${LIB}:
	make -C libft

all: ${NAME}

${NAME}: ${LIB} ${OBJ}
	${CC} ${OBJ} ${LIBS} -L libft -lft -L/usr/local/lib -lmlx -lmlx_Linux -lm -o ${NAME}

clean:
	make clean -C libft
	if [ -d "${NAME}" ]; then rm -r ${NAME}; fi

fclean: clean
	make fclean -C libft

re: fclean all

test: clean all
	./fdf

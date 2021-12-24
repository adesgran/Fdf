NAME = fdf

LIB = libft/libft.a
MLX = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = gcc
CFLAGS = -Wall -Wextra -Werror

C_FILES = $(wildcard *.c)

H_FILES = -I/usr/include -Imlx_linux -I . -I libft

${LIB}:
	make -C libft

all: ${LIB} ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${H_FILES} ${MLX} ${C_FILES} ${LIB} -o ${NAME}

clean:
	make clean -C libft
	if [ -d "${NAME}" ]; then rm -r ${NAME}; fi

fclean: clean
	make fclean -C libft

re: fclean all

test: clean all
	./fdf

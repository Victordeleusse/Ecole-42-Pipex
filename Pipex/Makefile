SRCS = Mandatory/pipex.c Mandatory/childs.c Mandatory/error.c Mandatory/free.c
		
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

EXEC = pipex

LIBFT_PATH = -I Libft -L Libft -lft

CC = cc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

# CFLAGS += -fsanitize=address,undefined -g2
# CFLAGS += -valgrind
# CFLAGS += -g 

%.o: %.c 
			${CC} -I. ${LIBFT_PATH} -MMD -c $< -o ${<:.c=.o}

all: run

run: ${OBJS}
		$(MAKE) -C Libft/ all
		clear
		@ $(CC) -o ${EXEC} $(CFLAGS) ${OBJS} ${LIBFT_PATH}

clean:	
		rm -f ${OBJS} ${DEPS} ${OBJS_BONUS} ${DEPS_BONUS}
		$(MAKE) -C Libft/ clean
		rm -f a.out
		clear

fclean:	clean
		$(MAKE) -C Libft/ fclean
		clear

-include $(DEPS) 

re:	fclean all

.PHONY: clean fclean re bonus run
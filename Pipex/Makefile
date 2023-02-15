NAME = pipex

NAME_BONUS = pipex_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	child.c free.c get_files.c pipe.c pipex.c \
		msg.c 

SRCS_BONUS =	child.c free.c get_files.c pipe.c pipex_bonus.c \
		msg.c 
		
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}
DEPS_BONUS = ${SRCS_BONUS:.c=.d}

LIBFT_PATH = -I Libft -L Libft -lft

# CFLAGS += -fsanitize=address,undefined -g2
# CFLAGS += -valgrind
CFLAGS += -g 

all: ${NAME}

${NAME}: ${OBJS} 
		$(MAKE) -C Libft/ all
		$(CC) -o ${NAME} $(CFLAGS) ${OBJS} ${LIBFT_PATH} 

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
		$(MAKE) -C Libft/ all
		$(CC) -o ${NAME_BONUS} $(CFLAGS) ${OBJS_BONUS} ${LIBFT_PATH}

%.o: %.c
			${CC} -g -MMD -o $@ -c $<

clean:	
		rm -f ${OBJS} ${DEPS} ${OBJS_BONUS} ${DEPS_BONUS}
		$(MAKE) -C Libft/ clean
		clear

fclean:	clean
		$(MAKE) -C Libft/ fclean
		rm -f ${NAME} ${NAME_BONUS}
		clear

-include ${DEPS} ${DEPS_BONUS} 

re:	fclean all

.PHONY: clean fclean re 
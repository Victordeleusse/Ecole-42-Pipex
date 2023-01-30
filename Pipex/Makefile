SRCS =	Bonus/childs.c Bonus/free.c Bonus/init_files.c Bonus/pipes.c Bonus/pipex_bonus.c \
		Bonus/error.c 
		
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
		rm -f ${OBJS} ${DEPS} ${OBJS_BONUS} ${DEPS_BONUS} ${EXEC}
		$(MAKE) -C Libft/ clean
		rm -f a.out
		clear

fclean:	clean
		$(MAKE) -C Libft/ fclean
		clear

-include $(DEPS) 

re:	fclean all

.PHONY: clean fclean re bonus run
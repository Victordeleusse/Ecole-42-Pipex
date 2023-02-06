NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	Finale/child.c Finale/free.c Finale/get_files.c Finale/pipe.c Finale/pipex.c \
		Finale/msg.c 

SRCS_BONUS =	Finale/child.c Finale/free.c Finale/get_files.c Finale/pipe.c Finale/pipex_bonus.c \
		Finale/msg.c 
		
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}
DEPS_BONUS = ${SRCS_BONUS:.c=.d}

LIBFT_PATH = -I Libft -L Libft -lft

# CFLAGS += -fsanitize=address,undefined -g2
# CFLAGS += -valgrind
# CFLAGS += -g 

all: ${NAME}

${NAME}: ${OBJS}
		rm -rf Finale/pipex_bonus.o Finale/pipex_bonus.d
		$(MAKE) -C Libft/ all
		@ $(CC) -o ${NAME} $(CFLAGS) ${OBJS} ${LIBFT_PATH} 

bonus: ${OBJS_BONUS}
		rm -rf Finale/pipex.o Finale/pipex.d
		$(MAKE) -C Libft/ all
		@ $(CC) -o ${NAME} $(CFLAGS) ${OBJS_BONUS} ${LIBFT_PATH}

%.o: %.c 
			${CC} -MMD -o $@ -c $<

clean:	
		rm -f ${OBJS} ${DEPS} ${OBJS_BONUS} ${DEPS_BONUS}
		$(MAKE) -C Libft/ clean
		clear

fclean:	clean
		$(MAKE) -C Libft/ fclean
		rm -f ${NAME}
		clear

-include $(DEPS) $(DEPS_BONUS) 

re:	fclean all

.PHONY: clean fclean re bonus
NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	child.c free.c get_files.c pipe.c pipex.c \
		msg.c 
SRCS_BONUS =	child.c free.c get_files.c pipe.c pipex_bonus.c \
		msg.c 
		
SRCS_PATH = srcs/

OBJS_PATH = objs
OBJS_PATH_BONUS = objs_bonus

HEADER_PATH += ${SRCS_PATH}includes/

HEADER = pipex.h

vpath %.c ${SRCS_PATH}
vpath %.h ${HEADER_PATH} 
# *.h -> ./srcs/includes/pipex.h

all: ${NAME}

OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_BONUS = ${patsubst %.c, ${OBJS_PATH_BONUS}/%.o, ${SRCS_BONUS}}


${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile ${HEADER}
		mkdir -p ${OBJS_PATH}
		${CC} ${CFLAGS} -g -c $< -o $@ -I ${HEADER_PATH}

${OBJS_BONUS}: ${OBJS_PATH_BONUS}/%.o: %.c Makefile ${HEADER}
		mkdir -p ${OBJS_PATH_BONUS}
		${CC} ${CFLAGS} -g -c $< -o $@ -I ${HEADER_PATH}

LIBFT_PATH = -I Libft -L Libft -lft

# CFLAGS += -fsanitize=address,undefined -g2
# CFLAGS += -valgrind
# CFLAGS += -g 

${NAME}: ${OBJS} 
		$(MAKE) -C Libft/ all
		$(CC) -o ${NAME} $(CFLAGS) ${OBJS} ${LIBFT_PATH} 

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
		$(MAKE) -C Libft/ all
		$(CC) -o ${NAME_BONUS} $(CFLAGS) ${OBJS_BONUS} ${LIBFT_PATH}

clean:	
		rm -rf $(OBJS_PATH) $(OBJS_PATH_BONUS)
		$(MAKE) -C Libft/ clean
		clear

fclean:	clean
		$(MAKE) -C Libft/ fclean
		rm -f ${NAME} ${NAME_BONUS}
		clear

re:	fclean all

.PHONY: clean fclean re 
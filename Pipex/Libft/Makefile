# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 13:42:36 by vde-leus          #+#    #+#              #
#    Updated: 2023/01/28 14:47:49 by vde-leus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

########################################## SRCS ####################################################

### SRCS Printf
SRCS += ft_strlen.c ft_putstr.c ft_putnbr.c ft_putnbr_hexmin.c ft_putnbr_hexmaj.c \
				ft_putchar.c ft_putadress_hex.c ft_put_unsigned_nbr.c ft_printf.c

### SRCS Libft

SRCS += ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c  ft_memchr.c ft_striteri.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putnbr_fd.c \
				ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_strcmp.c

### SRCS Get_next_line

SRCS += get_next_line.c get_next_line_utils.c


########################################## RULES ####################################################

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CC = gcc -Wall -Werror -Wextra -I ./

%.o: %.c 
			${CC} -I. -MMD -c $< -o ${<:.c=.o}

all: 	${NAME}

${NAME}:	${OBJS}
				ar -rsc ${NAME} ${OBJS} 

clean:	
		rm -f ${OBJS} ${DEPS} 

fclean:	clean
		rm -f ${NAME}

-include $(DEPS)

re:	fclean all

.PHONY: all clean fclean re 
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:53:27 by bhennequ          #+#    #+#              #
#    Updated: 2023/02/15 16:09:03 by bhennequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTNAME = libft.a

GCC = gcc

LIBFTDIR = ./libft

SRC = ft_printf.c printc.c \

AR = ar cr

FLAGS = -Wall -Wextra -Werror

RAN = ranlib

OBJ = ${SRC:.c=.o}

all : ${NAME}

makelibft :
	make -C ${LIBFTDIR}
	cp ${LIBFTDIR}/${LIBFTNAME} ./
	mv ${LIBFTNAME} ${NAME}

${NAME}: makelibft ${OBJ}
	${AR} ${NAME} ${OBJ}

.c.o :
	${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJ} ${OBJBONUS}
	cd ${LIBFTDIR} && make clean

fclean: clean
	rm -f ${NAME}
	cd ${LIBFTDIR} && make fclean

re: fclean all

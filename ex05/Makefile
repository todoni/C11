# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 06:50:51 by sohan             #+#    #+#              #
#    Updated: 2021/04/15 06:57:16 by sohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SOURCES = main.c ft_operations.c ft_functions.c

all: ${TARGET}

${TARGET}: ${SOURCES}
	${CC} ${CFLAGS} -o $@ ${SOURCES}

clean:
	rm -rf ${TARGET}
	rm -rf *.o

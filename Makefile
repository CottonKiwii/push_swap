# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 10:42:42 by jwolfram          #+#    #+#              #
#    Updated: 2024/06/26 18:14:33 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

### COMPILATION ###

CC := cc 

CFLAGS := -Wall -Wextra -Werror

RM := rm -fr

INCLUDES := -I./includes -I./libft/includes

### COLORS ###

RED := \033[1;31m

GREEN := \033[1;32m

DEFAULT := \033[0m

### SOURCES ###

SRCS_DIR := src

SRCS_FILES := main \
			  atoli \
			  tester \

SRCS := ${SRCS_FILES:%=${SRCS_DIR}/%.c}

### OBJECTS ###

OBJS_DIR := obj

OBJS := ${SRCS_FILES:%=${OBJS_DIR}/%.o}

OBJS_SORT := ${sort ${dir ${OBJS}}}

### LIBRARY/HEADER ###

LIBFT_DIR := ./libft

LIBFT_AR := ./libft/libft.a 

### COMMANDS ###

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_AR}
	${CC} ${CFLAGS} $^ ${INCLUDES} -o $@
	@echo "${GREEN}--------------------------${DEFAULT}"
	@echo "${GREEN}   COMPILATION COMPLETE   ${DEFAULT}"
	@echo "${GREEN}--------------------------${DEFAULT}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_SORT}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

${LIBFT_AR}:
	${MAKE} -C ${LIBFT_DIR}

${OBJS_SORT}:
	mkdir -p $@

### CLEANUP COMMANDS ###

clean:
	${MAKE} $@ -C ${LIBFT_DIR}
	${RM} ${OBJS_DIR}

fclean: clean
	${MAKE} $@ -C ${LIBFT_DIR}
	${RM} ${NAME}
	@echo "${RED}--------------------------${DEFAULT}"
	@echo "${RED}     CLEANUP COMPLETE     ${DEFAULT}"
	@echo "${RED}--------------------------${DEFAULT}"

re: fclean all

.PHONY: all clean fclean re

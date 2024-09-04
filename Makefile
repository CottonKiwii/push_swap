# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 10:42:42 by jwolfram          #+#    #+#              #
#    Updated: 2024/09/04 17:07:58 by jwolfram         ###   ########.fr        #
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
			  stack \
			  output \
			  tester \
			  sort/sort \
			  sort/send \
			  sort/move \
			  sort/small_sort \
			  operations/swap \
			  operations/rotate \
			  operations/push \
			  utils/utils \
			  utils/init \

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
	@${CC} ${CFLAGS} $^ ${INCLUDES} -o $@
	@echo "${GREEN}--------------------------${DEFAULT}"
	@echo "${GREEN}   COMPILATION COMPLETE   ${DEFAULT}"
	@echo "${GREEN}--------------------------${DEFAULT}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_SORT}
	@${CC} ${CFLAGS} -g -c $< ${INCLUDES} -o $@

${LIBFT_AR}:
	@${MAKE} -C ${LIBFT_DIR}

${OBJS_SORT}:
	@mkdir -p $@

### CLEANUP COMMANDS ###

clean:
	@${MAKE} $@ -C ${LIBFT_DIR}
	@${RM} ${OBJS_DIR}
	@echo "${RED}--------------------------${DEFAULT}"
	@echo "${RED}     CLEANUP COMPLETE     ${DEFAULT}"
	@echo "${RED}--------------------------${DEFAULT}"


fclean: clean
	@${MAKE} $@ -C ${LIBFT_DIR}
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:59:59 by yooshima          #+#    #+#              #
#    Updated: 2024/05/08 17:37:03 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c put_hex.c put_int_char.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f
LIBFT_PATH	= ./libft

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C ./libft
			cp libft/libft.a ${NAME}
			${AR} ${NAME} ${OBJS}

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}
			$(MAKE) -C $(LIBFT_PATH) clean

fclean:		clean
			${RM} ${NAME}
			$(MAKE) -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus



# NAME		= libftprintf.a

# SRCS		= \
# 			 ft_printf.c 
# 			\
# OBJS		= $(SRCS:.c=.o)

# CC			= cc
# CFLAGS		= -Wall -Wextra -Werror
# LIBFT		= ./libft/libft.a

# AR			= ar rcs
# RM			= rm -f

# all:		${NAME}

# ${NAME}:	${OBJS}
# 			${MAKE} -C ./libft
# 			cp libft/libft.a ${NAME}
# 			${AR} ${NAME} ${OBJS}

# %.o: %.c
# 		$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 			${MAKE} -C {LIBFT_PATH} clean
# 			${RM} ${OBJS}

# fclean:		clean
# 			${MAKE} -C {LIBFT_PATH} fclean
# 			${RM} ${NAME}

# re:			fclean all

# .PHONY:		all clean fclean re

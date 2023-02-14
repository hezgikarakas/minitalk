# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaraka <hakaraka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 09:59:06 by hakaraka          #+#    #+#              #
#    Updated: 2023/02/14 10:41:51 by hakaraka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= server.c client.c utils.c

OBJS		= $(SRCS:.c=.o)

BSRCS		= server_bonus.c client_bonus.c

B_OBJS		= $(BSRCS:.c=.o)

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

all		: server client

bonus		: server_bonus client_bonus

server		: server.o utils.o
		  $(CC) -o $@ $^

client		: client.o utils.o
		  $(CC) -o $@ $^
		  
server_bonus	: server_bonus.o utils.o
		  $(CC) -o $@ $^

client_bonus	: client_bonus.o utils.o
		  $(CC) -o $@ $^

%.o: %.c
		  $(CC) -c $(CFLAGS) $?

clean		: 
		  rm -rf $(OBJS) $(B_OBJS)


fclean		: clean
		  rm -rf server client server_bonus client_bonus


re		: fclean all


./PHONY		: all bonus clean fclean re

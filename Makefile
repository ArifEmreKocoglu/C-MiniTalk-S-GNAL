# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:21:01 by akocoglu          #+#    #+#              #
#    Updated: 2022/04/05 15:21:02 by akocoglu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = server
NAMECLIENT = client
LIB = ./ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)

$(LIB):
	make -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT)

ffclean: fclean
	make fclean -C ./ft_printf

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@

norm:
	norminette *.[ch]

re:fclean all

.PHONY : re fclean clean all ffclean norm

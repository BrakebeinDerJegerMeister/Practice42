# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: profchaos <temp@temp.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 09:54:28 by profchaos         #+#    #+#              #
#    Updated: 2024/07/29 10:44:57 by profchaos        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = $(wildcard srcs/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: libft.a

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I includes
	
libft.a: $(OBJECTS)
	ar -r libft.a $(OBJECTS)
	ranlib libft.a

clean:
	rm -f $(OBJECTS)

fclean: 
	$(MAKE) clean
	rm -f libft.a

re: 
	$(MAKE) fclean
	$(MAKE) all

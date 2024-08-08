# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: profchaos <temp@temp.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 10:05:16 by profchaos         #+#    #+#              #
#    Updated: 2024/08/02 10:18:08 by profchaos        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
NAME = do-op
HEADERS = headers

all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror -I $(HEADERS)

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror -I $(HEADERS)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re

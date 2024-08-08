# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: profchaos <temp@temp.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 12:21:22 by profchaos         #+#    #+#              #
#    Updated: 2024/07/30 12:58:42 by profchaos        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)
NAME = ft_tail

all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re

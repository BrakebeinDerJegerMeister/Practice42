# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: profchaos <temp@temp.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:01:58 by profchaos         #+#    #+#              #
#    Updated: 2024/07/29 12:51:48 by profchaos        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_display_file.c
OBJS = $(SRCS:.c=.o)
NAME = ft_display_file

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

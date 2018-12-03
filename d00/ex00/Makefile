# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 20:26:25 by akupriia          #+#    #+#              #
#    Updated: 2018/10/02 20:35:40 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C		=	clang++
FLAGS	=	-Wall -Wextra -Werror

NAME	=	megaphone
SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(C) $(FLAGS) -c $@ -o $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

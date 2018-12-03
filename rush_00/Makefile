# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 17:27:19 by akupriia          #+#    #+#              #
#    Updated: 2018/10/07 17:27:21 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -g -Wall -Werror -Wextra
CXXXFLAGS = -g -Wall -Werror -Wextra -lncurses
NAME = ft_retro

SRC = AObject.cpp Laser.cpp Enemy.cpp main.cpp Hero.cpp Window.cpp EnLaser.cpp Star.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

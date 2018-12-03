# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 22:07:24 by akupriia          #+#    #+#              #
#    Updated: 2018/06/22 22:07:38 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	game

SRCS =	main.cpp \
		AWeapon.cpp \
		Enemy.cpp \
		PlasmaRifle.cpp \
		PowerFist.cpp \
		Character.cpp \
		RadScorpion.cpp \
		SuperMutant.cpp


OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 00:08:05 by akupriia          #+#    #+#              #
#    Updated: 2018/10/02 00:08:07 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



C		=	clang++
FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.cpp \
			Contact.Class.cpp \
			PhoneBook.cpp

NAME	=	phonebook
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C) -o $(NAME) $(FLAGS) $(OBJ)

%.o: %.cpp
	$(C) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
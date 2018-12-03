# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 16:24:42 by akupriia          #+#    #+#              #
#    Updated: 2018/10/12 16:24:43 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mindopen

COMM_PATH = commands/
INC_PATH = includes/
OBJ_PATH = obj/

C = clang++
WFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -pedantic-errors
IFLAGS = -I $(INC_PATH)

COMMANDS = Comma Dot Pleft Pright Plus Minus Loop
FILES = main

SRCS = $(addprefix $(COMM_PATH), $(addsuffix .cpp, $(COMMANDS)))
SRCS += $(addsuffix .cpp, $(FILES))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(WFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(COMM_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(C) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 19:25:45 by akupriia          #+#    #+#              #
#    Updated: 2018/10/09 19:25:46 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialization

SRC_PATH = #./
INC_PATH = #./
OBJ_PATH = obj/

C = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98
IFLAGS = #-I $(INC_PATH)
LFLAGS = #-lncurses

FILES = Serialization

SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(FILES)))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(CFLAGS) $(LFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(C) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re

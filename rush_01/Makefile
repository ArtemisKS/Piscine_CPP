# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 22:54:10 by akupriia          #+#    #+#              #
#    Updated: 2018/10/14 23:33:55 by akupriia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC_PATH = classes/
MODULES_PATH = modules/
INC_PATH = includes/
OBJ_PATH = obj/

C = clang++
WFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(INC_PATH)
LFLAGS = -lncurses 
S = -I ./Frameworks/SDL2_image.framework/Headers -I ./Frameworks/SDL2_ttf.framework/Headers -I./Frameworks/SDL2.framework/Headers -rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2 -framework SDL2_ttf -framework SDL2_image
SDL = -I./Frameworks/SDL2.framework/Headers -rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2
CLASSES = CursesDisplay GUIDisplay
MODULES = ACursesModule Name OS Time CPU RAM NetworkThro NetworkInfo Unicat Disks Rest
FILES = main utils

SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(CLASSES)))
SRCS += $(addprefix $(SRC_PATH)$(MODULES_PATH), $(addsuffix .cpp, $(MODULES)))
SRCS += $(addsuffix .cpp, $(FILES))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(C) $(WFLAGS) $(S) $(LFLAGS) $(IFLAGS) $(OBJ) -o $(NAME) 

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)$(MODULES_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(C) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re

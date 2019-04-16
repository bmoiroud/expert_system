# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 22:43:33 by eferrand          #+#    #+#              #
#    Updated: 2019/04/16 19:06:05 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# our executable name
NAME			:=	expert-system

# base dirs
SRC_DIR			:=	./srcs
INC_DIR			:=	./includes
LIB_DIR			:=	./libs
OBJ_DIR			:=	./objs

# files to compile
FILE_LIST		:=	main.cpp		\
					AOperator.cpp	\
					Fact.cpp		\
					Graph.cpp		\
					get_influence.cpp

OBJ_FILES		:= $(addprefix $(OBJ_DIR)/,$(FILE_LIST:.cpp=.o))

# libraries

# our project
INCLUDES		:=	-I$(INC_DIR)
#LINK			:=	$(LIB_FT_LINK) $(LIB_MLX_LINK) -fsanitize=address -O0

# compiler and flags
CC				:=	g++
CFLAGS			:=	-std=c++11 -Wall -Wextra -Werror -Wno-sign-compare # -fsanitize=address -O0

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

# linking rule: executable NAME needs OBJ_FILES to link
$(NAME): $(OBJ_FILES)
	$(CC) -v $(LINK) $(OBJ_FILES) -o $(NAME)

# compiler rule: each .o file in OBJ_DIR needs a .c file in SRC_DIR
# $< -- input file (.c)
# $@ -- output file (.o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

relibs:
	@make re --no-print-directory

re: fclean all

.PHONY: all obj clean fclean relibs re

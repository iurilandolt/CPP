# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 23:02:25 by rlandolt          #+#    #+#              #
#    Updated: 2024/06/19 23:22:19 by rlandolt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = objects
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 16:01:15 by clballes          #+#    #+#              #
#    Updated: 2023/09/22 16:01:16 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieMoar
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Sources
SRCS = Zombie.cpp main.cpp zombieHorde.cpp
LIB = Zombie.hpp

# create obj and resources
OBJ = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

# compiling makefile
$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) -I. -c $(CFLAGS) -MMD $< -o $@

clean:
	$(RM) $(NAME) $(OBJ) $(DEPS)

fclean: clean

re: fclean all

all: $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re

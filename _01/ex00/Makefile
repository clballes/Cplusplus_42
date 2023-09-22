# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 15:44:24 by clballes          #+#    #+#              #
#    Updated: 2023/09/22 15:44:25 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieBrainz
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Sources
SRCS = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 13:02:46 by clballes          #+#    #+#              #
#    Updated: 2023/09/22 13:02:47 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Sources
SRCS = megaphone.cpp
LIB = lib_phone.hpp
OBJ = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)


# compiling makefile

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) -c $(CFLAGS) -MMD $< -o $@

clean:
	$(RM) $(NAME) $(OBJ) $(DEPS)

fclean: clean

re: fclean all

all: $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re

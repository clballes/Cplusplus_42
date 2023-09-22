# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 17:36:59 by clballes          #+#    #+#              #
#    Updated: 2023/09/22 17:37:00 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Sed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Sources
SRCS = main.cpp sed.cpp

# create obj and resources
OBJ = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

# compiling makefile
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) -c $(CFLAGS) -MMD $< -o $@

clean:
	$(RM) $(NAME) $(OBJ) $(DEPS) *.replace

fclean: clean

re: fclean all

all: $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re

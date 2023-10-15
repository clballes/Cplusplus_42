# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 10:39:40 by clballes          #+#    #+#              #
#    Updated: 2023/09/26 10:39:44 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRC = srcs/
INC = inc/
# Sources
SRCS = $(SRC)main.cpp $(SRC)Bureaucrat.cpp $(SRC)AForm.cpp $(SRC)ShrubberyCreationForm.cpp $(SRC)RobotomyRequestForm.cpp $(SRC)PresidentialPardonForm.cpp
LIB = $(INC)Bureaucrat.hpp $(INC)AForm.hpp $(INC)ShrubberyCreationForm.hpp $(INC)RobotomyRequestForm.hpp $(INC)PresidentialPardonForm.hpp

# create obj and resources
OBJ = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

# compiling makefile
$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) -I. -c $(CFLAGS) -MMD $< -o $@

clean:
	$(RM) $(NAME) $(OBJ) $(DEPS) *_shrubbery.txt

fclean: clean

re: fclean all

all: $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re

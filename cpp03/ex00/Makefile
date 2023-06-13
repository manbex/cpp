# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 09:19:04 by mbenicho          #+#    #+#              #
#    Updated: 2023/04/17 16:12:36 by mbenicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	claptrap

INC_DIR		=	includes/
SRC_DIR		=	srcs/
OBJ_DIR		=	obj/

INC			=	ClapTrap.hpp
SRC 		=	main.cpp		\
				ClapTrap.cpp

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			=	c++
CFLAGS		=	-I$(INC_DIR) -Wall -Wextra -Werror -std=c++98
RM			=	rm -f

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(addprefix $(INC_DIR), $(INC))
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $@

all:			$(NAME)

clean:
					$(RM) -r $(OBJ_DIR)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

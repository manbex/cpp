# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 09:19:04 by mbenicho          #+#    #+#              #
#    Updated: 2023/04/17 14:43:47 by mbenicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

INC			=	Contact.hpp		\
				PhoneBook.hpp	\

SRC 		=	main.cpp 		\
				Contact.cpp	\
				PhoneBook.cpp

OBJ			=	$(SRC:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

%.o:	%.cpp $(INC)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $@

all:			$(NAME)

clean:
					$(RM) -r $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

NAME		=	btc

CC			=	c++
CFLAGS		=	-I$(INC_DIR) -Wall -Wextra -Werror -std=c++98
RM			=	rm -f

INC_DIR		=	includes/
SRC_DIR		=	srcs/
OBJ_DIR		=	obj/

INC			=	BitcoinExchange.hpp
SRC 		=	main.cpp			\
				BitcoinExchange.cpp

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

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

test:			all
				@./$(NAME)

.PHONY:			all clean fclean re

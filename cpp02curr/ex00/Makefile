NAME = awesomeNumber
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp Fixed.cpp
OBJ = $(addprefix ./, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(OBJ) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm- rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

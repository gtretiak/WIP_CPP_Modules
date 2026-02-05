NAME = abstract
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp AAnimal.cpp Dog.cpp Cat.cpp AWrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = $(addprefix ./, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(OBJ) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

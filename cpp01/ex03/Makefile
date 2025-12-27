NAME = violence
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp Weapon.class.cpp HumanA.class.cpp HumanB.class.cpp
OBJ = $(addprefix ./, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(SRC) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

.PHONY: clean flean re

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
SRC = megaphone.cpp
OBJS = $(addprefix ./, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(SRC) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

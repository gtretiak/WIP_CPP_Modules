FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = runPhoneBook
SRC = myPhoneBook.cpp
OBJS = $(addprefix ./, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(SRC) -o $(NAME)

%.o: %.c
	@c++ $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

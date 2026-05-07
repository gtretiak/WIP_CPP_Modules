NAME = Interns
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
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
	@rm -rf *.txt

re: fclean all

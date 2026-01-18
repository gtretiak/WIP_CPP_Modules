NAME = mySed
TEST = test
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp
SRC2 = tests.cpp
OBJ = $(addprefix ./, $(SRC:.cpp=.o))
OBJ2 = $(addprefix ./, $(SRC2:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(SRC) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

.PHONY: clean fclean re test

$(TEST): $(OBJ2)
	@c++ $(SRC2) -o $(TEST)
	@touch empty
	@echo "42 is teaching us" > normal
	@cp normal protected
	@chmod u-r protected
	@cp main.cpp outprotected
	@touch outprotected.replace
	@chmod u-w outprotected.replace
	@echo "Error: Invalid number of arguments. Expected a filename and two strings." > error_no_arg
	@echo "Error: Invalid number of arguments. Expected a filename and two strings." > error_few_arg
	@echo "Error: Invalid number of arguments. Expected a filename and two strings." > error_many_arg
	@echo "Error: Invalid input file." > error_no_file
	@echo "Error: Invalid input file." > error_protected1
	@echo "Error: File is empty." > error_empty_file
	@echo "Error: String to be replaced is empty." > error_empty_str
	@echo "Error: Invalid output file." > error_protected2
	@printf "Life is teaching us" > success

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ2)
	@rm -rf normal normal.replace protected outprotected outprotected.replace empty success succ
	@rm -rf program_*
	@rm -rf error_*

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(TEST)

re: fclean all

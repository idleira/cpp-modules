CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

NAME = restored

SRC = Account.cpp tests.cpp

all: $(NAME)

$(NAME): $(OBJ)
	clear
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)
	@echo "replicating data (̿▀̿ ̿Ĺ̯̿̿▀̿ ̿)̄"

clean:
	@rm -rf $(NAME)
	@echo "dream job secured ⊂(▀¯▀⊂ )"

re: clean all

.PHONY: all clean re
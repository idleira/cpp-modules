CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

NAME = megaphone

SRC = megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)
	@echo "megaphone on ꒰ᐢ. .ᐢ꒱📢 ✅"

clean:
	@rm -rf $(NAME)
	@echo "megaphone off ꒰ᐢ. .ᐢ꒱📢 ⛔️"

re: clean all
	
.PHONY: all clean re
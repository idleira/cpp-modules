CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

NAME = phonebook

SRC = Contact.cpp	PhoneBook.cpp	main.cpp

all: $(NAME)

$(NAME): $(SRC)
	clear
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)
	@echo "phonebook created  ꒰ᐢ. .ᐢ꒱📕 ✅"

clean:
	@rm -rf $(NAME)
	@echo "phonebook deleted  ꒰ᐢ. .ᐢ꒱📕 ⛔️"

re: clean all

.PHONY: all clean re
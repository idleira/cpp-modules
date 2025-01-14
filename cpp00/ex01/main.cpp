#include <iostream>
#include <string>
#include "PhoneBook.hpp"

std::string	getUserInput(PhoneBook *book) {
	std::string	userInput;

	if (!std::getline(std::cin, userInput) || std::cin.eof()) {
		std::cout << "EXIT" << std::endl;
		return ("EXIT");
	}
	userInput = book->trimWhiteSpaces(userInput);
	for (std::string::iterator it = userInput.begin(); it != userInput.end(); it++)
			*it = std::toupper(*it);
	return (userInput);
}


int	main(void) {
	PhoneBook	book;
	std::string	userInput;

	std::cout << "\n\nwelcome to your phonebook! ꒰ᐢ. .ᐢ꒱\n" << std::endl;
	std::cout << "empty phonebook created.\n" << std::endl;
	while (true) {
		std::cout << "\nenter: ADD, SEARCH, or EXIT.\n" << std::endl;
		std::cout << "\n\033[1;33m→\033[0m	" << std::flush;
		userInput = getUserInput(&book);
		if (userInput == "EXIT" || userInput == "exit")
			break ;
		else if (userInput == "ADD" || userInput == "add") {
			if (!book.addContact())
				break ;
		}			
		else if (userInput == "SEARCH" || userInput == "search") {
			if (!book.searchContact())
				break ;
		}
		else {
			std::cout	<< "\n\033[1;31minvalid input\033[0m.please try:\n" << std::endl
						<< "\t- ADD     to add a new contact" << std::endl
						<< "\t- SEARCH  to search the contact list" << std::endl
						<< "\t- EXIT    to exit the phonebook" << std::endl;
		}
	}
	std::cout << "\ngoodbye! ꒰ᐢ. .ᐢ꒱" << std::endl;
	return (0);
}

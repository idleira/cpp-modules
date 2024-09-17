#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::cout << "welcome to your phonebook! ꒰ᐢ. .ᐢ꒱\n" << std::endl;
	std::cout << "empty phonebook created.\n" << std::endl;
	std::cout << "please enter: ADD, SEARCH, or EXIT." << std::endl;

	std::string input = "";
	while (input.compare("EXIT") != 0)
	{
		std::cin >> input;
		if (input.compare("ADD") == 0)
		{
			PhoneBook phoneBook;
			phoneBook.addContact();
		}
		else if (input.compare("SEARCH") == 0)
		{
			PhoneBook phoneBook;
			phoneBook.searchContact();
		}
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "goodbye! ꒰ᐢ. .ᐢ꒱" << std::endl;
		}
		else
		{
			std::cout << "please enter: ADD, SEARCH, or EXIT." << std::endl;
		}
	}
}
#include "PhoneBook.hpp"

bool	isEmpty( const std::string& input );

int main(void)
{
	std::cout << "welcome to your phonebook! ꒰ᐢ. .ᐢ꒱\n" << std::endl;
	std::cout << "empty phonebook created.\n" << std::endl;
	std::cout << "please enter: ADD, SEARCH, or EXIT." << std::endl;

	std::string input = "";
	PhoneBook phoneBook;
	while (input.compare("EXIT") || input.compare("exit"))
	{
		std::cout << "→" << std::flush;
		if (!std::getline(std::cin, input))
			break ;
		if (input.empty())
			continue;
		if (!input.compare("ADD") ||input.compare("add"))
			phoneBook.addContact();
		else if (input.compare("SEARCH")|| input.compare("search")) 
				phoneBook.searchContact();
		else if (input.compare("EXIT") || input.compare("exit"))
			std::cout << "invalid input. please enter: ADD, SEARCH, or EXIT." << std::endl;
	}
	std::cout << "goodbye! ꒰ᐢ. .ᐢ꒱" << std::endl;
	return (0);
}

bool isEmpty(const std::string& input)
{
	if (input.empty())
		return (true);
	for (int i =0; input[i]; ++i)
	{
		if (!std::isspace(input[i]))
			return (false);
	}
	return (true);
}

std::string getInput(const std::string& fieldName)
{
	std::string input = "";
	while (isEmpty(input))
	{
		std::cout << fieldName << ":" << std::flush;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string shortenContact(const std::string& input)
{
	if (input.length() > 10)
			return(input.substr(0,9) + '.');
		return (input);

}
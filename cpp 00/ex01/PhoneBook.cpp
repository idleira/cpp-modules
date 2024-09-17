#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { contactIndex = 0; }

void PhoneBook::addContact(void)
{
	Contact newContact;
	std::string input;

	std::cout << "time to make a new contact! 📚📞" << std::endl;
	std::cout << "just fill in the details below to get started:\n" << std::endl;

	std::cout << "first name:\n";
	std::cin >> input;
	newContact.setFirstName(input);
	std::cout << "last name:\n";
	std::cin >> input;
	newContact.setLastName(input);
	std::cout << "nickname:\n";
	std::cin >> input;
	newContact.setNickname(input);
	std::cout << "phone number:\n";
	std::cin >> input;
	newContact.setPhoneNumber(input);
	std::cout << "darkest secret:\n";
	std::cin >> input;
	newContact.setDarkestSecret(input);

	contacts[contactIndex %8] = newContact;
	contactIndex++;

	std::cout << "contact added! 👤✅\n " << std::endl;
}

void PhoneBook::searchContact(void)
{
	std::string input;
	int	index = 0;

	if (!index)
	{
		std::cout << "ADD a contact before SEARCHing" << std::endl;
		return ;
	}
	// printPhoneBook();
	std::cout << "searching for a contact! 🔍📞" << std::endl;
	std::cout << "please enter the index of the contact you would like to view:\n" << std::endl;
	std::cin >> input;
	index = std::stoi(input);

	if (index >= 0 && index < contactIndex)
	{
		std::cout << "first name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "last name: " << contacts[index].getLastName() << std::endl;
		std::cout << "nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "phone number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{ std::cout << "contact not found! 🚫📞" << std::endl; }
}

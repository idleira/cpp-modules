#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { contactIndex = 0; contactCount = 0;}

void PhoneBook::addContact(void)
{
	Contact newContact;

	std::cout << "time to make a new contact! 📚📞" << std::endl;
	std::cout << "just fill in the details below to get started:\n" << std::endl;

	newContact.setFirstName(getInput("first name: "));
	newContact.setLastName(getInput("last name: "));
	newContact.setNickname(getInput("nickname:"));
	newContact.setPhoneNumber(getInput("phone number: "));
	newContact.setDarkestSecret(getInput("darkest secret: "));

	contacts[contactIndex] = newContact;
	if (contactIndex < 7)
		contactIndex++;
	else
		contactIndex = 0;
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

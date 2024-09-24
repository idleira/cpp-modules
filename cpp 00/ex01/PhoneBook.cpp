#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { contactIndex = 0; contactCount = 0;}

void PhoneBook::addContact(void)
{
	Contact newContact;

	std::cout << "\ntime to make a new contact! 📚📞" << std::endl;
	std::cout << "just fill in the details below to get started:\n" << std::endl;

	newContact.setFirstName(getInput("first name: "));
	newContact.setLastName(getInput("last name: "));
	newContact.setNickname(getInput("nickname: "));
	newContact.setPhoneNumber(getInput("phone number: "));
	newContact.setDarkestSecret(getInput("darkest secret: "));

	contacts[contactIndex] = newContact;
	if (contactIndex < 7)
		contactIndex++;
	else
		contactIndex = 0;
	contactIndex++;

	std::cout << "\ncontact added! 👤✅ " << std::endl;
}

void PhoneBook::searchContact(void)
{
	std::string input;
	int	index = 0;

	if (!contactIndex)
	{
		std::cout << "\nADD a contact before SEARCHing" << std::endl;
		return ;
	}
	// printPhoneBook();
	std::cout << "\nsearching for a contact! 🔍📞" << std::endl;
	std::cout << "enter the index of the contact you would like to view:\n" << std::endl;
	std::cin >> input;
	index = std::atoi(input.c_str());

	if (index >= 0 && index < contactIndex)
	{
		std::cout << "\nfirst name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "last name: " << contacts[index].getLastName() << std::endl;
		std::cout << "nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "phone number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{ std::cout << "contact not found! 🚫📞" << std::endl; }
}

#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : currentContactIndex(-1), _abort(false) { return ;}

PhoneBook::~PhoneBook(void) { return ;}


std::string	PhoneBook::getNewInput(std::string const prompt) {
	std::string	input;

	std::cout << prompt << std::endl << "\033[1;33m→\033[0m ";
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_abort = true;
		std::cout << std::endl;
		return(std::string());
	}
	input = trimWhiteSpaces(input);
	return (input);
}

void	PhoneBook::incrementIndex(void) {
	currentContactIndex++;
	if (currentContactIndex > 7) {
		currentContactIndex = 0;
	}
}


void	PhoneBook::printContactList(void) const {
	std::cout	<< "✢----------✢----------✢----------✢----------✢" << std::endl
				<< "|   \033[1mINDEX\033[0m  |\033[1mFIRST NAME\033[0m|\033[1mLAST  NAME\033[0m| \033[1mNICKNAME\033[0m |" << std::endl
				<< "✢----------✢----------✢----------✢----------✢" << std::endl;
	for (int i = 0; i < 8; i++) {
		printContactToList(i);
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::printContactToList(int const contactIndex) const {
	if (this->contactList[contactIndex].isContactEmpty())
		return ;
	std::cout << "|" << std::setw(10) << contactIndex << "|";
	printListString(this->contactList[contactIndex].getFirstName());
	printListString(this->contactList[contactIndex].getLastName());
	printListString(this->contactList[contactIndex].getNickname());
	std::cout	<< std::endl
				<< "✢----------✢----------✢----------✢----------✢" << std::endl;
	return ;
}

void PhoneBook::printListString(std::string str) const {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

bool	PhoneBook::printContactByIndex(std::string const input) const {

	int			contactIndex;

	if (input.length() == 1 && std::isdigit(input[0])) {
		contactIndex = input[0] - '0';
		if (contactIndex >= 0 && contactIndex <= 7) {
			if (this->contactList[contactIndex].printContactEntry())
				return (true);
			else {
				std::cout << "contact [" << contactIndex << "] not found! 🚫📞" << std::endl;
				return (false);
			}
		}
	}
	std::cout << "error: index \'" << input << "' is not valid. (must be between 0 and 7). " << std::endl;
	return (false);
}


std::string	PhoneBook::trimWhiteSpaces(std::string str) {
	std::string	blank = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(blank);
	end = str.find_last_not_of(blank);
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}


bool 	PhoneBook::addContact(void) {
	std::string	input;

	incrementIndex();
	std::cout << std::endl << "time to make a new contact! 📚📞" << std::endl << std::endl;
	std::cout << "just fill in the details below to get started:\n\n" << std::endl;
	while (!_abort) {
		input = getNewInput("\033[1mfirst name\033[0m:");
		if (_abort || this->contactList[currentContactIndex].setFirstName(input))
			break ;
	}
	while (!_abort) {
		input = getNewInput("\033[1mlast name\033[0m:");
		if (_abort || this->contactList[currentContactIndex].setLastName(input))
			break ;
	}
	while (!_abort) {
		input = getNewInput("\033[1mnickname\033[0m:");
		if (_abort || this->contactList[currentContactIndex].setNickname(input))
			break ;
	}
	while (!_abort) {
		input = getNewInput("\033[1mphone number\033[0m:");
		if (_abort || this->contactList[currentContactIndex].setPhoneNumber(input))
			break ;
	}
	while (!_abort) {
		input = getNewInput("\033[1mdarkest secret\033[0m:");
		if (_abort || this->contactList[currentContactIndex].setDarkestSecret(input))
			break ;
	}
	if (_abort) {
		_abort = false;
		return (false);
	}
	std::cout << "\ncontact successfully added! 👤✅ " << std::endl;
	return (true);
}

void	PhoneBook::printContact(int contactIndex) const {
	if (contactIndex >= 0 && contactIndex <= 7) {
		if (this->contactList[contactIndex].printContactEntry())
			return ;
	}
	std::cout << "error: no entry for this contact." << std::endl;
}

bool	PhoneBook::searchContact(void) {
	std::string	input;

	if (currentContactIndex == -1) {
		std::cout << "\n\033[1;31merror\033[0m: please \033[1mADD\033[0m a contact before \033[1mSEARCH\033[0ming" << std::endl;
		return (true);
	}
	std::cout << std::endl << "searching for a contacts! 🔍📞" << std::endl << std::endl;
	this->printContactList();
	input = getNewInput("enter the index of the contact you would like to view:\n");
	if (input.empty())
		return (false);
	this->printContactByIndex((std::string const)input);
	return (true);
}

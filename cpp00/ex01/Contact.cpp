#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") { return ;}
Contact::~Contact(void) { return ;}


std::string const	Contact::getFirstName(void) const { return (this->firstName); }
std::string const	Contact::getLastName(void) const { return (this->lastName); }
std::string const	Contact::getNickname(void) const { return (this->nickName); }
std::string const	Contact::getPhoneNumber(void) const { return (this->phoneNumber); }
std::string const	Contact::getDarkestSecret(void) const { return (this->darkestSecret); }


bool	Contact::setFirstName(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!isOnlyLetters(str)) {
		std::cout << "\033[1;31merror\033[0m: name may only include letters, spaces, and hyphens." << std::endl;
		return (false);
	}
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		*it = std::toupper(*it);
	}
	this->firstName = str;
	return (true);
}

bool	Contact::setLastName(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!isOnlyLetters(str)) {
		std::cout << "\033[1;31merror\033[0m: name may only include letters, spaces, and hyphens." << std::endl;
		return (false);
	}
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		*it = std::toupper(*it);
	}
	this->lastName = str;
	return (true);
}

bool	Contact::setNickname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!isOnlyLetters(str)) {
		std::cout << "\033[1;31merror\033[0m: nickname may only include letters, spaces, and hyphens." << std::endl;
		return (false);
	}
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		*it = std::toupper(*it);
	}
	this->nickName = str;
	return (true);
}

bool	Contact::setPhoneNumber(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!isOnlyDigits(str)) {
		std::cout << "\033[1;31merror\033[0m: phone number may only include digits, spaces, and hyphens." << std::endl;
		return (false);
	}
	this->phoneNumber = str;
	return (true);
}

bool	Contact::setDarkestSecret(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	this->darkestSecret = str;
	return (true);
}

bool	Contact::isContactEmpty(void) const {
	if (this->firstName.empty()
		|| this->lastName.empty()
		|| this->nickName.empty()
		|| this->phoneNumber.empty()
		|| this->darkestSecret.empty())
		return (true);
	return (false);
}

bool	Contact::isOnlyLetters(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isalpha(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

bool	Contact::isOnlyDigits(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isdigit(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}


bool	Contact::printContactEntry(void) const {
	if (this->isContactEmpty())
		return (false);
	std::cout	<< "\n\033[1mfirst name\033[0m\t: "	<< this->getFirstName()	<< std::endl
				<< "\033[1mlast name\033[0m\t: "	<< this->getLastName()	<< std::endl
				<< "\033[1mnickname\033[0m\t: "		<< this->getNickname()	<< std::endl
				<< "\033[1mphone number\033[0m\t: "	<< this->getPhoneNumber() 	<< std::endl
				<< "\033[1mdarkest secret\033[0m\t: "	<< this->getDarkestSecret()	<< std::endl;
	return (true);
}

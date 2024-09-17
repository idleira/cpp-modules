#include "Contact.hpp"

//constructor to initialize Contact object to empty strings
Contact::Contact(): firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

//return the value of the private variables (read-only)
std::string Contact::getFirstName(void) { return firstName; }

std::string Contact::getLastName(void) { return lastName; }

std::string Contact::getNickname(void) { return nickname; }

std::string Contact::getPhoneNumber(void) { return phoneNumber; }

std::string Contact::getDarkestSecret(void) { return darkestSecret; }

//set the value of the private variables (modify)
void Contact:: setFirstName(std::string new_firstName) { firstName = new_firstName; }

void Contact:: setLastName(std::string new_lastName) { lastName = new_lastName; }

void Contact:: setNickname(std::string new_nickname) { nickname = new_nickname; }

void Contact:: setPhoneNumber(std::string new_phoneNumber) { phoneNumber = new_phoneNumber; }

void Contact:: setDarkestSecret(std::string new_darkestSecret) { darkestSecret = new_darkestSecret; }

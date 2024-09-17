#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>

class Contact;
class PhoneBook						// manages collection of contacts
{
	private:
		Contact contacts[8];		// array of 8 contacts
		int		contactIndex;		// index of the contact to be added

	public:
		PhoneBook(void);			// constructor to initialize PhoneBook object

		void addContact(void);
		void searchContact(void);
		// void printContact(void);
		// void printPhoneBook(void);
		
		Contact getContact(int contactIndex);		// function to get a Contact from contacts array
};


#endif

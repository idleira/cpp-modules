#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>

std::string getInput(const std::string& fieldName);
std::string shortenContact(const std::string& input);
class PhoneBook						// manages collection of contacts
{
	private:
		Contact contacts[8];		// array of 8 contacts
		int		contactIndex;		// index of the contact to be added
		int		contactCount;		// index to help keep number of contacts under 8
	public:
		PhoneBook(void);			// constructor to initialize PhoneBook object

		void addContact(void);
		void searchContact(void);
		void printContact(void);
		void printPhoneBook(void);
		
		void	incrementIndex( void );
		void	incrementCount( void );

		bool	isValidIndex( const std::string& );
};


#endif

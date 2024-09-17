#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactIndex;

	public:
		PhoneBook(void);

		void addContact(void);
		void searchContact(void);
		void printContact(void);
		void printPhoneBook(void);
		
		Contact getContact(int contactIndex);
};


#endif
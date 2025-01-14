#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class	PhoneBook {
	private:
		int		currentContactIndex;
		bool	_abort;
		Contact	contactList[8];

		std::string	getNewInput(std::string const prompt);
		void		incrementIndex(void);
		bool		printContactByIndex(std::string const input) const;
		void		printContactList(void) const;
		void		printContactToList(int const contactIndex) const;
		void		printListString(std::string str) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		std::string	trimWhiteSpaces(std::string str);
		bool		addContact(void);
		void		printContact(int contactIndex) const;
		bool		searchContact(void);
};

#endif
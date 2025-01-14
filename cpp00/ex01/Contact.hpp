#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

		bool		isOnlyLetters(std::string const input);
		bool		isOnlyDigits(std::string const input);
	
	public:
		Contact(void);
		~Contact(void);

		bool				isContactEmpty(void) const;
		std::string const	getFirstName(void) const;
		std::string const	getLastName(void) const;
		std::string const	getNickname(void) const;
		std::string const	getPhoneNumber(void) const;
		std::string const	getDarkestSecret(void) const;
		bool				setFirstName(std::string str);
		bool				setLastName(std::string str);
		bool				setNickname(std::string str);
		bool				setPhoneNumber(std::string const str);
		bool				setDarkestSecret(std::string const str);
		bool				printContactEntry(void) const;
};

#endif
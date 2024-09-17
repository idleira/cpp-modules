#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact(void);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);

		void setFirstName(std::string new_firstName);
		void setLastName(std::string new_lastName);
		void setNickname(std::string new_nickname);
		void setPhoneNumber(std::string new_phoneNumber);
		void setDarkestSecret(std::string new_darkestSecret);

};

#endif
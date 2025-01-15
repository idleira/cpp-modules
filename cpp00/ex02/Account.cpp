#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = this->getNbAccounts();
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
}

int Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	if (deposit <= 0)
	{
		std::cout << "index:" << _accountIndex << "p_amount:" << _amount << ";deposit:refused" << std::endl;
		return;
	}
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" << _accountIndex << "p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << "p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex << "p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

int Account::checkAmount( void ) const {
	return (this->_amount);
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	time_t now = time(0);
	tm *time = localtime(&now);
	std::cout << "[" << time->tm_year + 1900 << time->tm_mday << time->tm_mon + 1 << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] "; 
}

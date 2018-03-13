/*
 * Account.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: keith
 */

#include "Account.h"

Account::Account(int initial_balance) {
	this->balance = initial_balance;
}

Account::~Account() {
}

void Account::withdraw(double amount) {
	balance -= amount;
}

void Account::deposit(double amount) {
	balance += amount;
}



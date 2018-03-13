/*
 * Account.h
 *
 *  Created on: Feb 26, 2018
 *      Author: keith
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <mutex>

class Account {
public:
	Account(int initial_balance);
	virtual ~Account();
	void deposit(double amount);
	void withdraw(double amount);
	inline int getBalance(){return balance;}
	inline void lock(){m.lock();}
	inline void unlock(){m.unlock();};
private:
	int balance;
	std::mutex m;
};



#endif /* ACCOUNT_H_ */

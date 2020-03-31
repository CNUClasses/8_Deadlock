//============================================================================
// Name        : 8_Deadlock.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#include "Account.h"

//globals
Account a1(100000);
Account a2(100000);

//a bit of a bomb, just reverse the accounts and it deadlocks
void transfer(Account &from, Account &to, int amount) {
	from.lock();
	to.lock();
	
	if(from.getBalance()>=amount){
		from.withdraw(amount);
		to.deposit(amount);
	}
	
	from.unlock();	
	to.unlock();
}

void fun1(int amount, int numbiterations){
	while (numbiterations > 0) {
		transfer(a1, a2, amount);
//		transfer(a2, a1, amount);	//add this and it will deadlock every time
		numbiterations--;
	}
}

int main() {
	cout << "Initial balance =" << to_string(a1.getBalance() + a2.getBalance())
			<< endl;
	
	thread t1(fun1,1,100000);
	thread t2(fun1,-1,100000);

	t1.join();
	t2.join();	
	
	cout << "Final balance =" << to_string(a1.getBalance() + a2.getBalance())
			<< endl;
}

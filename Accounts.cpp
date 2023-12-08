/**********************************************
 * Accounts.cpp
 * Created by Ryan Aljaari
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Accounts.h"

/**********************************************
 * Constructor
 **********************************************/
account::account(string argf, string argl, int long phoneNum, string email, string addressName, float money)
{ 
  first = argf;
  last = argl;
  phone = phoneNum;
  mail = email;
  address = addressName;
  next = NULL;
  balance = money;
  id = -1;
  // increment account_lists based on how many times the constructor is called upon
}

/**********************************************
 * Destructor
 **********************************************/
account::~account()
{ 
  if(next!=NULL) delete next;
}



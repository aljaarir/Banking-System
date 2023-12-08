/**********************************************
 * Bank.cpp
 * Created by Ryan Aljaari
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Bank.h"

/**********************************************
 * Constructor
 **********************************************/
bank::bank() 
{
  head = NULL; // bank starts empty
}

/**********************************************
 * Destructor
 **********************************************/
 bank::~bank()
{
  while(head!=NULL) delete [] head;
  // replace map not an array, just the head pointer.  When you delete it, the destructor for the first account is called, which deletes the next account, and so on.
}


/**********************************************
 * insert()
 **********************************************/
bool bank::insert(string argf, string argl, long int phone, string email, string address, float balance)
{
  //First, create a new account, using argf,argl,arga
  account *p = new account(argf, argl, phone, email, address, balance);
  account *q; //traversal node


  //Head is null, set head = p
  if (head == NULL) 
  {
    p->next = head; //makes new account point to head
    head = p; //make new account the head of the bank
    p->id = length(); //sets their id to be the new size of linked list
    cout << "Your account number is: " << p->id << endl;
    return true; // insertion successful
  }
  q = head;
//** P goes at end of list
  while(q != NULL) // goes until end of list
    {
      q = q->next; //moves q forward one
    }
    q->next = p;
    p->id = length(); //sets their id to be the new size of linked list
    cout << "Your account number is: " << p->id << endl;
  return true;
  
}





/**********************************************
 * find()
 **********************************************/
account* bank::find(int argID)
{ 
  
  account *p = head; //sets pointer to head


  while(p!=NULL) //while pointer has a connecting node
    {
      if(p->id == argID) //checks node values to see if there is a match
      {
        return p;
      }
      p = p->next; //moves onto next node
    }
  return NULL;
}





/**********************************************
 * length()
 **********************************************/
int bank::length()
{ 
  int counter(0);
  account *p;

  p = head;

  while(p!=NULL)
  {
    p = p->next;
    counter++;
  }
  return counter;
}


/**********************************************
 * Withdraw()
 **********************************************/
bool bank::withdraw(int acc_num, int money)
{
  account* p = find(acc_num);
  if( money <= 0)
  {
    cout << "You cannot withdraw a negative amount, please try again." << endl;
    return false;
  }

  if(p != NULL)
  {
    if(money > p->balance)
    {
      return false;
    }
    p->balance -= money;
    cout << "Transaction has been completed, your new balance is: $" << p->balance << endl;
    return true;
  }
  else return false;
  cout << "Unable to process your transaction, please check if you have enough funds. " << endl;
}

/**********************************************
 * Deposit()
 **********************************************/
bool bank::deposit(int acc_num, int money)
{
  account* p = find(acc_num);
  if( money <= 0)
  {
    cout << "You cannot deposit a negative amount, please try again." << endl;
    return false;
  }

  if(p != NULL)
  {
    if(money > 0)
      {
        p->balance += money;
        cout << "Transaction has been completed, your new balance is: $" << p->balance << endl;
        return true;
      }
    else
      {
        cout << "Improper funding input, please try again.";
        return false;
      }
  }
  cout << "Unable to process your transaction, try again. " << endl;
  return false;

}

/**********************************************
 * balance()
 **********************************************/
float bank::balance(int acc_num)
{
  account* p = find(acc_num);

  if(p != NULL)
  {
    return p->balance;
  }
  return -1.00;
}

/***********************************
 * Bank Class Declaration
 * Written by Ryan Aljaari
 ***********************************/

#include "Accounts.h" //data class

class bank
{ 
  public:
    bank(); // Null constructor
    ~bank(); // destructor
    bool insert(string argf, string argl, long int phone, string email, string address, float balance); 
    account* find(int argID);  //goes through and finds the node that matches and then we can use the put() to display the correct node data
    bool withdraw(int acc_num, int money);
    bool deposit(int acc_num, int money);
    float balance(int acc_num);
    bool remove(string argf, string argl);  // bool bc we need to see if even in  & able to successfully remove
    int length();
; // Extra Credit

  private:
    account *head; // indicate the first node in a list.
};

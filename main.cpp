/**********************************************
 * Banking System simulation by Ryan Aljaari
 **********************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#include "Bank.h"

void display(ostream &out);
bool check_strvalue(string str);
bool check_intvalue(long int arg);
void clearScreen();


int main()
{
  int option(0), account_num(-1), counter(0);
  float money(0), b;
  long int phone_number;
  string fname, lname, address, email, s;
  bank CapitalOne;

  cout << "****************************************************" << endl;
  cout << "*                   Welcome to                     *" << endl;
  cout << "*                Capital One Bank                  *" << endl;
  cout << "****************************************************" << endl;
  //prompt user to choose an option
  display(cout);
  cin >> option;
  cout << endl << flush;
  clearScreen();

  while(option != 6)
    {

      if(option == 1) //opening new account
      {
        cout <<"Please enter your first name: ";
        cin >> fname;
        counter = 0;
        while(check_strvalue(fname) == true && counter < 3) //error check
        {
          cout << "Please re-enter your first name: ";
          cin >> fname;
          counter++;
          check_strvalue(fname);
        }
        cout << endl << "Please enter your last name: ";
        cin >> lname;
        counter = 0;
        while(check_strvalue(lname) == true && counter < 3) //error check
        {
          cout << "Please re-enter your last name: ";
          cin >> lname;
          counter++;
          check_strvalue(lname);
        }
        cout << endl << "Please enter your phone number: ";
        cin >> phone_number; //needs error check
        counter = 0;
        while(check_intvalue(phone_number) == false && counter < 3) //error check
        {
          cout << "Please re-enter your phone number: ";
          cin >> phone_number;
          counter++;
          check_intvalue(phone_number);
        }
        cout << endl << "Please enter your email: ";
        cin >> email;
        counter = 0;
        while(check_strvalue(email) == true && counter < 3) //error check
        {
          cout << "Please re-enter your email: ";
          cin >> email;
          counter++;
          check_strvalue(email);
        }
        cout << endl << "Please enter your home address: ";
        cin >> address;
        counter = 0;
        while(check_strvalue(address) == true && counter < 3) //error check **needs work
        {
          cout << "Please re-enter your address: ";
          cin >> address;
          counter++;
          check_strvalue(address);
        }
        cout << "Would you like to deposit money into this account?: Y/N ";
        cin >> s;
        if( s == "Y" or s == "y")
        {
          cin >> money;
        }
        else money = 0;
        
        CapitalOne.insert(fname,lname,phone_number,email,address,money);
        cout << "Is there anything else we can help you with?: (Y/N)";
        cin >> s;
        if( s == "Y" or s == "y")
        {
          clearScreen();
          display(cout);
          cin >> option;
        }
        else option = 6;
      }
      else if( CapitalOne.length() > 0) //if bank has no accounts, you cannot run other options until an account is created
      {
        if(option == 2) //checking account info
          {
            cout << "Please enter your account number: ";
            cin >> account_num;
            CapitalOne.find(account_num);
            cout << "Is there anything else we can help you with?: (Y/N)";
            cin >> s;
            if( s == "Y" or s == "y")
            {
              clearScreen();
              display(cout);
              cin >> option;
            }
            else option = 6;
          }
        else if(option == 3) //withdrawing funds
          {
            cout << "Please enter your account number: ";
            cin >> account_num;
            cout << endl << "Please enter the amount you would like to withdraw: ";
            cin >> money;
            // call  function
            CapitalOne.withdraw(account_num,money);
            cout << "Is there anything else we can help you with?: (Y/N)";
            cin >> s;
            if( s == "Y" or s == "y")
            {
              clearScreen();
              display(cout);
              cin >> option;
            }
            else option = 6;
          }
        else if(option == 4) //depositing funds
          {
            cout << "Please enter your account number: ";
            cin >> account_num;
            cout << endl << "Please enter the amount you would like to deposit: ";
            cin >> money;
            // call function
            CapitalOne.deposit(account_num,money);
            cout << "Is there anything else we can help you with?: (Y/N)";
            cin >> s;
            if( s == "Y" or s == "y")
            {
              clearScreen();
              display(cout);
              cin >> option;
            }
            else option = 6;
          }
        else if(option == 5) //check balance info
          {
            cout << "Please enter your account number: ";
            cin >> account_num;
            b = CapitalOne.balance(account_num);
            cout << " Your current balance is: $" << b << endl << flush;
            usleep(2000000); //sleeps for 2 seconds
            cout << "Is there anything else we can help you with?: (Y/N)";
            cin >> s;
            if( s == "Y" or s == "y")
            {
              clearScreen();
              display(cout);
              cin >> option;
            }
            else option = 6;
          }
      }

      else if(CapitalOne.length() <= 0)      //no accounts error response
      {
      cout << "There are currently no accounts stored in our database, please create one. " << endl << endl;
      usleep(2000000); //sleeps for 2 seconds
      display(cout);
      cin >> option;
      }
  }
   
  if(option == 6) 
  {
    cout << endl << "Have a great rest of your day!";
  }
}


/**********************************************
 * display()
 **********************************************/
void display(ostream &out)
{

  cout<<"PRESS 1 TO OPEN NEW ACCOUNT"<<endl;
  cout<<"PRESS 2 TO CHECK YOUR ACCOUNT INFO"<<endl;
  cout<<"PRESS 3 TO WITHDRAW AMOUNT"<<endl;
  cout<<"PRESS 4 TO DEPOSIT AMOUNT"<<endl;
  cout<<"PRESS 5 TO CHECK YOUR BALANCE INFO"<<endl;
  cout<<"PRESS 6 TO EXIT"<<endl<<endl;

  cout <<"CHOOSE AN OPTION: ";
}

/**********************************************
 * check_strvalue(string str)
 **********************************************/
bool check_strvalue(string str) 
{
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
      cout << "Please try again & enter a valid input: " << endl; 
}
/**********************************************
 * check_intvalue(long int arg)
 **********************************************/
bool check_intvalue(long int arg) 
{
    string str = to_string(arg); //creates a string from input
    for (char ch : str) // for every character in string
    {
        if (!isdigit(ch)) 
        {
            cout << "Please try again & enter a valid input: " << endl;
            return false;
        }
    }

    return true; //else return true
}

/**********************************************
 * clearScreen()
 **********************************************/
void clearScreen() 
{
    cout << "\033[2J\033[1;1H";  // ANSI escape code to clear screen
}

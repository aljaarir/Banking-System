/********************************
* Accounts.h
* Written by Ryan Aljaari
********************************/

class account
  { 
    friend class bank;
  
    public:
        account(string argf = "", string argl = "", int phone = 0, string email = "", string address = "", float balance = 0.0F);  // Default constructor -- Creates account
        ~account();                                         // Destructor 


      private:
        string first,last, mail, address;
        float balance;
        int id, phone;
        account *next;
  };

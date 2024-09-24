#include<iostream>
#include<string>
using namespace std;

string Username, Password;
void NewRegister();
bool validEmail(string);
bool validfirstname(string);
bool validlastname(string);
bool validpassword(string);
void verificationcode();
void Login();

int main()
{
    cout << "Hey.." << endl;
    cout << "Welcome to our website!" << endl;
    cout << "Let's begin the journey.." << endl
         << endl;
    
    NewRegister();
    return 0;

}


void NewRegister()
{
    string NewRegister, firstname, lastname,email;
    

    cout<<"New Register?  \n(Note; type yes/no) \n";
    cin>>NewRegister;
    cin.ignore();

    if(NewRegister == "Yes" || NewRegister == "yes")
    {
        cout<< "Enter your first name: ";
        cin>>firstname;

        while(validfirstname(firstname)==false)
        {
            cout<<"The first name is not valid, try again :"<<endl;
            cin>>firstname;
        }

        cout<<endl<<"Valid first name."<<endl
        <<endl;

    
        cout<<"Enter your last name: ";
        cin>>lastname;
        
        while(validlastname(lastname)==false)
        {
            cout<<"The last name is not valid, try again : "<<endl;
            cin>>lastname;
        }

        cout<<endl
            <<"Valid last name."<<endl
            <<endl;

        cout<<"Enter your Email: ";
        cin>>email;

        while(validEmail(email)==false)
        {
            cout<<"The email is not valid, try again : "<<endl;
            cin>>email;

        }

        cout<<endl<<"Valid email address."<<endl<<endl;


        cout<<"Enter your username: ";
        cin>>Username;
        cout<<endl<<endl;


        cout<<"Enter your password: \n(Note: your password must be at least one digit, one uppercase letter, one number, one special character )\n";
        cin>>Password;

        while(validpassword(Password)==false)
        {
            cout<<"The password is not valid, try again   \n(Note: your password must be at least one digit,one special character, one uppercase letter, and one lowercase letter) \n";
            cin>>Password;
        }

        cout<<endl<<"Valid password."<<endl
        <<endl;

        cout<<"Registration completed \n";

        verificationcode();    



    }else if(NewRegister == "No" || NewRegister == "no")
        {
            string username, password;

            cout<<endl<<"              Log in            "<<endl<<endl;

            cout<<"Enter your username :" <<endl;
            getline(cin,username);
            cout<<"Enter your password :"<<endl;
            cin>>password;

            cout<<endl
                << "Login success"<<endl;
        }

    
}

bool validfirstname(string firstname)
{
    if(firstname[0]>='A' && firstname[0]<='Z')
        return true;
    return false;
}
bool validlastname(string lastname)
{
    if(lastname[0]>='A' && lastname[0]<='Z')
        return true;
    return false;
}

bool validEmail(string email)
{
    int AT=-1, dot=-1,counterforAT=0,counterfordot=0;

    if((email[0]>='a' && email[0]<='z' ) || (email[0]>='A' && email[0]<='Z') )
    {
        for(int i=0;i<email.length();i++)
        {
            if(email[i]=='@' )
            {
                AT=i;
                ++counterforAT;
            }
            else if(email[i]=='.')
            {
                dot=i;
                ++counterfordot;

            }
        }

        if(AT==-1 || dot==-1)
        return false;

        if(AT>dot)
        return false;

        if(counterforAT>1 || counterfordot>1)
            return false;

        return !(dot>=(email.length()-1));
    }
    else if(email[0]>='0' && email[0]<='9')
            return false;
        else
            return false;
}


bool validpassword(string password)
{
    int digit=0, uppercase=0, lowercase=0, specialchar=0;
    if(password.length()>=8 && password.length()<=15)
    {
        if(password.find(" ") == -1)
        {
            for(int i=0;i<password.length();i++)
                {
                    if(password[i]>='0' && password[i]<='9')
                        ++digit;
                    else if(password[i]>='A' && password[i]<='Z')
                        ++uppercase;
                    else if(password[i]>='a' && password[i]<='z')
                        ++lowercase;
                    else if (password[i] == '@' || password[i] == '#' || password[i] == '_')
                         ++specialchar;
                
                }
            if(digit == 0 || uppercase == 0 || lowercase == 0 || specialchar == 0)
        {
            return false;
        }
        else
        return true;
        } else if(password.find(" ")!=-1)
        return false;
    }

    cout<< "Note: your password ylength is less than 8 or more than 15 characters"<<endl;
    return false;
}

void verificationcode() // verifying account
{
    int code ;
    cout<<endl<<endl;

    cout<<"We have sent a verification code to your email to confirm your account." << endl
         <<"Please check your email."<<endl;

  
     cout<<"Email message: Your verification code is  ";
    srand(time(0));

	for (int i = 0; i <= 3; i++)
	{
		cout<<rand() % 10 ;
	}
    cout<<"\n";

    cout<<endl<<endl;

    cout<<"Enter the verification code here : \n";
	cin>>code;

    cout<<endl;

    cout<<"Your account has been verified."<<endl;
    Login();
}

void Login()
{
    string usernamelog,passwordlog;

    cin.ignore();
    cout<<endl<<"            Log in         "<<endl<<endl;
    cout<<"Enter your Username: "<<endl;
    getline(cin,usernamelog);

    cout<<"Enter your password:"<<endl;

    cin>>passwordlog;

    if(Username==usernamelog && Password == passwordlog)
          cout<<endl<<"Log in successs!"<<endl;
    else{
        cout<<"Username or password wrong, try again";
        Login();
    }
}





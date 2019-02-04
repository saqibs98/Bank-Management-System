#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<windows.h>
using namespace std;
void Goto(int x,int y)
{
	HANDLE console_handle;
	COORD cur_cord;
	console_handle = GetStdHandle( STD_OUTPUT_HANDLE );
	cur_cord.X = x;
	cur_cord.Y = y;
	SetConsoleCursorPosition(console_handle,cur_cord);
}
void main()
{
	Main:
	system("COLOR 80");
	cout<<"\n\n\n\t\t\t\t\t  ##########################################"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"\t\t\t\t\t  #                                        #"<<endl;	
	}
	cout<<"\t\t\t\t\t  ##########################################"<<endl;
	Goto(53,4);
	cout<<"BANK";
	Goto(58,5);
	cout<<"MANAGEMENT";
	Goto(68,6);
	cout<<"SYSTEM";
	Goto(58,10);
	cout<<"MAIN MENU";
	Goto(30,14);
	cout<<"01. NEW ACCOUNT";
	Goto(30,17);
	cout<<"02. DEPOSIT AMMOUNT";
	Goto(30,20);
	cout<<"03. WITHDRAW AMMOUNT";
	Goto(30,23);
	cout<<"04. BALANCE ENQUIRY";
	Goto(75,14);
	cout<<"05. ALL ACCOUNT HOLDER LIST";
	Goto(75,17);
	cout<<"06. CLOSE AN ACCOUNT";
	Goto(75,20);
	cout<<"07. MODIFY AN ACCOUNT";
	Goto(75,23);
	cout<<"08. EXIT";
	Goto(52,12);
	cout<<"SELECT YOUR OPTION<1-8>";
	int choice;
	cin>>choice;
	system("cls");
	ofstream myFile; 
	myFile.open("Accounts.txt", ios::app);
	myFile.close();
	if (choice == 1)
	{
	
		string name1,name2,account;
		char type;
		int accountNo,amount;
		cout<<"\n\n\t\t\t\t\t----NEW ACCOUNT ENTRY FORM----\n";
	Up1:
		cout<<"\n\tEnter The Account Number : ";
		cin>>accountNo;
		cin.ignore();
		account = to_string(accountNo);
		if(account.length()>5)
		{
			system("cls");
			do
			{
				cout<<"\n\n\t\t\t\t\t----NEW ACCOUNT ENTRY FORM----\n";
				cout<<"\n\tPlease Enter A Valid Account Number : ";
				cin>>accountNo;
				cin.ignore();
				account = to_string(accountNo);
			}while(account.length()>5);
		}
		ifstream myFile;
		myFile.open("Accounts.txt", ios::app);
		for(int i=0; !myFile.eof(); i+=47)
		{
			myFile.seekg(i , ios::beg);
			int number;
			myFile>>number;
			if(accountNo == number)
			{
				system("cls");
				cout<<"\n\n\t\t\t\t\t----NEW ACCOUNT ENTRY FORM----\n";
				cout<<"\n\tSorry This Account Number Is Already In Use!";
				cout<<"\n\t";
				goto Up1;
			}
		}
		cout<<"\n\tEnter First Name Of The Account Holder : ";
		getline(cin,name1);
		cout<<"\n\tEnter Last Name Of The Account Holder : ";
		getline(cin,name2);
		cout<<"\n\tEnter Type Of The Account <C/S> : ";
		cin>>type;
		if(type>=97 && type<=122)
		{
			type = type - 32;
		}
		cout<<"\n\tEnter Initial Amount\n\t>=500 For Saving >=1000 For Current : ";
		cin>>amount;
		if(type == 'S'&& amount < 500 )
		{
			do
			{
				cout<<"\n\tPlease Enter Amount >=500 For Saving Account : ";
				cin>>amount;
			}while(amount < 500);
		}
		if(type == 'C' && amount < 1000)
		{
			do
			{
				cout<<"\n\tPlease Enter Amount >=1000 For Current Account : ";
				cin>>amount;
			}while(amount < 1000);
		}
		cout<<"\n\t\"Your Account Has Been Created Successfully!\""<<endl;
		ofstream File;
		File.open("Accounts.txt",ios::app);
		File<<setw(5)<<left<<accountNo<<setw(10)<<left<<name1<<setw(10)<<left<<name2<<setw(10)<<left<<type<<setw(10)<<left<<amount<<endl;
		File.close();
		char ch;
		cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
		cin>>ch;
		if(ch == 'M' || ch== 'm')
		{
			system("cls");
			goto Main;
		}
		else
		{
			cout<<"\t";
		}
	}
	else if(choice == 2)
	{
		int accountNo;
		string account;
		cout<<"\n\n\t\t\t\t\t----ACCOUNT TRANSACTION FORM----\n";
	Up2:
		cout<<"\n\tEnter The Account No. : ";
		cin>>accountNo;
		account = to_string(accountNo);
		if(account.length()>5)
		{
			system("cls");
			do
			{
				cout<<"\n\n\t\t\t\t\t----ACCOUNT TRANSACTION FORM----\n";
				cout<<"\n\tPlease Enter A Valid Account Number : ";
				cin>>accountNo;
				cin.ignore();
				account = to_string(accountNo);
			}while(account.length()>5);
		}
		fstream myFile;
		myFile.open("Accounts.txt", ios::in | ios::out );
		string name1,name2;
		char type;
		int amount,deposit;
		int a=0;
		for(int i=0; !myFile.eof(); i+=47)
		{
			int number;
			myFile.seekg(i,ios::beg);
			myFile>>number;
			if(accountNo == number)
			{
				a++;
				myFile>>name1;
				myFile>>name2;
				myFile>>type;
				myFile>>amount;
				cout<<"\n\n\t\t\t\t\t  ----ACCOUNT STATUS----\n";
				cout<<"\n\tAccount No. : "<<accountNo;
				cout<<"\n\tAccount Holder Name : "<<name1<<" "<<name2;
				cout<<"\n\tType of Account : "<<type;
				cout<<"\n\tBalance Amount : "<<amount;
				cout<<"\n\tEnter The Amount To DEPOSIT : ";
				cin>>deposit;
				amount = amount + deposit;
				myFile.seekp(i+=35 , ios::beg);
				myFile<<setw(10)<<left<<amount;
				cout<<"\n\n\t\"RECORD UPDATED\"";
				char ch;
				cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
				cin>>ch;
				if(ch == 'M' || ch== 'm')
				{
					system("cls");
					goto Main;
				}
				else
				{
					cout<<"\t";
				}
			}
		}
		if(a==0)
		{
			system("cls");
			cout<<"\n\n\t\t\t\t\t----ACCOUNT TRANSACTION FORM----\n";
			cout<<"\n\t\"Sorry This Account Number Does Not Match Our Record!\"";
			cout<<"\n\t";
			goto Up2;
		}
	}
	else if(choice == 3)
	{
		int accountNo;
		string account;
		cout<<"\n\n\t\t\t\t\t----ACCOUNT TRANSACTION FORM----\n";
	Up3:
		cout<<"\n\tEnter The Account No. : ";
		cin>>accountNo;
		account = to_string(accountNo);
		if(account.length()>5)
		{
			system("cls");
			do
			{
				cout<<"\n\n\t\t\t\t\t----ACCOUNT TRANSACTION FORM----\n";
				cout<<"\n\tPlease Enter A Valid Account Number : ";
				cin>>accountNo;
				cin.ignore();
				account = to_string(accountNo);
			}while(account.length()>5);
		}
		fstream myFile;
		myFile.open("Accounts.txt", ios::in | ios::out );
		string name1,name2;
		char type;
		int amount,withdraw;
		int a=0;
		for(int i=0; !myFile.eof(); i+=47)
		{
			int number;
			myFile.seekg(i,ios::beg);
			myFile>>number;
			if(accountNo == number)
			{
				a++;
				myFile>>name1;
				myFile>>name2;
				myFile>>type;
				myFile>>amount;
				cout<<"\n\n\t\t\t\t\t  ----ACCOUNT STATUS----\n";
				cout<<"\n\tAccount No. : "<<accountNo;
				cout<<"\n\tAccount Holder Name : "<<name1<<" "<<name2;
				cout<<"\n\tType of Account : "<<type;
				cout<<"\n\tBalance Amount : "<<amount;
				cout<<"\n\tEnter The Amount To WITHDRAW : ";
				cin>>withdraw;
				amount = amount - withdraw;
				myFile.seekp(i+=35 , ios::beg);
				myFile<<setw(10)<<left<<amount;
				cout<<"\n\n\t\"RECORD UPDATED\"";
				char ch;
				cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
				cin>>ch;
				if(ch == 'M' || ch== 'm')
				{
					system("cls");
					goto Main;
				}
				else
				{
					cout<<"\t";
				}
			}
		}
		if(a==0)
		{
			system("cls");
			cout<<"\n\n\t\t\t\t\t----ACCOUNT TRANSACTION FORM----\n";
			cout<<"\n\t\"Sorry This Account Number Does Not Match Our Record!\"";
			cout<<"\n\t";
			goto Up3;
		}
	}
	else if (choice == 4)
	{
		int accountNo;
		string account;
		cout<<"\n\n\t\t\t\t\t----BALANCE DETAILS----\n";
	Up4:
		cout<<"\n\tEnter The Account No. : ";
		cin>>accountNo;
		account = to_string(accountNo);
		if(account.length()>5)
		{
			system("cls");
			do
			{
				cout<<"\n\n\t\t\t\t\t----BALANCE DETAILS----\n";
				cout<<"\n\tPlease Enter A Valid Account Number : ";
				cin>>accountNo;
				cin.ignore();
				account = to_string(accountNo);
			}while(account.length()>5);
		}
		fstream myFile;
		myFile.open("Accounts.txt", ios::in | ios::out );
		string name1,name2;
		char type;
		int amount;
		int a=0;
		for(int i=0; !myFile.eof(); i+=47)
		{
			int number;
			myFile.seekg(i,ios::beg);
			myFile>>number;
			if(accountNo == number)
			{
				a++;
				myFile>>name1;
				myFile>>name2;
				myFile>>type;
				myFile>>amount;
				cout<<"\n\n\t\t\t\t\t  ----ACCOUNT STATUS----\n";
				cout<<"\n\tAccount No. : "<<accountNo;
				cout<<"\n\tAccount Holder Name : "<<name1<<" "<<name2;
				cout<<"\n\tType of Account : "<<type;
				cout<<"\n\tBalance Amount : "<<amount;
				char ch;
				cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
				cin>>ch;
				if(ch == 'M' || ch== 'm')
				{
					system("cls");
					goto Main;
				}
				else
				{
					cout<<"\t";
				}
			}
		}
		if(a==0)
		{
			system("cls");
			cout<<"\n\n\t\t\t\t\t----BALANCE DETAILS----\n";
			cout<<"\n\t\"Sorry This Account Number Does Not Match Our Record!\"";
			cout<<"\n\t";
			goto Up4;;
		}
	}
	else if(choice == 5)
	{
		cout<<"\n\n\t\t\t\t\t  ----ACCOUNT HOLDER LIST----\n";
		cout<<"\n    =============================================================================================================";
		cout<<"\n    A/c no.				NAME				TYPE				BALANCE";
		cout<<"\n    =============================================================================================================\n";
		ifstream myFile;
		myFile.open("Accounts.txt");
		string name1,name2;
		int balance,account;
		char type;
		for(int i=0;!myFile.eof();i+=47)
		{
			
			myFile.seekg(i, ios::beg);
			
			myFile>>account;
			if(myFile.eof())
			{
				break;
			}
			myFile>>name1;
			myFile>>name2;
			myFile>>type;
			myFile>>balance;
			cout<<"    "<<account<<"\t\t\t\t\t"<<name1<<" "<<name2<<"\t\t\t\t"<<type<<"\t\t\t\t"<<balance<<"\n";
		}
		char ch;
		cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
		cin>>ch;
		if(ch == 'M' || ch== 'm')
		{
			system("cls");
			goto Main;
		}
		else
		{
			cout<<"\t";
		}
	}
	else if(choice == 6)
	{
		int accountNo;
		string account;
		cout<<"\n\n\t\t\t\t\t----DELETE RECORD----\n";
	Up6:
		cout<<"\n\tEnter The Account No. : ";
		cin>>accountNo;
		account = to_string(accountNo);
		if(account.length()>5)
		{
			system("cls");
			do
			{
				cout<<"\n\n\t\t\t\t\t----DELETE RECORD----\n";
				cout<<"\n\tPlease Enter A Valid Account Number : ";
				cin>>accountNo;
				cin.ignore();
				account = to_string(accountNo);
			}while(account.length()>5);
		}
		fstream myFile;
		myFile.open("Accounts.txt", ios::in | ios::out );
		int a=0;
		for(int i=0; !myFile.eof(); i+=47)
		{
			int number;
			myFile.seekg(i,ios::beg);
			myFile>>number;
			if(accountNo == number)
			{
				a++;
				myFile.seekp(i , ios::beg);
				myFile<<setw(45)<<left<<" ";
				cout<<"\n\n\t\"RECORD DELETED\"";
				char ch;
				cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
				cin>>ch;
				if(ch == 'M' || ch== 'm')
				{
					system("cls");
					goto Main;
				}
				else
				{
					cout<<"\t";
				}
			}
		}
		if(a==0)
		{
			system("cls");
			cout<<"\n\n\t\t\t\t\t----DELETE RECORD----\n";
			cout<<"\n\t\"Sorry This Account Number Does Not Match Our Record!\"";
			cout<<"\n\t";
			goto Up6;
		}
	}
	else if(choice ==7)
	{
		int accountNo;
		string account;
		cout<<"\n\n\t\t\t\t\t----MODIFY RECORD----\n";
	Up7:
		cout<<"\n\tEnter The Account No. : ";
		cin>>accountNo;
		account = to_string(accountNo);
		if(account.length()>5)
		{
			system("cls");
			do
			{
				cout<<"\n\n\t\t\t\t\t----MODIFY RECORD----\n";
				cout<<"\n\tPlease Enter A Valid Account Number : ";
				cin>>accountNo;
				cin.ignore();
				account = to_string(accountNo);
			}while(account.length()>5);
		}
		fstream myFile;
		myFile.open("Accounts.txt", ios::in | ios::out );
		string name1,name2;
		char type;
		int amount,deposit;
		int a=0;
		for(int i=0; !myFile.eof(); i+=47)
		{
			int number;
			myFile.seekg(i,ios::beg);
			myFile>>number;
			if(accountNo == number)
			{
				a++;
				myFile>>name1;
				myFile>>name2;
				myFile>>type;
				myFile>>amount;
				cout<<"\n\n\t\t\t\t\t  ----ACCOUNT STATUS----\n";
				cout<<"\n\tAccount No. : "<<accountNo;
				cout<<"\n\tAccount Holder Name : "<<name1<<" "<<name2;
				cout<<"\n\tType of Account : "<<type;
				cout<<"\n\tBalance Amount : "<<amount;
				cout<<"\n\n\t\t\t\t\t----ENTER THE NEW DETAILS----\n";
				cout<<"\tAccount No. : ";
				cin>>accountNo;
				cout<<"\tAccount Holder First Name : ";
				cin>>name1;
				cout<<"\tAccount Holder Last Name : ";
				cin>>name2;
				cout<<"\tType of Account : ";
				cin>>type;
				cout<<"\tBalance Amount : ";
				cin>>amount;
				myFile.seekp(i , ios::beg);
				myFile<<setw(5)<<left<<accountNo<<setw(10)<<left<<name1<<setw(10)<<left<<name2<<setw(10)<<left<<type<<setw(10)<<left<<amount<<endl;
				cout<<"\n\n\t\"RECORD UPDATED\"";
				char ch;
				cout<<"\n\tIf You Want to go To The Main Again. PRESS M or m : ";
				cin>>ch;
				if(ch == 'M' || ch== 'm')
				{
					system("cls");
					goto Main;
				}
				else
				{
					cout<<"\t";
				}
			}
		}
		if(a==0)
		{
			system("cls");
			cout<<"\n\n\t\t\t\t\t----MODIFY RECORD----\n";
			cout<<"\n\t\"Sorry This Account Number Does Not Match Our Record!\"";
			cout<<"\n\t";
			goto Up7;
		}

	}
	else if(choice == 8)
	{
		system("cls");
	}
}
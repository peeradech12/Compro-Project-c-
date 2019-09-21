#include<iostream>
#include<string>
#include<iomanip>
#include<time.h>
using namespace std;
int login(int,string *Student_ID,string);
void Add_book(unsigned int ISBN[10],string Namebook[10], string Namewriter[10], string Publisher[10],string Year[10],int Quantity_book[10], int &Total_book);
void borrow(int &i, int *Quantity_stu, int Quantity_book[10], int *Total_quantity,int &Total_book,string Namebook[10]);
void Return_book(int &i, int *Quantity_stu, int Quantity_book[10], int *Total_quantity,int &Total_book,string Namebook[10]);
void Report();

int main()
{
	srand(time(NULL));
	int r=0 , BR_Book = 0 ,Quantity_book[10];
	unsigned int ISBN[10];
	string log , Namebook[10],Namewriter[10],Publisher[10],Year[10]; 
	char choose ,chose = ' ';
	bool flag = true;
	int stu_num;
	cout << "Enter of number all student  : ";
	cin >> stu_num;
	string *student_first =  new string [stu_num];
	string *student_last = new string[stu_num];
	string *branch = new string[stu_num];
	string *faculty = new string[stu_num];
	string *Student_ID = new string[stu_num];
	int *Quantity_stu = new int[stu_num]; //number of book to borrow 1 times
	int *Total_quantity = new int[stu_num]; //number of book that student to borrow 
	int Total_book = 0 ;//number of all book borrow to used
	do
	{
		string first = "",last = "", Faculty = "", Branch = "",SID ="";
		
		cout << "////////////////Menu////////////////\n";
		cout << " 1. Register\n";
		cout << " 2. Add book information\n";
		cout << " 3. Borrow a book\n";
		cout << " 4. Return the book\n";
		cout << " 5. Report\n";
		cout << " Q. Exit\n";
		cout << "____________________________\n";
		cout << "Enter Menu : ";
		cin >>choose;
		if (choose == '1')
		{
			char chose;
			int i=1;
			cout<<"--------------Register--------------\n";
			do
			{
				cout << "Input you first name : ";
				cin >> first;
				cout << "Input you last name : ";
				cin >> last;
				cout << "Input you Student ID : ";
				cin >> SID;
				cout << "Input you faculty : ";
				cin >> Faculty;
				cout << "Input you branch : ";
				cin >> Branch;

				cout << "Please check for accuracy.\n";
				cout << "Name : "<< first << " " << last <<endl;
				cout << "Student ID : "<< SID <<endl;
				cout << "Faculty : "<< Faculty <<endl;
				cout << "Branch : "<< Branch <<endl;
				cout << "Press Y(YES) or N(NO) or Press Q to Exit. ";
				cin >>chose;
				
				if (chose == 'Y')
				{
					student_first[r] = first;
					student_last[r] = last;
					faculty[r] = Faculty;
					branch[r] = Branch;
					Student_ID[r] = SID;

					cout<<"\nRegister complate\n";
					r++;
					break;
				}
				else if (chose == 'N')
				{
				cout << "\nPlease try again.\n";
				break;
				}
				
			}while( true);
			{}
		}
		
		else if (choose == '2')
		{
			Add_book(ISBN, Namebook, Namewriter, Publisher, Year, Quantity_book,Total_book);
		}
		
		else if (choose == '3')
		{
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(stu_num,Student_ID,log);
			cout<<"Hello "<<student_first[i]<<" "<<student_last[i]<<"\n\n";
			borrow(i, Quantity_stu, Quantity_book, Total_quantity,Total_book,Namebook);
		}
		
		else if (choose == '4')
		{
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(stu_num,Student_ID,log);
			cout<<"Hello "<<student_first[i]<<" "<<student_last[i]<<"\n\n";
			Return_book(i, Quantity_stu, Quantity_book, Total_quantity,Total_book,Namebook);
		}
		
		else if (choose == '5')
		{
			cout<<"Plest input your student ID: ";
			cin >>log;
			int i = login(stu_num,Student_ID,log);
			cout<<"Hello "<<student_first[i]<<" "<<student_last[i]<<"\n\n";
		}
		
		else if(choose == 'Q')
		{
			cout << "Exit menu...\n";
			flag = false;
		}
	}
	while(flag);
	{ cout << "End program.";}
	return 0;
}

int login(int stu_num,string *Student_ID,string login)
{
	int i;
	for(i=0;i<stu_num;i++)
	{
		if(login == Student_ID[i])
		{
			i = i;
			return i;
			break;
		}
		else if (i == (stu_num-1))
		{
			if(login != Student_ID[i])
			{
			cout << "Please register\n";
			}
		}
	}
}

void Add_book(unsigned int ISBN[100],string Namebook[10], string Namewriter[10], string Publisher[10], string Year[10],int Quantity_book[10],int &Total_book)
{
	for(int i = 0;i < 10;i++)
	{
	ISBN[i] = 1000000000 + rand() % 1000000000; 
	}
	for(int i = 0;i < 10;i++)
	{
	cout << "Enter name of book : ";
	cin >> Namebook[i];
	cout << "Enter name of writer : ";
	cin >> Namewriter[i];
	cout << "Enter publisher of book : ";
	cin >> Publisher[i];
	cout << "Enter years of book";
	cin >> Year[i];
	cout << "Enter quantity of books : ";
	cin >> Quantity_book[i];
	Total_book += Quantity_book[i];
	}
}

void borrow(int &i, int *Quantity_stu, int Quantity_book[10], int *Total_quantity,int &Total_book,string Namebook[10])
{
	char ch,qu;
	for (int j = 0 ;j < 10;j++)
	{
		cout << "No. " << i+1 << Namebook[j] << "amount " << Quantity_book[j] << " book.\n";
	}
	cout << "Enter no. of book to borrow (1-10) : ";
	cin >> ch;
	cout << "Enter quantity of book to borrow : ";
	cin >> qu;
	if (qu == '1')
	{
	Quantity_stu[i] += 1;
	Quantity_book[ch] -= 1;
	Total_quantity[i] +=1;
	Total_book -= 1;
	}
	else if (qu == '2')
	{
	Quantity_stu[i] += 2;
	Quantity_book[ch] -= 2;
	Total_quantity[i] +=2;
	Total_book -= 2;
	}
	else if (qu == '3')
	{
	Quantity_stu[i] += 3;
	Quantity_book[ch] -= 3;
	Total_quantity[i] += 3;
	Total_book -= 3;
	}
}

void Return_book(int &i, int *Quantity_stu, int Quantity_book[10], int *Total_quantity,int &Total_book,string Namebook[10])
{
	
}

void Report()
{

}
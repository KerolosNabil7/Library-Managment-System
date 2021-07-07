#include <iostream>
#include <string>
using namespace std;
const short LIBRARIAN = 4; //four librarains in the library
const int BOOKS = 5;
struct Date
{
	int day, month, year;
};
struct Librarian
{
	string username, password;
};
struct user
{
	int ID;
	string name, username, password, acc_type;
	Date create_date;
	int contact_nums[3];
};
struct book
{
	string Title, category;
	int produc_year, num_copies, edition;
};
Librarian man[LIBRARIAN];
user list_users[100];
book library[BOOKS];
int counter = 0;
bool cheak;
bool Availability;
bool cheak_staff;
short choice;
char answer;
bool sign_aslibrarian(Librarian lib);
void create_acc(user user1);
void sign_asuser(user user1);
void buy_book(book book1, bool test);
void search(book book1);
void view_books();
void print_reports();
int main()
{
	user user1;
	book book1;
	library[0].Title = "Healthcare";
	library[0].produc_year = 2015;
	library[0].num_copies = 10;
	library[0].category = "Healthy";
	library[0].edition = 5;
	library[1].Title = "c++";
	library[1].produc_year = 2010;
	library[1].num_copies = 35;
	library[1].category = "programming";
	library[1].edition = 9;
	library[2].Title = "football";
	library[2].produc_year = 2019;
	library[2].num_copies = 94;
	library[2].category = "sports";
	library[2].edition = 4;
	library[3].Title = "calculus";
	library[3].produc_year = 1999;
	library[3].num_copies = 102;
	library[3].category = "science";
	library[3].edition = 7;
	library[4].Title = "Earth";
	library[4].produc_year = 1998;
	library[4].num_copies = 0;
	library[4].category = "planet";
	library[4].edition = 5;
	man[0].username = "kerolos";
	man[0].password = "1234";
	man[1].username = "mohamed";
	man[1].password = "mohamed2222";
	man[2].username = "alaa";
	man[2].password = "alaa3333";
	man[3].username = "salah";
	man[3].password = "salah4444";
	cout << "Welcome to Management Library System\n\n";
	do
	{

		cout << "log in as\n";
		cout << "1. Librarian\n";
		cout << "2. User(You must have an account)\n";
		cout << "3. Close Application\n";
		cout << "Please Enter your choice number: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Librarian lib;
			do
			{
				sign_aslibrarian(lib);
			} while (cheak == false);
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				create_acc(user1);
				break;
			}
			case 2:
			{
				print_reports();
				break;
			}
			}
			break;
		}
		case 2:
		{
			do
			{
				sign_asuser(user1);
			} while (cheak == false);
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				buy_book(book1, cheak_staff);
				break;
			}
			case 2:
			{
				search(book1);
				break;
			}
			case 3:
			{
				view_books();
				break;
			}
			}
			break;
		}
		case 3:
		{
			return 0;
		}
		}
		cout << "Do you want to continue?(Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
bool sign_aslibrarian(Librarian lib)
{
	cheak = false;
	cout << "Username: ";
	cin >> lib.username;
	cout << "Password: ";
	cin >> lib.password;
	for (int i = 0; i < LIBRARIAN; i++)
		if (lib.username == man[i].username && lib.password == man[i].password)
			cheak = true;
	if (cheak == true)  //if both of username and passeord valid sign in
	{
		cout << "choose what do you want to do\n";
		cout << "1. Create a New Account\n";
		cout << "2. Print reports\n";
		cout << "Please Enter your choice number: ";
	}
	else
	{
		cout << "Invalid! Please re-enter your account\n";
	}
	return cheak;
}
void create_acc(user user1)
{
	do
	{
		counter++;
		cout << "Enter the new user details\n";
		cout << "ID: ";
		cin >> user1.ID;
		cout << "Name: ";
		cin >> user1.name;
		cout << "Username: ";
		cin >> user1.username;
		cout << "Password: ";
		cin >> user1.password;
		cout << "Account Type(student/staff/guest): ";
		cin >> user1.acc_type;
		cout << "Date: ";
		cin >> user1.create_date.day >> user1.create_date.month >> user1.create_date.year;
		cout << "Contact Numbers\n";
		for (int i = 1; i <= 3; i++)
		{
			cout << "Number " << i << ": ";
			cin >> user1.contact_nums[i];
		}
		cout << endl;
		list_users[counter] = user1;
		cout << "Do you want create more accounts?(y/n): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
}
void sign_asuser(user user1)
{
	cheak_staff = false;
	cheak = false;
	cout << "Username: ";
	cin >> user1.username;
	cout << "Password: ";
	cin >> user1.password;
	for (int i = 0; i < counter; i++)
	{
		if (user1.username == list_users[i].username && user1.password == list_users[i].password && list_users[i].acc_type == "staff")
		{
			cheak_staff = true;
			cheak = true;
		}
		else if (user1.username == list_users[i].username && user1.password == list_users[i].password && list_users[i].acc_type == "student")
		{
			cheak = true;
		}
		else if (user1.username == list_users[i].username && user1.password == list_users[i].password && list_users[i].acc_type == "guest")
		{
			cheak = true;
		}
	}
	if (cheak == true)
	{
		cout << "choose what do you want to do\n";
		cout << "1. Buy a Book\n";
		cout << "2. Search for a book\n";
		cout << "3. View Books\n";
		cout << "Please Enter your choice number: ";
	}
	else
	{
		cout << "Invalid! Please re-enter your account\n";
	}
}
void buy_book(book book1, bool test)
{
	Availability = false;
	if (test == true)
	{
		cout << "Enter the name of book you want to buy: ";
		cin >> book1.Title;
		for (int i = 0; i < BOOKS; i++)
		{
			if (book1.Title == library[i].Title && library[i].num_copies > 0) //if the book available 
			{
				Availability = true;
				library[i].num_copies--;   // the purchase is done  then the total of this book -1
			}
		}
		if (Availability == true)
		{
			cout << "The Purchase was done\n";
		}
		else
		{
			cout << "This book is unavailable now\n";
		}
	}
	else
	{
		cout << "This choice is for Staff only\n";
	}
}
void search(book book1)
{
	Availability = false;
	cout << "Search for a book by\n";
	cout << "1. Title\n";
	cout << "2. Production Year\n";
	cout << "Please enter your choice number: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Title: ";
		cin >> book1.Title;
		for (int i = 0; i < BOOKS; i++)
		{
			if (book1.Title == library[i].Title && library[i].num_copies > 0)
				Availability = true;
		}
		if (Availability == true)
		{
			cout << "Available\n";
		}
		else
		{
			cout << "Unavailable\n";
		}
		break;
	}
	case 2:
	{
		cout << "Production Year: ";
		cin >> book1.produc_year;
		for (int i = 0; i < BOOKS; i++)
		{
			if (book1.produc_year == library[i].produc_year && library[i].num_copies > 0)
				Availability = true;
		}
		if (Availability == true)
		{
			cout << "Available\n";
		}
		else
		{
			cout << "Unavialble\n";
		}
		break;
	}
	}
}
void view_books()
{
	cout << "Books\n";
	for (int i = 0; i < BOOKS; i++)
	{
		cout << "Book " << i + 1 << endl;
		cout << "Title: " << library[i].Title << endl;
		cout << "Production Year: " << library[i].produc_year << endl;
		cout << "Number of copies: " << library[i].num_copies << endl;
		cout << "Category: " << library[i].category << endl;
		cout << "Edition: " << library[i].edition << endl;
		cout << endl;
	}
}
void print_reports()
{
	Date today;
	cout << "Today's Date: ";
	cin >> today.day >> today.month >> today.year;
	today.day -= 7;
	for (int i = 0; i <= counter; i++)
	{
		if (list_users[i].create_date.day >= today.day && list_users[i].create_date.month == today.month && list_users[i].create_date.year == today.year)
		{
			cout << "ID: " << list_users[i].ID << endl;
			cout << "Name: " << list_users[i].name << endl;
			cout << "Username: " << list_users[i].username << endl;
			cout << "Password: " << list_users[i].password << endl;
			cout << "Account Type: " << list_users[i].acc_type << endl;
			cout << "Date: " << list_users[i].create_date.day << "/" << list_users[i].create_date.month << "/" << list_users[i].create_date.year << endl;
			cout << "Contact Numbers\n";
			for (int j = 1; j <= 3; j++)
				cout << "Number " << j << ": " << list_users[i].contact_nums[j] << endl;
			cout << endl;
		}
	}
}
/*
Name:			Muhammad Abdullah				Hamza Azeem					Shoaib Malik
Reg:			2020256							2020296						2020223
*/


#include <iostream>
#include <iomanip>

using namespace std;

class CBook
{
public:
	//constructors
	CBook()
	{
		this->ID = 100;
		this->price = 2000;
		this->pages = 200;

		this->IssuedBy = "Oxford";
		this->IssuedOn = "27/02/2018";
		this->BookName = "DefaultBook";
		this->author = "DefaultAuthor";
		this->ISBN = "1a2s3d";
		this->ReturnDate = "27/03/2020";
	}

	CBook(int ID, int price, int pages, int IssuedBy, string IssuedOn, string BookName, string author, string ISBN, string ReturnDate)
	{
		this->ID = ID;
		this->price = price;
		this->pages = pages;
		this->IssuedBy = IssuedBy;

		this->IssuedOn = IssuedOn;
		this->BookName = BookName;
		this->author = author;
		this->ISBN = ISBN;
		this->ReturnDate = ReturnDate;
	}

	//destructor
	~CBook() {}


	//setter functions
	void setID(int ID) { this->ID = ID; }

	void setPrice(int price) { this->price = price; }

	void setPages(int pages) { this->pages = pages; }

	void setIssuedBy(string IssuedBy) { this->IssuedBy = IssuedBy; }

	void setIssuedOn(string IssuedOn) { this->IssuedOn = IssuedOn; }

	void setBookName(string BookName) { this->BookName = BookName; }

	void setAuthor(string author) { this->author = author; }

	void setISBN(string ISBN) { this->ISBN = ISBN; }

	void setReturnDate(string ReturnDate) { this->ReturnDate = ReturnDate; }


	//getter functions
	int getID() { return ID; }

	int getPrice() { return price; }

	int getPages() { return pages; }

	string getIssuedBy() { return IssuedBy; }

	string getIssuedOn() { return IssuedOn; }

	string getBookName() { return BookName; }

	string getAuthor() { return author; }

	string getISBN() { return ISBN; }

	string getReturnDate() { return ReturnDate; }


	//print function
	void print()
	{
		cout << "\nDetails for Book with ID " << this->ID << ": " << endl;
		cout << endl << left << setw(15) << "Book Name" << setw(2) << ":" << setw(50) << this->BookName;
		cout << endl << left << setw(15) << "Author" << setw(2) << ":" << setw(50) << this->author;
		cout << endl << left << setw(15) << "Price" << setw(2) << ":" << setw(10) << this->price;
		cout << endl << left << setw(15) << "Pages" << setw(2) << ":" << setw(5) << this->pages;
		cout << endl << left << setw(15) << "IssuedBy" << setw(2) << ":" << setw(10) << this->IssuedBy;
		cout << endl << left << setw(15) << "IssuedOn" << setw(2) << ":" << setw(10) << this->IssuedOn;
		cout << endl << left << setw(15) << "ISBN" << setw(2) << ":" << setw(20) << this->ISBN;
		cout << endl << left << setw(15) << "Return Date" << setw(2) << ":" << setw(20) << this->ReturnDate;

		cout << endl;
	}


	//copy constructor
	CBook(const CBook& Book2)
	{
		this->ID = Book2.ID;
		this->price = Book2.price;
		this->pages = Book2.pages;
		this->IssuedBy = Book2.IssuedBy;
		this->IssuedOn = Book2.IssuedOn;
		this->BookName = Book2.BookName;
		this->author = Book2.author;
		this->ISBN = Book2.ISBN;
		this->ReturnDate = Book2.ReturnDate;

	}

private:
	int ID;
	int price;
	int pages;

	string IssuedBy;
	string IssuedOn;
	string BookName;
	string author;
	string ISBN;
	string ReturnDate;

};

//linkded list struct for BOOK
struct BookNode
{
	CBook Book;

	BookNode* next;
};


class CBookList
{
public:
	//constructors
	CBookList()
	{
		HeadPtr = NULL;
	}

	//destructor
	~CBookList() {}

	BookNode* getHeadPtr()
	{
		return HeadPtr;
	}

	//node adder
	void Add()
	{
		BookNode* ptrBook = HeadPtr;

		bool AlreadyChosen = false;

		int ID;
		int price;
		int pages;

		string IssuedBy;
		string IssuedOn;
		string BookName;
		string author;
		string ISBN;
		string ReturnDate;

		cout << "\nEnter New Book Details\n";

		//checks if the ID is already chosen or not
		BookNode* ptrCheck;

		do
		{
			ptrCheck = HeadPtr;
			AlreadyChosen = false;

			cout << "\nEnter ID: ";
			cin >> ID;

			while (ptrCheck != NULL)
			{
				if (ID == ptrCheck->Book.getID())
				{
					cout << "\nInvalid Input. Book with ID " << ID << " already exists.\n";

					AlreadyChosen = true;
					break;
				}

				ptrCheck = ptrCheck->next;
			}

		} while (AlreadyChosen == true);


		cout << "Enter price: ";
		cin >> price;
		cout << "Enter pages: ";
		cin >> pages;
		cout << "Enter IssuedBy: ";
		cin >> IssuedBy;

		cout << "Enter IssuedOn: ";
		cin >> IssuedOn;
		cout << "Enter Book Name: ";
		cin >> BookName;
		cout << "Enter Author Name: ";
		cin >> author;
		cout << "Enter ISBN: ";
		cin >> ISBN;
		cout << "Enter ReturnDate: ";
		cin >> ReturnDate;

		BookNode* ptrNew = new BookNode, * ptrTemp = HeadPtr;

		//setting values
		ptrNew->Book.setID(ID);
		ptrNew->Book.setPrice(price);
		ptrNew->Book.setPages(pages);
		ptrNew->Book.setIssuedBy(IssuedBy);
		ptrNew->Book.setIssuedOn(IssuedOn);
		ptrNew->Book.setBookName(BookName);
		ptrNew->Book.setAuthor(author);
		ptrNew->Book.setISBN(ISBN);
		ptrNew->Book.setReturnDate(ReturnDate);

		ptrNew->next = NULL;

		if (HeadPtr == NULL)
		{
			HeadPtr = ptrNew;
			return;
		}

		while (ptrTemp->next != NULL) { ptrTemp = ptrTemp->next; }

		ptrTemp->next = ptrNew;

	}

	//node remover
	void Delete()
	{
		int ID;

		cout << "\nEnter Book ID: ";
		cin >> ID;

		BookNode* ptrCurrent = HeadPtr, * ptrPrevious = NULL;

		while (ptrCurrent != NULL && ptrCurrent->Book.getID() != ID)
		{
			ptrPrevious = ptrCurrent;
			ptrCurrent = ptrCurrent->next;
		}

		if (ptrCurrent == NULL)
		{
			cout << "\nBook with ID " << ID << " not found in the list\n";
			return;
		}

		if (ptrCurrent == HeadPtr)	//if the first node is to be delete 
		{
			HeadPtr = HeadPtr->next;
		}
		else						//if the node to be delete is in middle or atlast
		{
			ptrPrevious->next = ptrCurrent->next;
		}

		cout << "\nBook with ID " << ID << " has been Deleted.\n";

		delete ptrCurrent;

	}


	//print functions
	void printSpecific()
	{
		int ID;

		cout << "\nEnter Book ID: ";
		cin >> ID;

		BookNode* ptrCurrent = HeadPtr;

		while (ptrCurrent != NULL && ptrCurrent->Book.getID() != ID) { ptrCurrent = ptrCurrent->next; }

		if (ptrCurrent == NULL)
		{
			cout << "\nBook not found in the list. Invalid ID\n";
		}
		else		//invokes print functtion of CBook
		{
			ptrCurrent->Book.print();
		}

	}

	void printAll()
	{
		BookNode* ptrTemp = HeadPtr;

		cout << "\nDetails of all Books: " << endl;

		cout << endl << left << setw(6) << "ID:" << setw(20) << "BOOK NAME:" << setw(18) << "AUTHOR:" << setw(10) << "PRICE:" << setw(10) << "PAGES:" << setw(15) << "ISSUEDBY:" << setw(15) << "ISSUEDON:" << setw(10) << "ISBN:" << setw(11) << "RETURN DATE:" << endl;

		cout << setfill('-') << setw(116) << '-' << endl << setfill(' ');

		while (ptrTemp != NULL)
		{
			cout << left << setw(6) << ptrTemp->Book.getID() << setw(20) << ptrTemp->Book.getBookName() << setw(18) << ptrTemp->Book.getAuthor() << setw(10) << ptrTemp->Book.getPrice() << setw(10) << ptrTemp->Book.getPages() << setw(15) << ptrTemp->Book.getIssuedBy() << setw(15) << ptrTemp->Book.getIssuedOn() << setw(10) << ptrTemp->Book.getISBN() << setw(11) << ptrTemp->Book.getReturnDate() << endl;

			ptrTemp = ptrTemp->next;
		}

		cout << setfill('-') << setw(116) << '-' << endl << setfill(' ');


	}


	//sorting functions
	void sortAscendingOrder()
	{
		BookNode* ptrCurrent = HeadPtr;

		CBook TempBook, nextBook;

		int totalBooks = 0;

		//checks the total number of books
		while (ptrCurrent)
		{
			ptrCurrent = ptrCurrent->next;
			totalBooks++;
		}

		ptrCurrent = HeadPtr;

		for (int i = 0; i < totalBooks; i++)
		{
			while (ptrCurrent->next)	//while the next pointer doesn't point to NULL
			{
				if (ptrCurrent->Book.getID() > ptrCurrent->next->Book.getID()) //checks if the 'ID' of current Book is larger than the next one
				{
					//SWAPPING values
					TempBook = ptrCurrent->Book;
					nextBook = ptrCurrent->next->Book;

					ptrCurrent->Book = nextBook;
					ptrCurrent->next->Book = TempBook;

				}
				else
				{
					ptrCurrent = ptrCurrent->next;
				}
			}

			ptrCurrent = HeadPtr;	//reset to HeadPtr
		}

		cout << "\nBooks Sorted in Ascending Order.\n";
	}

	void sortDescendingOrder()
	{
		BookNode* ptrCurrent = HeadPtr;

		CBook TempBook, nextBook;

		int totalBooks = 0;

		//checks the total number of books
		while (ptrCurrent)	//while ptrCurrent doesn't point to NULL
		{
			ptrCurrent = ptrCurrent->next;
			totalBooks++;
		}

		ptrCurrent = HeadPtr;

		for (int i = 0; i < totalBooks; i++)
		{
			while (ptrCurrent->next)	//while the next pointer doesn't point to NULL
			{
				if (ptrCurrent->Book.getID() < ptrCurrent->next->Book.getID()) //checks if the 'ID' of current Book is smaller than the next one
				{
					//SWAPPING values
					TempBook = ptrCurrent->Book;
					nextBook = ptrCurrent->next->Book;

					ptrCurrent->Book = nextBook;
					ptrCurrent->next->Book = TempBook;

				}
				else
				{
					ptrCurrent = ptrCurrent->next;
				}
			}

			ptrCurrent = HeadPtr;	//reset to HeadPtr
		}

		cout << "\nBooks Sorted in Descending Order.\n";
	}

private:
	BookNode* HeadPtr;

};







// CSTUDENT

class CStudent
{
public:
	//constructors
	CStudent()
	{
		this->ID = 0;
		this->StdName = "X";
		this->RollNo = 0;

		this->BooksIssued[0] = 0;
	}

	CStudent(int ID, string StdName, int RollNo)
	{

		this->ID = ID;
		this->StdName = StdName;
		this->RollNo = RollNo;
		this->BooksIssued[0] = 0;

	}

	//destructor
	~CStudent() {}


	//setter functions
	void setID(int ID) { this->ID = ID; }

	void setName(string StdName) { this->StdName = StdName; }

	void setRollNo(int RollNo) { this->RollNo = RollNo; }

	void setBooksIssued(int BookID)			//value of '0' means that the slot is free
	{
		for (int i = 0; true; i++)
		{
			if (BooksIssued[i] == 0)
			{
				this->BooksIssued[i] = BookID;

				this->BooksIssued[i + 1] = 0;

				break;
			}

		}
	}


	//getter functions
	int getID() { return ID; }

	string getName() { return StdName; }

	int getRollNo() { return RollNo; }

	int getBooksIssued(int index) { return BooksIssued[index]; }

	void removeIssuedBook(int BookID)
	{
		int books = 0;
		int index = 0;

		for (int i = 0; true; i++)
		{
			if (BooksIssued[i] == BookID)
			{
				index = i;
			}

			if (BooksIssued[i] == 0)
			{
				break;
			}
			else
			{
				books++;
			}
		}

		if (index == books - 1)
		{
			BooksIssued[index] = 0;
		}
		else
		{
			for (int i = index; i < books; i++)
			{
				BooksIssued[i] = BooksIssued[i + 1];
			}
		}

	}

	//print function
	void print()
	{
		cout << "\nDetails for the Student with ID " << this->ID << ": " << endl;
		cout << endl << left << setw(15) << "Student Name" << setw(2) << ":" << setw(50) << this->StdName;
		cout << endl << left << setw(15) << "Roll Number" << setw(2) << ":" << setw(50) << this->RollNo;

		cout << endl << left << setw(15) << "Books Issued" << setw(2) << ":";

		for (int i = 0; true; i++)
		{
			if (BooksIssued[i] != 0)
			{
				cout << this->BooksIssued[i] << "   ";
			}
			else
			{
				if (BooksIssued[0] == 0)
				{
					cout << "None";
				}

				break;
			}
		}

		cout << endl;
	}

private:
	int ID;
	int RollNo;

	//stores the books issued to the Student
	int BooksIssued[5];

	string StdName;

};


//linked list structure for CSTUDENT
struct StudentNode
{
	CStudent Student;

	StudentNode* next;
};


class CStudentList
{
public:
	//constructors
	CStudentList()
	{
		HeadPtr = NULL;
	}

	//destructor
	~CStudentList() {}

	//node adder
	void Add()
	{
		bool AlreadyChosen = false;

		int ID;
		int RollNo;
		int BooksIssued[5];
		string StdName;

		cout << "\nEnter New Student Details\n";

		StudentNode* ptrCheck;

		//checks if the ID is already chosen or not
		do
		{
			ptrCheck = HeadPtr;
			AlreadyChosen = false;

			cout << "\nEnter ID: ";
			cin >> ID;

			while (ptrCheck != NULL)
			{
				if (ID == ptrCheck->Student.getID())
				{
					cout << "\nInvalid Input. Student with ID " << ID << " already exists.\n";

					AlreadyChosen = true;
					break;
				}

				ptrCheck = ptrCheck->next;
			}

		} while (AlreadyChosen == true);

		cout << "Enter Student Name: ";
		cin >> StdName;

		//checks if the Rollumber is already chosen or not
		do
		{
			ptrCheck = HeadPtr;
			AlreadyChosen = false;

			cout << "Enter Roll Number: ";
			cin >> RollNo;

			while (ptrCheck != NULL)
			{
				if (RollNo == ptrCheck->Student.getRollNo())
				{
					cout << "\nInvalid Input. Roll Number " << RollNo << " is already assigned to another Student.\n\n";

					AlreadyChosen = true;
					break;
				}

				ptrCheck = ptrCheck->next;
			}

		} while (AlreadyChosen == true);

		StudentNode* ptrNew = new StudentNode, * ptrTemp = HeadPtr;

		//setting values
		ptrNew->Student.setID(ID);
		ptrNew->Student.setName(StdName);
		ptrNew->Student.setRollNo(RollNo);

		ptrNew->next = NULL;

		if (HeadPtr == NULL)
		{
			HeadPtr = ptrNew;
			return;
		}

		while (ptrTemp->next != NULL) { ptrTemp = ptrTemp->next; }

		ptrTemp->next = ptrNew;

	}

	//node remover
	void Delete()
	{
		int ID;

		cout << "\nEnter Book ID: ";
		cin >> ID;

		StudentNode* ptrCurrent = HeadPtr, * ptrPrevious = NULL;

		while (ptrCurrent != NULL && ptrCurrent->Student.getID() != ID)
		{
			ptrPrevious = ptrCurrent;
			ptrCurrent = ptrCurrent->next;
		}

		if (ptrCurrent == NULL)
		{
			cout << "\nStudent with ID " << ID << " not found in the list\n";
			return;
		}

		if (ptrCurrent == HeadPtr)	//if the first node is to be delete
		{
			HeadPtr = HeadPtr->next;
		}
		else						//if the node to be delete is in middle or atlast
		{
			ptrPrevious->next = ptrCurrent->next;
		}

		cout << "\nStudent with ID " << ID << " has been Deleted.\n";

		delete ptrCurrent;

	}


	//print functions
	void printSpecific()
	{
		int ID;

		cout << "\nEnter Student ID: ";
		cin >> ID;

		StudentNode* ptrCurrent = HeadPtr;

		while (ptrCurrent != NULL && ptrCurrent->Student.getID() != ID) { ptrCurrent = ptrCurrent->next; }

		if (ptrCurrent == NULL)
		{
			cout << "\nStudent not found in the list. Invalid ID\n";
		}
		else
		{
			ptrCurrent->Student.print();
		}

	}

	void printAll()
	{
		StudentNode* ptrTemp = HeadPtr;

		cout << "\nDetails of all Students: " << endl;

		cout << endl << left << setw(6) << "ID:" << setw(20) << "STUDENT NAME:" << setw(18) << "ROLL NUMBER:" << setw(10) << "BOOKS ISSUED:" << endl;

		cout << setfill('-') << setw(63) << '-' << endl << setfill(' ');

		while (ptrTemp != NULL)
		{
			cout << left << setw(6) << ptrTemp->Student.getID() << setw(20) << ptrTemp->Student.getName() << setw(18) << ptrTemp->Student.getRollNo();

			if (ptrTemp->Student.getBooksIssued(0) == 0)
			{
				cout << setw(10) << "None";
			}
			else
			{
				for (int i = 0; true; i++)
				{
					if (ptrTemp->Student.getBooksIssued(i) != 0)
					{
						cout << ptrTemp->Student.getBooksIssued(i) << "   ";
					}
					else
					{
						break;
					}
				}
			}

			ptrTemp = ptrTemp->next;
			cout << endl;
		}

		cout << setfill('-') << setw(63) << '-' << endl << setfill(' ');

	}

	StudentNode* getHeadPtr()
	{
		return HeadPtr;
	}

private:
	StudentNode* HeadPtr;

};



class CLibrary
{
public:
	//constructors
	CLibrary()
	{
		totalBooksIssued = 0;

		BooksIssued = new int[totalBooksIssued];
	}

	//destructors
	~CLibrary() {}

	//list accessing functions
	//these functions are used to access CBOOKLIST and CSTUDENTLIST functions
	void accessBookList(int method)
	{
		switch (method)
		{
		case 1:
			BookList.Add();
			break;
		case 2:
			BookList.Delete();
			break;
		case 3:
			BookList.printSpecific();
			break;
		case 4:
			BookList.printAll();
			break;
		case 5:
			BookList.sortAscendingOrder();
			break;
		case 6:
			BookList.sortDescendingOrder();
			break;
		}
	}

	void accessStudentList(int method)
	{
		switch (method)
		{
		case 1:
			StudentList.Add();
			break;
		case 2:
			StudentList.Delete();
			break;
		case 3:
			StudentList.printSpecific();
			break;
		case 4:
			StudentList.printAll();
			break;
		}
	}

	//issue and return function
	void IssueBook()
	{
		int StudentID, BookID;
		int count = 0;

		BookNode* ptrBook = BookList.getHeadPtr();

		cout << "\nEnter the Book ID: ";
		cin >> BookID;

		//checking if the book to be issued already exists
		while (ptrBook != NULL && ptrBook->Book.getID() != BookID) { ptrBook = ptrBook->next; }

		if (ptrBook == NULL)
		{
			cout << "\nInvalid Input. Book with ID " << BookID << " does not exist.\n";
			return;
		}

		cout << "\nEnter the ID of the Student: ";
		cin >> StudentID;

		StudentNode* TEMPptr;

		StudentNode* ptrCurrent = StudentList.getHeadPtr();

		while (ptrCurrent != NULL && ptrCurrent->Student.getID() != StudentID) { ptrCurrent = ptrCurrent->next; }

		if (ptrCurrent == NULL)
		{
			cout << "\nInvalid Input. Student with ID " << StudentID << " does not exist.\n";
		}
		else
		{
			TEMPptr = ptrCurrent;

			for (int i = 0; true; i++)
			{
				if (TEMPptr->Student.getBooksIssued(i) != 0)
				{
					count++;
				}
				else
				{
					break;
				}

			}

			if (count == 5)
			{
				cout << "\nLimit Reached. Only 5 books can be Issued to one Student at a time\n";
				return;
			}


			ptrCurrent->Student.setBooksIssued(BookID);

			cout << "\nBook with ID " << BookID << " Issued to Student with ID " << StudentID << endl;

			totalBooksIssued++;

			//storing the ID of Issued Book in the array
			int* tempBooksIssued = new int[totalBooksIssued];

			for (int i = 0; i < totalBooksIssued - 1; i++)
			{
				tempBooksIssued[i] = BooksIssued[i];
			}
			tempBooksIssued[totalBooksIssued - 1] = BookID;

			BooksIssued = new int[totalBooksIssued];

			for (int i = 0; i < totalBooksIssued; i++)
			{
				BooksIssued[i] = tempBooksIssued[i];
			}

			delete[] tempBooksIssued;



		}

	}

	void ReturnBook()
	{
		int StudentID, BookID;

		int index = 0, count = 0;

		BookNode* ptrBook = BookList.getHeadPtr();

		cout << "\nEnter the Book ID: ";
		cin >> BookID;

		//checking if the book exists
		while (ptrBook != NULL && ptrBook->Book.getID() != BookID) { ptrBook = ptrBook->next; }

		if (ptrBook == NULL)
		{
			cout << "\nInvalid Input. Book with ID " << BookID << " does not exist.\n";
			return;
		}

		//checking if the book was issued before returning
		for (int i = 0; i < totalBooksIssued; i++)
		{
			count++;

			if (BookID == BooksIssued[i])
			{
				break;
			}

			if (count == totalBooksIssued)
			{
				cout << "\nBook with ID " << BookID << " was never Issued Before.\n";
				return;
			}
		}

		cout << "\nEnter the ID of the Student: ";
		cin >> StudentID;

		StudentNode* ptrCurrent = StudentList.getHeadPtr();

		while (ptrCurrent != NULL && ptrCurrent->Student.getID() != StudentID) { ptrCurrent = ptrCurrent->next; }

		if (ptrCurrent == NULL)
		{
			cout << "\nInvalid Input. Student with ID " << StudentID << " does not exist.\n";
			return;
		}
		else
		{
			ptrCurrent->Student.removeIssuedBook(BookID);

			cout << "\nStudent with ID " << StudentID << " has returned Book with ID " << BookID << "\n";

			//removing ID from array
			for (int i = 0; i < totalBooksIssued; i++)
			{
				if (BooksIssued[i] == BookID)
				{
					index = i;
				}
			}

			int* tempBooksIssued = new int[totalBooksIssued];

			for (int i = 0; i < totalBooksIssued; i++)
			{
				tempBooksIssued[i] = BooksIssued[i];
			}

			totalBooksIssued--;

			if (index == totalBooksIssued)
			{

			}
			else
			{
				for (int i = index; i < totalBooksIssued; i++)
				{
					tempBooksIssued[i] = tempBooksIssued[i + 1];
				}
			}

			BooksIssued = new int[totalBooksIssued];

			for (int i = 0; i < totalBooksIssued; i++)
			{
				BooksIssued[i] = tempBooksIssued[i];
			}

			delete[] tempBooksIssued;
		}

	}

	//print function
	void printIssued()
	{
		cout << "\nFollowing are the IDs of the Issued Books: ";

		for (int i = 0; i < totalBooksIssued; i++)
		{
			cout << "\n" << (i + 1) << ". " << BooksIssued[i];
		}

		if (totalBooksIssued == 0)
		{
			cout << "\nNone";
		}

		cout << endl;
	}

private:
	CBookList BookList;
	CStudentList StudentList;

	int* BooksIssued;	//array storing ID's of the books Issued
	int totalBooksIssued;

};








int main()
{
	int MainMenuOption;
	int SubMenuOption;

	CLibrary Library;

	do
	{
		cout << "\t---Main Menu---" << endl;

		cout << "\n1. Student";
		cout << "\n2. Book";
		cout << "\n3. Library";
		cout << "\n4. Exit";
		cout << "\n>> ";
		cin >> MainMenuOption;

		switch (MainMenuOption)
		{
		case 1:
			cout << "\n\t--Student SubMenu--" << endl;
			cout << "\n1. Add New Student";
			cout << "\n2. Delete Existing Student";
			cout << "\n3. Show Particular Student";
			cout << "\n4. Show all Students";
			cout << "\n>> ";
			cin >> SubMenuOption;

			switch (SubMenuOption)
			{
			case 1:
				Library.accessStudentList(1);
				break;
			case 2:
				Library.accessStudentList(2);
				break;
			case 3:
				Library.accessStudentList(3);
				break;
			case 4:
				Library.accessStudentList(4);
				break;
			default:
				cout << "\nInvalid Input\n";
				break;
			}

			break;
		case 2:
			cout << "\n\t--Book SubMenu--" << endl;
			cout << "\n1. Add New Book";
			cout << "\n2. Delete Existing Book";
			cout << "\n3. Show Particular Book";
			cout << "\n4. Show all Books";
			cout << "\n5. Sort Books in Ascending order.";
			cout << "\n6. Sort Books in Descending order.";
			cout << "\n>> ";
			cin >> SubMenuOption;

			switch (SubMenuOption)
			{
			case 1:
				Library.accessBookList(1);
				break;
			case 2:
				Library.accessBookList(2);
				break;
			case 3:
				Library.accessBookList(3);
				break;
			case 4:
				Library.accessBookList(4);
				break;
			case 5:
				Library.accessBookList(5);
				break;
			case 6:
				Library.accessBookList(6);
				break;
			default:
				cout << "\nInvalid Input\n";
				break;
			}

			break;

		case 3:
			cout << "\n\t--Library SubMenu--" << endl;
			cout << "\n1. Issue Book to a Student";
			cout << "\n2. Return Book from a Student";
			cout << "\n3. Show All Issued Books";
			cout << "\n>> ";
			cin >> SubMenuOption;

			switch (SubMenuOption)
			{
			case 1:
				Library.IssueBook();
				break;
			case 2:
				Library.ReturnBook();
				break;
			case 3:
				Library.printIssued();
				break;
			default:
				cout << "\nInvalid Input\n";
				break;
			}

			break;
		case 4:
			//Exit
			break;
		default:
			cout << "\nInvalid Input\n";
			break;
		}

		cout << endl;

	} while (MainMenuOption != 4);




}
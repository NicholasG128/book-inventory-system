#include <iostream>
#include <string>
#include <cmath>
#include "bookType.h"
#include "shelfSpace.h"
#include "shelf.h"
#include <iomanip>

using namespace std;

shelf sellingBooks;
int selection;
bool finished;
bool isSet;


void menu();
void bookTitle(shelf&);
void displayAuthor(shelf&);
void displayPrice(shelf&);
void displayDate(shelf&);
void sellBook(shelf&);
void buyBook(shelf&);


// NICHOLAS GRAHAM Recitation # 5
int main()
{
    finished = false;

    while(!finished)
    {

        // MAIN MENU
        menu();


        switch(selection)
        {

        case 1:
            bookTitle(sellingBooks);
            break;
        case 2:
            displayAuthor(sellingBooks);
            break;
        case 3:
            displayPrice(sellingBooks);
            break;
        case 4:
            displayDate(sellingBooks);
            break;
        case 5:
            sellBook(sellingBooks);
            break;
        case 6:
            buyBook(sellingBooks);
            break;
        case 7:
            finished = true;
            break;
        default:
            break;

        }
    }
return 0;
}


void menu()
{
    cout << "*************************************************" << endl;
    cout << "* 1 Search for a book by title.                 *" << endl;
    cout << "* 2 Display a book's author.                    *" << endl;
    cout << "* 3 Display a book's price.                     *" << endl;
    cout << "* 4 Display a book's publish date.              *" << endl;
    cout << "* 5 Sell a book - title.                        *" << endl;
    cout << "* 6 Buy a book.                                 *" << endl;
    cout << "* 7 Terminate the program.                      *" << endl;
    cout << "*************************************************" << endl;
    cout << "Please enter the number of your request. _______" << endl;
    cin >> selection;
    cout << endl;

}

void bookTitle(shelf& position)
{
    string title = " ";
    string pTitle = " ";

    system("CLS");
            cout << "Search for a book - title." << endl;
            cout << "Do you have this book? (Input title)" << endl;
            getline(cin >> ws, title);
            cout << endl;
            shelfSpace& request = position.findBookTitle(title);
            pTitle = request.getTitle();
            if (title == pTitle)
            {
                request.printInfo();
            }


}
void displayAuthor(shelf& position)
{
    string author = " ";
    string title = " ";
    string pTitle = " ";

    system("CLS");
            cout << "Display the author of a book." << endl;
            cout << "Who is the author of this book? (Input Title)" << endl;
            getline(cin >> ws, title);
            cout << endl;

            shelfSpace& request = position.findBookTitle(title);
            pTitle = request.getTitle();
            author = request.getAuthor();

            if (title == pTitle)
            {
                cout << "The author of this title is : " << author << "." << endl;
            }
            else
            {
                    cout << "Title not found." << endl;
            }
}
void displayPrice(shelf& position)
{
    string author = " ";
    string pAuthor = " ";
    string title = " ";
    string pTitle = " ";
    double price = 0.00;

    system("CLS");
            cout << "Display the price of a book." << endl;
            cout << "How much does this book cost?" << endl << endl;
            cout << "Please input the title of the book." << endl;
            getline(cin >> ws, title);
            cout << endl;
            cout << "Please input the author of the book." << endl;
            getline(cin >> ws, author);
            cout << endl;

            shelfSpace& request = position.findBookTitle(title);
            pAuthor = request.getAuthor();
            pTitle = request.getTitle();
            price = request.getPrice();


            if(title == pTitle && author == pAuthor)
            {
                cout << "The price of the book is : " << setprecision(2) << fixed << price << endl << endl;
            }
            else
            {
                    cout << "Book not found." << endl;
            }

}
void displayDate(shelf& position)
{
    string author = " ";
    string title = " ";
    string pTitle = " ";
    int year = 0;

    system("CLS");

            cout << "Display a book's publish date." << endl;
            cout << "What year was this book published? (Input Title)" << endl;
            getline(cin >> ws,title);
            cout << endl;
            shelfSpace& request = position.findBookTitle(title);
            year = request.getPublishYear();
            pTitle = request.getTitle();

            if (pTitle == title)
            {
                cout << "The year of this book is : " << year << endl;
            }
            else
            {
                cout << "Title not found" << endl;
            }


}
void sellBook(shelf& position)
{
    string pTitle = " ";
    string title = " ";
    string author = " ";
    string pAuthor = " ";
    int copies = 0;

    system("CLS");
            isSet = false;

            cout << "Sell a book - title." << endl;
            cout << "I want to buy this book! (Input Title)" << endl;
            getline(cin >> ws, title);
            cout << endl;
            cout << "Input an Author : " << endl;
            getline(cin >> ws, author);
            cout << endl;

            shelfSpace& request = position.findBookTitle(title);
            copies = request.getCopy();
            pTitle = request.getTitle();
            pAuthor = request.getAuthor();


            if(title == pTitle && author == pAuthor)
            {

                if (copies >= 2)
                {
                    cout << "Book has been purchased!" << endl;
                    request.updateCopySale();
                }
                else if (copies == 1)
                {
                    cout << "Book has been purchased!" << endl;
                    cout << "The shelf is now empty!" << endl;
                    request.updateCopySale();
                    request.setStatus(false);
                    request.setEmpty();
                }
                else
                {
                    cout << "There are no copies." << endl;
                }

            }

}
void buyBook(shelf& position)
{
    int numberSet = 0;
    char yesNo = 'n';
    string author = " ";
    string pAuthor = " ";
    string title = " ";
    string pTitle = " ";
    int year = 0;
    double price = 0.00;
    int copies = 0;
    bool isFinished = false;
    bool isFinished1 = false;

    system("CLS");
            cout << "Buy a book." << endl;
            cout << "I want to sell you this book. (Input Title)" << endl;
            getline(cin >> ws, title);
            cout << endl;
            shelfSpace& request = position.findBookTitle(title);
            pTitle = request.getTitle();
            if(pTitle == title)
               {
                   cout << "This book already exists, add some copies." << endl;
                   cout << "Input number of Copies : " << endl;
                   cin >> copies;
                   cout << endl;
                   for (int i = 0; i != copies; i++)
                   {
                       request.updateCopySent();
                   }
                   cout << copies << " copies have been added to " << pTitle << endl << endl;
               }
            else
            {
                cout << "Input Author : " << endl;
                getline(cin >> ws, author);
                cout << endl;
                cout << "Input Copies : " << endl;
                while (!isFinished1)
                {
                    cin >> copies;
                    try
                    {
                        if (copies < 0)
                        {
                            throw copies;
                        }
                        else
                        {
                            isFinished1 = true;
                        }
                    }
                    catch(int c)
                    {
                        cout << "Please input a positive numbers of copies" << endl;
                    }


                }
                cout << endl;
                cout << "Input Price : " << endl;
                while(!isFinished)
                {
                    try
                    {
                        cin >> price;
                        if (price <= 0)
                        {
                            throw price;
                        }
                        else
                        {
                            isFinished = true;
                        }
                    }
                    catch(double p)
                    {
                        if(p == 0)
                        {
                            cout << "The number was set as " << p << " Did you mean to? (Input Y or N)" << endl;
                            cin >> yesNo;
                                if(yesNo == 'y' || yesNo == 'Y')
                                {
                                    isFinished = true;
                                }
                        }
                        else
                        {
                        if(p < 0)
                        {
                        cout << "The number must be positive." << endl;
                        cout << "Would you like to set " << p << " as a positive? (Input Y or N)" << endl;
                        cin >> yesNo;
                            if(yesNo == 'y' || yesNo == 'Y')
                            {
                                price = fabs(p);
                                isFinished = true;
                            }

                        }
                        else
                        {
                            cout << "Please input a number." << endl;
                        }
                    }

                }
            }
            cout << endl;
            cout << "Input year the book was published : " << endl;
            isFinished = false;
            while(!isFinished)
            {
                numberSet = 0;
                try
                {
                    cin >> year;
                    for(int i = 0; i < 4; ++i)
                    {
                        if (year >= 0 && year <= 2024)
                        {
                            isFinished = true;
                        }
                        else
                        {
                            throw year;
                        }
                    }

                }
                catch (int year)
                {
                    cout << "Please enter values between 0 & 2024" << endl;
                }
            }

            shelfSpace& request = position.findEmptySpace();

            request.setAuthor(author);
            request.setTitle(title);
            request.setCopy(copies);
            request.setPrice(price);
            request.setPublishYear(year);
            request.setStatus(true);
        }
}

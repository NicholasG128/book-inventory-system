#include <iostream>
#include <iomanip>
#include "bookType.h"


using namespace std;

bookType::bookType()
        {
        title = " ";
        author = " ";
        bookPrice = 0;
        copies = 0;
        publishedYear = 0;
        }

void bookType::setEmpty()
        {
        title = " ";
        author = " ";
        bookPrice = 0;
        copies = 0;
        publishedYear = 0;
        }

void bookType::setTitle(string t)
{
    title = t;
}
string bookType::getTitle()
{
    return title;
}

void bookType::setAuthor(string a)
{
    author = a;
}

string bookType::getAuthor()
{
    return author;
}

double bookType::getPrice()
{
    return bookPrice;
}

void bookType::setPrice(double p)
{
    bookPrice = p;
}

int bookType::getCopy()
{
    return copies;
}

void bookType::setCopy(int c)
{
   copies = c;
}

void bookType::updateCopySale()
{
    copies--;
}

void bookType::updateCopySent()
{
    copies++;
}
void bookType::setPublishYear(int year)
{
    publishedYear = year;
}

int bookType::getPublishYear(void)
{
    return publishedYear;
}



void bookType::printInfo()
{
    cout << "The title of the book is : " << title << endl;
    cout << "The author of the book is : " << author << endl;
    cout << "The price of the book is : $" << setprecision(2) << fixed << bookPrice << endl;
    cout << "Amount in stock : " << copies << endl;
    cout << "The publishing year of the book is : " << publishedYear << endl;
    cout << endl;
}

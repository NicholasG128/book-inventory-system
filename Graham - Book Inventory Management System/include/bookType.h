#include <iostream>
#ifndef BOOKTYPE_H
#define BOOKTYPE_H

using namespace std;

class bookType
{
    private:
        string title;
        string author;
        double bookPrice;
        int copies;
        int publishedYear;
    public:
        bookType();
        void setEmpty();

        string getTitle();
        void setTitle(string t);

        void setAuthor(string a);
        string getAuthor();

        double getPrice();
        void setPrice(double p);

        int getCopy();
        void setCopy(int c);

        void updateCopySale();
        void updateCopySent();

        void setPublishYear(int year);
        int getPublishYear(void);

        void setStatus(bool s);
        bool getStatus();

        void printInfo();

};

#endif // BOOKTYPE_H

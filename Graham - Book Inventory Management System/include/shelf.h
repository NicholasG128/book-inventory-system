#ifndef SHELF_H
#define SHELF_H
#include <shelfSpace.h>

class shelf
{
    private:
        static const int ARRAY_SIZE = 100;
        shelfSpace fiveFootShelf[ARRAY_SIZE];
    public:
        shelf();
        shelfSpace& findBookTitle(string title);
        shelfSpace& findEmptySpace();
};

#endif // SHELF_H

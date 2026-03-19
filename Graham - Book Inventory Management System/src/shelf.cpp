#include "shelf.h"

shelf::shelf()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        fiveFootShelf[i] = shelfSpace();
    }
}
shelfSpace& shelf::findBookTitle(string title)
{
    string pTitle;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        pTitle = fiveFootShelf[i].getTitle();
        if (pTitle == title)
        {
            return fiveFootShelf[i];
        }
    }
}
shelfSpace& shelf::findEmptySpace()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (fiveFootShelf[i].getStatus() == false)
        {
            return fiveFootShelf[i];
            break;
        }
    }
    cout << "No empty spaces in the shelf." << endl;
}

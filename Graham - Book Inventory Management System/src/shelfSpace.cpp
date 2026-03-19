#include <iostream>
#include "shelfSpace.h"
#include "bookType.h"

using namespace std;

shelfSpace::shelfSpace()
{
    status = false;
}
void shelfSpace::setStatus(bool s)
{
     status = s;
}
bool shelfSpace::getStatus()
{
    return status;
}

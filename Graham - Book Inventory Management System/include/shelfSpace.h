#ifndef SHELFSPACE_H
#define SHELFSPACE_H
#include "bookType.h"

class shelfSpace : public bookType
{
    private:
        bool status;
    public:
        shelfSpace();
        void setStatus(bool s);
        bool getStatus();

};

#endif // SHELFSPACE_H

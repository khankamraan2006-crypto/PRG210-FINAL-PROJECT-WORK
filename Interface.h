#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
public:
    virtual void showMenu() = 0;
    virtual ~Interface();

protected:
    int readIntInRange(int min, int max);
    int readPositiveInt();
    double readPositiveDouble();
    void readNonEmptyString(char* text, int size);
};

#endif

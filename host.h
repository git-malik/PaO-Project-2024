#ifndef HOST_H
#define HOST_H

class Host
{
private:
    char* id;
public:
    char* getId();
    Host();
    Host(char* id);
    Host(const Host& other);
    Host& operator=(const Host& other);
    ~Host();
};
#endif


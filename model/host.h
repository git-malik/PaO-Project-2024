#ifndef HOST_H
#define HOST_H
#include <iostream>
#include <cstring>

class Host
{
private:
    static int hostId;
    int id;
    std::string name;
public:
    int getId();
    std::string getName() const;
    Host();
    Host(std::string id);
    Host(Host& other);

    Host& operator=(const Host& other);
};
#endif


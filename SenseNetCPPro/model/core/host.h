#ifndef HOST_H
#define HOST_H
#include <iostream>
#include <cstring>

class Host
{
private:
    static int hostId;
    /**
     * @brief unique for every host
     */
    std::string name;
public:
    int getId() const;
    const std::string& getName() const;
    Host();
    Host(const std::string& name);
    Host(Host& other);

    Host& operator=(const Host& other);
    bool operator==(const Host& other) const;
};
#endif


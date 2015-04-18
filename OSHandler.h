#include <iostream>

class OSHandler
{
public:
    void win32();
    void mac();
    
    std::string getResourcePath();
private:
    std::string _resourcePath;
};
#include "OSHandler.h"

void OSHandler::win32() {
    std::cout << "WIN32" << std::endl;
    _resourcePath = "";
}

#ifdef __APPLE__
void OSHandler::mac() {
    std::cout << "MAC" << std::endl;
    _resourcePath = "/Users/christoferarleryd/Documents/Programming/LIUGameJam2015/LIUGameJam2015/";
}
#endif

std::string OSHandler::getResourcePath() {
    return _resourcePath;
}
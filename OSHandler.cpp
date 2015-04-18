#include "OSHandler.h"

void OSHandler::win32() {
    _resourcePath = "";
}

#ifdef __APPLE__
void OSHandler::mac() {
    _resourcePath = "/Users/christoferarleryd/Documents/Programming/LIUGameJam2015/LIUGameJam2015/";
}
#endif

std::string OSHandler::getResourcePath() {
    return _resourcePath;
}
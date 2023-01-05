#include <awesomeLib/ConsoleButtonHandler.h>
#include <iostream>

const char* ConsoleButtonHandler::getHandlerName() 
{
    return "ConsoleButtonHandler";
}

void ConsoleButtonHandler::buttonDown(uint16_t keyCode) 
{
    std::cout << __FUNCTION__ << " keyCode = " << keyCode << std::endl;
}

void ConsoleButtonHandler::buttonUp(uint16_t keyCode) 
{
    std::cout << __FUNCTION__ << " keyCode = " << keyCode << std::endl;
}

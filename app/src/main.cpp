#include <iostream>
#include <awesomeLib/awesomeHeader.h>
#include <awesomeLib/ButtonDispatcher.h>
#include <awesomeLib/ConsoleButtonHandler.h>

int main(int argc, char* argv[]) {
    std::cout << "Not Hello World! The random number is " << getRandomNumber() << std::endl;

    ConsoleButtonHandler consoleButtonHandler;
    ButtonDispatcher buttonDispatcher;
    
    buttonDispatcher.subscribeHandler(&consoleButtonHandler);

    buttonDispatcher.on_event_keyPress(10);
    buttonDispatcher.on_event_keyRelease(10);

    
    buttonDispatcher.on_event_keyPress(128);
    buttonDispatcher.on_event_keyRelease(128);

    
    buttonDispatcher.on_event_keyPress(32535);
    buttonDispatcher.on_event_keyRelease(32535);

    
    buttonDispatcher.on_event_keyPress(0);
    buttonDispatcher.on_event_keyRelease(0);

    //clear the input stream and wait for any key press.
    //std::cin.sync();
    //std::cin.get();
    return 0;
}
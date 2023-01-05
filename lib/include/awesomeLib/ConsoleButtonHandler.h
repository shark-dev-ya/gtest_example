#ifndef AWESOME_LIB_CONSOLE_BUTTON_HANDLER_H
#define AWESOME_LIB_CONSOLE_BUTTON_HANDLER_H

#include <awesomeLib/IButtonHandler.h>

class ConsoleButtonHandler : public interfaces::V1::IButtonHandler {
    virtual const char* getHandlerName() override;
    virtual void buttonDown(uint16_t keyCode) override;
    virtual void buttonUp(uint16_t keyCode) override;
};

#endif //AWESOME_LIB_CONSOLE_BUTTON_HANDLER_H




#ifndef AWESOME_LIB_IBUTTONHANDLER_H
#define AWESOME_LIB_IBUTTONHANDLER_H

#include <cstdint>

namespace interfaces {
namespace V1{
    
/*
    Interace IButtonHandler should be implemented by other classes.
    each handler should be installed to our ButtonDispatcher.

    This is an example of a middle layer with limited logic.
*/
class IButtonHandler {
public:
    virtual const char* getHandlerName() = 0;
    virtual void buttonDown(uint16_t keyCode) = 0;
    virtual void buttonUp(uint16_t keyCode) = 0;
};

}  //namespace V1
}  //namespace interfaces

#endif //AWESOME_LIB_IBUTTONHANDLER_H
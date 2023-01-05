#ifndef AWESOME_LIB_BUTTONDISPATCHER_H
#define AWESOME_LIB_BUTTONDISPATCHER_H

#include <cstdint>
#include <list>
#include <awesomeLib/IButtonHandler.h>

/*
    Main logic class, which is receiving from lower layer
    an event and forwarding it to subscribed/installed button handlers

    This is an example of a middle layer with limited logic.
*/
class ButtonDispatcher {
public:
    explicit ButtonDispatcher();
    ~ButtonDispatcher();

    bool subscribeHandler(interfaces::V1::IButtonHandler* handler);
    bool unsubscribeHandler(interfaces::V1::IButtonHandler* handler);

    uint16_t on_event_keyPress(uint16_t idx);
    uint16_t on_event_keyRelease(uint16_t idx);
    
private:
    std::list<interfaces::V1::IButtonHandler*> m_subscribedHandlers;
};

#endif //AWESOME_LIB_BUTTONDISPATCHER_H
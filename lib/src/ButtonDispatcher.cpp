#include <awesomeLib/ButtonDispatcher.h>
#include <cstring>

ButtonDispatcher::ButtonDispatcher() {

}

ButtonDispatcher::~ButtonDispatcher() {
    //every handler is responsible to free memory. we just remove pointers!
    m_subscribedHandlers.clear();
}

bool ButtonDispatcher::subscribeHandler(interfaces::V1::IButtonHandler* handler) {
    bool isAdded = false;
    if (nullptr == handler) {
        return isAdded;
    }

    for (auto subscribedHandler : m_subscribedHandlers) {
        if (0 == strcmp(handler->getHandlerName() , subscribedHandler->getHandlerName()) ) {
            isAdded = true;
            break;
        }
    }
    if (!isAdded) {
        m_subscribedHandlers.push_back(handler);
        isAdded = true;
    }
    return isAdded;
}

bool ButtonDispatcher::unsubscribeHandler(interfaces::V1::IButtonHandler* handler) {
    bool isRemoved = false;
    for (auto handlerIt = m_subscribedHandlers.begin() ; handlerIt != m_subscribedHandlers.end() ; ++handlerIt) {
        interfaces::V1::IButtonHandler* handlerPtr = *handlerIt;
        if ( 0 == strcmp( handlerPtr->getHandlerName() , handler->getHandlerName() ) ) {
            m_subscribedHandlers.erase(handlerIt);
            isRemoved = true;
            break;
        }
    }
    return isRemoved;
}

uint16_t ButtonDispatcher::on_event_keyPress(uint16_t idx) {
    uint16_t amountOfHandlersNotified = 0;
    for (auto subscribedHandler : m_subscribedHandlers) {
        subscribedHandler->buttonDown(idx);
        ++amountOfHandlersNotified;
    }
    return amountOfHandlersNotified;
}
uint16_t ButtonDispatcher::on_event_keyRelease(uint16_t idx) {
    uint16_t amountOfHandlersNotified = 0;
    for (auto subscribedHandler : m_subscribedHandlers) {
        subscribedHandler->buttonUp(idx);
        ++amountOfHandlersNotified;
    }
    return amountOfHandlersNotified;
}

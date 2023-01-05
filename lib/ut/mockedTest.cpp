#include <awesomeLib/ButtonDispatcher.h>
#include <awesomeLib/IButtonHandler.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockedButtonHandler : public interfaces::V1::IButtonHandler {
    public:
    MOCK_METHOD(const char* , getHandlerName , ()                 , (override) );
    MOCK_METHOD(void        , buttonDown     , (uint16_t keyCode) , (override) );
    MOCK_METHOD(void        , buttonUp       , (uint16_t keyCode) , (override) );
};

class ButtonDispatcherTest : public ::testing::Test {
    protected:
        void SetUp() override {
            //let's imagine that we are doing here some settings before all test cases, for example, allocating memory
        }
        void TearDown() override {
            //let's imagine that we are doing here some cool down settings, for example, deallocating memory.
        }

    ButtonDispatcher buttonDispatcher;
};


// Now we are writing test cases/ test fixtures with using Our ButtonDispatcherTest class.

TEST_F(ButtonDispatcherTest, MockedButtonHandlerShouldNotBeCalled) {
    //create an object of mocked handler.
    MockedButtonHandler  mockedHandler;

    //we will not subscribe our mocked handler to dispatcher, so we expect 0 calls
    //for buttonDown and buttonUp methods
    EXPECT_CALL(mockedHandler, buttonDown( ::testing::_ ))
        .Times( 0 );
    EXPECT_CALL(mockedHandler, buttonUp( ::testing::_ ))
        .Times( 0 );
    EXPECT_CALL(mockedHandler, getHandlerName())
        .Times( 0 );

    buttonDispatcher.on_event_keyPress(10);
    buttonDispatcher.on_event_keyRelease(10);
}


TEST_F(ButtonDispatcherTest, MockedButtonHandlerShouldBeCalledOnce) {
    //create an object of mocked handler.
    MockedButtonHandler  mockedHandler;

    //we will not subscribe our mocked handler to dispatcher, so we expect 0 calls
    //for buttonDown and buttonUp methods
    EXPECT_CALL(mockedHandler, buttonDown( ::testing::_ ))
        .Times( 1 );
    EXPECT_CALL(mockedHandler, buttonUp( ::testing::_ ))
        .Times( 1 );
    EXPECT_CALL(mockedHandler, getHandlerName())
        .Times( ::testing::AtLeast(1) );

    //specify here what we want to return on the function "getHandlerName" call
    ON_CALL( mockedHandler, getHandlerName())
        .WillByDefault(::testing::Return( "myCustomHandlerName" ));

    buttonDispatcher.subscribeHandler( &mockedHandler );
    buttonDispatcher.subscribeHandler( &mockedHandler );



    buttonDispatcher.on_event_keyPress(10);
    buttonDispatcher.on_event_keyRelease(10);
}



TEST_F(ButtonDispatcherTest, MockedButtonHandlerButtonDownCalled5Times) {
    //create an object of mocked handler.
    MockedButtonHandler  mockedHandler;

    const uint16_t amountOfCalls = 5;

    //we will not subscribe our mocked handler to dispatcher, so we expect 0 calls
    //for buttonDown and buttonUp methods
    EXPECT_CALL(mockedHandler, buttonDown( ::testing::_ ))
        .Times( amountOfCalls );
    EXPECT_CALL(mockedHandler, buttonUp( ::testing::_ ))
        .Times( 0 );
    EXPECT_CALL(mockedHandler, getHandlerName())
        .Times( ::testing::AtLeast(1) );

    //specify here what we want to return on the function "getHandlerName" call
    ON_CALL( mockedHandler, getHandlerName())
        .WillByDefault(::testing::Return( "myCustomHandlerName" ));

    buttonDispatcher.subscribeHandler( &mockedHandler );
    buttonDispatcher.subscribeHandler( &mockedHandler );

    for (uint16_t i = 0 ; i < amountOfCalls ; ++i ) {
        buttonDispatcher.on_event_keyPress(amountOfCalls + i);
    }

}





TEST_F(ButtonDispatcherTest, MockedButtonHandlerButtonUpCalled5Times) {
    //create an object of mocked handler.
    MockedButtonHandler  mockedHandler;

    const uint16_t amountOfCalls = 5;

    //we will not subscribe our mocked handler to dispatcher, so we expect 0 calls
    //for buttonDown and buttonUp methods
    EXPECT_CALL(mockedHandler, buttonDown( ::testing::_ ))
        .Times( 0 );
    EXPECT_CALL(mockedHandler, buttonUp( ::testing::_ ))
        .Times( amountOfCalls );
    EXPECT_CALL(mockedHandler, getHandlerName())
        .Times( ::testing::AtLeast(1) );

    //specify here what we want to return on the function "getHandlerName" call
    ON_CALL( mockedHandler, getHandlerName())
        .WillByDefault(::testing::Return( "myCustomHandlerName" ));

    buttonDispatcher.subscribeHandler( &mockedHandler );
    buttonDispatcher.subscribeHandler( &mockedHandler );

    for (uint16_t i = 0 ; i < amountOfCalls ; ++i ) {
        buttonDispatcher.on_event_keyRelease(amountOfCalls + i);
    }
    
}

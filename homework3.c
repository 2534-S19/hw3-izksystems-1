#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

typedef enum {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN} THECOUNT;

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    //enum {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN} THECOUNT;
    //static THECOUNT currentState = ZERO;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER0_PRESCALER, TIMER1_COUNT);
    //turnOff_LaunchpadLED2Blue(); turnOff_LaunchpadLED2Green(); turnOn_LaunchpadLED2Red();

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);

        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        timer0Expired();









        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        timer1Expired();



        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.



        // TODO: If a completed, debounced button press has occurred, increment count1.



    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{

    static THECOUNT currentState = ZERO;

    switch (currentState){
    case ZERO:
        if (count == 0)
            turnOff_LaunchpadLED2Blue(); turnOff_LaunchpadLED2Green(); turnOff_LaunchpadLED2Red();
            currentState = ONE;
    count++;

    break;

    case ONE:
        if (count == 1)
            turnOff_LaunchpadLED2Blue(); turnOff_LaunchpadLED2Green(); turnOn_LaunchpadLED2Red();

            currentState =TWO;
    count++;

    break;

    case TWO:
    if (count == 2)
            turnOff_LaunchpadLED2Blue(); turnOn_LaunchpadLED2Green(); turnOff_LaunchpadLED2Red();

            currentState =THREE;
    count++;

    break;

    case THREE:
        if (count == 3)
                turnOff_LaunchpadLED2Blue(); turnOn_LaunchpadLED2Green(); turnOn_LaunchpadLED2Red();
                currentState =FOUR;
        count++;

        break;

    case FOUR:
        if (count == 4)
                turnOn_LaunchpadLED2Blue(); turnOff_LaunchpadLED2Green(); turnOff_LaunchpadLED2Red();
               currentState = FIVE;
        count++;

        break;

    case FIVE:
        if (count == 5)
                turnOn_LaunchpadLED2Blue(); turnOff_LaunchpadLED2Green(); turnOn_LaunchpadLED2Red();
                currentState =SIX;
        count++;

        break;

    case SIX:
        if (count == 6)
                turnOn_LaunchpadLED2Blue(); turnOn_LaunchpadLED2Green(); turnOff_LaunchpadLED2Red();
                currentState =SEVEN;
        count++;

        break;

    case SEVEN:
        if (count == 7)
                turnOn_LaunchpadLED2Blue(); turnOn_LaunchpadLED2Green(); turnOn_LaunchpadLED2Red();
                currentState =ZERO;
        count = 0;

        break;

    }

}
// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{



}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;


    return pressed;
}

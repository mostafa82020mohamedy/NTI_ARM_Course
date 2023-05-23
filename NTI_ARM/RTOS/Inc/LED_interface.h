#ifndef LED_H_
#define LED_H_


/* Firstly, You must Set the Direction of the Needed Pin for any Led to "OUTPUT PUSH PULL" before Calling any Other Function of Leds  */

void Led_voidON (u8 LedPort  , u8 LedPin );
void Led_voidOFF (u8 LedPort  , u8 LedPin);
void Led_voidToggle (u8 LedPort  , u8 LedPin , u8 Duration ); /* Duration in Milli Seconds */

#endif /* LED_H_ */

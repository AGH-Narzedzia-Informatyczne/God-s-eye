/**
 * @file serial.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Serial communication instructions
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Listening for user input.
 * Enter `exit` to leave this mode or `shutdown` to disable device
 * 
 */
void readFromSerial()
{
    if (Serial.available() > 0)
    {
        enableLED();                                      // On data recieve, turn LED on
        String userString = Serial.readStringUntil('\n'); // Save user string to variable
        Serial.print("    > ");                           // Print indentation
        Serial.println(userString);                       // Print recieved string
        disableLED();                                     // Turn LED off
        if (userString == "exit")
            break;
        if (userString == "shutdown")
            ESP.deepSleep(0);
    }
}
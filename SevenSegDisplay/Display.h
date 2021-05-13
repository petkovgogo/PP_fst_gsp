/*
 * Display.h
 *
 *  Created on: Apr 22, 2021
 *      Author: petkovgogo
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "Segment.h"

enum
{
    A = 0, B, C, D, E, F, G, H, SEGMENT_COUNT
};

typedef struct
{
    Segment segments[SEGMENT_COUNT];
} Display;

// uint32_t delayTime = 1000; // Used in the blink function. Initial value 1s (1000ms)

/**
 * @brief Display Initialization Function
 * @param Receives a pointer to the Display instance to initialize
 * @param Array of the ports of the segments
 * @param Array of the pins of the segments
 * @retval None
 *
 * @note Example: Initialize two displays
 *
    GPIO_TypeDef *d0Ports[] =
       { Ports for the first display go here };

    uint16_t d0Pins[] =
        { Pins for the first display go here };

    GPIO_TypeDef *d1Ports[] =
        { Ports for the second display go here };

    uint16_t d1Pins[] =
        { Pins for the second display go here };

    Display d0; // Create the first display
    Display d1; // Create the second display

    displayFactory (&d0, d0Ports, d0Pins); // Initialize the first display
    displayFactory (&d1, d1Ports, d1Pins); // Initialize the second display

    Display *displays[] =
        { &d0, &d1 }; // Create an array of displays, used to display a number
 */
void displayFactory (Display *display, GPIO_TypeDef *ports[], uint16_t pins[]);

/**
 * @brief Displays a single digit on a single display
 * @param A pointer to a Display instance
 * @param A digit to display
 * @retval None
 */
void displayDigit (Display *display, int digit);

/**
 * @brief Displays a whole number on dispayCount displays and updates delayTime to the given delay
 * @param An array of pointers to Display instances
 * @param The count of the displays
 * @param The number to display
 * @param A time interval for a blink
 * @retval None
 */
void displayNumber (Display *display[], int displayCount, double number,
                    uint32_t delay);

void displayDigit0 (Display *display);
void displayDigit1 (Display *display);
void displayDigit2 (Display *display);
void displayDigit3 (Display *display);
void displayDigit4 (Display *display);
void displayDigit5 (Display *display);
void displayDigit6 (Display *display);
void displayDigit7 (Display *display);
void displayDigit8 (Display *display);
void displayDigit9 (Display *display);
void displayDP (Display *display); // Displays a Decimal Point
void displayError (Display *displays[], int displayCount);

/**
 * @brief Blinks the given segments for a delayTime milliseconds
 * @param An array of pointers to Segment instances
 * @param The count of the segments
 * @retval None
 */
void blink (Segment *segments[], int segCount);

#endif /* INC_DISPLAY_H_ */

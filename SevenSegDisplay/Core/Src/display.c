/*
 * display.c
 *
 *  Created on: Apr 22, 2021
 *      Author: petkovgogo
 */

#include "Display.h"
#include "math.h"

uint32_t delayTime = 1000; // Used in the blink function. Initial value 1s (1000ms)

void createSegment (Segment *seg, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    seg->port = GPIOx;
    seg->pin = GPIO_Pin;
}

void displayFactory (Display *display, GPIO_TypeDef *ports[], uint16_t pins[])
{
    for (int i = 0; i < SEGMENT_COUNT; ++i)
    {
        createSegment (&display->segments[i], ports[i], pins[i]);
    }
}

void displayDigit (Display *display, int digit)
{
    switch (digit)
        {
        case 1:
            displayDigit1 (display);
            break;
        case 2:
            displayDigit2 (display);
            break;
        case 3:
            displayDigit3 (display);
            break;
        case 4:
            displayDigit4 (display);
            break;
        case 5:
            displayDigit5 (display);
            break;
        case 6:
            displayDigit6 (display);
            break;
        case 7:
            displayDigit7 (display);
            break;
        case 8:
            displayDigit8 (display);
            break;
        case 9:
            displayDigit9 (display);
            break;
        default:
            displayDigit0 (display);
            break;
        }
}

int digitCount (int number)
{
    int count = !number;

    while (number > 0)
    {
        count++;
        number /= 10;
    }

    return count;
}

void displayNumber (Display *displays[], int displayCount, double number,
                    uint32_t delay)
{
    delayTime = delay;

    int digits = digitCount (number);

    if (digits > displayCount)
    {
        displayError (displays, displayCount);
    }
    else
    {
        int displayNum = (int) number;

        if (digits < displayCount
                && (int) (number * pow (10, (displayCount - digits))) % 10 != 0)
        {
            displayNum =
                    (int) (number * pow (10, (displayCount - digits)) + 0.5);

            displayDP (displays[displayCount - digits]);

            digits += displayCount - digits;
        }

        for (int i = 1; i <= digits; ++i)
        {
            displayDigit (displays[i - 1], displayNum % 10);
            displayNum /= 10;
        }
    }
}

enum
{
    DIGIT_ZERO = 6,
    DIGIT_ONE = 2,
    DIGIT_TWO = 5,
    DIGIT_THREE = 5,
    DIGIT_FOUR = 4,
    DIGIT_FIVE = 5,
    DIGIT_SIX = 6,
    DIGIT_SEVEN = 3,
    DIGIT_EIGHT = 7,
    DIGIT_NINE = 6
};

void displayDigit0 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[B], &display->segments[C],
                &display->segments[D], &display->segments[E],
                &display->segments[F] };

    blink (segments, DIGIT_ZERO);
}

void displayDigit1 (Display *display)
{
    Segment *segments[] =
        { &display->segments[B], &display->segments[C] };

    blink (segments, DIGIT_ONE);
}

void displayDigit2 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[B], &display->segments[G],
                &display->segments[E], &display->segments[D] };

    blink (segments, DIGIT_TWO);
}

void displayDigit3 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[B], &display->segments[G],
                &display->segments[C], &display->segments[D] };

    blink (segments, DIGIT_THREE);
}

void displayDigit4 (Display *display)
{
    Segment *segments[] =
        { &display->segments[F], &display->segments[B], &display->segments[G],
                &display->segments[C] };

    blink (segments, DIGIT_FOUR);
}

void displayDigit5 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[F], &display->segments[G],
                &display->segments[C], &display->segments[D] };

    blink (segments, DIGIT_FIVE);
}

void displayDigit6 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[F], &display->segments[G],
                &display->segments[E], &display->segments[C],
                &display->segments[D] };

    blink (segments, DIGIT_SIX);
}

void displayDigit7 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[B], &display->segments[C] };

    blink (segments, DIGIT_SEVEN);
}

void displayDigit8 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[B], &display->segments[C],
                &display->segments[D], &display->segments[E],
                &display->segments[F], &display->segments[G] };

    blink (segments, DIGIT_EIGHT);
}

void displayDigit9 (Display *display)
{
    Segment *segments[] =
        { &display->segments[A], &display->segments[B], &display->segments[C],
                &display->segments[D], &display->segments[F],
                &display->segments[G] };

    blink (segments, DIGIT_NINE);
}

void displayDP (Display *display)
{
    HAL_GPIO_WritePin (display->segments[H].port, display->segments[H].pin,
                       GPIO_PIN_RESET);
}

void displayError (Display *displays[], int displayCount)
{
    enum
    {
        R_SEG_COUNT = 2, E_SEG_COUNT = 5
    };

    int d = displayCount - 1;

    Segment *letterE[] =
        { &displays[d]->segments[A], &displays[d]->segments[F],
                &displays[d]->segments[G], &displays[d]->segments[E],
                &displays[d]->segments[D] };

    Segment *letterR1[] =
        { &displays[--d]->segments[E], &displays[d]->segments[G] }; // decrementing d: moving to next display

    blink (letterE, E_SEG_COUNT);
    blink (letterR1, R_SEG_COUNT);

    if (displayCount >= 3)
    {
        Segment *letterR2[] =
            { &displays[--d]->segments[E], &displays[d]->segments[G] }; // decrementing d: moving to next display

        blink (letterR2, R_SEG_COUNT);
    }
}

void blink (Segment *segments[], int segCount)
{
    for (int i = 0; i < segCount; ++i)
    {
        HAL_GPIO_WritePin (segments[i]->port, segments[i]->pin, GPIO_PIN_RESET);
    }

    HAL_Delay(delayTime);

    for (int i = 0; i < segCount; ++i)
    {
        HAL_GPIO_WritePin (segments[i]->port, segments[i]->pin,
                           GPIO_PIN_SET);
    }
}

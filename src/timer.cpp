#include "../include/timer.h"


void start_2s_timer() {
    TCCR1A = 0;                 // CTC mode
    TCCR1B = 0b00001101;        // CTC mode, 1024 prescaler
    TIMSK1 |= (1 << OCIE1A);    // Enable interrupt for OCR1A
    OCR1A = 31250 - 1;          // 2 seconds (2 / (1024 / 16 * 10^6))
}
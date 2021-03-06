#include "Trace.hh"

#include <iostream>
#include <cstdint>

void Trace::begin(UART *) {}

Trace &Trace::operator<<(char *str) {
    if (str[0] == 0x56 && str[11] == 0x23) {
        uint16_t id = *reinterpret_cast<uint16_t *>(str + 1);
        float data = *reinterpret_cast<float *>(str + 1 + 2);
        float time = *reinterpret_cast<float *>(str + 1 + 2 + 4);
        if (id == 0xff00) {
            printf("\n%i: (%.2f, %i)\n", id, time, *reinterpret_cast<uint32_t *>(str + 1 + 2));
        } else {
            printf("%i: (%.2f, %.2f)\n", id, time, data);
        }
    }
}

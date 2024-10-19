#include <stdio.h>

// Little Endian ou Big Endian

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);  // Affiche chaque octet en hexadécimal
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}



int main() {

    // Big Edian ou little Edian -> little Edian
    
    // Tester avec le nombre 15213
    short test_number = 15213;  // 15213 en hexadécimal est 0x3B6D
    
    printf("Representation de 15213 en octets (short int) :\n");
    show_short(test_number);

    return 0;
}

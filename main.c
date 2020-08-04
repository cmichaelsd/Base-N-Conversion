#include "stack.h"
#include <stdio.h>

void reverse_char_array(char arr[], int length);
void hex_to_decimal(char arr[], int length);
void decimal_to_hex(int decimal);
int hex_char_to_int(char c);

int main() {
    stack hex;
    int decimal = 61453;
    decimal_to_hex(decimal);
    printf("\n");

    init_stack(&hex, "F00D");

    hex_to_decimal(hex.stack, stack_length(&hex));

    return 0;
}

int hex_char_to_int(char c) {
    switch (c) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            return c - '0';
    }
}

void hex_to_decimal(char arr[], int length) {
    int sum = 0;

    int i;
    int pow = 1;
    int factor = 16;
    for (i = length - 1; i >= 0; --i) {
        int decimal = hex_char_to_int(arr[i]);
        sum += pow * decimal;
        pow *= factor;
    }

    /* 
    h0 = D -> 13, h1 = 0 -> 0, h2 = 0 -> 0, h3 = F -> 15
    16^0 * 13,    16^1 * 0,    16^2 * 0     16^3 * 15
    multiply hex decimal equivilant by its position from the right
    collect sum 
    */
    printf("%d", sum);
}

void decimal_to_hex(int decimal) {
    stack hex;
    char hex_set[16] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F'
    };

    int i;
    for (i = 0; decimal != 0; ++i) {
        int remainder = decimal % 16;
        decimal = decimal / 16;
        hex.stack[i] = hex_set[remainder];
    }

    hex.stack[i+1] = 0;

    reverse_char_array(hex.stack, stack_length(&hex));
    print_stack(&hex);
}

void reverse_char_array(char arr[], int length) {
    char temp;
    int i;
    int half_length = length / 2;
    for (i = 0; i < half_length; ++i) {
        temp = arr[length - 1 - i];
        arr[length - 1 - i] = arr[i];
        arr[i] = temp;
    }
}

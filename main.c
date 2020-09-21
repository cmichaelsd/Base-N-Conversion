#include "stack.h"
#include <stdio.h>

void reverse_char_array(char arr[], int length);
void to_decimal(int base, char arr[], int length);
void decimal_to_base_n(int base, int decimal);
int char_to_int(char c);

int main() {
    stack base_n;
    int decimal = 61453;
    int base = 8;

    if (base > 16) {
        printf("Base can not be greater than sixteen for this program");
        return 0;
    }
    
    decimal_to_base_n(base, decimal);
    printf("\n");

    init_stack(&base_n, "F00D");

    to_decimal(base, base_n.stack, stack_length(&base_n));

    return 0;
}

int char_to_int(char c) {
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

void to_decimal(int base, char arr[], int length) {
    int sum = 0;

    int i;
    int pow;
    for (i = length - 1, pow = 1; i >= 0; --i, pow *= base) {
        int decimal = char_to_int(arr[i]);
        sum += pow * decimal;
    }

    /* 
    h0 = D -> 13, h1 = 0 -> 0, h2 = 0 -> 0, h3 = F -> 15
    16^0 * 13,    16^1 * 0,    16^2 * 0     16^3 * 15
    multiply hex decimal equivilant by its position from the right
    collect sum 
    */
    printf("%d", sum);
}

void decimal_to_base_n(int base, int decimal) {
    stack base_n_stack;
    char char_set[16] = {
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
        int remainder = decimal % base;
        decimal = decimal / base;
        base_n_stack.stack[i] = char_set[remainder];
    }

    base_n_stack.stack[i+1] = 0;

    reverse_char_array(base_n_stack.stack, stack_length(&base_n_stack));
    print_stack(&base_n_stack);
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

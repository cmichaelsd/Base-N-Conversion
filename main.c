#include "stack.h"
#include <stdio.h>
#include <ctype.h>

void reverse_char_array(char arr[], int length);
void to_decimal(int base, char arr[], int length);
void decimal_to_base_n(int base, int decimal);
int char_to_int(char c);
char int_to_char(int n);

int main() {
    stack base_n;
    int decimal = 61453;
    int base = 16;

    if (base > 36) {
        printf("Base can not be greater than sixteen for this program");
        return 0;
    }
    
    decimal_to_base_n(base, decimal);
    printf("\n");

    init_stack(&base_n, "F00D");
    to_decimal(base, base_n.stack, stack_length(&base_n));
    
    return 0;
}

char int_to_char(int n) {
    if (n > 9) {
        return n + 55;
    }
    return n + '0';
}

int char_to_int(char c) {
    const int alpha = isalpha(c) > 0;
    /* evaluate this (boolean) 1 or 0 */
    switch (alpha) {
        case 1:
            return c - 55;
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

    int i;
    for (i = 0; decimal != 0; ++i) {
        int remainder = decimal % base;
        decimal = decimal / base;
        base_n_stack.stack[i] = int_to_char(remainder);
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

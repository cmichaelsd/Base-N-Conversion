#include "stack.h"
#include <stdio.h>
#include <ctype.h>

/* 
h0 = D -> 13, h1 = 0 -> 0, h2 = 0 -> 0, h3 = F -> 15
16^0 * 13,    16^1 * 0,    16^2 * 0     16^3 * 15
multiply hex decimal equivilant by its position from the right
collect sum 
*/

void reverse_char_array(char arr[], int length);
void from_base_n(int base, char arr[], int length);
void to_base_n(int base, int decimal);
int char_to_int(char c);
char int_to_char(int n);

int main() {
    stack base_n;
    int trigger;
    int number;
    char base_n_string[64];
    int base;

    printf("Convert decimal to a new base (1).\n");
    printf("Convert a non-decimal number to a decimal (0).\n");
    scanf("%d", &trigger);

    if (trigger) {
        printf("Enter your decimal number.\n");
        scanf("%d", &number);
        printf("What base would you like to convert to?\n");
    } else {
        printf("Enter your non-decimal number.\n");
        scanf("%s", base_n_string);
        printf("What base are you converting from?\n");
    }

    printf("Enter a base less than base36.\n");
    scanf("%d", &base);

    if (base > 36) {
        printf("Base is larger than 36.\n");
        return 0;
    }

    if (trigger) {
        to_base_n(base, number);
    } else {
        init_stack(&base_n, base_n_string);
        from_base_n(base, base_n.stack, stack_length(&base_n));
    }

    return 0;
}

char int_to_char(int n) {
    if (n > 9) {
        return n + 55;
    }
    return n + '0';
}

int char_to_int(char c) {
    if (isalpha(c) > 0) {
        return c - 55;
    }
    return c - '0';
}

void from_base_n(int base, char arr[], int length) {
    int sum = 0;
    int i;
    int pow;

    for (i = length - 1, pow = 1; i >= 0; --i, pow *= base) {
        int n = char_to_int(arr[i]);
        sum += pow * n;
    }

    printf("%d", sum);
}

void to_base_n(int base, int decimal) {
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

#include <stdio.h>

int main() {
    char str[5] = {'H', 'E', 'L', 'L', 'O'};
    char str2[5] = "Hello";
    char *ptr = &str[0];
    printf("ptr = %08x\n", ptr);
    printf("str = %08x\n", str);
    return 0;


}
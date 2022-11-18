#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mystr.h"

void test0()
{
    // char *str = "kl86g65";
    // int r6 = ht_str_len(str);
    // printf("%s length is:%d\n", str, r6);
    // int r7 = ht_str_cmp("NUL1", "NULL");
    // printf("compared is %d\n", r7);
    // int r8 = ht_str_2int("45264");
    // printf("transfer to %d\n", r8);
}

void test1()
{
    char ch = 88;
    int r1 = isalpha(ch);
    printf("%c is alpha:%d\n", ch, r1);
    int r2 = isblank(ch);
    printf("%c is blank:%d\n", ch, r2);
    int r3 = toupper(ch);
    printf("%c uppercase is:%c\n", ch, r3);
    int r4 = tolower(ch);
    printf("%c lowercase is:%c\n", ch, r4);

    char *str = "kl86g65";
    int r5 = strlen(str);
    printf("%s length is:%d\n", str, r5);
}

int main(int argc, const char *argv[])
{
    test0();
    test1();
}

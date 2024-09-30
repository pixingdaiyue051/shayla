/**
 * 共同体 一个共同体内有多个属性 但一次只能有一个属性被赋值
 * 当数据项使用两种或更多种格式又不会同时使用时可节省空间 不宜放置太多属性
 * 一个共同体内的属性都是同一个地址
 */
#include <stdio.h>
#include <stdlib.h>

typedef union {
    int int_val;
    char *ch_val;
} ID;

int main(int argc, const char *argv[]) {

    ID *id = malloc(sizeof(ID));

    id->int_val = 22221;
    printf("%d\n", id->int_val);

    id->ch_val = "5522ddd";
    printf("%s\n", id->ch_val);

    free(id->ch_val);
    free(id);
    return 0;
}

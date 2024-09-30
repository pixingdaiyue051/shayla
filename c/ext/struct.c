/**
 * 结构体 把同一事物的属性安排在同一个结构内 方便访问
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float height;
    float weight;
} Person;

Emp *person_crt(char *name, int age, float height, float weight) {
    Emp *who = malloc(sizeof(Emp));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void person_free(Emp *who) {
    if (who == NULL) {
        return;
    }
    free(who->name);
    free(who);
}

void person_show(Emp *who) {
    if (who == NULL) {
        return;
    }

    printf("name:%s\n", who->name);
    printf("age:%d\n", who->age);
    printf("height:%.2f\n", who->height);
    printf("weight:%.2f\n", who->weight);
}

int main() {
    char *s = "khnnfs";
    Emp *p1 = person_crt(s, 5, 5.3f, 2.6f);
    person_show(p1);
    person_free(p1);
    return 0;
}
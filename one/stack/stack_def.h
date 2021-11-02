typedef struct STACK
{
    double data;
    struct STACK *next;
} stack_t;

stack_t *ss_top;
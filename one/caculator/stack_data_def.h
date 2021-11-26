typedef struct STACK_DATA
{
    double data;
    struct STACK_DATA *next;
} stack_data_t;

stack_data_t *dd_top;
typedef struct STACK_OPE
{
    char ope;
    struct STACK_OPE *next;
} stack_ope_t;

stack_ope_t *ope_top;
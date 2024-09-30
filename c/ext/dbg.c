/**
 * 简单使用调试宏
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define _NDBG
#include "dbg.h"

int test_log()
{
    _ht_debug("veegdg");
    _ht_log_info("vege");
    _ht_log_warn("nfrtr");
    _ht_log_error("rethdf %s %d", "vds", 544);
}

int test_err(int argc)
{
    _ht_check_debug(argc > 1, "need more args");

    char *s = malloc(20 * sizeof(char));
    _ht_check_mem(s);

    strcpy(s, "/data/c_test/test.txt");
    FILE *f = fopen(s, "r+");
    _ht_check(f, "failed to open file %s", s);

    return 0;
_ht_error:
    if (s)
        free(s);
    if (f)
        fclose(f);
    return -1;
}

int main()
{
    test_log();
    test_err(argc);

    return 0;
_ht_error:
    return -1;
}
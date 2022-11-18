/**
 * 一个可以通用的调试宏
 * 打印日志 调试错误
 */
#ifndef _HEAD_DBG
#define _HEAD_DBG

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef _NDBG
#define _ht_debug(M, ...)
#else
#define _ht_debug(M, ...) fprintf(stderr, "[DEBUG] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define _ht_clean_errno() (errno == 0 ? "None" : strerror(errno))

#define _ht_log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d error:%s) " M "\n", __FILE__, __LINE__, _ht_clean_errno(), ##__VA_ARGS__)
#define _ht_log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d error:%s) " M "\n", __FILE__, __LINE__, _ht_clean_errno(), ##__VA_ARGS__)
#define _ht_log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define _ht_check(A, M, ...) if(!(A)) { _ht_log_error(M, ##__VA_ARGS__); errno = 0; goto _ht_error; }
#define _ht_check_sentinel(M, ...) { _ht_log_error(M, ##__VA_ARGS__); errno = 0; goto _ht_error; }
#define _ht_check_mem(A) if(!(A)) { _ht_log_error("Out of Memory"); errno = 0; goto _ht_error; }
#define _ht_check_debug(A, M, ...) if(!(A)) { _ht_debug(M, ##__VA_ARGS__); errno = 0; goto _ht_error; }

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
typedef LPVOID thread_param_p;
typedef DWORD(WINAPI *COMMON_THREAD_RETURN_TYPE)(thread_param_p param);
#elif defined(__linux__)
typedef void COMMON_THREAD_RETURN_TYPE;
typedef void *thread_param_p;
#endif

struct A
{
    char name[32];
    char value[100];
};

int main()
{
    struct A a;
    printf("%lu", sizeof(a) / sizeof(char));
    return 0;
}
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

typedef int (*fun)(void);

_Noreturn void abort()
{
    if ( getenv("FAKEABORT") )
    {
        kill(getpid(), 9);
    } else
    {
        fun abrt;
        abrt = dlsym(RTLD_NEXT,"abort");
        abrt();
    }
    abort();
}
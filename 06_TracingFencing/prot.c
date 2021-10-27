#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>


typedef void (*fun)( const char *);

int unlink( const char *name)
{
    if ( strstr( name, "PROTECT") == NULL )
    {
        fun old_unlink;
        old_unlink = dlsym( RTLD_NEXT,"unlink");
        old_unlink( name);
    }
}
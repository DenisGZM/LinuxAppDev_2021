#include "../src/buf.h"
#include "../src/tests.h"



#suite Grow
#test OperatorSqrPar
    long *ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
    ck_assert_uint_eq( buf_size(ai), 10000);
    int match = 0;
    for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;
    ck_assert_uint_eq( match, 10000);
#include "../src/buf.h"
#include "../src/tests.h"

static int count_fail = 0;
static int count_pass = 0;

#suite Tests
#test Initialization
    float *a = 0;
    ck_assert_int_eq(buf_capacity(a), 0);
    ck_assert_int_eq(buf_size(a), 0);
    buf_push(a, 1.3f);
    ck_assert_int_eq(buf_size(a), 1);
    buf_clear(a);
    ck_assert_int_eq(buf_size(a), 0);

    
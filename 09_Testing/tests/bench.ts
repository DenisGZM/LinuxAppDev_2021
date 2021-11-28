#include "../src/buf.h"
#include "../src/tests.h"
#include <sys/time.h>

static int count_fail = 0;
static int count_pass = 0;

static uint32_t
pcg32(uint64_t *s)
{
    uint64_t m = 0x5851f42d4c957f2d;
    uint64_t a = 0x8b260b70b8e98891;
    uint64_t p = *s;
    uint32_t x = ((p >> 18) ^ p) >> 27;
    uint32_t r = p >> 59;
    *s = p * m + a;
    return (x >> r) | (x << (-r & 31u));
}

static unsigned long
bench(uint64_t *rng)
{
    unsigned long r = 0;
    uint32_t n = 1000000 + pcg32(rng) % 4000000;
    float *buf = 0;

    for (uint32_t i = 0; i < n; i++)
        buf_push(buf, pcg32(rng) / (double)UINT32_MAX);

    float threshold = pcg32(rng) / (double)UINT32_MAX;
    for (uint32_t i = 0; i < n; i++)
        r += buf[i] > threshold;

    buf_free(buf);
    return r;
}

uint64_t
uepoch(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return 1000000LL * tv.tv_sec + tv.tv_usec;
}

#suite Tests
#test Benchmark
    uint64_t rng = strtoull("558d2750ae0e0887", 0, 16);
    unsigned long r = 0;
    uint64_t start = uepoch();
    for (int i = 0; i < 30; i++)
        r += bench(&rng);
    double t = (uepoch() - start) / 1e6;
    ck_assert_uint_eq(r, 41544924);
    printf("%.6gs : acutal %lu, expect 41544924\n", t, r);

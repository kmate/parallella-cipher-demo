#include <e-lib.h>
#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la2 = (bool *) 8192;
volatile bool *const la3 = (bool *) 8208;
volatile bool *const la5 = (bool *) 2156929024;
volatile bool *const la6 = (bool *) 2156929040;
volatile uint32_t *const la7 = (uint32_t *) 2156929056;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
volatile void *const sa4 = (void *) 16781392;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,32");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
int main()
{
    uint32_t _a0[18] __attribute__((aligned(16)));
    uint32_t *a0 = _a0;
    uint32_t _a1[1024] __attribute__((aligned(16)));
    uint32_t *a1 = _a1;
    
    core_read_shared(sa0, a0, 0, 0, 17);
    core_read_shared(sa1, a1, 0, 0, 1023);
    while (1) {
        uint64_t _a2[1] __attribute__((aligned(16)));
        uint64_t *a2 = _a2;
        bool v3;
        uint64_t v4;
        uint32_t r5;
        uint32_t r6;
        bool v7;
        uint32_t r8;
        bool v9;
        
        v3 = core_read_h2c(sa4, la2, la3, a2, 0, 1);
        if (!v3) {
            core_close_chan(la7, la5, la6);
            core_halt();
        }
        v4 = a2[0];
        r5 = (uint32_t) (v4 >> 32) ^ a0[0];
        r6 = (((a1[r5 >> 24] + a1[(r5 >> 16 & 255) + 256]) ^ a1[(r5 >> 8 &
                                                                 255) + 512]) +
              a1[(r5 & 255) + 768]) ^ (uint32_t) v4;
        v7 = core_write_c2c(la7, la5, la6, &r6, 0, 1);
        if (!v7) {
            core_close_chan(sa4, la2, la3);
            core_halt();
        }
        r8 = r5;
        v9 = core_write_c2c(la7, la5, la6, &r8, 0, 1);
        if (!v9) {
            core_close_chan(sa4, la2, la3);
            core_halt();
        }
    }
    return 0;
}

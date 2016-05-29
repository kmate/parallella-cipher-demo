#include <e-lib.h>
#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la47 = (bool *) 8192;
volatile bool *const la48 = (bool *) 8208;
volatile uint32_t *const la49 = (uint32_t *) 8224;
volatile bool *const la50 = (bool *) 8240;
volatile bool *const la51 = (bool *) 8256;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
volatile void *const sa52 = (void *) 16781408;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,11");
int main()
{
    uint32_t _a0[18] __attribute__((aligned(16)));
    uint32_t *a0 = _a0;
    uint32_t _a1[1024] __attribute__((aligned(16)));
    uint32_t *a1 = _a1;
    
    core_read_shared(sa0, a0, 0, 0, 17);
    core_read_shared(sa1, a1, 0, 0, 1023);
    while (1) {
        uint32_t _a2[1] __attribute__((aligned(16)));
        uint32_t *a2 = _a2;
        bool v3;
        uint32_t v4;
        uint32_t _a5[1] __attribute__((aligned(16)));
        uint32_t *a5 = _a5;
        bool v6;
        uint32_t v7;
        uint32_t r8;
        uint64_t r9;
        bool v10;
        
        v3 = core_read_c2c(la49, la47, la48, a2, 0, 1);
        if (!v3) {
            core_close_chan(sa52, la50, la51);
            core_halt();
        }
        v4 = a2[0];
        v6 = core_read_c2c(la49, la47, la48, a5, 0, 1);
        if (!v6) {
            core_close_chan(sa52, la50, la51);
            core_halt();
        }
        v7 = a5[0];
        r8 = v4 ^ a0[15];
        r9 = (uint64_t) (r8 ^ a0[17]) << 32 | (uint64_t) (((((a1[r8 >> 24] +
                                                              a1[(r8 >> 16 &
                                                                  255) + 256]) ^
                                                             a1[(r8 >> 8 &
                                                                 255) + 512]) +
                                                            a1[(r8 & 255) +
                                                               768]) ^ v7) ^
                                                          a0[16]);
        v10 = core_write_c2h(sa52, la50, la51, &r9, 0, 1);
        if (!v10) {
            core_close_chan(la49, la47, la48);
            core_halt();
        }
    }
    return 0;
}

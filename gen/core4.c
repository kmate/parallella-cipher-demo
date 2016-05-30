#include <e-lib.h>
#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la14 = (bool *) 8192;
volatile bool *const la15 = (bool *) 8208;
volatile uint32_t *const la16 = (uint32_t *) 8224;
volatile bool *const la17 = (bool *) 2224037888;
volatile bool *const la18 = (bool *) 2224037904;
volatile uint32_t *const la19 = (uint32_t *) 2224037920;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
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
        uint32_t r2;
        uint32_t _a3[512] __attribute__((aligned(16)));
        uint32_t *a3 = _a3;
        bool v4;
        uint32_t r5;
        uint32_t _a6[512] __attribute__((aligned(16)));
        uint32_t *a6 = _a6;
        bool v7;
        uint32_t v9;
        uint32_t r10;
        uint32_t v12;
        bool v14;
        uint32_t r15;
        uint32_t v17;
        bool v18;
        
        r2 = 512;
        v4 = core_read_c2c(la16, la14, la15, a3, 0, r2);
        if (!v4) {
            core_close_chan(la19, la17, la18);
            core_halt();
        }
        r5 = 512;
        v7 = core_read_c2c(la16, la14, la15, a6, 0, r5);
        if (!v7) {
            core_close_chan(la19, la17, la18);
            core_halt();
        }
        
        uint32_t _a8[r2] __attribute__((aligned(16)));
        uint32_t *a8 = _a8;
        
        for (v9 = 0; v9 < r2; v9++) {
            a8[v9] = a3[v9] ^ a0[4];
        }
        r10 = r2 <= r5 ? r2 : r5;
        
        uint32_t _a11[r2 <= r5 ? r2 : r5] __attribute__((aligned(16)));
        uint32_t *a11 = _a11;
        
        for (v12 = 0; v12 < (r2 <= r5 ? r2 : r5); v12++) {
            uint32_t let13;
            
            let13 = a8[v12];
            a11[v12] = (((a1[let13 >> 24] + a1[(let13 >> 16 & 255) + 256]) ^
                         a1[(let13 >> 8 & 255) + 512]) + a1[(let13 & 255) +
                                                            768]) ^ a6[v12];
        }
        v14 = core_write_c2c(la19, la17, la18, a11, 0, r10);
        if (!v14) {
            core_close_chan(la16, la14, la15);
            core_halt();
        }
        r15 = r2;
        
        uint32_t _a16[r2] __attribute__((aligned(16)));
        uint32_t *a16 = _a16;
        
        for (v17 = 0; v17 < r2; v17++) {
            a16[v17] = a8[v17];
        }
        v18 = core_write_c2c(la19, la17, la18, a16, 0, r15);
        if (!v18) {
            core_close_chan(la16, la14, la15);
            core_halt();
        }
    }
    return 0;
}

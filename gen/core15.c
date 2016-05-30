#include <e-lib.h>
#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la47 = (bool *) 8192;
volatile bool *const la48 = (bool *) 8208;
volatile uint32_t *const la49 = (uint32_t *) 8224;
volatile bool *const la50 = (bool *) 10272;
volatile bool *const la51 = (bool *) 10288;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
volatile void *const sa52 = (void *) 16785488;
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
        uint32_t r2;
        uint32_t _a3[512] __attribute__((aligned(16)));
        uint32_t *a3 = _a3;
        bool v4;
        uint32_t r5;
        uint32_t _a6[512] __attribute__((aligned(16)));
        uint32_t *a6 = _a6;
        bool v7;
        uint32_t v9;
        uint32_t let10;
        uint32_t r11;
        uint32_t let12;
        uint32_t let14;
        uint32_t v15;
        bool v17;
        
        r2 = 512;
        v4 = core_read_c2c(la49, la47, la48, a3, 0, r2);
        if (!v4) {
            core_close_chan(sa52, la50, la51);
            core_halt();
        }
        r5 = 512;
        v7 = core_read_c2c(la49, la47, la48, a6, 0, r5);
        if (!v7) {
            core_close_chan(sa52, la50, la51);
            core_halt();
        }
        
        uint32_t _a8[r2] __attribute__((aligned(16)));
        uint32_t *a8 = _a8;
        
        for (v9 = 0; v9 < r2; v9++) {
            a8[v9] = a3[v9] ^ a0[15];
        }
        let10 = r2 <= r5 ? r2 : r5;
        r11 = r2 <= let10 ? r2 : let10;
        let12 = r2 <= r5 ? r2 : r5;
        
        uint64_t _a13[r2 <= let12 ? r2 : let12] __attribute__((aligned(16)));
        uint64_t *a13 = _a13;
        
        let14 = r2 <= r5 ? r2 : r5;
        for (v15 = 0; v15 < (r2 <= let14 ? r2 : let14); v15++) {
            uint32_t let16;
            
            let16 = a8[v15];
            a13[v15] = (uint64_t) (let16 ^ a0[17]) << 32 |
                (uint64_t) (((((a1[let16 >> 24] + a1[(let16 >> 16 & 255) +
                                                     256]) ^ a1[(let16 >> 8 &
                                                                 255) + 512]) +
                              a1[(let16 & 255) + 768]) ^ a6[v15]) ^ a0[16]);
        }
        v17 = core_write_c2h(sa52, la50, la51, a13, 0, r11);
        if (!v17) {
            core_close_chan(la49, la47, la48);
            core_halt();
        }
    }
    return 0;
}

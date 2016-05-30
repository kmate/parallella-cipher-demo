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
        uint32_t r2;
        uint64_t _a3[512] __attribute__((aligned(16)));
        uint64_t *a3 = _a3;
        bool v4;
        uint32_t v6;
        uint32_t r7;
        uint32_t v9;
        bool v11;
        uint32_t r12;
        uint32_t v14;
        bool v15;
        
        r2 = 512;
        v4 = core_read_h2c(sa4, la2, la3, a3, 0, r2);
        if (!v4) {
            core_close_chan(la7, la5, la6);
            core_halt();
        }
        
        uint32_t _a5[r2] __attribute__((aligned(16)));
        uint32_t *a5 = _a5;
        
        for (v6 = 0; v6 < r2; v6++) {
            a5[v6] = (uint32_t) (a3[v6] >> 32) ^ a0[0];
        }
        r7 = r2;
        
        uint32_t _a8[r2] __attribute__((aligned(16)));
        uint32_t *a8 = _a8;
        
        for (v9 = 0; v9 < r2; v9++) {
            uint32_t let10;
            
            let10 = a5[v9];
            a8[v9] = (((a1[let10 >> 24] + a1[(let10 >> 16 & 255) + 256]) ^
                       a1[(let10 >> 8 & 255) + 512]) + a1[(let10 & 255) +
                                                          768]) ^
                (uint32_t) a3[v9];
        }
        v11 = core_write_c2c(la7, la5, la6, a8, 0, r7);
        if (!v11) {
            core_close_chan(sa4, la2, la3);
            core_halt();
        }
        r12 = r2;
        
        uint32_t _a13[r2] __attribute__((aligned(16)));
        uint32_t *a13 = _a13;
        
        for (v14 = 0; v14 < r2; v14++) {
            a13[v14] = a5[v14];
        }
        v15 = core_write_c2c(la7, la5, la6, a13, 0, r12);
        if (!v15) {
            core_close_chan(sa4, la2, la3);
            core_halt();
        }
    }
    return 0;
}

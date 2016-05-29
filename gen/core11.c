#include <e-lib.h>
#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la35 = (bool *) 8192;
volatile bool *const la36 = (bool *) 8208;
volatile uint32_t *const la37 = (uint32_t *) 8224;
volatile bool *const la38 = (bool *) 2357207040;
volatile bool *const la39 = (bool *) 2357207056;
volatile uint32_t *const la40 = (uint32_t *) 2357207072;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,34");
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
        uint32_t r9;
        bool v10;
        uint32_t r11;
        bool v12;
        
        v3 = core_read_c2c(la37, la35, la36, a2, 0, 1);
        if (!v3) {
            core_close_chan(la40, la38, la39);
            core_halt();
        }
        v4 = a2[0];
        v6 = core_read_c2c(la37, la35, la36, a5, 0, 1);
        if (!v6) {
            core_close_chan(la40, la38, la39);
            core_halt();
        }
        v7 = a5[0];
        r8 = v4 ^ a0[11];
        r9 = (((a1[r8 >> 24] + a1[(r8 >> 16 & 255) + 256]) ^ a1[(r8 >> 8 &
                                                                 255) + 512]) +
              a1[(r8 & 255) + 768]) ^ v7;
        v10 = core_write_c2c(la40, la38, la39, &r9, 0, 1);
        if (!v10) {
            core_close_chan(la37, la35, la36);
            core_halt();
        }
        r11 = r8;
        v12 = core_write_c2c(la40, la38, la39, &r11, 0, 1);
        if (!v12) {
            core_close_chan(la37, la35, la36);
            core_halt();
        }
    }
    return 0;
}

#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la105 = (bool *) 2359304272;
volatile bool *const la106 = (bool *) 2359304288;
volatile uint32_t *const la107 = (uint32_t *) 8192;
volatile uint32_t *const la108 = (uint32_t *) 2359304304;
volatile uint32_t *const la110 = (uint32_t *) 8208;
volatile uint32_t *const la111 = (uint32_t *) 8224;
volatile bool *const la112 = (bool *) 8272;
volatile uint32_t *const la114 = (uint32_t *) 8304;
volatile uint32_t *const la115 = (uint32_t *) 8320;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
volatile void *const sa116 = (void *) 16781488;
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
        bool v3;
        bool v17;
        uint32_t v18;
        uint32_t r19;
        bool v20;
        bool v34;
        uint32_t v35;
        uint32_t r36;
        bool v37;
        bool r38;
        
        v3 = la106[0];
        if (v3) {
            bool r4;
            bool r5;
            bool v16;
            
            r4 = true;
            r5 = true;
            while (1) {
                bool v6;
                uint32_t v7;
                uint32_t v8;
                
                v6 = r4;
                if (!v6)
                    break;
                v7 = la107[0];
                v8 = la110[0];
                if (!(v7 == v8)) {
                    uint32_t v9;
                    uint32_t v10;
                    uint32_t let11;
                    uint32_t let12;
                    uint32_t let13;
                    uint32_t let14;
                    
                    v9 = la107[0];
                    v10 = la111[v9];
                    let11 = v9 + 1;
                    let12 = 11;
                    la107[0] = let11 < let12 ? let11 : let11 - let12;
                    let13 = v9 + 1;
                    let14 = 11;
                    la108[0] = let13 < let14 ? let13 : let13 - let14;
                    r2 = v10;
                    r4 = false;
                } else {
                    bool v15;
                    
                    v15 = la105[0];
                    if (!v15) {
                        r4 = false;
                        r5 = false;
                    }
                }
            }
            v16 = r5;
            la106[0] = v16;
        }
        v17 = la106[0];
        if (!v17) {
            la112[0] = false;
            core_halt();
        }
        v18 = r2;
        v20 = la106[0];
        if (v20) {
            bool r21;
            bool r22;
            bool v33;
            
            r21 = true;
            r22 = true;
            while (1) {
                bool v23;
                uint32_t v24;
                uint32_t v25;
                
                v23 = r21;
                if (!v23)
                    break;
                v24 = la107[0];
                v25 = la110[0];
                if (!(v24 == v25)) {
                    uint32_t v26;
                    uint32_t v27;
                    uint32_t let28;
                    uint32_t let29;
                    uint32_t let30;
                    uint32_t let31;
                    
                    v26 = la107[0];
                    v27 = la111[v26];
                    let28 = v26 + 1;
                    let29 = 11;
                    la107[0] = let28 < let29 ? let28 : let28 - let29;
                    let30 = v26 + 1;
                    let31 = 11;
                    la108[0] = let30 < let31 ? let30 : let30 - let31;
                    r19 = v27;
                    r21 = false;
                } else {
                    bool v32;
                    
                    v32 = la105[0];
                    if (!v32) {
                        r21 = false;
                        r22 = false;
                    }
                }
            }
            v33 = r22;
            la106[0] = v33;
        }
        v34 = la106[0];
        if (!v34) {
            la112[0] = false;
            core_halt();
        }
        v35 = r19;
        r36 = v18 ^ a0[15];
        v37 = la112[0];
        if (v37) {
            while (1) {
                bool v39;
                uint32_t v40;
                uint32_t v41;
                bool r42;
                uint32_t let43;
                uint32_t let44;
                bool v49;
                
                v39 = la112[0];
                v40 = la114[0];
                v41 = la115[0];
                r42 = false;
                let43 = v41 + 1;
                let44 = 11;
                if ((let43 < let44 ? let43 : let43 - let44) == v40) {
                    r42 = false;
                } else {
                    uint32_t v45;
                    uint64_t _a46[1] __attribute__((aligned(16)));
                    uint64_t *a46 = _a46;
                    uint32_t let47;
                    uint32_t let48;
                    
                    v45 = la115[0];
                    a46[0] = (uint64_t) (r36 ^ a0[17]) << 32 |
                        (uint64_t) (((((a1[r36 >> 24] + a1[(r36 >> 16 & 255) +
                                                           256]) ^ a1[(r36 >>
                                                                       8 &
                                                                       255) +
                                                                      512]) +
                                      a1[(r36 & 255) + 768]) ^ v35) ^ a0[16]);
                    core_write_shared(sa116, a46, v45, 0, 0);
                    let47 = v41 + 1;
                    let48 = 11;
                    la115[0] = let47 < let48 ? let47 : let47 - let48;
                    r42 = true;
                }
                v49 = r42;
                if (!(v39 && !v49))
                    break;
            }
            r38 = true;
        } else {
            r38 = false;
        }
        if (!r38) {
            la105[0] = false;
            core_halt();
        }
    }
    return 0;
}

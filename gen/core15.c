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
        uint32_t v17;
        uint32_t r18;
        bool v19;
        uint32_t v33;
        uint32_t r34;
        bool v35;
        bool r36;
        
        v3 = la105[0];
        la106[0] = v3;
        if (v3) {
            uint32_t r4;
            bool r5;
            uint32_t v16;
            
            r5 = true;
            while (1) {
                bool v6;
                bool v7;
                uint32_t v8;
                uint32_t v9;
                
                v6 = la105[0];
                v7 = r5;
                if (!(v6 && v7))
                    break;
                v8 = la107[0];
                v9 = la110[0];
                if (!(v8 == v9)) {
                    uint32_t v10;
                    uint32_t v11;
                    uint32_t let12;
                    uint32_t let13;
                    uint32_t let14;
                    uint32_t let15;
                    
                    v10 = la107[0];
                    v11 = la111[v10];
                    let12 = v10 + 1;
                    let13 = 11;
                    la107[0] = let12 < let13 ? let12 : let12 - let13;
                    let14 = v10 + 1;
                    let15 = 11;
                    la108[0] = let14 < let15 ? let14 : let14 - let15;
                    r4 = v11;
                    r5 = false;
                }
            }
            v16 = r4;
            r2 = v16;
        }
        if (!v3) {
            la112[0] = false;
            core_halt();
        }
        v17 = r2;
        v19 = la105[0];
        la106[0] = v19;
        if (v19) {
            uint32_t r20;
            bool r21;
            uint32_t v32;
            
            r21 = true;
            while (1) {
                bool v22;
                bool v23;
                uint32_t v24;
                uint32_t v25;
                
                v22 = la105[0];
                v23 = r21;
                if (!(v22 && v23))
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
                    r20 = v27;
                    r21 = false;
                }
            }
            v32 = r20;
            r18 = v32;
        }
        if (!v19) {
            la112[0] = false;
            core_halt();
        }
        v33 = r18;
        r34 = v17 ^ a0[15];
        v35 = la112[0];
        if (v35) {
            while (1) {
                bool v37;
                uint32_t v38;
                uint32_t v39;
                bool r40;
                uint32_t let41;
                uint32_t let42;
                bool v47;
                
                v37 = la112[0];
                v38 = la114[0];
                v39 = la115[0];
                r40 = false;
                let41 = v39 + 1;
                let42 = 11;
                if ((let41 < let42 ? let41 : let41 - let42) == v38) {
                    r40 = false;
                } else {
                    uint32_t v43;
                    uint64_t _a44[1] __attribute__((aligned(16)));
                    uint64_t *a44 = _a44;
                    uint32_t let45;
                    uint32_t let46;
                    
                    v43 = la115[0];
                    a44[0] = (uint64_t) (r34 ^ a0[17]) << 32 |
                        (uint64_t) (((((a1[r34 >> 24] + a1[(r34 >> 16 & 255) +
                                                           256]) ^ a1[(r34 >>
                                                                       8 &
                                                                       255) +
                                                                      512]) +
                                      a1[(r34 & 255) + 768]) ^ v33) ^ a0[16]);
                    core_write_shared(sa116, a44, v43, 0, 0);
                    let45 = v39 + 1;
                    let46 = 11;
                    la115[0] = let45 < let46 ? let45 : let45 - let46;
                    r40 = true;
                }
                v47 = r40;
                if (!(v37 && !v47))
                    break;
            }
            r36 = true;
        } else {
            r36 = false;
        }
        if (!r36) {
            la105[0] = false;
            core_halt();
        }
    }
    return 0;
}

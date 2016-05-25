#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
volatile bool *const la70 = (bool *) 2291146832;
volatile bool *const la71 = (bool *) 2291146848;
volatile uint32_t *const la72 = (uint32_t *) 8192;
volatile uint32_t *const la73 = (uint32_t *) 2291146864;
volatile uint32_t *const la75 = (uint32_t *) 8208;
volatile uint32_t *const la76 = (uint32_t *) 8224;
volatile bool *const la77 = (bool *) 8272;
volatile uint32_t *const la80 = (uint32_t *) 8304;
volatile uint32_t *const la81 = (uint32_t *) 8320;
volatile uint32_t *const la82 = (uint32_t *) 2293243920;
volatile uint32_t *const la83 = (uint32_t *) 2293243936;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,34");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,10");
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
        bool v49;
        bool r50;
        
        v3 = la70[0];
        la71[0] = v3;
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
                
                v6 = la70[0];
                v7 = r5;
                if (!(v6 && v7))
                    break;
                v8 = la72[0];
                v9 = la75[0];
                if (!(v8 == v9)) {
                    uint32_t v10;
                    uint32_t v11;
                    uint32_t let12;
                    uint32_t let13;
                    uint32_t let14;
                    uint32_t let15;
                    
                    v10 = la72[0];
                    v11 = la76[v10];
                    let12 = v10 + 1;
                    let13 = 11;
                    la72[0] = let12 < let13 ? let12 : let12 - let13;
                    let14 = v10 + 1;
                    let15 = 11;
                    la73[0] = let14 < let15 ? let14 : let14 - let15;
                    r4 = v11;
                    r5 = false;
                }
            }
            v16 = r4;
            r2 = v16;
        }
        if (!v3) {
            la77[0] = false;
            core_halt();
        }
        v17 = r2;
        v19 = la70[0];
        la71[0] = v19;
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
                
                v22 = la70[0];
                v23 = r21;
                if (!(v22 && v23))
                    break;
                v24 = la72[0];
                v25 = la75[0];
                if (!(v24 == v25)) {
                    uint32_t v26;
                    uint32_t v27;
                    uint32_t let28;
                    uint32_t let29;
                    uint32_t let30;
                    uint32_t let31;
                    
                    v26 = la72[0];
                    v27 = la76[v26];
                    let28 = v26 + 1;
                    let29 = 11;
                    la72[0] = let28 < let29 ? let28 : let28 - let29;
                    let30 = v26 + 1;
                    let31 = 11;
                    la73[0] = let30 < let31 ? let30 : let30 - let31;
                    r20 = v27;
                    r21 = false;
                }
            }
            v32 = r20;
            r18 = v32;
        }
        if (!v19) {
            la77[0] = false;
            core_halt();
        }
        v33 = r18;
        r34 = v17 ^ a0[10];
        v35 = la77[0];
        if (v35) {
            while (1) {
                bool v37;
                uint32_t v38;
                uint32_t v39;
                bool r40;
                uint32_t let41;
                uint32_t let42;
                bool v48;
                
                v37 = la77[0];
                v38 = la80[0];
                v39 = la81[0];
                r40 = false;
                let41 = v39 + 1;
                let42 = 11;
                if ((let41 < let42 ? let41 : let41 - let42) == v38) {
                    r40 = false;
                } else {
                    uint32_t v43;
                    uint32_t let44;
                    uint32_t let45;
                    uint32_t let46;
                    uint32_t let47;
                    
                    v43 = la81[0];
                    la83[v43] = (((a1[r34 >> 24] + a1[(r34 >> 16 & 255) +
                                                      256]) ^ a1[(r34 >> 8 &
                                                                  255) + 512]) +
                                 a1[(r34 & 255) + 768]) ^ v33;
                    let44 = v39 + 1;
                    let45 = 11;
                    la81[0] = let44 < let45 ? let44 : let44 - let45;
                    let46 = v39 + 1;
                    let47 = 11;
                    la82[0] = let46 < let47 ? let46 : let46 - let47;
                    r40 = true;
                }
                v48 = r40;
                if (!(v37 && !v48))
                    break;
            }
            r36 = true;
        } else {
            r36 = false;
        }
        if (!r36) {
            la70[0] = false;
            core_halt();
        }
        v49 = la77[0];
        if (v49) {
            while (1) {
                bool v51;
                uint32_t v52;
                uint32_t v53;
                bool r54;
                uint32_t let55;
                uint32_t let56;
                bool v62;
                
                v51 = la77[0];
                v52 = la80[0];
                v53 = la81[0];
                r54 = false;
                let55 = v53 + 1;
                let56 = 11;
                if ((let55 < let56 ? let55 : let55 - let56) == v52) {
                    r54 = false;
                } else {
                    uint32_t v57;
                    uint32_t let58;
                    uint32_t let59;
                    uint32_t let60;
                    uint32_t let61;
                    
                    v57 = la81[0];
                    la83[v57] = r34;
                    let58 = v53 + 1;
                    let59 = 11;
                    la81[0] = let58 < let59 ? let58 : let58 - let59;
                    let60 = v53 + 1;
                    let61 = 11;
                    la82[0] = let60 < let61 ? let60 : let60 - let61;
                    r54 = true;
                }
                v62 = r54;
                if (!(v51 && !v62))
                    break;
            }
            r50 = true;
        } else {
            r50 = false;
        }
        if (!r50) {
            la70[0] = false;
            core_halt();
        }
    }
    return 0;
}

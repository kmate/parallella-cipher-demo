#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
volatile uint32_t *const la10 = (uint32_t *) 8288;
volatile uint32_t *const la11 = (uint32_t *) 8304;
volatile uint32_t *const la12 = (uint32_t *) 2156929040;
volatile uint32_t *const la13 = (uint32_t *) 2156929056;
volatile bool *const la2 = (bool *) 8192;
volatile bool *const la3 = (bool *) 8208;
volatile uint32_t *const la4 = (uint32_t *) 8224;
volatile uint32_t *const la5 = (uint32_t *) 8240;
volatile bool *const la7 = (bool *) 8256;
volatile void *const sa0 = (void *) 16777216;
volatile void *const sa1 = (void *) 16777296;
volatile void *const sa6 = (void *) 16781392;
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
        uint64_t r2;
        bool v3;
        bool v16;
        uint64_t v17;
        uint32_t r18;
        bool v19;
        bool r20;
        bool v33;
        bool r34;
        
        v3 = la3[0];
        if (v3) {
            bool r4;
            bool r5;
            bool v15;
            
            r4 = true;
            r5 = true;
            while (1) {
                bool v6;
                uint32_t v7;
                uint32_t v8;
                
                v6 = r4;
                if (!v6)
                    break;
                v7 = la4[0];
                v8 = la5[0];
                if (!(v7 == v8)) {
                    uint32_t v9;
                    uint64_t _a10[1] __attribute__((aligned(16)));
                    uint64_t *a10 = _a10;
                    uint64_t v11;
                    uint32_t let12;
                    uint32_t let13;
                    
                    v9 = la4[0];
                    core_read_shared(sa6, a10, v9, 0, 0);
                    v11 = a10[0];
                    let12 = v9 + 1;
                    let13 = 11;
                    la4[0] = let12 < let13 ? let12 : let12 - let13;
                    r2 = v11;
                    r4 = false;
                } else {
                    bool v14;
                    
                    v14 = la2[0];
                    if (!v14) {
                        r4 = false;
                        r5 = false;
                    }
                }
            }
            v15 = r5;
            la3[0] = v15;
        }
        v16 = la3[0];
        if (!v16) {
            la7[0] = false;
            core_halt();
        }
        v17 = r2;
        r18 = (uint32_t) (v17 >> 32) ^ a0[0];
        v19 = la7[0];
        if (v19) {
            while (1) {
                bool v21;
                uint32_t v22;
                uint32_t v23;
                bool r24;
                uint32_t let25;
                uint32_t let26;
                bool v32;
                
                v21 = la7[0];
                v22 = la10[0];
                v23 = la11[0];
                r24 = false;
                let25 = v23 + 1;
                let26 = 11;
                if ((let25 < let26 ? let25 : let25 - let26) == v22) {
                    r24 = false;
                } else {
                    uint32_t v27;
                    uint32_t let28;
                    uint32_t let29;
                    uint32_t let30;
                    uint32_t let31;
                    
                    v27 = la11[0];
                    la13[v27] = (((a1[r18 >> 24] + a1[(r18 >> 16 & 255) +
                                                      256]) ^ a1[(r18 >> 8 &
                                                                  255) + 512]) +
                                 a1[(r18 & 255) + 768]) ^ (uint32_t) v17;
                    let28 = v23 + 1;
                    let29 = 11;
                    la11[0] = let28 < let29 ? let28 : let28 - let29;
                    let30 = v23 + 1;
                    let31 = 11;
                    la12[0] = let30 < let31 ? let30 : let30 - let31;
                    r24 = true;
                }
                v32 = r24;
                if (!(v21 && !v32))
                    break;
            }
            r20 = true;
        } else {
            r20 = false;
        }
        if (!r20) {
            la2[0] = false;
            core_halt();
        }
        v33 = la7[0];
        if (v33) {
            while (1) {
                bool v35;
                uint32_t v36;
                uint32_t v37;
                bool r38;
                uint32_t let39;
                uint32_t let40;
                bool v46;
                
                v35 = la7[0];
                v36 = la10[0];
                v37 = la11[0];
                r38 = false;
                let39 = v37 + 1;
                let40 = 11;
                if ((let39 < let40 ? let39 : let39 - let40) == v36) {
                    r38 = false;
                } else {
                    uint32_t v41;
                    uint32_t let42;
                    uint32_t let43;
                    uint32_t let44;
                    uint32_t let45;
                    
                    v41 = la11[0];
                    la13[v41] = r18;
                    let42 = v37 + 1;
                    let43 = 11;
                    la11[0] = let42 < let43 ? let42 : let42 - let43;
                    let44 = v37 + 1;
                    let45 = 11;
                    la12[0] = let44 < let45 ? let44 : let44 - let45;
                    r38 = true;
                }
                v46 = r38;
                if (!(v35 && !v46))
                    break;
            }
            r34 = true;
        } else {
            r34 = false;
        }
        if (!r34) {
            la2[0] = false;
            core_halt();
        }
    }
    return 0;
}

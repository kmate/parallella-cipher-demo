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
        uint64_t v16;
        uint32_t r17;
        bool v18;
        bool r19;
        bool v32;
        bool r33;
        
        v3 = la2[0];
        la3[0] = v3;
        if (v3) {
            uint64_t r4;
            bool r5;
            uint64_t v15;
            
            r5 = true;
            while (1) {
                bool v6;
                bool v7;
                uint32_t v8;
                uint32_t v9;
                
                v6 = la2[0];
                v7 = r5;
                if (!(v6 && v7))
                    break;
                v8 = la4[0];
                v9 = la5[0];
                if (!(v8 == v9)) {
                    uint32_t v10;
                    uint64_t _a11[1] __attribute__((aligned(16)));
                    uint64_t *a11 = _a11;
                    uint64_t v12;
                    uint32_t let13;
                    uint32_t let14;
                    
                    v10 = la4[0];
                    core_read_shared(sa6, a11, v10, 0, 0);
                    v12 = a11[0];
                    let13 = v10 + 1;
                    let14 = 11;
                    la4[0] = let13 < let14 ? let13 : let13 - let14;
                    r4 = v12;
                    r5 = false;
                }
            }
            v15 = r4;
            r2 = v15;
        }
        if (!v3) {
            la7[0] = false;
            core_halt();
        }
        v16 = r2;
        r17 = (uint32_t) (v16 >> 32) ^ a0[0];
        v18 = la7[0];
        if (v18) {
            while (1) {
                bool v20;
                uint32_t v21;
                uint32_t v22;
                bool r23;
                uint32_t let24;
                uint32_t let25;
                bool v31;
                
                v20 = la7[0];
                v21 = la10[0];
                v22 = la11[0];
                r23 = false;
                let24 = v22 + 1;
                let25 = 11;
                if ((let24 < let25 ? let24 : let24 - let25) == v21) {
                    r23 = false;
                } else {
                    uint32_t v26;
                    uint32_t let27;
                    uint32_t let28;
                    uint32_t let29;
                    uint32_t let30;
                    
                    v26 = la11[0];
                    la13[v26] = (((a1[r17 >> 24] + a1[(r17 >> 16 & 255) +
                                                      256]) ^ a1[(r17 >> 8 &
                                                                  255) + 512]) +
                                 a1[(r17 & 255) + 768]) ^ (uint32_t) v16;
                    let27 = v22 + 1;
                    let28 = 11;
                    la11[0] = let27 < let28 ? let27 : let27 - let28;
                    let29 = v22 + 1;
                    let30 = 11;
                    la12[0] = let29 < let30 ? let29 : let29 - let30;
                    r23 = true;
                }
                v31 = r23;
                if (!(v20 && !v31))
                    break;
            }
            r19 = true;
        } else {
            r19 = false;
        }
        if (!r19) {
            la2[0] = false;
            core_halt();
        }
        v32 = la7[0];
        if (v32) {
            while (1) {
                bool v34;
                uint32_t v35;
                uint32_t v36;
                bool r37;
                uint32_t let38;
                uint32_t let39;
                bool v45;
                
                v34 = la7[0];
                v35 = la10[0];
                v36 = la11[0];
                r37 = false;
                let38 = v36 + 1;
                let39 = 11;
                if ((let38 < let39 ? let38 : let38 - let39) == v35) {
                    r37 = false;
                } else {
                    uint32_t v40;
                    uint32_t let41;
                    uint32_t let42;
                    uint32_t let43;
                    uint32_t let44;
                    
                    v40 = la11[0];
                    la13[v40] = r17;
                    let41 = v36 + 1;
                    let42 = 11;
                    la11[0] = let41 < let42 ? let41 : let41 - let42;
                    let43 = v36 + 1;
                    let44 = 11;
                    la12[0] = let43 < let44 ? let43 : let43 - let44;
                    r37 = true;
                }
                v45 = r37;
                if (!(v34 && !v45))
                    break;
            }
            r33 = true;
        } else {
            r33 = false;
        }
        if (!r33) {
            la2[0] = false;
            core_halt();
        }
    }
    return 0;
}

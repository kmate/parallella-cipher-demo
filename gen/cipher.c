#include "chan.h"
#include "io-vectorized.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
void *thread_t64(void *unused);
void *thread_t86(void *unused);
void *thread_t111(void *unused);
void *thread_t136(void *unused);
void *thread_t161(void *unused);
void *thread_t186(void *unused);
void *thread_t211(void *unused);
void *thread_t236(void *unused);
void *thread_t261(void *unused);
void *thread_t286(void *unused);
void *thread_t311(void *unused);
void *thread_t336(void *unused);
void *thread_t361(void *unused);
void *thread_t386(void *unused);
void *thread_t411(void *unused);
void *thread_t436(void *unused);
void *thread_t459(void *unused);
pthread_t t111;
pthread_t t136;
pthread_t t161;
pthread_t t186;
pthread_t t211;
pthread_t t236;
pthread_t t261;
pthread_t t286;
pthread_t t311;
pthread_t t336;
pthread_t t361;
pthread_t t386;
pthread_t t411;
pthread_t t436;
pthread_t t64;
pthread_t t86;
uint32_t _a0[18];
uint32_t _a1[1024];
uint32_t *a0 = _a0;
uint32_t *a1 = _a1;
chan_t chan62;
chan_t chan63;
void *thread_t64(void *unused)
{
    uint32_t _a65[18];
    uint32_t *a65 = _a65;
    uint32_t _a66[1024];
    uint32_t *a66 = _a66;
    uint32_t v67;
    uint32_t v69;
    
    for (v67 = 0; v67 <= 17; v67++) {
        uint32_t v68;
        
        v68 = a0[v67];
        a65[v67] = v68;
    }
    for (v69 = 0; v69 <= 1023; v69++) {
        uint32_t v70;
        
        v70 = a1[v69];
        a66[v69] = v70;
    }
    while (1) {
        uint32_t r71;
        uint64_t _a72[512];
        uint64_t *a72 = _a72;
        bool v73;
        uint32_t v75;
        uint32_t r76;
        uint32_t v78;
        bool v80;
        uint32_t r81;
        uint32_t v83;
        bool v84;
        
        r71 = 512;
        chan_read(chan62, sizeof(*a72) * (r71 - 0), &a72[0]);
        v73 = chan_last_read_ok(chan62);
        if (!v73) {
            chan_close(chan63);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
        
        uint32_t _a74[r71];
        uint32_t *a74 = _a74;
        
        for (v75 = 0; v75 < r71; v75++) {
            a74[v75] = (uint32_t) (a72[v75] >> 32) ^ a65[0];
        }
        r76 = r71;
        
        uint32_t _a77[r71];
        uint32_t *a77 = _a77;
        
        for (v78 = 0; v78 < r71; v78++) {
            uint32_t let79;
            
            let79 = a74[v78];
            a77[v78] = (((a66[let79 >> 24] + a66[(let79 >> 16 & 255) + 256]) ^
                         a66[(let79 >> 8 & 255) + 512]) + a66[(let79 & 255) +
                                                              768]) ^
                (uint32_t) a72[v78];
        }
        v80 = chan_write(chan63, sizeof(*a77) * (r76 - 0), &a77[0]);
        if (!v80) {
            chan_close(chan62);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
        r81 = r71;
        
        uint32_t _a82[r71];
        uint32_t *a82 = _a82;
        
        for (v83 = 0; v83 < r71; v83++) {
            a82[v83] = a74[v83];
        }
        v84 = chan_write(chan63, sizeof(*a82) * (r81 - 0), &a82[0]);
        if (!v84) {
            chan_close(chan62);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
    }
    return NULL;
}
chan_t chan85;
void *thread_t86(void *unused)
{
    uint32_t _a87[18];
    uint32_t *a87 = _a87;
    uint32_t _a88[1024];
    uint32_t *a88 = _a88;
    uint32_t v89;
    uint32_t v91;
    
    for (v89 = 0; v89 <= 17; v89++) {
        uint32_t v90;
        
        v90 = a0[v89];
        a87[v89] = v90;
    }
    for (v91 = 0; v91 <= 1023; v91++) {
        uint32_t v92;
        
        v92 = a1[v91];
        a88[v91] = v92;
    }
    while (1) {
        uint32_t r93;
        uint32_t _a94[512];
        uint32_t *a94 = _a94;
        bool v95;
        uint32_t r96;
        uint32_t _a97[512];
        uint32_t *a97 = _a97;
        bool v98;
        uint32_t v100;
        uint32_t r101;
        uint32_t v103;
        bool v105;
        uint32_t r106;
        uint32_t v108;
        bool v109;
        
        r93 = 512;
        chan_read(chan63, sizeof(*a94) * (r93 - 0), &a94[0]);
        v95 = chan_last_read_ok(chan63);
        if (!v95) {
            chan_close(chan85);
            pthread_cancel(t86);
            pthread_join(t86, NULL);
        }
        r96 = 512;
        chan_read(chan63, sizeof(*a97) * (r96 - 0), &a97[0]);
        v98 = chan_last_read_ok(chan63);
        if (!v98) {
            chan_close(chan85);
            pthread_cancel(t86);
            pthread_join(t86, NULL);
        }
        
        uint32_t _a99[r93];
        uint32_t *a99 = _a99;
        
        for (v100 = 0; v100 < r93; v100++) {
            a99[v100] = a94[v100] ^ a87[1];
        }
        r101 = r93 <= r96 ? r93 : r96;
        
        uint32_t _a102[r93 <= r96 ? r93 : r96];
        uint32_t *a102 = _a102;
        
        for (v103 = 0; v103 < (r93 <= r96 ? r93 : r96); v103++) {
            uint32_t let104;
            
            let104 = a99[v103];
            a102[v103] = (((a88[let104 >> 24] + a88[(let104 >> 16 & 255) +
                                                    256]) ^ a88[(let104 >> 8 &
                                                                 255) + 512]) +
                          a88[(let104 & 255) + 768]) ^ a97[v103];
        }
        v105 = chan_write(chan85, sizeof(*a102) * (r101 - 0), &a102[0]);
        if (!v105) {
            chan_close(chan63);
            pthread_cancel(t86);
            pthread_join(t86, NULL);
        }
        r106 = r93;
        
        uint32_t _a107[r93];
        uint32_t *a107 = _a107;
        
        for (v108 = 0; v108 < r93; v108++) {
            a107[v108] = a99[v108];
        }
        v109 = chan_write(chan85, sizeof(*a107) * (r106 - 0), &a107[0]);
        if (!v109) {
            chan_close(chan63);
            pthread_cancel(t86);
            pthread_join(t86, NULL);
        }
    }
    return NULL;
}
chan_t chan110;
void *thread_t111(void *unused)
{
    uint32_t _a112[18];
    uint32_t *a112 = _a112;
    uint32_t _a113[1024];
    uint32_t *a113 = _a113;
    uint32_t v114;
    uint32_t v116;
    
    for (v114 = 0; v114 <= 17; v114++) {
        uint32_t v115;
        
        v115 = a0[v114];
        a112[v114] = v115;
    }
    for (v116 = 0; v116 <= 1023; v116++) {
        uint32_t v117;
        
        v117 = a1[v116];
        a113[v116] = v117;
    }
    while (1) {
        uint32_t r118;
        uint32_t _a119[512];
        uint32_t *a119 = _a119;
        bool v120;
        uint32_t r121;
        uint32_t _a122[512];
        uint32_t *a122 = _a122;
        bool v123;
        uint32_t v125;
        uint32_t r126;
        uint32_t v128;
        bool v130;
        uint32_t r131;
        uint32_t v133;
        bool v134;
        
        r118 = 512;
        chan_read(chan85, sizeof(*a119) * (r118 - 0), &a119[0]);
        v120 = chan_last_read_ok(chan85);
        if (!v120) {
            chan_close(chan110);
            pthread_cancel(t111);
            pthread_join(t111, NULL);
        }
        r121 = 512;
        chan_read(chan85, sizeof(*a122) * (r121 - 0), &a122[0]);
        v123 = chan_last_read_ok(chan85);
        if (!v123) {
            chan_close(chan110);
            pthread_cancel(t111);
            pthread_join(t111, NULL);
        }
        
        uint32_t _a124[r118];
        uint32_t *a124 = _a124;
        
        for (v125 = 0; v125 < r118; v125++) {
            a124[v125] = a119[v125] ^ a112[2];
        }
        r126 = r118 <= r121 ? r118 : r121;
        
        uint32_t _a127[r118 <= r121 ? r118 : r121];
        uint32_t *a127 = _a127;
        
        for (v128 = 0; v128 < (r118 <= r121 ? r118 : r121); v128++) {
            uint32_t let129;
            
            let129 = a124[v128];
            a127[v128] = (((a113[let129 >> 24] + a113[(let129 >> 16 & 255) +
                                                      256]) ^ a113[(let129 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a113[(let129 & 255) + 768]) ^ a122[v128];
        }
        v130 = chan_write(chan110, sizeof(*a127) * (r126 - 0), &a127[0]);
        if (!v130) {
            chan_close(chan85);
            pthread_cancel(t111);
            pthread_join(t111, NULL);
        }
        r131 = r118;
        
        uint32_t _a132[r118];
        uint32_t *a132 = _a132;
        
        for (v133 = 0; v133 < r118; v133++) {
            a132[v133] = a124[v133];
        }
        v134 = chan_write(chan110, sizeof(*a132) * (r131 - 0), &a132[0]);
        if (!v134) {
            chan_close(chan85);
            pthread_cancel(t111);
            pthread_join(t111, NULL);
        }
    }
    return NULL;
}
chan_t chan135;
void *thread_t136(void *unused)
{
    uint32_t _a137[18];
    uint32_t *a137 = _a137;
    uint32_t _a138[1024];
    uint32_t *a138 = _a138;
    uint32_t v139;
    uint32_t v141;
    
    for (v139 = 0; v139 <= 17; v139++) {
        uint32_t v140;
        
        v140 = a0[v139];
        a137[v139] = v140;
    }
    for (v141 = 0; v141 <= 1023; v141++) {
        uint32_t v142;
        
        v142 = a1[v141];
        a138[v141] = v142;
    }
    while (1) {
        uint32_t r143;
        uint32_t _a144[512];
        uint32_t *a144 = _a144;
        bool v145;
        uint32_t r146;
        uint32_t _a147[512];
        uint32_t *a147 = _a147;
        bool v148;
        uint32_t v150;
        uint32_t r151;
        uint32_t v153;
        bool v155;
        uint32_t r156;
        uint32_t v158;
        bool v159;
        
        r143 = 512;
        chan_read(chan110, sizeof(*a144) * (r143 - 0), &a144[0]);
        v145 = chan_last_read_ok(chan110);
        if (!v145) {
            chan_close(chan135);
            pthread_cancel(t136);
            pthread_join(t136, NULL);
        }
        r146 = 512;
        chan_read(chan110, sizeof(*a147) * (r146 - 0), &a147[0]);
        v148 = chan_last_read_ok(chan110);
        if (!v148) {
            chan_close(chan135);
            pthread_cancel(t136);
            pthread_join(t136, NULL);
        }
        
        uint32_t _a149[r143];
        uint32_t *a149 = _a149;
        
        for (v150 = 0; v150 < r143; v150++) {
            a149[v150] = a144[v150] ^ a137[3];
        }
        r151 = r143 <= r146 ? r143 : r146;
        
        uint32_t _a152[r143 <= r146 ? r143 : r146];
        uint32_t *a152 = _a152;
        
        for (v153 = 0; v153 < (r143 <= r146 ? r143 : r146); v153++) {
            uint32_t let154;
            
            let154 = a149[v153];
            a152[v153] = (((a138[let154 >> 24] + a138[(let154 >> 16 & 255) +
                                                      256]) ^ a138[(let154 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a138[(let154 & 255) + 768]) ^ a147[v153];
        }
        v155 = chan_write(chan135, sizeof(*a152) * (r151 - 0), &a152[0]);
        if (!v155) {
            chan_close(chan110);
            pthread_cancel(t136);
            pthread_join(t136, NULL);
        }
        r156 = r143;
        
        uint32_t _a157[r143];
        uint32_t *a157 = _a157;
        
        for (v158 = 0; v158 < r143; v158++) {
            a157[v158] = a149[v158];
        }
        v159 = chan_write(chan135, sizeof(*a157) * (r156 - 0), &a157[0]);
        if (!v159) {
            chan_close(chan110);
            pthread_cancel(t136);
            pthread_join(t136, NULL);
        }
    }
    return NULL;
}
chan_t chan160;
void *thread_t161(void *unused)
{
    uint32_t _a162[18];
    uint32_t *a162 = _a162;
    uint32_t _a163[1024];
    uint32_t *a163 = _a163;
    uint32_t v164;
    uint32_t v166;
    
    for (v164 = 0; v164 <= 17; v164++) {
        uint32_t v165;
        
        v165 = a0[v164];
        a162[v164] = v165;
    }
    for (v166 = 0; v166 <= 1023; v166++) {
        uint32_t v167;
        
        v167 = a1[v166];
        a163[v166] = v167;
    }
    while (1) {
        uint32_t r168;
        uint32_t _a169[512];
        uint32_t *a169 = _a169;
        bool v170;
        uint32_t r171;
        uint32_t _a172[512];
        uint32_t *a172 = _a172;
        bool v173;
        uint32_t v175;
        uint32_t r176;
        uint32_t v178;
        bool v180;
        uint32_t r181;
        uint32_t v183;
        bool v184;
        
        r168 = 512;
        chan_read(chan135, sizeof(*a169) * (r168 - 0), &a169[0]);
        v170 = chan_last_read_ok(chan135);
        if (!v170) {
            chan_close(chan160);
            pthread_cancel(t161);
            pthread_join(t161, NULL);
        }
        r171 = 512;
        chan_read(chan135, sizeof(*a172) * (r171 - 0), &a172[0]);
        v173 = chan_last_read_ok(chan135);
        if (!v173) {
            chan_close(chan160);
            pthread_cancel(t161);
            pthread_join(t161, NULL);
        }
        
        uint32_t _a174[r168];
        uint32_t *a174 = _a174;
        
        for (v175 = 0; v175 < r168; v175++) {
            a174[v175] = a169[v175] ^ a162[4];
        }
        r176 = r168 <= r171 ? r168 : r171;
        
        uint32_t _a177[r168 <= r171 ? r168 : r171];
        uint32_t *a177 = _a177;
        
        for (v178 = 0; v178 < (r168 <= r171 ? r168 : r171); v178++) {
            uint32_t let179;
            
            let179 = a174[v178];
            a177[v178] = (((a163[let179 >> 24] + a163[(let179 >> 16 & 255) +
                                                      256]) ^ a163[(let179 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a163[(let179 & 255) + 768]) ^ a172[v178];
        }
        v180 = chan_write(chan160, sizeof(*a177) * (r176 - 0), &a177[0]);
        if (!v180) {
            chan_close(chan135);
            pthread_cancel(t161);
            pthread_join(t161, NULL);
        }
        r181 = r168;
        
        uint32_t _a182[r168];
        uint32_t *a182 = _a182;
        
        for (v183 = 0; v183 < r168; v183++) {
            a182[v183] = a174[v183];
        }
        v184 = chan_write(chan160, sizeof(*a182) * (r181 - 0), &a182[0]);
        if (!v184) {
            chan_close(chan135);
            pthread_cancel(t161);
            pthread_join(t161, NULL);
        }
    }
    return NULL;
}
chan_t chan185;
void *thread_t186(void *unused)
{
    uint32_t _a187[18];
    uint32_t *a187 = _a187;
    uint32_t _a188[1024];
    uint32_t *a188 = _a188;
    uint32_t v189;
    uint32_t v191;
    
    for (v189 = 0; v189 <= 17; v189++) {
        uint32_t v190;
        
        v190 = a0[v189];
        a187[v189] = v190;
    }
    for (v191 = 0; v191 <= 1023; v191++) {
        uint32_t v192;
        
        v192 = a1[v191];
        a188[v191] = v192;
    }
    while (1) {
        uint32_t r193;
        uint32_t _a194[512];
        uint32_t *a194 = _a194;
        bool v195;
        uint32_t r196;
        uint32_t _a197[512];
        uint32_t *a197 = _a197;
        bool v198;
        uint32_t v200;
        uint32_t r201;
        uint32_t v203;
        bool v205;
        uint32_t r206;
        uint32_t v208;
        bool v209;
        
        r193 = 512;
        chan_read(chan160, sizeof(*a194) * (r193 - 0), &a194[0]);
        v195 = chan_last_read_ok(chan160);
        if (!v195) {
            chan_close(chan185);
            pthread_cancel(t186);
            pthread_join(t186, NULL);
        }
        r196 = 512;
        chan_read(chan160, sizeof(*a197) * (r196 - 0), &a197[0]);
        v198 = chan_last_read_ok(chan160);
        if (!v198) {
            chan_close(chan185);
            pthread_cancel(t186);
            pthread_join(t186, NULL);
        }
        
        uint32_t _a199[r193];
        uint32_t *a199 = _a199;
        
        for (v200 = 0; v200 < r193; v200++) {
            a199[v200] = a194[v200] ^ a187[5];
        }
        r201 = r193 <= r196 ? r193 : r196;
        
        uint32_t _a202[r193 <= r196 ? r193 : r196];
        uint32_t *a202 = _a202;
        
        for (v203 = 0; v203 < (r193 <= r196 ? r193 : r196); v203++) {
            uint32_t let204;
            
            let204 = a199[v203];
            a202[v203] = (((a188[let204 >> 24] + a188[(let204 >> 16 & 255) +
                                                      256]) ^ a188[(let204 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a188[(let204 & 255) + 768]) ^ a197[v203];
        }
        v205 = chan_write(chan185, sizeof(*a202) * (r201 - 0), &a202[0]);
        if (!v205) {
            chan_close(chan160);
            pthread_cancel(t186);
            pthread_join(t186, NULL);
        }
        r206 = r193;
        
        uint32_t _a207[r193];
        uint32_t *a207 = _a207;
        
        for (v208 = 0; v208 < r193; v208++) {
            a207[v208] = a199[v208];
        }
        v209 = chan_write(chan185, sizeof(*a207) * (r206 - 0), &a207[0]);
        if (!v209) {
            chan_close(chan160);
            pthread_cancel(t186);
            pthread_join(t186, NULL);
        }
    }
    return NULL;
}
chan_t chan210;
void *thread_t211(void *unused)
{
    uint32_t _a212[18];
    uint32_t *a212 = _a212;
    uint32_t _a213[1024];
    uint32_t *a213 = _a213;
    uint32_t v214;
    uint32_t v216;
    
    for (v214 = 0; v214 <= 17; v214++) {
        uint32_t v215;
        
        v215 = a0[v214];
        a212[v214] = v215;
    }
    for (v216 = 0; v216 <= 1023; v216++) {
        uint32_t v217;
        
        v217 = a1[v216];
        a213[v216] = v217;
    }
    while (1) {
        uint32_t r218;
        uint32_t _a219[512];
        uint32_t *a219 = _a219;
        bool v220;
        uint32_t r221;
        uint32_t _a222[512];
        uint32_t *a222 = _a222;
        bool v223;
        uint32_t v225;
        uint32_t r226;
        uint32_t v228;
        bool v230;
        uint32_t r231;
        uint32_t v233;
        bool v234;
        
        r218 = 512;
        chan_read(chan185, sizeof(*a219) * (r218 - 0), &a219[0]);
        v220 = chan_last_read_ok(chan185);
        if (!v220) {
            chan_close(chan210);
            pthread_cancel(t211);
            pthread_join(t211, NULL);
        }
        r221 = 512;
        chan_read(chan185, sizeof(*a222) * (r221 - 0), &a222[0]);
        v223 = chan_last_read_ok(chan185);
        if (!v223) {
            chan_close(chan210);
            pthread_cancel(t211);
            pthread_join(t211, NULL);
        }
        
        uint32_t _a224[r218];
        uint32_t *a224 = _a224;
        
        for (v225 = 0; v225 < r218; v225++) {
            a224[v225] = a219[v225] ^ a212[6];
        }
        r226 = r218 <= r221 ? r218 : r221;
        
        uint32_t _a227[r218 <= r221 ? r218 : r221];
        uint32_t *a227 = _a227;
        
        for (v228 = 0; v228 < (r218 <= r221 ? r218 : r221); v228++) {
            uint32_t let229;
            
            let229 = a224[v228];
            a227[v228] = (((a213[let229 >> 24] + a213[(let229 >> 16 & 255) +
                                                      256]) ^ a213[(let229 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a213[(let229 & 255) + 768]) ^ a222[v228];
        }
        v230 = chan_write(chan210, sizeof(*a227) * (r226 - 0), &a227[0]);
        if (!v230) {
            chan_close(chan185);
            pthread_cancel(t211);
            pthread_join(t211, NULL);
        }
        r231 = r218;
        
        uint32_t _a232[r218];
        uint32_t *a232 = _a232;
        
        for (v233 = 0; v233 < r218; v233++) {
            a232[v233] = a224[v233];
        }
        v234 = chan_write(chan210, sizeof(*a232) * (r231 - 0), &a232[0]);
        if (!v234) {
            chan_close(chan185);
            pthread_cancel(t211);
            pthread_join(t211, NULL);
        }
    }
    return NULL;
}
chan_t chan235;
void *thread_t236(void *unused)
{
    uint32_t _a237[18];
    uint32_t *a237 = _a237;
    uint32_t _a238[1024];
    uint32_t *a238 = _a238;
    uint32_t v239;
    uint32_t v241;
    
    for (v239 = 0; v239 <= 17; v239++) {
        uint32_t v240;
        
        v240 = a0[v239];
        a237[v239] = v240;
    }
    for (v241 = 0; v241 <= 1023; v241++) {
        uint32_t v242;
        
        v242 = a1[v241];
        a238[v241] = v242;
    }
    while (1) {
        uint32_t r243;
        uint32_t _a244[512];
        uint32_t *a244 = _a244;
        bool v245;
        uint32_t r246;
        uint32_t _a247[512];
        uint32_t *a247 = _a247;
        bool v248;
        uint32_t v250;
        uint32_t r251;
        uint32_t v253;
        bool v255;
        uint32_t r256;
        uint32_t v258;
        bool v259;
        
        r243 = 512;
        chan_read(chan210, sizeof(*a244) * (r243 - 0), &a244[0]);
        v245 = chan_last_read_ok(chan210);
        if (!v245) {
            chan_close(chan235);
            pthread_cancel(t236);
            pthread_join(t236, NULL);
        }
        r246 = 512;
        chan_read(chan210, sizeof(*a247) * (r246 - 0), &a247[0]);
        v248 = chan_last_read_ok(chan210);
        if (!v248) {
            chan_close(chan235);
            pthread_cancel(t236);
            pthread_join(t236, NULL);
        }
        
        uint32_t _a249[r243];
        uint32_t *a249 = _a249;
        
        for (v250 = 0; v250 < r243; v250++) {
            a249[v250] = a244[v250] ^ a237[7];
        }
        r251 = r243 <= r246 ? r243 : r246;
        
        uint32_t _a252[r243 <= r246 ? r243 : r246];
        uint32_t *a252 = _a252;
        
        for (v253 = 0; v253 < (r243 <= r246 ? r243 : r246); v253++) {
            uint32_t let254;
            
            let254 = a249[v253];
            a252[v253] = (((a238[let254 >> 24] + a238[(let254 >> 16 & 255) +
                                                      256]) ^ a238[(let254 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a238[(let254 & 255) + 768]) ^ a247[v253];
        }
        v255 = chan_write(chan235, sizeof(*a252) * (r251 - 0), &a252[0]);
        if (!v255) {
            chan_close(chan210);
            pthread_cancel(t236);
            pthread_join(t236, NULL);
        }
        r256 = r243;
        
        uint32_t _a257[r243];
        uint32_t *a257 = _a257;
        
        for (v258 = 0; v258 < r243; v258++) {
            a257[v258] = a249[v258];
        }
        v259 = chan_write(chan235, sizeof(*a257) * (r256 - 0), &a257[0]);
        if (!v259) {
            chan_close(chan210);
            pthread_cancel(t236);
            pthread_join(t236, NULL);
        }
    }
    return NULL;
}
chan_t chan260;
void *thread_t261(void *unused)
{
    uint32_t _a262[18];
    uint32_t *a262 = _a262;
    uint32_t _a263[1024];
    uint32_t *a263 = _a263;
    uint32_t v264;
    uint32_t v266;
    
    for (v264 = 0; v264 <= 17; v264++) {
        uint32_t v265;
        
        v265 = a0[v264];
        a262[v264] = v265;
    }
    for (v266 = 0; v266 <= 1023; v266++) {
        uint32_t v267;
        
        v267 = a1[v266];
        a263[v266] = v267;
    }
    while (1) {
        uint32_t r268;
        uint32_t _a269[512];
        uint32_t *a269 = _a269;
        bool v270;
        uint32_t r271;
        uint32_t _a272[512];
        uint32_t *a272 = _a272;
        bool v273;
        uint32_t v275;
        uint32_t r276;
        uint32_t v278;
        bool v280;
        uint32_t r281;
        uint32_t v283;
        bool v284;
        
        r268 = 512;
        chan_read(chan235, sizeof(*a269) * (r268 - 0), &a269[0]);
        v270 = chan_last_read_ok(chan235);
        if (!v270) {
            chan_close(chan260);
            pthread_cancel(t261);
            pthread_join(t261, NULL);
        }
        r271 = 512;
        chan_read(chan235, sizeof(*a272) * (r271 - 0), &a272[0]);
        v273 = chan_last_read_ok(chan235);
        if (!v273) {
            chan_close(chan260);
            pthread_cancel(t261);
            pthread_join(t261, NULL);
        }
        
        uint32_t _a274[r268];
        uint32_t *a274 = _a274;
        
        for (v275 = 0; v275 < r268; v275++) {
            a274[v275] = a269[v275] ^ a262[8];
        }
        r276 = r268 <= r271 ? r268 : r271;
        
        uint32_t _a277[r268 <= r271 ? r268 : r271];
        uint32_t *a277 = _a277;
        
        for (v278 = 0; v278 < (r268 <= r271 ? r268 : r271); v278++) {
            uint32_t let279;
            
            let279 = a274[v278];
            a277[v278] = (((a263[let279 >> 24] + a263[(let279 >> 16 & 255) +
                                                      256]) ^ a263[(let279 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a263[(let279 & 255) + 768]) ^ a272[v278];
        }
        v280 = chan_write(chan260, sizeof(*a277) * (r276 - 0), &a277[0]);
        if (!v280) {
            chan_close(chan235);
            pthread_cancel(t261);
            pthread_join(t261, NULL);
        }
        r281 = r268;
        
        uint32_t _a282[r268];
        uint32_t *a282 = _a282;
        
        for (v283 = 0; v283 < r268; v283++) {
            a282[v283] = a274[v283];
        }
        v284 = chan_write(chan260, sizeof(*a282) * (r281 - 0), &a282[0]);
        if (!v284) {
            chan_close(chan235);
            pthread_cancel(t261);
            pthread_join(t261, NULL);
        }
    }
    return NULL;
}
chan_t chan285;
void *thread_t286(void *unused)
{
    uint32_t _a287[18];
    uint32_t *a287 = _a287;
    uint32_t _a288[1024];
    uint32_t *a288 = _a288;
    uint32_t v289;
    uint32_t v291;
    
    for (v289 = 0; v289 <= 17; v289++) {
        uint32_t v290;
        
        v290 = a0[v289];
        a287[v289] = v290;
    }
    for (v291 = 0; v291 <= 1023; v291++) {
        uint32_t v292;
        
        v292 = a1[v291];
        a288[v291] = v292;
    }
    while (1) {
        uint32_t r293;
        uint32_t _a294[512];
        uint32_t *a294 = _a294;
        bool v295;
        uint32_t r296;
        uint32_t _a297[512];
        uint32_t *a297 = _a297;
        bool v298;
        uint32_t v300;
        uint32_t r301;
        uint32_t v303;
        bool v305;
        uint32_t r306;
        uint32_t v308;
        bool v309;
        
        r293 = 512;
        chan_read(chan260, sizeof(*a294) * (r293 - 0), &a294[0]);
        v295 = chan_last_read_ok(chan260);
        if (!v295) {
            chan_close(chan285);
            pthread_cancel(t286);
            pthread_join(t286, NULL);
        }
        r296 = 512;
        chan_read(chan260, sizeof(*a297) * (r296 - 0), &a297[0]);
        v298 = chan_last_read_ok(chan260);
        if (!v298) {
            chan_close(chan285);
            pthread_cancel(t286);
            pthread_join(t286, NULL);
        }
        
        uint32_t _a299[r293];
        uint32_t *a299 = _a299;
        
        for (v300 = 0; v300 < r293; v300++) {
            a299[v300] = a294[v300] ^ a287[9];
        }
        r301 = r293 <= r296 ? r293 : r296;
        
        uint32_t _a302[r293 <= r296 ? r293 : r296];
        uint32_t *a302 = _a302;
        
        for (v303 = 0; v303 < (r293 <= r296 ? r293 : r296); v303++) {
            uint32_t let304;
            
            let304 = a299[v303];
            a302[v303] = (((a288[let304 >> 24] + a288[(let304 >> 16 & 255) +
                                                      256]) ^ a288[(let304 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a288[(let304 & 255) + 768]) ^ a297[v303];
        }
        v305 = chan_write(chan285, sizeof(*a302) * (r301 - 0), &a302[0]);
        if (!v305) {
            chan_close(chan260);
            pthread_cancel(t286);
            pthread_join(t286, NULL);
        }
        r306 = r293;
        
        uint32_t _a307[r293];
        uint32_t *a307 = _a307;
        
        for (v308 = 0; v308 < r293; v308++) {
            a307[v308] = a299[v308];
        }
        v309 = chan_write(chan285, sizeof(*a307) * (r306 - 0), &a307[0]);
        if (!v309) {
            chan_close(chan260);
            pthread_cancel(t286);
            pthread_join(t286, NULL);
        }
    }
    return NULL;
}
chan_t chan310;
void *thread_t311(void *unused)
{
    uint32_t _a312[18];
    uint32_t *a312 = _a312;
    uint32_t _a313[1024];
    uint32_t *a313 = _a313;
    uint32_t v314;
    uint32_t v316;
    
    for (v314 = 0; v314 <= 17; v314++) {
        uint32_t v315;
        
        v315 = a0[v314];
        a312[v314] = v315;
    }
    for (v316 = 0; v316 <= 1023; v316++) {
        uint32_t v317;
        
        v317 = a1[v316];
        a313[v316] = v317;
    }
    while (1) {
        uint32_t r318;
        uint32_t _a319[512];
        uint32_t *a319 = _a319;
        bool v320;
        uint32_t r321;
        uint32_t _a322[512];
        uint32_t *a322 = _a322;
        bool v323;
        uint32_t v325;
        uint32_t r326;
        uint32_t v328;
        bool v330;
        uint32_t r331;
        uint32_t v333;
        bool v334;
        
        r318 = 512;
        chan_read(chan285, sizeof(*a319) * (r318 - 0), &a319[0]);
        v320 = chan_last_read_ok(chan285);
        if (!v320) {
            chan_close(chan310);
            pthread_cancel(t311);
            pthread_join(t311, NULL);
        }
        r321 = 512;
        chan_read(chan285, sizeof(*a322) * (r321 - 0), &a322[0]);
        v323 = chan_last_read_ok(chan285);
        if (!v323) {
            chan_close(chan310);
            pthread_cancel(t311);
            pthread_join(t311, NULL);
        }
        
        uint32_t _a324[r318];
        uint32_t *a324 = _a324;
        
        for (v325 = 0; v325 < r318; v325++) {
            a324[v325] = a319[v325] ^ a312[10];
        }
        r326 = r318 <= r321 ? r318 : r321;
        
        uint32_t _a327[r318 <= r321 ? r318 : r321];
        uint32_t *a327 = _a327;
        
        for (v328 = 0; v328 < (r318 <= r321 ? r318 : r321); v328++) {
            uint32_t let329;
            
            let329 = a324[v328];
            a327[v328] = (((a313[let329 >> 24] + a313[(let329 >> 16 & 255) +
                                                      256]) ^ a313[(let329 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a313[(let329 & 255) + 768]) ^ a322[v328];
        }
        v330 = chan_write(chan310, sizeof(*a327) * (r326 - 0), &a327[0]);
        if (!v330) {
            chan_close(chan285);
            pthread_cancel(t311);
            pthread_join(t311, NULL);
        }
        r331 = r318;
        
        uint32_t _a332[r318];
        uint32_t *a332 = _a332;
        
        for (v333 = 0; v333 < r318; v333++) {
            a332[v333] = a324[v333];
        }
        v334 = chan_write(chan310, sizeof(*a332) * (r331 - 0), &a332[0]);
        if (!v334) {
            chan_close(chan285);
            pthread_cancel(t311);
            pthread_join(t311, NULL);
        }
    }
    return NULL;
}
chan_t chan335;
void *thread_t336(void *unused)
{
    uint32_t _a337[18];
    uint32_t *a337 = _a337;
    uint32_t _a338[1024];
    uint32_t *a338 = _a338;
    uint32_t v339;
    uint32_t v341;
    
    for (v339 = 0; v339 <= 17; v339++) {
        uint32_t v340;
        
        v340 = a0[v339];
        a337[v339] = v340;
    }
    for (v341 = 0; v341 <= 1023; v341++) {
        uint32_t v342;
        
        v342 = a1[v341];
        a338[v341] = v342;
    }
    while (1) {
        uint32_t r343;
        uint32_t _a344[512];
        uint32_t *a344 = _a344;
        bool v345;
        uint32_t r346;
        uint32_t _a347[512];
        uint32_t *a347 = _a347;
        bool v348;
        uint32_t v350;
        uint32_t r351;
        uint32_t v353;
        bool v355;
        uint32_t r356;
        uint32_t v358;
        bool v359;
        
        r343 = 512;
        chan_read(chan310, sizeof(*a344) * (r343 - 0), &a344[0]);
        v345 = chan_last_read_ok(chan310);
        if (!v345) {
            chan_close(chan335);
            pthread_cancel(t336);
            pthread_join(t336, NULL);
        }
        r346 = 512;
        chan_read(chan310, sizeof(*a347) * (r346 - 0), &a347[0]);
        v348 = chan_last_read_ok(chan310);
        if (!v348) {
            chan_close(chan335);
            pthread_cancel(t336);
            pthread_join(t336, NULL);
        }
        
        uint32_t _a349[r343];
        uint32_t *a349 = _a349;
        
        for (v350 = 0; v350 < r343; v350++) {
            a349[v350] = a344[v350] ^ a337[11];
        }
        r351 = r343 <= r346 ? r343 : r346;
        
        uint32_t _a352[r343 <= r346 ? r343 : r346];
        uint32_t *a352 = _a352;
        
        for (v353 = 0; v353 < (r343 <= r346 ? r343 : r346); v353++) {
            uint32_t let354;
            
            let354 = a349[v353];
            a352[v353] = (((a338[let354 >> 24] + a338[(let354 >> 16 & 255) +
                                                      256]) ^ a338[(let354 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a338[(let354 & 255) + 768]) ^ a347[v353];
        }
        v355 = chan_write(chan335, sizeof(*a352) * (r351 - 0), &a352[0]);
        if (!v355) {
            chan_close(chan310);
            pthread_cancel(t336);
            pthread_join(t336, NULL);
        }
        r356 = r343;
        
        uint32_t _a357[r343];
        uint32_t *a357 = _a357;
        
        for (v358 = 0; v358 < r343; v358++) {
            a357[v358] = a349[v358];
        }
        v359 = chan_write(chan335, sizeof(*a357) * (r356 - 0), &a357[0]);
        if (!v359) {
            chan_close(chan310);
            pthread_cancel(t336);
            pthread_join(t336, NULL);
        }
    }
    return NULL;
}
chan_t chan360;
void *thread_t361(void *unused)
{
    uint32_t _a362[18];
    uint32_t *a362 = _a362;
    uint32_t _a363[1024];
    uint32_t *a363 = _a363;
    uint32_t v364;
    uint32_t v366;
    
    for (v364 = 0; v364 <= 17; v364++) {
        uint32_t v365;
        
        v365 = a0[v364];
        a362[v364] = v365;
    }
    for (v366 = 0; v366 <= 1023; v366++) {
        uint32_t v367;
        
        v367 = a1[v366];
        a363[v366] = v367;
    }
    while (1) {
        uint32_t r368;
        uint32_t _a369[512];
        uint32_t *a369 = _a369;
        bool v370;
        uint32_t r371;
        uint32_t _a372[512];
        uint32_t *a372 = _a372;
        bool v373;
        uint32_t v375;
        uint32_t r376;
        uint32_t v378;
        bool v380;
        uint32_t r381;
        uint32_t v383;
        bool v384;
        
        r368 = 512;
        chan_read(chan335, sizeof(*a369) * (r368 - 0), &a369[0]);
        v370 = chan_last_read_ok(chan335);
        if (!v370) {
            chan_close(chan360);
            pthread_cancel(t361);
            pthread_join(t361, NULL);
        }
        r371 = 512;
        chan_read(chan335, sizeof(*a372) * (r371 - 0), &a372[0]);
        v373 = chan_last_read_ok(chan335);
        if (!v373) {
            chan_close(chan360);
            pthread_cancel(t361);
            pthread_join(t361, NULL);
        }
        
        uint32_t _a374[r368];
        uint32_t *a374 = _a374;
        
        for (v375 = 0; v375 < r368; v375++) {
            a374[v375] = a369[v375] ^ a362[12];
        }
        r376 = r368 <= r371 ? r368 : r371;
        
        uint32_t _a377[r368 <= r371 ? r368 : r371];
        uint32_t *a377 = _a377;
        
        for (v378 = 0; v378 < (r368 <= r371 ? r368 : r371); v378++) {
            uint32_t let379;
            
            let379 = a374[v378];
            a377[v378] = (((a363[let379 >> 24] + a363[(let379 >> 16 & 255) +
                                                      256]) ^ a363[(let379 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a363[(let379 & 255) + 768]) ^ a372[v378];
        }
        v380 = chan_write(chan360, sizeof(*a377) * (r376 - 0), &a377[0]);
        if (!v380) {
            chan_close(chan335);
            pthread_cancel(t361);
            pthread_join(t361, NULL);
        }
        r381 = r368;
        
        uint32_t _a382[r368];
        uint32_t *a382 = _a382;
        
        for (v383 = 0; v383 < r368; v383++) {
            a382[v383] = a374[v383];
        }
        v384 = chan_write(chan360, sizeof(*a382) * (r381 - 0), &a382[0]);
        if (!v384) {
            chan_close(chan335);
            pthread_cancel(t361);
            pthread_join(t361, NULL);
        }
    }
    return NULL;
}
chan_t chan385;
void *thread_t386(void *unused)
{
    uint32_t _a387[18];
    uint32_t *a387 = _a387;
    uint32_t _a388[1024];
    uint32_t *a388 = _a388;
    uint32_t v389;
    uint32_t v391;
    
    for (v389 = 0; v389 <= 17; v389++) {
        uint32_t v390;
        
        v390 = a0[v389];
        a387[v389] = v390;
    }
    for (v391 = 0; v391 <= 1023; v391++) {
        uint32_t v392;
        
        v392 = a1[v391];
        a388[v391] = v392;
    }
    while (1) {
        uint32_t r393;
        uint32_t _a394[512];
        uint32_t *a394 = _a394;
        bool v395;
        uint32_t r396;
        uint32_t _a397[512];
        uint32_t *a397 = _a397;
        bool v398;
        uint32_t v400;
        uint32_t r401;
        uint32_t v403;
        bool v405;
        uint32_t r406;
        uint32_t v408;
        bool v409;
        
        r393 = 512;
        chan_read(chan360, sizeof(*a394) * (r393 - 0), &a394[0]);
        v395 = chan_last_read_ok(chan360);
        if (!v395) {
            chan_close(chan385);
            pthread_cancel(t386);
            pthread_join(t386, NULL);
        }
        r396 = 512;
        chan_read(chan360, sizeof(*a397) * (r396 - 0), &a397[0]);
        v398 = chan_last_read_ok(chan360);
        if (!v398) {
            chan_close(chan385);
            pthread_cancel(t386);
            pthread_join(t386, NULL);
        }
        
        uint32_t _a399[r393];
        uint32_t *a399 = _a399;
        
        for (v400 = 0; v400 < r393; v400++) {
            a399[v400] = a394[v400] ^ a387[13];
        }
        r401 = r393 <= r396 ? r393 : r396;
        
        uint32_t _a402[r393 <= r396 ? r393 : r396];
        uint32_t *a402 = _a402;
        
        for (v403 = 0; v403 < (r393 <= r396 ? r393 : r396); v403++) {
            uint32_t let404;
            
            let404 = a399[v403];
            a402[v403] = (((a388[let404 >> 24] + a388[(let404 >> 16 & 255) +
                                                      256]) ^ a388[(let404 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a388[(let404 & 255) + 768]) ^ a397[v403];
        }
        v405 = chan_write(chan385, sizeof(*a402) * (r401 - 0), &a402[0]);
        if (!v405) {
            chan_close(chan360);
            pthread_cancel(t386);
            pthread_join(t386, NULL);
        }
        r406 = r393;
        
        uint32_t _a407[r393];
        uint32_t *a407 = _a407;
        
        for (v408 = 0; v408 < r393; v408++) {
            a407[v408] = a399[v408];
        }
        v409 = chan_write(chan385, sizeof(*a407) * (r406 - 0), &a407[0]);
        if (!v409) {
            chan_close(chan360);
            pthread_cancel(t386);
            pthread_join(t386, NULL);
        }
    }
    return NULL;
}
chan_t chan410;
void *thread_t411(void *unused)
{
    uint32_t _a412[18];
    uint32_t *a412 = _a412;
    uint32_t _a413[1024];
    uint32_t *a413 = _a413;
    uint32_t v414;
    uint32_t v416;
    
    for (v414 = 0; v414 <= 17; v414++) {
        uint32_t v415;
        
        v415 = a0[v414];
        a412[v414] = v415;
    }
    for (v416 = 0; v416 <= 1023; v416++) {
        uint32_t v417;
        
        v417 = a1[v416];
        a413[v416] = v417;
    }
    while (1) {
        uint32_t r418;
        uint32_t _a419[512];
        uint32_t *a419 = _a419;
        bool v420;
        uint32_t r421;
        uint32_t _a422[512];
        uint32_t *a422 = _a422;
        bool v423;
        uint32_t v425;
        uint32_t r426;
        uint32_t v428;
        bool v430;
        uint32_t r431;
        uint32_t v433;
        bool v434;
        
        r418 = 512;
        chan_read(chan385, sizeof(*a419) * (r418 - 0), &a419[0]);
        v420 = chan_last_read_ok(chan385);
        if (!v420) {
            chan_close(chan410);
            pthread_cancel(t411);
            pthread_join(t411, NULL);
        }
        r421 = 512;
        chan_read(chan385, sizeof(*a422) * (r421 - 0), &a422[0]);
        v423 = chan_last_read_ok(chan385);
        if (!v423) {
            chan_close(chan410);
            pthread_cancel(t411);
            pthread_join(t411, NULL);
        }
        
        uint32_t _a424[r418];
        uint32_t *a424 = _a424;
        
        for (v425 = 0; v425 < r418; v425++) {
            a424[v425] = a419[v425] ^ a412[14];
        }
        r426 = r418 <= r421 ? r418 : r421;
        
        uint32_t _a427[r418 <= r421 ? r418 : r421];
        uint32_t *a427 = _a427;
        
        for (v428 = 0; v428 < (r418 <= r421 ? r418 : r421); v428++) {
            uint32_t let429;
            
            let429 = a424[v428];
            a427[v428] = (((a413[let429 >> 24] + a413[(let429 >> 16 & 255) +
                                                      256]) ^ a413[(let429 >>
                                                                    8 & 255) +
                                                                   512]) +
                          a413[(let429 & 255) + 768]) ^ a422[v428];
        }
        v430 = chan_write(chan410, sizeof(*a427) * (r426 - 0), &a427[0]);
        if (!v430) {
            chan_close(chan385);
            pthread_cancel(t411);
            pthread_join(t411, NULL);
        }
        r431 = r418;
        
        uint32_t _a432[r418];
        uint32_t *a432 = _a432;
        
        for (v433 = 0; v433 < r418; v433++) {
            a432[v433] = a424[v433];
        }
        v434 = chan_write(chan410, sizeof(*a432) * (r431 - 0), &a432[0]);
        if (!v434) {
            chan_close(chan385);
            pthread_cancel(t411);
            pthread_join(t411, NULL);
        }
    }
    return NULL;
}
chan_t chan435;
void *thread_t436(void *unused)
{
    uint32_t _a437[18];
    uint32_t *a437 = _a437;
    uint32_t _a438[1024];
    uint32_t *a438 = _a438;
    uint32_t v439;
    uint32_t v441;
    
    for (v439 = 0; v439 <= 17; v439++) {
        uint32_t v440;
        
        v440 = a0[v439];
        a437[v439] = v440;
    }
    for (v441 = 0; v441 <= 1023; v441++) {
        uint32_t v442;
        
        v442 = a1[v441];
        a438[v441] = v442;
    }
    while (1) {
        uint32_t r443;
        uint32_t _a444[512];
        uint32_t *a444 = _a444;
        bool v445;
        uint32_t r446;
        uint32_t _a447[512];
        uint32_t *a447 = _a447;
        bool v448;
        uint32_t v450;
        uint32_t let451;
        uint32_t r452;
        uint32_t let453;
        uint32_t let455;
        uint32_t v456;
        bool v458;
        
        r443 = 512;
        chan_read(chan410, sizeof(*a444) * (r443 - 0), &a444[0]);
        v445 = chan_last_read_ok(chan410);
        if (!v445) {
            chan_close(chan435);
            pthread_cancel(t436);
            pthread_join(t436, NULL);
        }
        r446 = 512;
        chan_read(chan410, sizeof(*a447) * (r446 - 0), &a447[0]);
        v448 = chan_last_read_ok(chan410);
        if (!v448) {
            chan_close(chan435);
            pthread_cancel(t436);
            pthread_join(t436, NULL);
        }
        
        uint32_t _a449[r443];
        uint32_t *a449 = _a449;
        
        for (v450 = 0; v450 < r443; v450++) {
            a449[v450] = a444[v450] ^ a437[15];
        }
        let451 = r443 <= r446 ? r443 : r446;
        r452 = r443 <= let451 ? r443 : let451;
        let453 = r443 <= r446 ? r443 : r446;
        
        uint64_t _a454[r443 <= let453 ? r443 : let453];
        uint64_t *a454 = _a454;
        
        let455 = r443 <= r446 ? r443 : r446;
        for (v456 = 0; v456 < (r443 <= let455 ? r443 : let455); v456++) {
            uint32_t let457;
            
            let457 = a449[v456];
            a454[v456] = (uint64_t) (let457 ^ a437[17]) << 32 |
                (uint64_t) (((((a438[let457 >> 24] + a438[(let457 >> 16 & 255) +
                                                          256]) ^
                               a438[(let457 >> 8 & 255) + 512]) + a438[(let457 &
                                                                        255) +
                                                                       768]) ^
                             a447[v456]) ^ a437[16]);
        }
        v458 = chan_write(chan435, sizeof(*a454) * (r452 - 0), &a454[0]);
        if (!v458) {
            chan_close(chan410);
            pthread_cancel(t436);
            pthread_join(t436, NULL);
        }
    }
    return NULL;
}
void *thread_t459(void *unused)
{
    bool r460;
    
    r460 = true;
    while (1) {
        bool v461;
        uint32_t r462;
        uint64_t _a463[512];
        uint64_t *a463 = _a463;
        bool v464;
        
        v461 = r460;
        if (!v461)
            break;
        r462 = 512;
        chan_read(chan435, sizeof(*a463) * (r462 - 0), &a463[0]);
        v464 = chan_last_read_ok(chan435);
        if (v464) {
            bool v465;
            
            v465 = write_block(a463, &r462);
            r460 = v465;
            if (!v465) {
                chan_close(chan435);
            }
        } else {
            r460 = false;
        }
    }
    return NULL;
}
int main()
{
    uint8_t _a2[16];
    uint8_t *a2 = _a2;
    uint32_t _a3[] = {3509652390, 2564797868, 805139163, 3491422135, 3101798381,
                      1780907670, 3128725573, 4046225305, 614570311, 3012652279,
                      134345442, 2240740374, 1667834072, 1901547113, 2757295779,
                      4103290238, 227898511, 1921955416, 1904987480, 2182433518,
                      2069144605, 3260701109, 2620446009, 720527379, 3318853667,
                      677414384, 3393288472, 3101374703, 2390351024, 1614419982,
                      1822297739, 2954791486, 3608508353, 3174124327,
                      2024746970, 1432378464, 3864339955, 2857741204,
                      1464375394, 1676153920, 1439316330, 715854006, 3033291828,
                      289532110, 2706671279, 2087905683, 3018724369, 1668267050,
                      732546397, 1947742710, 3462151702, 2609353502, 2950085171,
                      1814351708, 2050118529, 680887927, 999245976, 1800124847,
                      3300911131, 1713906067, 1641548236, 4213287313,
                      1216130144, 1575780402, 4018429277, 3917837745,
                      3693486850, 3949271944, 596196993, 3549867205, 258830323,
                      2213823033, 772490370, 2760122372, 1774776394, 2652871518,
                      566650946, 4142492826, 1728879713, 2882767088, 1783734482,
                      3629395816, 2517608232, 2874225571, 1861159788, 326777828,
                      3124490320, 2130389656, 2716951837, 967770486, 1724537150,
                      2185432712, 2364442137, 1164943284, 2105845187, 998989502,
                      3765401048, 2244026483, 1075463327, 1455516326,
                      1322494562, 910128902, 469688178, 1117454909, 936433444,
                      3490320968, 3675253459, 1240580251, 122909385, 2157517691,
                      634681816, 4142456567, 3825094682, 3061402683, 2540495037,
                      79693498, 3249098678, 1084186820, 1583128258, 426386531,
                      1761308591, 1047286709, 322548459, 995290223, 1845252383,
                      2603652396, 3431023940, 2942221577, 3202600964,
                      3727903485, 1712269319, 422464435, 3234572375, 1170764815,
                      3523960633, 3117677531, 1434042557, 442511882, 3600875718,
                      1076654713, 1738483198, 4213154764, 2393238008,
                      3677496056, 1014306527, 4251020053, 793779912, 2902807211,
                      842905082, 4246964064, 1395751752, 1040244610, 2656851899,
                      3396308128, 445077038, 3742853595, 3577915638, 679411651,
                      2892444358, 2354009459, 1767581616, 3150600392,
                      3791627101, 3102740896, 284835224, 4246832056, 1258075500,
                      768725851, 2589189241, 3069724005, 3532540348, 1274779536,
                      3789419226, 2764799539, 1660621633, 3471099624,
                      4011903706, 913787905, 3497959166, 737222580, 2514213453,
                      2928710040, 3937242737, 1804850592, 3499020752,
                      2949064160, 2386320175, 2390070455, 2415321851,
                      4061277028, 2290661394, 2416832540, 1336762016,
                      1754252060, 3520065937, 3014181293, 791618072, 3188594551,
                      3933548030, 2332172193, 3852520463, 3043980520, 413987798,
                      3465142937, 3030929376, 4245938359, 2093235073,
                      3534596313, 375366246, 2157278981, 2479649556, 555357303,
                      3870105701, 2008414854, 3344188149, 4221384143,
                      3956125452, 2067696032, 3594591187, 2921233993, 2428461,
                      544322398, 577241275, 1471733935, 610547355, 4027169054,
                      1432588573, 1507829418, 2025931657, 3646575487, 545086370,
                      48609733, 2200306550, 1653985193, 298326376, 1316178497,
                      3007786442, 2064951626, 458293330, 2589141269, 3591329599,
                      3164325604, 727753846, 2179363840, 146436021, 1461446943,
                      4069977195, 705550613, 3059967265, 3887724982, 4281599278,
                      3313849956, 1404054877, 2845806497, 146425753, 1854211946,
                      1266315497, 3048417604, 3681880366, 3289982499,
                      2909710000, 1235738493, 2632868024, 2414719590,
                      3970600049, 1771706367, 1449415276, 3266420449, 422970021,
                      1963543593, 2690192192, 3826793022, 1062508698,
                      1531092325, 1804592342, 2583117782, 2714934279,
                      4024971509, 1294809318, 4028980673, 1289560198,
                      2221992742, 1669523910, 35572830, 157838143, 1052438473,
                      1016535060, 1802137761, 1753167236, 1386275462,
                      3080475397, 2857371447, 1040679964, 2145300060,
                      2390574316, 1461121720, 2956646967, 4031777805,
                      4028374788, 33600511, 2920084762, 1018524850, 629373528,
                      3691585981, 3515945977, 2091462646, 2486323059, 586499841,
                      988145025, 935516892, 3367335476, 2599673255, 2839830854,
                      265290510, 3972581182, 2759138881, 3795373465, 1005194799,
                      847297441, 406762289, 1314163512, 1332590856, 1866599683,
                      4127851711, 750260880, 613907577, 1450815602, 3165620655,
                      3734664991, 3650291728, 3012275730, 3704569646,
                      1427272223, 778793252, 1343938022, 2676280711, 2052605720,
                      1946737175, 3164576444, 3914038668, 3967478842,
                      3682934266, 1661551462, 3294938066, 4011595847, 840292616,
                      3712170807, 616741398, 312560963, 711312465, 1351876610,
                      322626781, 1910503582, 271666773, 2175563734, 1594956187,
                      70604529, 3617834859, 1007753275, 1495573769, 4069517037,
                      2549218298, 2663038764, 504708206, 2263041392, 3941167025,
                      2249088522, 1514023603, 1998579484, 1312622330, 694541497,
                      2582060303, 2151582166, 1382467621, 776784248, 2618340202,
                      3323268794, 2497899128, 2784771155, 503983604, 4076293799,
                      907881277, 423175695, 432175456, 1378068232, 4145222326,
                      3954048622, 3938656102, 3820766613, 2793130115,
                      2977904593, 26017576, 3274890735, 3194772133, 1700274565,
                      1756076034, 4006520079, 3677328699, 720338349, 1533947780,
                      354530856, 688349552, 3973924725, 1637815568, 332179504,
                      3949051286, 53804574, 2852348879, 3044236432, 1282449977,
                      3583942155, 3416972820, 4006381244, 1617046695,
                      2628476075, 3002303598, 1686838959, 431878346, 2686675385,
                      1700445008, 1080580658, 1009431731, 832498133, 3223435511,
                      2605976345, 2271191193, 2516031870, 1648197032,
                      4164389018, 2548247927, 300782431, 375919233, 238389289,
                      3353747414, 2531188641, 2019080857, 1475708069, 455242339,
                      2609103871, 448939670, 3451063019, 1395535956, 2413381860,
                      1841049896, 1491858159, 885456874, 4264095073, 4001119347,
                      1565136089, 3898914787, 1108368660, 540939232, 1173283510,
                      2745871338, 3681308437, 4207628240, 3343053890,
                      4016749493, 1699691293, 1103962373, 3625875870,
                      2256883143, 3830138730, 1031889488, 3479347698,
                      1535977030, 4236805024, 3251091107, 2132092099,
                      1774941330, 1199868427, 1452454533, 157007616, 2904115357,
                      342012276, 595725824, 1480756522, 206960106, 497939518,
                      591360097, 863170706, 2375253569, 3596610801, 1814182875,
                      2094937945, 3421402208, 1082520231, 3463918190,
                      2785509508, 435703966, 3908032597, 1641649973, 2842273706,
                      3305899714, 1510255612, 2148256476, 2655287854,
                      3276092548, 4258621189, 236887753, 3681803219, 274041037,
                      1734335097, 3815195456, 3317970021, 1899903192,
                      1026095262, 4050517792, 356393447, 2410691914, 3873677099,
                      3682840055, 3913112168, 2491498743, 4132185628,
                      2489919796, 1091903735, 1979897079, 3170134830,
                      3567386728, 3557303409, 857797738, 1136121015, 1342202287,
                      507115054, 2535736646, 337727348, 3213592640, 1301675037,
                      2528481711, 1895095763, 1721773893, 3216771564, 62756741,
                      2142006736, 835421444, 2531993523, 1442658625, 3659876326,
                      2882144922, 676362277, 1392781812, 170690266, 3921047035,
                      1759253602, 3611846912, 1745797284, 664899054, 1329594018,
                      3901205900, 3045908486, 2062866102, 2865634940,
                      3543621612, 3464012697, 1080764994, 553557557, 3656615353,
                      3996768171, 991055499, 499776247, 1265440854, 648242737,
                      3940784050, 980351604, 3713745714, 1749149687, 3396870395,
                      4211799374, 3640570775, 1161844396, 3125318951,
                      1431517754, 545492359, 4268468663, 3499529547, 1437099964,
                      2702547544, 3433638243, 2581715763, 2787789398,
                      1060185593, 1593081372, 2418618748, 4260947970, 69676912,
                      2159744348, 86519011, 2512459080, 3838209314, 1220612927,
                      3339683548, 133810670, 1090789135, 1078426020, 1569222167,
                      845107691, 3583754449, 4072456591, 1091646820, 628848692,
                      1613405280, 3757631651, 526609435, 236106946, 48312990,
                      2942717905, 3402727701, 1797494240, 859738849, 992217954,
                      4005476642, 2243076622, 3870952857, 3732016268, 765654824,
                      3490871365, 2511836413, 1685915746, 3888969200,
                      1414112111, 2273134842, 3281911079, 4080962846, 172450625,
                      2569994100, 980381355, 4109958455, 2819808352, 2716589560,
                      2568741196, 3681446669, 3329971472, 1835478071, 660984891,
                      3704678404, 4045999559, 3422617507, 3040415634,
                      1762651403, 1719377915, 3470491036, 2693910283,
                      3642056355, 3138596744, 1364962596, 2073328063,
                      1983633131, 926494387, 3423689081, 2150032023, 4096667949,
                      1749200295, 3328846651, 309677260, 2016342300, 1779581495,
                      3079819751, 111262694, 1274766160, 443224088, 298511866,
                      1025883608, 3806446537, 1145181785, 168956806, 3641502830,
                      3584813610, 1689216846, 3666258015, 3200248200,
                      1692713982, 2646376535, 4042768518, 1618508792,
                      1610833997, 3523052358, 4130873264, 2001055236,
                      3610705100, 2202168115, 4028541809, 2961195399,
                      1006657119, 2006996926, 3186142756, 1430667929,
                      3210227297, 1314452623, 4074634658, 4101304120,
                      2273951170, 1399257539, 3367210612, 3027628629,
                      1190975929, 2062231137, 2333990788, 2221543033,
                      2438960610, 1181637006, 548689776, 2362791313, 3372408396,
                      3104550113, 3145860560, 296247880, 1970579870, 3078560182,
                      3769228297, 1714227617, 3291629107, 3898220290, 166772364,
                      1251581989, 493813264, 448347421, 195405023, 2709975567,
                      677966185, 3703036547, 1463355134, 2715995803, 1338867538,
                      1343315457, 2802222074, 2684532164, 233230375, 2599980071,
                      2000651841, 3277868038, 1638401717, 4028070440,
                      3237316320, 6314154, 819756386, 300326615, 590932579,
                      1405279636, 3267499572, 3150704214, 2428286686,
                      3959192993, 3461946742, 1862657033, 1266418056, 963775037,
                      2089974820, 2263052895, 1917689273, 448879540, 3550394620,
                      3981727096, 150775221, 3627908307, 1303187396, 508620638,
                      2975983352, 2726630617, 1817252668, 1876281319,
                      1457606340, 908771278, 3720792119, 3617206836, 2455994898,
                      1729034894, 1080033504, 976866871, 3556439503, 2881648439,
                      1522871579, 1555064734, 1336096578, 3548522304,
                      2579274686, 3574697629, 3205460757, 3593280638,
                      3338716283, 3079412587, 564236357, 2993598910, 1781952180,
                      1464380207, 3163844217, 3332601554, 1699332808,
                      1393555694, 1183702653, 3581086237, 1288719814, 691649499,
                      2847557200, 2895455976, 3193889540, 2717570544,
                      1781354906, 1676643554, 2592534050, 3230253752,
                      1126444790, 2770207658, 2633158820, 2210423226,
                      2615765581, 2414155088, 3127139286, 673620729, 2805611233,
                      1269405062, 4015350505, 3341807571, 4149409754,
                      1057255273, 2012875353, 2162469141, 2276492801,
                      2601117357, 993977747, 3918593370, 2654263191, 753973209,
                      36408145, 2530585658, 25011837, 3520020182, 2088578344,
                      530523599, 2918365339, 1524020338, 1518925132, 3760827505,
                      3759777254, 1202760957, 3985898139, 3906192525, 674977740,
                      4174734889, 2031300136, 2019492241, 3983892565,
                      4153806404, 3822280332, 352677332, 2297720250, 60907813,
                      90501309, 3286998549, 1016092578, 2535922412, 2839152426,
                      457141659, 509813237, 4120667899, 652014361, 1966332200,
                      2975202805, 55981186, 2327461051, 676427537, 3255491064,
                      2882294119, 3433927263, 1307055953, 942726286, 933058658,
                      2468411793, 3933900994, 4215176142, 1361170020,
                      2001714738, 2830558078, 3274259782, 1222529897,
                      1679025792, 2729314320, 3714953764, 1770335741, 151462246,
                      3013232138, 1682292957, 1483529935, 471910574, 1539241949,
                      458788160, 3436315007, 1807016891, 3718408830, 978976581,
                      1043663428, 3165965781, 1927990952, 4200891579,
                      2372276910, 3208408903, 3533431907, 1412390302,
                      2931980059, 4132332400, 1947078029, 3881505623,
                      4168226417, 2941484381, 1077988104, 1320477388, 886195818,
                      18198404, 3786409000, 2509781533, 112762804, 3463356488,
                      1866414978, 891333506, 18488651, 661792760, 1628790961,
                      3885187036, 3141171499, 876946877, 2693282273, 1372485963,
                      791857591, 2686433993, 3759982718, 3167212022, 3472953795,
                      2716379847, 445679433, 3561995674, 3504004811, 3574258232,
                      54117162, 3331405415, 2381918588, 3769707343, 4154350007,
                      1140177722, 4074052095, 668550556, 3214352940, 367459370,
                      261225585, 2610173221, 4209349473, 3468074219, 3265815641,
                      314222801, 3066103646, 3808782860, 282218597, 3406013506,
                      3773591054, 379116347, 1285071038, 846784868, 2669647154,
                      3771962079, 3550491691, 2305946142, 453669953, 1268987020,
                      3317592352, 3279303384, 3744833421, 2610507566,
                      3859509063, 266596637, 3847019092, 517658769, 3462560207,
                      3443424879, 370717030, 4247526661, 2224018117, 4143653529,
                      4112773975, 2788324899, 2477274417, 1456262402,
                      2901442914, 1517677493, 1846949527, 2295493580,
                      3734397586, 2176403920, 1280348187, 1908823572,
                      3871786941, 846861322, 1172426758, 3287448474, 3383383037,
                      1655181056, 3139813346, 901632758, 1897031941, 2986607138,
                      3066810236, 3447102507, 1393639104, 373351379, 950779232,
                      625454576, 3124240540, 4148612726, 2007998917, 544563296,
                      2244738638, 2330496472, 2058025392, 1291430526, 424198748,
                      50039436, 29584100, 3605783033, 2429876329, 2791104160,
                      1057563949, 3255363231, 3075367218, 3463963227,
                      1469046755, 985887462};
    uint32_t *a3 = _a3;
    uint32_t _a4[] = {608135816, 2242054355, 320440878, 57701188, 2752067618,
                      698298832, 137296536, 3964562569, 1160258022, 953160567,
                      3193202383, 887688300, 3232508343, 3380367581, 1065670069,
                      3041331479, 2450970073, 2306472731};
    uint32_t *a4 = _a4;
    uint32_t r5;
    uint32_t v6;
    uint32_t r14;
    uint32_t r15;
    uint32_t v16;
    uint32_t v37;
    uint32_t v58;
    uint32_t v60;
    pthread_t t459;
    bool r466;
    
    read_key(a2);
    r5 = 0;
    for (v6 = 0; v6 < 18; v6++) {
        uint32_t r7;
        uint32_t v8;
        uint32_t v12;
        uint32_t v13;
        
        r7 = 0;
        for (v8 = 0; v8 < 4; v8++) {
            uint32_t v9;
            uint32_t v10;
            uint32_t let11;
            
            v9 = r5;
            v10 = r7;
            r7 = v10 << 8 | (uint32_t) a2[v9];
            let11 = v9 + 1;
            r5 = let11 >= 16 ? 0 : let11;
        }
        v12 = a4[v6];
        v13 = r7;
        a4[v6] = v12 ^ v13;
    }
    r14 = 0;
    r15 = 0;
    for (v16 = 0; v16 < 18; v16 = v16 + 2) {
        uint32_t v17;
        uint32_t v18;
        uint32_t r19;
        uint32_t r20;
        uint32_t r21;
        uint32_t r22;
        uint32_t r23;
        uint32_t r24;
        uint32_t r25;
        uint32_t r26;
        uint32_t r27;
        uint32_t r28;
        uint32_t r29;
        uint32_t r30;
        uint32_t r31;
        uint32_t r32;
        uint32_t r33;
        uint32_t r34;
        uint32_t v35;
        uint32_t v36;
        
        v17 = r14;
        v18 = r15;
        r19 = v17 ^ a4[0];
        r20 = ((((a3[r19 >> 24] + a3[(r19 >> 16 & 255) + 256]) ^ a3[(r19 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r19 & 255) + 768]) ^ v18) ^ a4[1];
        r21 = ((((a3[r20 >> 24] + a3[(r20 >> 16 & 255) + 256]) ^ a3[(r20 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r20 & 255) + 768]) ^ r19) ^ a4[2];
        r22 = ((((a3[r21 >> 24] + a3[(r21 >> 16 & 255) + 256]) ^ a3[(r21 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r21 & 255) + 768]) ^ r20) ^ a4[3];
        r23 = ((((a3[r22 >> 24] + a3[(r22 >> 16 & 255) + 256]) ^ a3[(r22 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r22 & 255) + 768]) ^ r21) ^ a4[4];
        r24 = ((((a3[r23 >> 24] + a3[(r23 >> 16 & 255) + 256]) ^ a3[(r23 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r23 & 255) + 768]) ^ r22) ^ a4[5];
        r25 = ((((a3[r24 >> 24] + a3[(r24 >> 16 & 255) + 256]) ^ a3[(r24 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r24 & 255) + 768]) ^ r23) ^ a4[6];
        r26 = ((((a3[r25 >> 24] + a3[(r25 >> 16 & 255) + 256]) ^ a3[(r25 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r25 & 255) + 768]) ^ r24) ^ a4[7];
        r27 = ((((a3[r26 >> 24] + a3[(r26 >> 16 & 255) + 256]) ^ a3[(r26 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r26 & 255) + 768]) ^ r25) ^ a4[8];
        r28 = ((((a3[r27 >> 24] + a3[(r27 >> 16 & 255) + 256]) ^ a3[(r27 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r27 & 255) + 768]) ^ r26) ^ a4[9];
        r29 = ((((a3[r28 >> 24] + a3[(r28 >> 16 & 255) + 256]) ^ a3[(r28 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r28 & 255) + 768]) ^ r27) ^ a4[10];
        r30 = ((((a3[r29 >> 24] + a3[(r29 >> 16 & 255) + 256]) ^ a3[(r29 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r29 & 255) + 768]) ^ r28) ^ a4[11];
        r31 = ((((a3[r30 >> 24] + a3[(r30 >> 16 & 255) + 256]) ^ a3[(r30 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r30 & 255) + 768]) ^ r29) ^ a4[12];
        r32 = ((((a3[r31 >> 24] + a3[(r31 >> 16 & 255) + 256]) ^ a3[(r31 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r31 & 255) + 768]) ^ r30) ^ a4[13];
        r33 = ((((a3[r32 >> 24] + a3[(r32 >> 16 & 255) + 256]) ^ a3[(r32 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r32 & 255) + 768]) ^ r31) ^ a4[14];
        r34 = ((((a3[r33 >> 24] + a3[(r33 >> 16 & 255) + 256]) ^ a3[(r33 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r33 & 255) + 768]) ^ r32) ^ a4[15];
        r14 = r34 ^ a4[17];
        r15 = ((((a3[r34 >> 24] + a3[(r34 >> 16 & 255) + 256]) ^ a3[(r34 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r34 & 255) + 768]) ^ r33) ^ a4[16];
        v35 = r14;
        v36 = r15;
        a4[v16] = v35;
        a4[v16 + 1] = v36;
    }
    for (v37 = 0; v37 < 1024; v37 = v37 + 2) {
        uint32_t v38;
        uint32_t v39;
        uint32_t r40;
        uint32_t r41;
        uint32_t r42;
        uint32_t r43;
        uint32_t r44;
        uint32_t r45;
        uint32_t r46;
        uint32_t r47;
        uint32_t r48;
        uint32_t r49;
        uint32_t r50;
        uint32_t r51;
        uint32_t r52;
        uint32_t r53;
        uint32_t r54;
        uint32_t r55;
        uint32_t v56;
        uint32_t v57;
        
        v38 = r14;
        v39 = r15;
        r40 = v38 ^ a4[0];
        r41 = ((((a3[r40 >> 24] + a3[(r40 >> 16 & 255) + 256]) ^ a3[(r40 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r40 & 255) + 768]) ^ v39) ^ a4[1];
        r42 = ((((a3[r41 >> 24] + a3[(r41 >> 16 & 255) + 256]) ^ a3[(r41 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r41 & 255) + 768]) ^ r40) ^ a4[2];
        r43 = ((((a3[r42 >> 24] + a3[(r42 >> 16 & 255) + 256]) ^ a3[(r42 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r42 & 255) + 768]) ^ r41) ^ a4[3];
        r44 = ((((a3[r43 >> 24] + a3[(r43 >> 16 & 255) + 256]) ^ a3[(r43 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r43 & 255) + 768]) ^ r42) ^ a4[4];
        r45 = ((((a3[r44 >> 24] + a3[(r44 >> 16 & 255) + 256]) ^ a3[(r44 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r44 & 255) + 768]) ^ r43) ^ a4[5];
        r46 = ((((a3[r45 >> 24] + a3[(r45 >> 16 & 255) + 256]) ^ a3[(r45 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r45 & 255) + 768]) ^ r44) ^ a4[6];
        r47 = ((((a3[r46 >> 24] + a3[(r46 >> 16 & 255) + 256]) ^ a3[(r46 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r46 & 255) + 768]) ^ r45) ^ a4[7];
        r48 = ((((a3[r47 >> 24] + a3[(r47 >> 16 & 255) + 256]) ^ a3[(r47 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r47 & 255) + 768]) ^ r46) ^ a4[8];
        r49 = ((((a3[r48 >> 24] + a3[(r48 >> 16 & 255) + 256]) ^ a3[(r48 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r48 & 255) + 768]) ^ r47) ^ a4[9];
        r50 = ((((a3[r49 >> 24] + a3[(r49 >> 16 & 255) + 256]) ^ a3[(r49 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r49 & 255) + 768]) ^ r48) ^ a4[10];
        r51 = ((((a3[r50 >> 24] + a3[(r50 >> 16 & 255) + 256]) ^ a3[(r50 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r50 & 255) + 768]) ^ r49) ^ a4[11];
        r52 = ((((a3[r51 >> 24] + a3[(r51 >> 16 & 255) + 256]) ^ a3[(r51 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r51 & 255) + 768]) ^ r50) ^ a4[12];
        r53 = ((((a3[r52 >> 24] + a3[(r52 >> 16 & 255) + 256]) ^ a3[(r52 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r52 & 255) + 768]) ^ r51) ^ a4[13];
        r54 = ((((a3[r53 >> 24] + a3[(r53 >> 16 & 255) + 256]) ^ a3[(r53 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r53 & 255) + 768]) ^ r52) ^ a4[14];
        r55 = ((((a3[r54 >> 24] + a3[(r54 >> 16 & 255) + 256]) ^ a3[(r54 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r54 & 255) + 768]) ^ r53) ^ a4[15];
        r14 = r55 ^ a4[17];
        r15 = ((((a3[r55 >> 24] + a3[(r55 >> 16 & 255) + 256]) ^ a3[(r55 >> 8 &
                                                                     255) +
                                                                    512]) +
                a3[(r55 & 255) + 768]) ^ r54) ^ a4[16];
        v56 = r14;
        v57 = r15;
        a3[v37] = v56;
        a3[v37 + 1] = v57;
    }
    for (v58 = 0; v58 <= 17; v58++) {
        uint32_t v59;
        
        v59 = a4[v58];
        a0[v58] = v59;
    }
    for (v60 = 0; v60 <= 1023; v60++) {
        uint32_t v61;
        
        v61 = a3[v60];
        a1[v60] = v61;
    }
    chan62 = chan_new(512 * sizeof(uint64_t));
    chan63 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t64, NULL, thread_t64, NULL);
    chan85 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t86, NULL, thread_t86, NULL);
    chan110 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t111, NULL, thread_t111, NULL);
    chan135 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t136, NULL, thread_t136, NULL);
    chan160 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t161, NULL, thread_t161, NULL);
    chan185 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t186, NULL, thread_t186, NULL);
    chan210 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t211, NULL, thread_t211, NULL);
    chan235 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t236, NULL, thread_t236, NULL);
    chan260 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t261, NULL, thread_t261, NULL);
    chan285 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t286, NULL, thread_t286, NULL);
    chan310 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t311, NULL, thread_t311, NULL);
    chan335 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t336, NULL, thread_t336, NULL);
    chan360 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t361, NULL, thread_t361, NULL);
    chan385 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t386, NULL, thread_t386, NULL);
    chan410 = chan_new(512 * sizeof(uint32_t));
    pthread_create(&t411, NULL, thread_t411, NULL);
    chan435 = chan_new(512 * sizeof(uint64_t));
    pthread_create(&t436, NULL, thread_t436, NULL);
    pthread_create(&t459, NULL, thread_t459, NULL);
    r466 = true;
    while (1) {
        bool v467;
        uint32_t r468;
        uint64_t _a469[512];
        uint64_t *a469 = _a469;
        bool v470;
        
        v467 = r466;
        if (!v467)
            break;
        v470 = read_block(&a469, &r468);
        if (v470) {
            bool v471;
            
            v471 = chan_write(chan62, sizeof(*a469) * (r468 - 0), &a469[0]);
            r466 = v471;
        } else {
            r466 = false;
        }
    }
    chan_close(chan62);
    pthread_join(t459, NULL);
    return 0;
}


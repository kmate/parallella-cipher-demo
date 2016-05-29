#include "chan.h"
#include "io.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
void *thread_t64(void *unused);
void *thread_t82(void *unused);
void *thread_t103(void *unused);
void *thread_t124(void *unused);
void *thread_t145(void *unused);
void *thread_t166(void *unused);
void *thread_t187(void *unused);
void *thread_t208(void *unused);
void *thread_t229(void *unused);
void *thread_t250(void *unused);
void *thread_t271(void *unused);
void *thread_t292(void *unused);
void *thread_t313(void *unused);
void *thread_t334(void *unused);
void *thread_t355(void *unused);
void *thread_t376(void *unused);
void *thread_t393(void *unused);
pthread_t t103;
pthread_t t124;
pthread_t t145;
pthread_t t166;
pthread_t t187;
pthread_t t208;
pthread_t t229;
pthread_t t250;
pthread_t t271;
pthread_t t292;
pthread_t t313;
pthread_t t334;
pthread_t t355;
pthread_t t376;
pthread_t t64;
pthread_t t82;
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
        uint64_t _a71[1];
        uint64_t *a71 = _a71;
        bool v72;
        uint64_t v73;
        uint32_t r74;
        uint32_t r75;
        uint32_t v76;
        bool v77;
        uint32_t r78;
        uint32_t v79;
        bool v80;
        
        chan_read(chan62, sizeof(*a71) * (1 - 0), &a71[0]);
        v72 = chan_last_read_ok(chan62);
        if (!v72) {
            chan_close(chan63);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
        v73 = a71[0];
        r74 = (uint32_t) (v73 >> 32) ^ a65[0];
        r75 = (((a66[r74 >> 24] + a66[(r74 >> 16 & 255) + 256]) ^ a66[(r74 >>
                                                                       8 &
                                                                       255) +
                                                                      512]) +
               a66[(r74 & 255) + 768]) ^ (uint32_t) v73;
        v76 = r75;
        v77 = chan_write(chan63, sizeof(v76), &v76);
        if (!v77) {
            chan_close(chan62);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
        r78 = r74;
        v79 = r78;
        v80 = chan_write(chan63, sizeof(v79), &v79);
        if (!v80) {
            chan_close(chan62);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
    }
    return NULL;
}
chan_t chan81;
void *thread_t82(void *unused)
{
    uint32_t _a83[18];
    uint32_t *a83 = _a83;
    uint32_t _a84[1024];
    uint32_t *a84 = _a84;
    uint32_t v85;
    uint32_t v87;
    
    for (v85 = 0; v85 <= 17; v85++) {
        uint32_t v86;
        
        v86 = a0[v85];
        a83[v85] = v86;
    }
    for (v87 = 0; v87 <= 1023; v87++) {
        uint32_t v88;
        
        v88 = a1[v87];
        a84[v87] = v88;
    }
    while (1) {
        uint32_t _a89[1];
        uint32_t *a89 = _a89;
        bool v90;
        uint32_t v91;
        uint32_t _a92[1];
        uint32_t *a92 = _a92;
        bool v93;
        uint32_t v94;
        uint32_t r95;
        uint32_t r96;
        uint32_t v97;
        bool v98;
        uint32_t r99;
        uint32_t v100;
        bool v101;
        
        chan_read(chan63, sizeof(*a89) * (1 - 0), &a89[0]);
        v90 = chan_last_read_ok(chan63);
        if (!v90) {
            chan_close(chan81);
            pthread_cancel(t82);
            pthread_join(t82, NULL);
        }
        v91 = a89[0];
        chan_read(chan63, sizeof(*a92) * (1 - 0), &a92[0]);
        v93 = chan_last_read_ok(chan63);
        if (!v93) {
            chan_close(chan81);
            pthread_cancel(t82);
            pthread_join(t82, NULL);
        }
        v94 = a92[0];
        r95 = v91 ^ a83[1];
        r96 = (((a84[r95 >> 24] + a84[(r95 >> 16 & 255) + 256]) ^ a84[(r95 >>
                                                                       8 &
                                                                       255) +
                                                                      512]) +
               a84[(r95 & 255) + 768]) ^ v94;
        v97 = r96;
        v98 = chan_write(chan81, sizeof(v97), &v97);
        if (!v98) {
            chan_close(chan63);
            pthread_cancel(t82);
            pthread_join(t82, NULL);
        }
        r99 = r95;
        v100 = r99;
        v101 = chan_write(chan81, sizeof(v100), &v100);
        if (!v101) {
            chan_close(chan63);
            pthread_cancel(t82);
            pthread_join(t82, NULL);
        }
    }
    return NULL;
}
chan_t chan102;
void *thread_t103(void *unused)
{
    uint32_t _a104[18];
    uint32_t *a104 = _a104;
    uint32_t _a105[1024];
    uint32_t *a105 = _a105;
    uint32_t v106;
    uint32_t v108;
    
    for (v106 = 0; v106 <= 17; v106++) {
        uint32_t v107;
        
        v107 = a0[v106];
        a104[v106] = v107;
    }
    for (v108 = 0; v108 <= 1023; v108++) {
        uint32_t v109;
        
        v109 = a1[v108];
        a105[v108] = v109;
    }
    while (1) {
        uint32_t _a110[1];
        uint32_t *a110 = _a110;
        bool v111;
        uint32_t v112;
        uint32_t _a113[1];
        uint32_t *a113 = _a113;
        bool v114;
        uint32_t v115;
        uint32_t r116;
        uint32_t r117;
        uint32_t v118;
        bool v119;
        uint32_t r120;
        uint32_t v121;
        bool v122;
        
        chan_read(chan81, sizeof(*a110) * (1 - 0), &a110[0]);
        v111 = chan_last_read_ok(chan81);
        if (!v111) {
            chan_close(chan102);
            pthread_cancel(t103);
            pthread_join(t103, NULL);
        }
        v112 = a110[0];
        chan_read(chan81, sizeof(*a113) * (1 - 0), &a113[0]);
        v114 = chan_last_read_ok(chan81);
        if (!v114) {
            chan_close(chan102);
            pthread_cancel(t103);
            pthread_join(t103, NULL);
        }
        v115 = a113[0];
        r116 = v112 ^ a104[2];
        r117 = (((a105[r116 >> 24] + a105[(r116 >> 16 & 255) + 256]) ^
                 a105[(r116 >> 8 & 255) + 512]) + a105[(r116 & 255) + 768]) ^
            v115;
        v118 = r117;
        v119 = chan_write(chan102, sizeof(v118), &v118);
        if (!v119) {
            chan_close(chan81);
            pthread_cancel(t103);
            pthread_join(t103, NULL);
        }
        r120 = r116;
        v121 = r120;
        v122 = chan_write(chan102, sizeof(v121), &v121);
        if (!v122) {
            chan_close(chan81);
            pthread_cancel(t103);
            pthread_join(t103, NULL);
        }
    }
    return NULL;
}
chan_t chan123;
void *thread_t124(void *unused)
{
    uint32_t _a125[18];
    uint32_t *a125 = _a125;
    uint32_t _a126[1024];
    uint32_t *a126 = _a126;
    uint32_t v127;
    uint32_t v129;
    
    for (v127 = 0; v127 <= 17; v127++) {
        uint32_t v128;
        
        v128 = a0[v127];
        a125[v127] = v128;
    }
    for (v129 = 0; v129 <= 1023; v129++) {
        uint32_t v130;
        
        v130 = a1[v129];
        a126[v129] = v130;
    }
    while (1) {
        uint32_t _a131[1];
        uint32_t *a131 = _a131;
        bool v132;
        uint32_t v133;
        uint32_t _a134[1];
        uint32_t *a134 = _a134;
        bool v135;
        uint32_t v136;
        uint32_t r137;
        uint32_t r138;
        uint32_t v139;
        bool v140;
        uint32_t r141;
        uint32_t v142;
        bool v143;
        
        chan_read(chan102, sizeof(*a131) * (1 - 0), &a131[0]);
        v132 = chan_last_read_ok(chan102);
        if (!v132) {
            chan_close(chan123);
            pthread_cancel(t124);
            pthread_join(t124, NULL);
        }
        v133 = a131[0];
        chan_read(chan102, sizeof(*a134) * (1 - 0), &a134[0]);
        v135 = chan_last_read_ok(chan102);
        if (!v135) {
            chan_close(chan123);
            pthread_cancel(t124);
            pthread_join(t124, NULL);
        }
        v136 = a134[0];
        r137 = v133 ^ a125[3];
        r138 = (((a126[r137 >> 24] + a126[(r137 >> 16 & 255) + 256]) ^
                 a126[(r137 >> 8 & 255) + 512]) + a126[(r137 & 255) + 768]) ^
            v136;
        v139 = r138;
        v140 = chan_write(chan123, sizeof(v139), &v139);
        if (!v140) {
            chan_close(chan102);
            pthread_cancel(t124);
            pthread_join(t124, NULL);
        }
        r141 = r137;
        v142 = r141;
        v143 = chan_write(chan123, sizeof(v142), &v142);
        if (!v143) {
            chan_close(chan102);
            pthread_cancel(t124);
            pthread_join(t124, NULL);
        }
    }
    return NULL;
}
chan_t chan144;
void *thread_t145(void *unused)
{
    uint32_t _a146[18];
    uint32_t *a146 = _a146;
    uint32_t _a147[1024];
    uint32_t *a147 = _a147;
    uint32_t v148;
    uint32_t v150;
    
    for (v148 = 0; v148 <= 17; v148++) {
        uint32_t v149;
        
        v149 = a0[v148];
        a146[v148] = v149;
    }
    for (v150 = 0; v150 <= 1023; v150++) {
        uint32_t v151;
        
        v151 = a1[v150];
        a147[v150] = v151;
    }
    while (1) {
        uint32_t _a152[1];
        uint32_t *a152 = _a152;
        bool v153;
        uint32_t v154;
        uint32_t _a155[1];
        uint32_t *a155 = _a155;
        bool v156;
        uint32_t v157;
        uint32_t r158;
        uint32_t r159;
        uint32_t v160;
        bool v161;
        uint32_t r162;
        uint32_t v163;
        bool v164;
        
        chan_read(chan123, sizeof(*a152) * (1 - 0), &a152[0]);
        v153 = chan_last_read_ok(chan123);
        if (!v153) {
            chan_close(chan144);
            pthread_cancel(t145);
            pthread_join(t145, NULL);
        }
        v154 = a152[0];
        chan_read(chan123, sizeof(*a155) * (1 - 0), &a155[0]);
        v156 = chan_last_read_ok(chan123);
        if (!v156) {
            chan_close(chan144);
            pthread_cancel(t145);
            pthread_join(t145, NULL);
        }
        v157 = a155[0];
        r158 = v154 ^ a146[4];
        r159 = (((a147[r158 >> 24] + a147[(r158 >> 16 & 255) + 256]) ^
                 a147[(r158 >> 8 & 255) + 512]) + a147[(r158 & 255) + 768]) ^
            v157;
        v160 = r159;
        v161 = chan_write(chan144, sizeof(v160), &v160);
        if (!v161) {
            chan_close(chan123);
            pthread_cancel(t145);
            pthread_join(t145, NULL);
        }
        r162 = r158;
        v163 = r162;
        v164 = chan_write(chan144, sizeof(v163), &v163);
        if (!v164) {
            chan_close(chan123);
            pthread_cancel(t145);
            pthread_join(t145, NULL);
        }
    }
    return NULL;
}
chan_t chan165;
void *thread_t166(void *unused)
{
    uint32_t _a167[18];
    uint32_t *a167 = _a167;
    uint32_t _a168[1024];
    uint32_t *a168 = _a168;
    uint32_t v169;
    uint32_t v171;
    
    for (v169 = 0; v169 <= 17; v169++) {
        uint32_t v170;
        
        v170 = a0[v169];
        a167[v169] = v170;
    }
    for (v171 = 0; v171 <= 1023; v171++) {
        uint32_t v172;
        
        v172 = a1[v171];
        a168[v171] = v172;
    }
    while (1) {
        uint32_t _a173[1];
        uint32_t *a173 = _a173;
        bool v174;
        uint32_t v175;
        uint32_t _a176[1];
        uint32_t *a176 = _a176;
        bool v177;
        uint32_t v178;
        uint32_t r179;
        uint32_t r180;
        uint32_t v181;
        bool v182;
        uint32_t r183;
        uint32_t v184;
        bool v185;
        
        chan_read(chan144, sizeof(*a173) * (1 - 0), &a173[0]);
        v174 = chan_last_read_ok(chan144);
        if (!v174) {
            chan_close(chan165);
            pthread_cancel(t166);
            pthread_join(t166, NULL);
        }
        v175 = a173[0];
        chan_read(chan144, sizeof(*a176) * (1 - 0), &a176[0]);
        v177 = chan_last_read_ok(chan144);
        if (!v177) {
            chan_close(chan165);
            pthread_cancel(t166);
            pthread_join(t166, NULL);
        }
        v178 = a176[0];
        r179 = v175 ^ a167[5];
        r180 = (((a168[r179 >> 24] + a168[(r179 >> 16 & 255) + 256]) ^
                 a168[(r179 >> 8 & 255) + 512]) + a168[(r179 & 255) + 768]) ^
            v178;
        v181 = r180;
        v182 = chan_write(chan165, sizeof(v181), &v181);
        if (!v182) {
            chan_close(chan144);
            pthread_cancel(t166);
            pthread_join(t166, NULL);
        }
        r183 = r179;
        v184 = r183;
        v185 = chan_write(chan165, sizeof(v184), &v184);
        if (!v185) {
            chan_close(chan144);
            pthread_cancel(t166);
            pthread_join(t166, NULL);
        }
    }
    return NULL;
}
chan_t chan186;
void *thread_t187(void *unused)
{
    uint32_t _a188[18];
    uint32_t *a188 = _a188;
    uint32_t _a189[1024];
    uint32_t *a189 = _a189;
    uint32_t v190;
    uint32_t v192;
    
    for (v190 = 0; v190 <= 17; v190++) {
        uint32_t v191;
        
        v191 = a0[v190];
        a188[v190] = v191;
    }
    for (v192 = 0; v192 <= 1023; v192++) {
        uint32_t v193;
        
        v193 = a1[v192];
        a189[v192] = v193;
    }
    while (1) {
        uint32_t _a194[1];
        uint32_t *a194 = _a194;
        bool v195;
        uint32_t v196;
        uint32_t _a197[1];
        uint32_t *a197 = _a197;
        bool v198;
        uint32_t v199;
        uint32_t r200;
        uint32_t r201;
        uint32_t v202;
        bool v203;
        uint32_t r204;
        uint32_t v205;
        bool v206;
        
        chan_read(chan165, sizeof(*a194) * (1 - 0), &a194[0]);
        v195 = chan_last_read_ok(chan165);
        if (!v195) {
            chan_close(chan186);
            pthread_cancel(t187);
            pthread_join(t187, NULL);
        }
        v196 = a194[0];
        chan_read(chan165, sizeof(*a197) * (1 - 0), &a197[0]);
        v198 = chan_last_read_ok(chan165);
        if (!v198) {
            chan_close(chan186);
            pthread_cancel(t187);
            pthread_join(t187, NULL);
        }
        v199 = a197[0];
        r200 = v196 ^ a188[6];
        r201 = (((a189[r200 >> 24] + a189[(r200 >> 16 & 255) + 256]) ^
                 a189[(r200 >> 8 & 255) + 512]) + a189[(r200 & 255) + 768]) ^
            v199;
        v202 = r201;
        v203 = chan_write(chan186, sizeof(v202), &v202);
        if (!v203) {
            chan_close(chan165);
            pthread_cancel(t187);
            pthread_join(t187, NULL);
        }
        r204 = r200;
        v205 = r204;
        v206 = chan_write(chan186, sizeof(v205), &v205);
        if (!v206) {
            chan_close(chan165);
            pthread_cancel(t187);
            pthread_join(t187, NULL);
        }
    }
    return NULL;
}
chan_t chan207;
void *thread_t208(void *unused)
{
    uint32_t _a209[18];
    uint32_t *a209 = _a209;
    uint32_t _a210[1024];
    uint32_t *a210 = _a210;
    uint32_t v211;
    uint32_t v213;
    
    for (v211 = 0; v211 <= 17; v211++) {
        uint32_t v212;
        
        v212 = a0[v211];
        a209[v211] = v212;
    }
    for (v213 = 0; v213 <= 1023; v213++) {
        uint32_t v214;
        
        v214 = a1[v213];
        a210[v213] = v214;
    }
    while (1) {
        uint32_t _a215[1];
        uint32_t *a215 = _a215;
        bool v216;
        uint32_t v217;
        uint32_t _a218[1];
        uint32_t *a218 = _a218;
        bool v219;
        uint32_t v220;
        uint32_t r221;
        uint32_t r222;
        uint32_t v223;
        bool v224;
        uint32_t r225;
        uint32_t v226;
        bool v227;
        
        chan_read(chan186, sizeof(*a215) * (1 - 0), &a215[0]);
        v216 = chan_last_read_ok(chan186);
        if (!v216) {
            chan_close(chan207);
            pthread_cancel(t208);
            pthread_join(t208, NULL);
        }
        v217 = a215[0];
        chan_read(chan186, sizeof(*a218) * (1 - 0), &a218[0]);
        v219 = chan_last_read_ok(chan186);
        if (!v219) {
            chan_close(chan207);
            pthread_cancel(t208);
            pthread_join(t208, NULL);
        }
        v220 = a218[0];
        r221 = v217 ^ a209[7];
        r222 = (((a210[r221 >> 24] + a210[(r221 >> 16 & 255) + 256]) ^
                 a210[(r221 >> 8 & 255) + 512]) + a210[(r221 & 255) + 768]) ^
            v220;
        v223 = r222;
        v224 = chan_write(chan207, sizeof(v223), &v223);
        if (!v224) {
            chan_close(chan186);
            pthread_cancel(t208);
            pthread_join(t208, NULL);
        }
        r225 = r221;
        v226 = r225;
        v227 = chan_write(chan207, sizeof(v226), &v226);
        if (!v227) {
            chan_close(chan186);
            pthread_cancel(t208);
            pthread_join(t208, NULL);
        }
    }
    return NULL;
}
chan_t chan228;
void *thread_t229(void *unused)
{
    uint32_t _a230[18];
    uint32_t *a230 = _a230;
    uint32_t _a231[1024];
    uint32_t *a231 = _a231;
    uint32_t v232;
    uint32_t v234;
    
    for (v232 = 0; v232 <= 17; v232++) {
        uint32_t v233;
        
        v233 = a0[v232];
        a230[v232] = v233;
    }
    for (v234 = 0; v234 <= 1023; v234++) {
        uint32_t v235;
        
        v235 = a1[v234];
        a231[v234] = v235;
    }
    while (1) {
        uint32_t _a236[1];
        uint32_t *a236 = _a236;
        bool v237;
        uint32_t v238;
        uint32_t _a239[1];
        uint32_t *a239 = _a239;
        bool v240;
        uint32_t v241;
        uint32_t r242;
        uint32_t r243;
        uint32_t v244;
        bool v245;
        uint32_t r246;
        uint32_t v247;
        bool v248;
        
        chan_read(chan207, sizeof(*a236) * (1 - 0), &a236[0]);
        v237 = chan_last_read_ok(chan207);
        if (!v237) {
            chan_close(chan228);
            pthread_cancel(t229);
            pthread_join(t229, NULL);
        }
        v238 = a236[0];
        chan_read(chan207, sizeof(*a239) * (1 - 0), &a239[0]);
        v240 = chan_last_read_ok(chan207);
        if (!v240) {
            chan_close(chan228);
            pthread_cancel(t229);
            pthread_join(t229, NULL);
        }
        v241 = a239[0];
        r242 = v238 ^ a230[8];
        r243 = (((a231[r242 >> 24] + a231[(r242 >> 16 & 255) + 256]) ^
                 a231[(r242 >> 8 & 255) + 512]) + a231[(r242 & 255) + 768]) ^
            v241;
        v244 = r243;
        v245 = chan_write(chan228, sizeof(v244), &v244);
        if (!v245) {
            chan_close(chan207);
            pthread_cancel(t229);
            pthread_join(t229, NULL);
        }
        r246 = r242;
        v247 = r246;
        v248 = chan_write(chan228, sizeof(v247), &v247);
        if (!v248) {
            chan_close(chan207);
            pthread_cancel(t229);
            pthread_join(t229, NULL);
        }
    }
    return NULL;
}
chan_t chan249;
void *thread_t250(void *unused)
{
    uint32_t _a251[18];
    uint32_t *a251 = _a251;
    uint32_t _a252[1024];
    uint32_t *a252 = _a252;
    uint32_t v253;
    uint32_t v255;
    
    for (v253 = 0; v253 <= 17; v253++) {
        uint32_t v254;
        
        v254 = a0[v253];
        a251[v253] = v254;
    }
    for (v255 = 0; v255 <= 1023; v255++) {
        uint32_t v256;
        
        v256 = a1[v255];
        a252[v255] = v256;
    }
    while (1) {
        uint32_t _a257[1];
        uint32_t *a257 = _a257;
        bool v258;
        uint32_t v259;
        uint32_t _a260[1];
        uint32_t *a260 = _a260;
        bool v261;
        uint32_t v262;
        uint32_t r263;
        uint32_t r264;
        uint32_t v265;
        bool v266;
        uint32_t r267;
        uint32_t v268;
        bool v269;
        
        chan_read(chan228, sizeof(*a257) * (1 - 0), &a257[0]);
        v258 = chan_last_read_ok(chan228);
        if (!v258) {
            chan_close(chan249);
            pthread_cancel(t250);
            pthread_join(t250, NULL);
        }
        v259 = a257[0];
        chan_read(chan228, sizeof(*a260) * (1 - 0), &a260[0]);
        v261 = chan_last_read_ok(chan228);
        if (!v261) {
            chan_close(chan249);
            pthread_cancel(t250);
            pthread_join(t250, NULL);
        }
        v262 = a260[0];
        r263 = v259 ^ a251[9];
        r264 = (((a252[r263 >> 24] + a252[(r263 >> 16 & 255) + 256]) ^
                 a252[(r263 >> 8 & 255) + 512]) + a252[(r263 & 255) + 768]) ^
            v262;
        v265 = r264;
        v266 = chan_write(chan249, sizeof(v265), &v265);
        if (!v266) {
            chan_close(chan228);
            pthread_cancel(t250);
            pthread_join(t250, NULL);
        }
        r267 = r263;
        v268 = r267;
        v269 = chan_write(chan249, sizeof(v268), &v268);
        if (!v269) {
            chan_close(chan228);
            pthread_cancel(t250);
            pthread_join(t250, NULL);
        }
    }
    return NULL;
}
chan_t chan270;
void *thread_t271(void *unused)
{
    uint32_t _a272[18];
    uint32_t *a272 = _a272;
    uint32_t _a273[1024];
    uint32_t *a273 = _a273;
    uint32_t v274;
    uint32_t v276;
    
    for (v274 = 0; v274 <= 17; v274++) {
        uint32_t v275;
        
        v275 = a0[v274];
        a272[v274] = v275;
    }
    for (v276 = 0; v276 <= 1023; v276++) {
        uint32_t v277;
        
        v277 = a1[v276];
        a273[v276] = v277;
    }
    while (1) {
        uint32_t _a278[1];
        uint32_t *a278 = _a278;
        bool v279;
        uint32_t v280;
        uint32_t _a281[1];
        uint32_t *a281 = _a281;
        bool v282;
        uint32_t v283;
        uint32_t r284;
        uint32_t r285;
        uint32_t v286;
        bool v287;
        uint32_t r288;
        uint32_t v289;
        bool v290;
        
        chan_read(chan249, sizeof(*a278) * (1 - 0), &a278[0]);
        v279 = chan_last_read_ok(chan249);
        if (!v279) {
            chan_close(chan270);
            pthread_cancel(t271);
            pthread_join(t271, NULL);
        }
        v280 = a278[0];
        chan_read(chan249, sizeof(*a281) * (1 - 0), &a281[0]);
        v282 = chan_last_read_ok(chan249);
        if (!v282) {
            chan_close(chan270);
            pthread_cancel(t271);
            pthread_join(t271, NULL);
        }
        v283 = a281[0];
        r284 = v280 ^ a272[10];
        r285 = (((a273[r284 >> 24] + a273[(r284 >> 16 & 255) + 256]) ^
                 a273[(r284 >> 8 & 255) + 512]) + a273[(r284 & 255) + 768]) ^
            v283;
        v286 = r285;
        v287 = chan_write(chan270, sizeof(v286), &v286);
        if (!v287) {
            chan_close(chan249);
            pthread_cancel(t271);
            pthread_join(t271, NULL);
        }
        r288 = r284;
        v289 = r288;
        v290 = chan_write(chan270, sizeof(v289), &v289);
        if (!v290) {
            chan_close(chan249);
            pthread_cancel(t271);
            pthread_join(t271, NULL);
        }
    }
    return NULL;
}
chan_t chan291;
void *thread_t292(void *unused)
{
    uint32_t _a293[18];
    uint32_t *a293 = _a293;
    uint32_t _a294[1024];
    uint32_t *a294 = _a294;
    uint32_t v295;
    uint32_t v297;
    
    for (v295 = 0; v295 <= 17; v295++) {
        uint32_t v296;
        
        v296 = a0[v295];
        a293[v295] = v296;
    }
    for (v297 = 0; v297 <= 1023; v297++) {
        uint32_t v298;
        
        v298 = a1[v297];
        a294[v297] = v298;
    }
    while (1) {
        uint32_t _a299[1];
        uint32_t *a299 = _a299;
        bool v300;
        uint32_t v301;
        uint32_t _a302[1];
        uint32_t *a302 = _a302;
        bool v303;
        uint32_t v304;
        uint32_t r305;
        uint32_t r306;
        uint32_t v307;
        bool v308;
        uint32_t r309;
        uint32_t v310;
        bool v311;
        
        chan_read(chan270, sizeof(*a299) * (1 - 0), &a299[0]);
        v300 = chan_last_read_ok(chan270);
        if (!v300) {
            chan_close(chan291);
            pthread_cancel(t292);
            pthread_join(t292, NULL);
        }
        v301 = a299[0];
        chan_read(chan270, sizeof(*a302) * (1 - 0), &a302[0]);
        v303 = chan_last_read_ok(chan270);
        if (!v303) {
            chan_close(chan291);
            pthread_cancel(t292);
            pthread_join(t292, NULL);
        }
        v304 = a302[0];
        r305 = v301 ^ a293[11];
        r306 = (((a294[r305 >> 24] + a294[(r305 >> 16 & 255) + 256]) ^
                 a294[(r305 >> 8 & 255) + 512]) + a294[(r305 & 255) + 768]) ^
            v304;
        v307 = r306;
        v308 = chan_write(chan291, sizeof(v307), &v307);
        if (!v308) {
            chan_close(chan270);
            pthread_cancel(t292);
            pthread_join(t292, NULL);
        }
        r309 = r305;
        v310 = r309;
        v311 = chan_write(chan291, sizeof(v310), &v310);
        if (!v311) {
            chan_close(chan270);
            pthread_cancel(t292);
            pthread_join(t292, NULL);
        }
    }
    return NULL;
}
chan_t chan312;
void *thread_t313(void *unused)
{
    uint32_t _a314[18];
    uint32_t *a314 = _a314;
    uint32_t _a315[1024];
    uint32_t *a315 = _a315;
    uint32_t v316;
    uint32_t v318;
    
    for (v316 = 0; v316 <= 17; v316++) {
        uint32_t v317;
        
        v317 = a0[v316];
        a314[v316] = v317;
    }
    for (v318 = 0; v318 <= 1023; v318++) {
        uint32_t v319;
        
        v319 = a1[v318];
        a315[v318] = v319;
    }
    while (1) {
        uint32_t _a320[1];
        uint32_t *a320 = _a320;
        bool v321;
        uint32_t v322;
        uint32_t _a323[1];
        uint32_t *a323 = _a323;
        bool v324;
        uint32_t v325;
        uint32_t r326;
        uint32_t r327;
        uint32_t v328;
        bool v329;
        uint32_t r330;
        uint32_t v331;
        bool v332;
        
        chan_read(chan291, sizeof(*a320) * (1 - 0), &a320[0]);
        v321 = chan_last_read_ok(chan291);
        if (!v321) {
            chan_close(chan312);
            pthread_cancel(t313);
            pthread_join(t313, NULL);
        }
        v322 = a320[0];
        chan_read(chan291, sizeof(*a323) * (1 - 0), &a323[0]);
        v324 = chan_last_read_ok(chan291);
        if (!v324) {
            chan_close(chan312);
            pthread_cancel(t313);
            pthread_join(t313, NULL);
        }
        v325 = a323[0];
        r326 = v322 ^ a314[12];
        r327 = (((a315[r326 >> 24] + a315[(r326 >> 16 & 255) + 256]) ^
                 a315[(r326 >> 8 & 255) + 512]) + a315[(r326 & 255) + 768]) ^
            v325;
        v328 = r327;
        v329 = chan_write(chan312, sizeof(v328), &v328);
        if (!v329) {
            chan_close(chan291);
            pthread_cancel(t313);
            pthread_join(t313, NULL);
        }
        r330 = r326;
        v331 = r330;
        v332 = chan_write(chan312, sizeof(v331), &v331);
        if (!v332) {
            chan_close(chan291);
            pthread_cancel(t313);
            pthread_join(t313, NULL);
        }
    }
    return NULL;
}
chan_t chan333;
void *thread_t334(void *unused)
{
    uint32_t _a335[18];
    uint32_t *a335 = _a335;
    uint32_t _a336[1024];
    uint32_t *a336 = _a336;
    uint32_t v337;
    uint32_t v339;
    
    for (v337 = 0; v337 <= 17; v337++) {
        uint32_t v338;
        
        v338 = a0[v337];
        a335[v337] = v338;
    }
    for (v339 = 0; v339 <= 1023; v339++) {
        uint32_t v340;
        
        v340 = a1[v339];
        a336[v339] = v340;
    }
    while (1) {
        uint32_t _a341[1];
        uint32_t *a341 = _a341;
        bool v342;
        uint32_t v343;
        uint32_t _a344[1];
        uint32_t *a344 = _a344;
        bool v345;
        uint32_t v346;
        uint32_t r347;
        uint32_t r348;
        uint32_t v349;
        bool v350;
        uint32_t r351;
        uint32_t v352;
        bool v353;
        
        chan_read(chan312, sizeof(*a341) * (1 - 0), &a341[0]);
        v342 = chan_last_read_ok(chan312);
        if (!v342) {
            chan_close(chan333);
            pthread_cancel(t334);
            pthread_join(t334, NULL);
        }
        v343 = a341[0];
        chan_read(chan312, sizeof(*a344) * (1 - 0), &a344[0]);
        v345 = chan_last_read_ok(chan312);
        if (!v345) {
            chan_close(chan333);
            pthread_cancel(t334);
            pthread_join(t334, NULL);
        }
        v346 = a344[0];
        r347 = v343 ^ a335[13];
        r348 = (((a336[r347 >> 24] + a336[(r347 >> 16 & 255) + 256]) ^
                 a336[(r347 >> 8 & 255) + 512]) + a336[(r347 & 255) + 768]) ^
            v346;
        v349 = r348;
        v350 = chan_write(chan333, sizeof(v349), &v349);
        if (!v350) {
            chan_close(chan312);
            pthread_cancel(t334);
            pthread_join(t334, NULL);
        }
        r351 = r347;
        v352 = r351;
        v353 = chan_write(chan333, sizeof(v352), &v352);
        if (!v353) {
            chan_close(chan312);
            pthread_cancel(t334);
            pthread_join(t334, NULL);
        }
    }
    return NULL;
}
chan_t chan354;
void *thread_t355(void *unused)
{
    uint32_t _a356[18];
    uint32_t *a356 = _a356;
    uint32_t _a357[1024];
    uint32_t *a357 = _a357;
    uint32_t v358;
    uint32_t v360;
    
    for (v358 = 0; v358 <= 17; v358++) {
        uint32_t v359;
        
        v359 = a0[v358];
        a356[v358] = v359;
    }
    for (v360 = 0; v360 <= 1023; v360++) {
        uint32_t v361;
        
        v361 = a1[v360];
        a357[v360] = v361;
    }
    while (1) {
        uint32_t _a362[1];
        uint32_t *a362 = _a362;
        bool v363;
        uint32_t v364;
        uint32_t _a365[1];
        uint32_t *a365 = _a365;
        bool v366;
        uint32_t v367;
        uint32_t r368;
        uint32_t r369;
        uint32_t v370;
        bool v371;
        uint32_t r372;
        uint32_t v373;
        bool v374;
        
        chan_read(chan333, sizeof(*a362) * (1 - 0), &a362[0]);
        v363 = chan_last_read_ok(chan333);
        if (!v363) {
            chan_close(chan354);
            pthread_cancel(t355);
            pthread_join(t355, NULL);
        }
        v364 = a362[0];
        chan_read(chan333, sizeof(*a365) * (1 - 0), &a365[0]);
        v366 = chan_last_read_ok(chan333);
        if (!v366) {
            chan_close(chan354);
            pthread_cancel(t355);
            pthread_join(t355, NULL);
        }
        v367 = a365[0];
        r368 = v364 ^ a356[14];
        r369 = (((a357[r368 >> 24] + a357[(r368 >> 16 & 255) + 256]) ^
                 a357[(r368 >> 8 & 255) + 512]) + a357[(r368 & 255) + 768]) ^
            v367;
        v370 = r369;
        v371 = chan_write(chan354, sizeof(v370), &v370);
        if (!v371) {
            chan_close(chan333);
            pthread_cancel(t355);
            pthread_join(t355, NULL);
        }
        r372 = r368;
        v373 = r372;
        v374 = chan_write(chan354, sizeof(v373), &v373);
        if (!v374) {
            chan_close(chan333);
            pthread_cancel(t355);
            pthread_join(t355, NULL);
        }
    }
    return NULL;
}
chan_t chan375;
void *thread_t376(void *unused)
{
    uint32_t _a377[18];
    uint32_t *a377 = _a377;
    uint32_t _a378[1024];
    uint32_t *a378 = _a378;
    uint32_t v379;
    uint32_t v381;
    
    for (v379 = 0; v379 <= 17; v379++) {
        uint32_t v380;
        
        v380 = a0[v379];
        a377[v379] = v380;
    }
    for (v381 = 0; v381 <= 1023; v381++) {
        uint32_t v382;
        
        v382 = a1[v381];
        a378[v381] = v382;
    }
    while (1) {
        uint32_t _a383[1];
        uint32_t *a383 = _a383;
        bool v384;
        uint32_t v385;
        uint32_t _a386[1];
        uint32_t *a386 = _a386;
        bool v387;
        uint32_t v388;
        uint32_t r389;
        uint64_t r390;
        uint64_t v391;
        bool v392;
        
        chan_read(chan354, sizeof(*a383) * (1 - 0), &a383[0]);
        v384 = chan_last_read_ok(chan354);
        if (!v384) {
            chan_close(chan375);
            pthread_cancel(t376);
            pthread_join(t376, NULL);
        }
        v385 = a383[0];
        chan_read(chan354, sizeof(*a386) * (1 - 0), &a386[0]);
        v387 = chan_last_read_ok(chan354);
        if (!v387) {
            chan_close(chan375);
            pthread_cancel(t376);
            pthread_join(t376, NULL);
        }
        v388 = a386[0];
        r389 = v385 ^ a377[15];
        r390 = (uint64_t) (r389 ^ a377[17]) << 32 | (uint64_t) (((((a378[r389 >>
                                                                         24] +
                                                                    a378[(r389 >>
                                                                          16 &
                                                                          255) +
                                                                         256]) ^
                                                                   a378[(r389 >>
                                                                         8 &
                                                                         255) +
                                                                        512]) +
                                                                  a378[(r389 &
                                                                        255) +
                                                                       768]) ^
                                                                 v388) ^
                                                                a377[16]);
        v391 = r390;
        v392 = chan_write(chan375, sizeof(v391), &v391);
        if (!v392) {
            chan_close(chan354);
            pthread_cancel(t376);
            pthread_join(t376, NULL);
        }
    }
    return NULL;
}
void *thread_t393(void *unused)
{
    bool r394;
    
    r394 = true;
    while (1) {
        bool v395;
        uint64_t _a396[1];
        uint64_t *a396 = _a396;
        bool v397;
        
        v395 = r394;
        if (!v395)
            break;
        chan_read(chan375, sizeof(*a396) * (1 - 0), &a396[0]);
        v397 = chan_last_read_ok(chan375);
        if (v397) {
            uint64_t v398;
            bool v399;
            
            v398 = a396[0];
            v399 = write_block(v398);
            r394 = v399;
            if (!v399) {
                chan_close(chan375);
            }
        } else {
            r394 = false;
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
    pthread_t t393;
    bool r400;
    
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
    chan62 = chan_new(1 * sizeof(uint64_t));
    chan63 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t64, NULL, thread_t64, NULL);
    chan81 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t82, NULL, thread_t82, NULL);
    chan102 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t103, NULL, thread_t103, NULL);
    chan123 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t124, NULL, thread_t124, NULL);
    chan144 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t145, NULL, thread_t145, NULL);
    chan165 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t166, NULL, thread_t166, NULL);
    chan186 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t187, NULL, thread_t187, NULL);
    chan207 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t208, NULL, thread_t208, NULL);
    chan228 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t229, NULL, thread_t229, NULL);
    chan249 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t250, NULL, thread_t250, NULL);
    chan270 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t271, NULL, thread_t271, NULL);
    chan291 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t292, NULL, thread_t292, NULL);
    chan312 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t313, NULL, thread_t313, NULL);
    chan333 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t334, NULL, thread_t334, NULL);
    chan354 = chan_new(1 * sizeof(uint32_t));
    pthread_create(&t355, NULL, thread_t355, NULL);
    chan375 = chan_new(1 * sizeof(uint64_t));
    pthread_create(&t376, NULL, thread_t376, NULL);
    pthread_create(&t393, NULL, thread_t393, NULL);
    r400 = true;
    while (1) {
        bool v401;
        uint64_t r402;
        bool v403;
        uint64_t v404;
        
        v401 = r400;
        if (!v401)
            break;
        v403 = read_block(&r402);
        v404 = r402;
        if (v403) {
            uint64_t r405;
            uint64_t v406;
            bool v407;
            
            r405 = v404;
            v406 = r405;
            v407 = chan_write(chan62, sizeof(v406), &v406);
            r400 = v407;
        } else {
            r400 = false;
        }
    }
    chan_close(chan62);
    pthread_join(t393, NULL);
    return 0;
}


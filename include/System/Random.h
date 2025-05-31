#pragma once

#include <globaldefs.h>

struct Random {
    Random(char const *name, unsigned char unk_1C);

    void Init(unsigned long long lcg_state, char const *name, unsigned char unk_1C);
    void Seed64(unsigned long long lcg_state);
    void Seed(unsigned long long lcg_state);
    void Seed32(unsigned int stateHi, unsigned int stateLo);

    unsigned int GetStateHi() const;
    unsigned int GetStateLo() const;

    /* generate a random unsigned integer between 0 and 0xFFFFFFFFu (inclusive). */
    unsigned int Next();

    /* generate a random integer between 0 and maximum (exclusive).
     * if maximum <= 0, returns 0 without updating state. */
    int NextBelow(int maximum);

    /* generate a random floating point number between 0.0f and 1.0f (inclusive). */
    float NextFloat01();

    /* generate a random floating point number between minimum and maximum (inclusive). */
    float NextFloatBetween(float minimum, float maximum);

    /* generate a random floating point number between minimum and maximum (inclusive) with digits precision. */
    float NextFloatScaled(float minimum, float maximum, int digits);

    /* generate a random integer between minimum and maximum (inclusive) */
    int NextBetween(int minimum, int maximum);

    /* +00 */ unsigned long long lcg_state;
    /* +08 */ unsigned long long lcg_multiplier;
    /* +10 */ unsigned long long lcg_increment;
    /* +18 */ char const *name;
    /* +1C */ unsigned char unk_1C;
};

#ifdef jpn
    #define data_02108ddc data_02108d20
#endif

extern Random data_02108ddc;

/* get instance of the global "BT" ("Hoimi table") random */
EXTERN_C Random *GetBTRandom(void);

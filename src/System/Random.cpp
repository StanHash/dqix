#include "System/Random.h"

#include <globaldefs.h>

extern char const data_020f0d5c[]; // = "(no-name)";
extern char const data_020f0d66[]; // = "public";

extern Random data_02108ddc;
// Random data_02108ddc(data_020f0d66, 1);

EXTERN_C struct Random* GetBTRandom(void) {
    return &data_02108ddc;
}

Random::Random(char const* name, unsigned char unk_1C) {
    Init(0uLL, name, unk_1C);
}

void Random::Init(unsigned long long lcg_state, char const* name, unsigned char unk_1C) {
    if (name == NULL) {
        name = data_020f0d5c;
    }

    this->unk_1C = unk_1C;
    this->name = name;

    Seed(lcg_state);
}

void Random::Seed64(unsigned long long lcg_state) {
    Seed(lcg_state);
}

void Random::Seed(unsigned long long lcg_state) {
    static const unsigned long long multiplier = 0x5D588B656C078965uLL;
    static const unsigned long long increment = 0x0000000000269EC3uLL;

    this->lcg_state = lcg_state;
    this->lcg_multiplier = multiplier;
    this->lcg_increment = increment;
}

void Random::Seed32(unsigned int stateHi, unsigned int stateLo) {
    /* ugly! */
    Seed((((unsigned long long) stateHi << 32u) & 0xFFFFFFFF00000000uLL) | (stateLo & 0xFFFFFFFFull));
}

unsigned int Random::GetStateHi() const {
    return (lcg_state >> 32u) & 0xFFFFFFFFu;
}

unsigned int Random::GetStateLo() const {
    return lcg_state & 0xFFFFFFFFu;
}

unsigned int Random::Next() {
    /* <https://en.wikipedia.org/wiki/Linear_congruential_generator> */

    lcg_state = lcg_multiplier * lcg_state + lcg_increment;
    return lcg_state >> 32u;
}

int Random::NextBelow(int maximum) {
    if (maximum <= 0) {
        return 0;
    }

    unsigned char saved_unk_1C = unk_1C;
    unk_1C = 0;

    int result = maximum * NextFloat01();

    if (result >= maximum) {
        result = maximum - 1;
    }

    unk_1C = saved_unk_1C;

    return result;
}

float Random::NextFloat01() {
    unsigned char saved_unk_1C = unk_1C;
    unk_1C = 0;

    float result = Next() / (double) 0xFFFFFFFF;

    unk_1C = saved_unk_1C;

    return result;
}

float Random::NextFloatBetween(float minimum, float maximum) {
    unsigned char saved_unk_1C = unk_1C;
    unk_1C = 0;

    float result = (maximum - minimum) * NextFloat01() + minimum;

    unk_1C = saved_unk_1C;

    return result;
}

float Random::NextFloatScaled(float minimum, float maximum, int digits) {
    unsigned char saved_unk_1C = unk_1C;
    unk_1C = 0;

    int scale = 1;

    for (int i = 0; i < digits; i++) {
        scale = scale * 10;
    }

    int minimum_int = minimum * scale;
    int minimum_max = maximum * scale;

    float result = (float) NextBetween(minimum_int, minimum_max) / scale;

    unk_1C = saved_unk_1C;

    return result;
}

int Random::NextBetween(int minimum, int maximum) {
    unsigned char saved_unk_1C = unk_1C;
    unk_1C = 0;

    int result = NextBelow((maximum - minimum) + 1) + minimum;

    unk_1C = saved_unk_1C;

    return result;
}

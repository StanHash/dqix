#include <globaldefs.h>

EXTERN_C ARM float CalculateTensionBonus(int tension, int attackerLevel) {
    float levelMultiplier = 1.0f + (int) (attackerLevel / 10);
    return levelMultiplier * tension;
}

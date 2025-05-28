#pragma once

#include <globaldefs.h>

EXTERN_C int RoundUp(float value);
EXTERN_C float CalculatePhysicalDamage(int attack, int defense, int* variance);
EXTERN_C float CalculateAttackBuffMultiplier(signed char buffLevel);
EXTERN_C float CalculateDefenseBuffMultiplier(signed char buffLevel);
EXTERN_C float CalculateAgilityBuffMultiplier(signed char buffLevel);
EXTERN_C float CalculateCharmBuffMultiplier(signed char buffLevel);
EXTERN_C float CalculateMagicalMightBuffMultiplier(signed char buffLevel);
EXTERN_C float CalculateMagicalMendingBuffMultiplier(signed char buffLevel);

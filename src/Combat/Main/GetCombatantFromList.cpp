#include <globaldefs.h>

#include "Combat/Main/BattleList.h"

EXTERN_C ARM struct CombatantStruct* GetCombatantFromList(struct BattleStruct* battleStruct, int combatantId) {
    if (combatantId < 0) {
        return 0;
    }
    if (combatantId >= 0xE9) {
        return 0;
    }
    struct CombatantStruct* combatant = battleStruct->combatantList[combatantId];
    if (combatant == 0) {
        return 0;
    }
    if ((combatant->flags & 0x80) == 0) {
        combatant = 0;
    }
    return combatant;
}
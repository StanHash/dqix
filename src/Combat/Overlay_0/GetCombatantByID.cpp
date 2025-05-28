#include <globaldefs.h>

#include "Combat/Main/BattleList.h"

EXTERN_C struct CombatantStruct* GetCombatantByID(int unused, int id) {
    return GetCombatantFromList(GetBattleStruct(), id);
}

#include "procGen.h"

///// Debug
#include <iostream>

#include <cstring> // For Memset 

ProceduralWeaponGen::Weapon::Weapon()
{
    // reserve 5 mods to prevent some fragmentation
    vecModifier.reserve(5);
}

ProceduralWeaponGen::Weapon::~Weapon(){}

bool ProceduralWeaponGen::Weapon::AddModifier(Modifier mod)
{
    vecModifier.push_back(mod);
    EvaluateStats();
    
    return true;
}

//// OOB checks are missing BTW!!! From both remove and replace
/// index can be out of bounds!

bool ProceduralWeaponGen::Weapon::RemoveModifier(uint16_t index)
{
    if(index >= vecModifier.size()) return false;
    // Remove
    vecModifier.erase(vecModifier.begin() + index);
    
    EvaluateStats();
    return true;
}
bool ProceduralWeaponGen::Weapon::ReplaceModifier(uint16_t index, Modifier mod)
{
    if(index >= vecModifier.size()) return false;
    //memcpy(&vecModifier[index], &mod, sizeof(Modifier));
    
    // Remove 
    vecModifier.erase(vecModifier.begin() + index);
    
    // Add new
    vecModifier.push_back(mod);
    
    EvaluateStats();
    return true;
}


void ProceduralWeaponGen::Weapon::EvaluateStats()
{
    // Calc Damage Modifiers
    float tDamage = 0.f;
    for(uint32_t i = 0; i < vecModifier.size(); ++i)
    {
        tDamage += vecModifier[i].weaponDamageMod;
    }
    stats.damage = tDamage;
}
#include "procGen.h"

///// Debug
#include <iostream>

#include <cstring> // For Memset 

ProceduralWeaponGen::Weapon::Weapon()
{
    // reserve 5 mods to prevent some fragmentation
    vecModifier.reserve(5);

	ResetValues();
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
    
    //// Remove 
    //vecModifier.erase(vecModifier.begin() + index);
    //
    //// Add new
    //vecModifier.push_back(mod);
    
    vecModifier[index] = mod;
    
    EvaluateStats();
    return true;
}

void ProceduralWeaponGen::Weapon::ResetValues()
{
	// Zero out all the variables
	stats.fRange = 0.f;
	stats.fDamage = 0.f;
	stats.fFireRate = 0.f;
	stats.bFiresProjectiles = false;
	stats.uAmmoCapacityMagazine = 0;
	stats.uCurrentAmmo = 0;
	stats.uAmmoCapacityMax = 0;
	projDetails.pEffects.clear();
	projDetails.fLifespan = 0.f;
	projDetails.fProjectileForce = 0.f;
	projDetails.fProjectileDamage = 0.f;
}

void ProceduralWeaponGen::Weapon::EvaluateStats()
{
	/// Horrible long eval function! - Maybe functionise it later
	ResetValues();

	for (uint32_t i = 0; i < vecModifier.size(); ++i)
	{
		stats.fRange += vecModifier[i].weaponRangeMod;

		stats.fDamage += vecModifier[i].weaponDamageMod;

		stats.fFireRate += vecModifier[i].weaponFireRateMod;

		stats.bFiresProjectiles = stats.bFiresProjectiles || vecModifier[i].weaponProjectileMod;

		stats.uAmmoCapacityMagazine += vecModifier[i].weaponAmmoCapMagMod;

		stats.uAmmoCapacityMax += vecModifier[i].weaponAmmoCapMaxMod;
		
		projDetails.fLifespan += vecModifier[i].projectileLifespanMod;

		projDetails.fProjectileForce += vecModifier[i].projectileForceMod;

		projDetails.fProjectileDamage += vecModifier[i].projectileDamageMod;

		// Handle this last as it's a loop
		for (uint32_t j = 0; j < vecModifier[i].projectileEffectMod.size(); ++j)
		{
			// This may need handling at some point
			projDetails.pEffects.push_back(vecModifier[i].projectileEffectMod[j]);
		}
		
	}
}

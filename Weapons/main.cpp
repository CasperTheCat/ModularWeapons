// Check C++ Version is at least C++11
#if __cplusplus < 201103L && !_WIN32
#error "Insufficent C++ Standard"
#else


#include "main.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include "procGen.h"

using namespace ProceduralWeaponGen;

int main(int argc, char **argv)
{
    // Create our weapon
    Weapon *tWeap = new Weapon();
    
    // Create a mod
    Modifier tMod;
    tMod.weaponDamageMod = 11.f;
    tMod.weaponRangeMod = 0.f;
    tMod.weaponFireRateMod = 0.f;
	tMod.weaponProjectileMod = false;
	tMod.weaponAmmoCapMagMod = 0;
	tMod.weaponAmmoCapMaxMod = 0;
	tMod.projectileEffectMod.push_back(0x29);
	tMod.projectileLifespanMod = 0.f;
	tMod.projectileForceMod = 0.f;
	tMod.projectileDamageMod = 0.f;
    
    Modifier uMod;
	uMod.weaponDamageMod = 1.f;
	uMod.weaponRangeMod = 0.f;
	uMod.weaponFireRateMod = 10.f;
	uMod.weaponProjectileMod = true;
	uMod.weaponAmmoCapMagMod = 30;
	uMod.weaponAmmoCapMaxMod = 180;
	uMod.projectileEffectMod.push_back(0x10); // Some SpellID or something game engine specific
	uMod.projectileEffectMod.push_back(0x25);
	uMod.projectileEffectMod.push_back(0x100);
	uMod.projectileEffectMod.push_back(0x1A);
	uMod.projectileLifespanMod = 900.f;
	uMod.projectileForceMod = 100.f;
	uMod.projectileDamageMod = 160.f;
    
    // Weapon Example
    std::cout << "Pushing Mod with +" << tMod.weaponDamageMod << " Damage" << std::endl;
    tWeap->AddModifier(tMod);
    std::cout << "New Weapon Damage: " << tWeap->stats.fDamage << std::endl;
    
    std::cout << "Pushing Mod with +" << uMod.weaponDamageMod << " Damage" << std::endl;
    tWeap->AddModifier(uMod);
    std::cout << "New Weapon Damage: " << tWeap->stats.fDamage << std::endl;
    
    std::cout << "Removing the second modifier" << std::endl;
    tWeap->RemoveModifier(1);
    std::cout << "New Weapon Damage: " << tWeap->stats.fDamage << std::endl;
    
    std::cout << "Replacing first modifier with the second" << std::endl;
    tWeap->ReplaceModifier(0,uMod);
    std::cout << "New Weapon Damage: " << tWeap->stats.fDamage << std::endl;

	std::cout << "This weapon ";
	if (tWeap->stats.bFiresProjectiles) std::cout << "is ";
	else std::cout << "is not ";
	std::cout << "ranged" << std::endl;
	
	std::cout << "A projectile fired by thing weapon possesses the following effects: " << std::endl;
	for (int i = 0; i < tWeap->projDetails.pEffects.size(); ++i)
	{
		std::cout << "\t" << std::hex << tWeap->projDetails.pEffects[i] << std::endl;
	}    
}


#endif // End >= C++11 Check

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
    
    Modifier uMod;
    uMod.weaponDamageMod = 5.f;
    uMod.weaponFireRateMod = 1.f;
    uMod.weaponRangeMod = 2.f;
    
    // Weapon Example
    std::cout << "Pushing Mod with +" << tMod.weaponDamageMod << " Damage" << std::endl;
    tWeap->AddModifier(tMod);
    std::cout << "New Weapon Damage: " << tWeap->stats.damage << std::endl;
    
    std::cout << "Pushing Mod with +" << uMod.weaponDamageMod << " Damage" << std::endl;
    tWeap->AddModifier(uMod);
    std::cout << "New Weapon Damage: " << tWeap->stats.damage << std::endl;
    
    std::cout << "Removing the first modifier" << std::endl;
    tWeap->RemoveModifier(0); /// THIS IS STILL ALLOCATED MEMORY! A BETTER SOLUTION SHOULD BE DEVISED
    std::cout << "New Weapon Damage: " << tWeap->stats.damage << std::endl;
    
    std::cout << "Replacing second modifier with the first" << std::endl;
    tWeap->ReplaceModifier(0,tMod); // Remove removed a previous element
    std::cout << "New Weapon Damage: " << tWeap->stats.damage << std::endl;
    
    /// NOTE: IF A WEAPON IS RANGED, IT'S PROJECTILES CAN BE HANDLED VIA THE SAME MODIFIER INTERFACE.
    
    
    
}


#endif // End >= C++11 Check

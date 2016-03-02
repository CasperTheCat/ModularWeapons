#pragma once
#include <cstdint>
#include <vector>

namespace ProceduralWeaponGen
{
    struct Modifier
    {
        float weaponDamageMod;
        float weaponRangeMod;
        float weaponFireRateMod;
    };
    
    struct WeaponStats
    {
        float range;
        float damage;
        float fireRate;
    };

    class Weapon
    {
        /// Private Var
    private:
        std::vector<Modifier> vecModifier;
        
        // Weapon Stats
        //WeaponStats stats;
        
        /// Public Vars
    public:
        WeaponStats stats;
       
        /// Private Methods
    private:
        void EvaluateStats();
        
        /// Public Methods
    public:
        Weapon();
        ~Weapon();
        bool AddModifier(Modifier mod);
        bool RemoveModifier(uint16_t index);
        bool ReplaceModifier(uint16_t index, Modifier mod);    
    };
}
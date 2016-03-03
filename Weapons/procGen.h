#pragma once
#include <cstdint>
#include <vector>

typedef int PROJ_EFFECT;

namespace ProceduralWeaponGen
{
	// Contains all possible modifiable data
    struct Modifier
    {
        float weaponDamageMod;
        float weaponRangeMod;
        float weaponFireRateMod;
		bool weaponProjectileMod;
		uint32_t weaponAmmoCapMagMod;
		uint32_t weaponAmmoCapMaxMod;

		float projectileLifespanMod;
		std::vector<PROJ_EFFECT> projectileEffectMod;
		float projectileForceMod;
		float projectileDamageMod;
    };
    
	// Struct for weapon stats - could (and possibly should) be made part of parent class
    struct WeaponStats
    {
		// Weapon Range
        float fRange;

		// Weapon Damage or some stat
        float fDamage;

		// Weapon fire rate in RPM
        float fFireRate;

		// Does the weapon fire projectiles?
		bool bFiresProjectiles;

		// Ammo Cap per magazine
		uint32_t uAmmoCapacityMagazine;

		// Ammo Current
		uint32_t uCurrentAmmo;

		// Max Capacity
		uint32_t uAmmoCapacityMax;
    };

	struct ProjectileDetails
	{
		// Lifespan
		float fLifespan;

		// Effects. Vector of effects (handled by the game engine)
		std::vector<PROJ_EFFECT> pEffects;

		// Projectile Force
		float fProjectileForce;

		// Projectile Damage
		float fProjectileDamage;
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
        WeaponStats stats; // Should be private, probably
		ProjectileDetails projDetails; // Should be private, probably
       
        /// Private Methods
    private:
        void EvaluateStats();
		void ResetValues();
        
        /// Public Methods
    public:
        Weapon();
        ~Weapon();
        bool AddModifier(Modifier mod);
        bool RemoveModifier(uint16_t index);
        bool ReplaceModifier(uint16_t index, Modifier mod);    
    };
}
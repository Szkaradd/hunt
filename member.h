#ifndef _MEMBER_H
#define _MEMBER_H

//#include "treasure.h"
#include <cstddef>
#include <type_traits>

using strength_t = unsigned int;

template <typename ValueType>
concept TreasureType = requires (ValueType type) {
    {Treasure(type)} -> std::same_as<ValueType>;
};

template<typename ValueType, bool IsArmed>
requires TreasureType<SafeTreasure<ValueType>>
class Adventurer {
    strength_t strength = 0;
    ValueType treasureGathered = 0; // nie wiem jak to przekazac albo pamietac, ale jakos
public:
    
    constexpr static bool isArmed = IsArmed;

    // Zmieniłem te konstruktory ale clang tidy jakos nie lubi tego drugiego xd.
    constexpr Adventurer() requires (!IsArmed) = default;

    constexpr explicit Adventurer(strength_t str) requires (IsArmed){
        strength = str;
    }

    // Tu też clang tidy się wkurza idk czemu.
    constexpr strength_t getStrength() const requires (IsArmed){
        return strength;
    }

    constexpr ValueType pay() {
        ValueType temp = treasureGathered;
        treasureGathered = 0;
        return temp;
    }

    template<bool isTrapped>
    constexpr void loot(Treasure<ValueType, isTrapped> &&treasure) {
        if ((isTrapped && strength > 0) || !isTrapped) { // można zabrać skarb
            treasureGathered += treasure.getLoot(); // nie wiem czy tu nie powinno być -> zamiast .
            if (isTrapped)
                strength /= 2;
        }
    }
};

template<typename ValueType>
using Explorer = Adventurer<ValueType, false>; // nieuzbrojony poszukiwacz przygód

constexpr strength_t fib(size_t n) {
    int f[25] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34,55, 89, 144, 233, 377, 610,
                 987, 1597, 2584, 4181, 6765, 10946,
                 17711, 28657, 46368};

    return f[n];
}

template<typename ValueType, size_t CompletedExpeditions>
requires TreasureType<SafeTreasure<ValueType>> && (CompletedExpeditions < 25)
class Veteran {
    ValueType treasureGathered = 0;
    size_t completedExpeditions = CompletedExpeditions;
    strength_t strength = fib(completedExpeditions);
public:

    constexpr Veteran() = default;
    static const bool isArmed = true;

    template<bool isTrapped>
    constexpr void loot(Treasure<ValueType, isTrapped> &&treasure) {
        // weteran zawsze kozak wie co robic
        treasureGathered += treasure.getLoot();
    }

    constexpr ValueType pay() {
        ValueType temp = treasureGathered;
        treasureGathered = 0;
        return temp;
    }

    constexpr strength_t getStrength() const {
        return strength;
    }
};

#endif //_MEMBER_H

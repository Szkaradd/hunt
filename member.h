//
// Created by szkaradd on 22.11.2021.
//

#ifndef _MEMBER_H
#define _MEMBER_H
using strength_t = uint32_t;

template<typename T, bool trap>
class Adventurer {
    strength_t strength;
    T treasureGathered; // nie wiem jak to przekazac albo pamietac, ale jakos
public:
    constexpr static bool isArmed = trap;

    constexpr Adventurer() {
//        static_assert(!isArmed, "Is armed!"); // nie wiedziec czemu nie dziala
        strength = 0;
        treasureGathered = 0;
    } // pewnie da sie zgrabniej
    constexpr Adventurer(strength_t arg) {
        static_assert(isArmed == false);
        static_assert(std::is_integral<T>::value, "Integral required.");
        strength = arg;
        treasureGathered = 0;
    } // naprawde nie wiem jak to ma do konca byc



    constexpr T getStrength() {
        static_assert(isArmed ==
                      true); // moze cos innego, tylko dla ubzrojonego tasiemca
        return strength;
    }


    constexpr T pay() {
        T temp = treasureGathered;
        treasureGathered = 0;
        return temp;
    }

    template<bool isTrapped>
    constexpr void loot(Treasure<T, isTrapped> &&treasure) {
        if ((isTrapped && strength > 0) || !isTrapped) { // można zabrać skarb
            treasureGathered += treasure.getLoot(); // nie wiem czy tu nie powinno być -> zamiast .
            strength /= 2;
        }
    }
};

constexpr strength_t fib(size_t n) {
    int f[25] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610,
                 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368};

    return f[n];
}

template<typename T, size_t CompletedExpeditions>
class Veteran {
    T treasureGathered;
    size_t completedExpeditions = CompletedExpeditions;
    strength_t strength = fib(completedExpeditions);
public:
//    constexpr Veteran() {
//        static_assert(std::is_integral<T>::value, "Integral required."); // poprawny typ jak wcześniej
//        static_assert(completedExpeditions < 25);
//    }

    constexpr Veteran() = default; // nie wiem troche jak to inaczej sprawdzac, do poprawy bo brakuje asercji
    static const bool isArmed = true;

    template<bool isTrapped>
    constexpr void loot(Treasure<T, isTrapped> &&treasure) {
        // weteran zawsze kozak wie co robic
        treasureGathered += treasure.getLoot();
    }

    constexpr T pay() {
        T temp = treasureGathered;
        treasureGathered = 0;
        return temp;
    }

    constexpr T getStrength() {
        return strength;
    }
};

#endif //_MEMBER_H

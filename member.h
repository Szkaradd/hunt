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
    constexpr Adventurer(strength_t arg)  {
        static_assert(isArmed == true);
        static_assert(std::is_integral<T>::value, "Integral required.");
        strength = arg;
        treasureGathered = 0;
    } // naprawde nie wiem jak to ma do konca byc



    constexpr T getStrength() {
        static_assert(isArmed == true); // moze cos innego, tylko dla ubzrojonego tasiemca
        return strength;
    }


    constexpr T pay() {
        T temp = treasureGathered;
        treasureGathered = 0;
        return temp;
    }
};


#endif //_MEMBER_H


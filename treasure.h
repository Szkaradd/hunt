//
// Created by szkaradd on 22.11.2021.
//

#ifndef _TREASURE_H
#define _TREASURE_H
// Przykladowe wywolanie
// Treasure<int, false> t1(5);        Treasure<int, false> t2(6);
// Treasure<ValueType, IsTrapped>
// ValueType - całkowitoliczbowy, IsTrapped - logiczny

#include <type_traits>
using namespace std;
using strength_t = unsigned int;

template<typename T,  bool IsTrapped>
class Treasure {
    T value;
public:
    constexpr Treasure(T arg) {
        static_assert(is_integral<T>::value, "Integral required.");
        value = arg;
    }
    static const bool isTrapped = IsTrapped;

    constexpr T evaluate() {
        return value;
    }

    constexpr T getLoot() {
        T temp = value;
        value = 0;
        return temp;
    }

};


template<typename T>
using SafeTreasure = Treasure<T, false>;


template<typename T>
using TrappedTreasure = Treasure<T, true>;


#endif //_TREASURE_H


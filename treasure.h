//
// Created by szkaradd on 22.11.2021.
//

#ifndef _TREASURE_H
#define _TREASURE_H
// Przykladowe wywolanie
// Treasure<int, false> t1(5);        Treasure<int, false> t2(6);
// Treasure<ValueType, IsTrapped>
// ValueType - całkowitoliczbowy, IsTrapped - logiczny


using strength_t = uint32_t;



//template<template<typename T1> requires Integral<T1> typename T>
// tu na pewno trzeba dodać odpowiednie constexpr itd, inline itd, ale teraz juz nie ogarniam
template<typename T,  bool trap> // ale fikoł ja pierdole, bedzie sie psulo jak przekazemy int zamiast bool, potem pomysle
//requires true<IsTrapped>
class Treasure {
    T value;
public:
    constexpr Treasure(T arg) {
        static_assert(std::is_integral<T>::value, "Integral required.");
        value = arg;
    }
    static constexpr bool IsTrapped = trap;

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
class SafeTreasure {
    T value;
public:
    constexpr SafeTreasure(T arg) {
        static_assert(std::is_integral<T>::value, "Integral required.");
        value = arg;
    }
    constexpr static bool IsTrapped = false;

    constexpr T evaluate() {
        return value;
    }

    constexpr T getLoot() {
        T temp = value;
        value = 0;
        return temp;
    }

};



#endif //_TREASURE_H

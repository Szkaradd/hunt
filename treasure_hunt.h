#ifndef _TREASURE_HUNT_H
#define _TREASURE_HUNT_H

#include "treasure.h"
#include "member.h"
#include <concepts>
#include <utility>

template <typename T>
// To jest jakieś dziwne nie do końca wiem czy jest ok...
concept MemberType = requires (T m) {
    typename T::strength_t;

    {[] () constexpr { return T::isArmed; }() } -> std::convertible_to<bool>;

    {m.pay()} -> std::integral;

    m.loot(std::declval<Treasure<decltype(m.pay()), true>>());
    m.loot(std::declval<Treasure<decltype(m.pay()), false>>());
};

template <typename T>
concept EncounterSide = TreasureType<T> || MemberType<T>;

#endif //_TREASURE_HUNT_H

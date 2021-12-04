#ifndef _TREASURE_H
#define _TREASURE_H
// Przykladowe wywolanie
// Treasure<int, false> t1(5);        Treasure<int, false> t2(6);
// Treasure<ValueType, IsTrapped>
// ValueType - całkowitoliczbowy, IsTrapped - logiczny
#include <concepts>
#include <type_traits>

using strength_t = unsigned int;

template<typename ValueType>
concept Integral = std::integral<ValueType>;

template<typename ValueType, bool IsTrapped>
requires Integral<ValueType>
class Treasure {
    ValueType value;
public:
    constexpr explicit Treasure(ValueType arg) {
        static_assert(std::is_integral<ValueType>::value, "Integral required.");
        value = arg;
    }
    static const bool isTrapped = IsTrapped;

    constexpr ValueType evaluate() {
        return value;
    }

    constexpr ValueType getLoot() {
        ValueType temp = value;
        value = 0;
        return temp;
    }

};

template<typename ValueType>
using SafeTreasure = Treasure<ValueType, false>;

template<typename ValueType>
using TrappedTreasure = Treasure<ValueType, true>;

#endif //_TREASURE_H

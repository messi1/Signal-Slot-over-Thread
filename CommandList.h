#ifndef COMMANDLIST_H
#define COMMANDLIST_H

enum class ParamCommand
{
    BLA,
    GUGUS,
    FIFI
};

#include <type_traits>

template <typename E>
constexpr auto to_underlying(E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

#endif // COMMANDLIST_H

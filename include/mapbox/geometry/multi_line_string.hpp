#pragma once

// mapbox
#include <mapbox/geometry/line_string.hpp>
// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct multi_line_string : Cont<line_string<T>>
{
    using coordinate_type = T;
    using line_string_type = line_string<T>;
    using container_type = Cont<line_string_type>;

    multi_line_string() = default;
    multi_line_string(std::initializer_list<line_string_type> && args)
      : container_type(std::forward<std::initializer_list<line_string_type>>(args)) {};

    using size_type = typename container_type::size_type;
};

} // namespace geometry
} // namespace mapbox

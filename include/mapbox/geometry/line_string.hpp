#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>
// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct line_string : Cont<point<T> >
{
    using coordinate_type = T;
    using point_type = point<T>;
    using container_type = Cont<point_type>;
    using size_type = typename container_type::size_type;

    line_string() = default;
    line_string(line_string const&) = default;
    line_string(line_string &&) = default;
    line_string(std::initializer_list<point_type> args)
      : container_type(args) {}
    explicit line_string(size_type n): container_type(n) {}
};

} // namespace geometry
} // namespace mapbox

#pragma once

// mapbox
#include <mapbox/geometry/polygon.hpp>
// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct multi_polygon : Cont<polygon<T>>
{
    using coordinate_type = T;
    using polygon_type = polygon<T>;
    using container_type = Cont<polygon_type>;
    using size_type = typename container_type::size_type;

    multi_polygon() = default;
    multi_polygon(multi_polygon const&) = default;
    multi_polygon(multi_polygon &&) = default;
    multi_polygon(std::initializer_list<polygon_type> args)
      : container_type(args) {}
    explicit multi_polygon(size_type n) : container_type(n) {}
};

} // namespace geometry
} // namespace mapbox

#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>
// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct multi_point : Cont<point<T>>
{
    using coordinate_type = T;
    using point_type = point<T>;
    using container_type = Cont<point_type>;
    using size_type = typename container_type::size_type;

    multi_point() = default;
    multi_point(multi_point const&) = default;
    multi_point(multi_point &&) = default;
    multi_point(std::initializer_list<point_type> args)
      : container_type(args) {}
    explicit multi_point(size_type n) : container_type(n) {}
};

} // namespace geometry
} // namespace mapbox

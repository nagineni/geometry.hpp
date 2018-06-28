#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>

// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct linear_ring : Cont<point<T>>
{
    using coordinate_type = T;
    using point_type = point<T>;
    using container_type = Cont<point_type>;
    using size_type = typename container_type::size_type;

    linear_ring() = default;
    linear_ring(linear_ring const&) = default;
    linear_ring(linear_ring &&) = default;
    linear_ring(std::initializer_list<point_type> args)
      : container_type(args) {};
};

template <typename T, template <typename...> class Cont = std::vector>
struct polygon : Cont<linear_ring<T>>
{
    using coordinate_type = T;
    using linear_ring_type = linear_ring<T>;
    using container_type = Cont<linear_ring_type>;
    using size_type = typename container_type::size_type;

    polygon() = default;
    polygon(polygon const&) = default;
    polygon(polygon &&) = default;
    polygon(std::initializer_list<linear_ring_type> args)
      : container_type(args) {};
};

} // namespace geometry
} // namespace mapbox

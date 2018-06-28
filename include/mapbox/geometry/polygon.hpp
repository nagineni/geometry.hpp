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

    linear_ring() = default;
    linear_ring(std::initializer_list<point_type> && args)
      : container_type(std::forward<std::initializer_list<point_type>>(args)) {};

    using size_type = typename container_type::size_type;
};

template <typename T, template <typename...> class Cont = std::vector>
struct polygon : Cont<linear_ring<T>>
{
    using coordinate_type = T;
    using linear_ring_type = linear_ring<T>;
    using container_type = Cont<linear_ring_type>;

    polygon() = default;
    polygon(std::initializer_list<linear_ring_type> && args)
      : container_type(std::forward<std::initializer_list<linear_ring_type>>(args)) {};

    using size_type = typename container_type::size_type;
};

} // namespace geometry
} // namespace mapbox

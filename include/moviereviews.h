//
// Created by aknight on 7/25/18.
//

#ifndef NEARESTNEIGHBOR_NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_NEARESTNEIGHBOR_H

#include <cstddef>
#include <cstdint>

namespace edu { namespace vcccd { namespace vc { namespace csv13 {
    static constexpr size_t NUMBER_MOVIES = 6;
    static constexpr size_t MAX_REVIEWS = 1000;

    void predictEmptyReviews(uint8_t reviews[][NUMBER_MOVIES], uint8_t userReviews[], size_t reviewCount);

}}}}

#endif //NEARESTNEIGHBOR_NEARESTNEIGHBOR_H

//
// Created by aknight on 7/25/18.
//

#include <cmath>
#include "moviereviews.h"

namespace edu { namespace vcccd { namespace vc { namespace csv13 {
    namespace {
        double _computeDistance(const uint8_t *review1, const uint8_t *review2) {
            double distance = 0.0;

            for (size_t i = 0; i < NUMBER_MOVIES; i++) {
                if (review1[i] != 0 && review2[i] != 0) {
                    double variance = review1[i] - review2[i];
                    distance += variance * variance;
                }
            }

            return sqrt(distance);
        }
    }

    void predictEmptyReviews(uint8_t reviews[][NUMBER_MOVIES], uint8_t userReviews[], size_t reviewCount) {
        if (reviews == nullptr || userReviews == nullptr) return;
        double minDistance = MAXFLOAT;
        size_t minIndexes[MAX_REVIEWS];
        size_t minIndexCount = 0;

        for (size_t i = 0; i < MAX_REVIEWS && i < reviewCount; i++) {
            double distance = _computeDistance(userReviews, reviews[i]);
            if (minDistance > distance) {
                minDistance = distance;
                minIndexCount = 0;
                minIndexes[minIndexCount++] = i;
            } else if (minDistance == distance) {
                minIndexes[minIndexCount++] = i;
            }
        }

        for  (size_t j= 0; j < NUMBER_MOVIES; j++) {
            if (userReviews[j] == 0) {
                double sum = 0.0;
                for (size_t i = 0; i < minIndexCount; i++) {
                    sum += reviews[minIndexes[i]][j];
                }
                userReviews[j] = static_cast<uint8_t >(round(sum / minIndexCount));
            }
        }
    }

}}}}

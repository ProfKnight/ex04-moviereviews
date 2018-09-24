#include <iostream>
#include <fstream>

#include "moviereviews.h"

using edu::vcccd::vc::csv13::predictEmptyReviews;
using edu::vcccd::vc::csv13::MAX_REVIEWS;
using edu::vcccd::vc::csv13::NUMBER_MOVIES;

int main() {
    std::ifstream in("../reviews.txt");

    uint8_t reviews[MAX_REVIEWS][NUMBER_MOVIES];
    size_t count = 0;
    for (; !in.eof(); count++) {
        for (size_t j = 0; j < NUMBER_MOVIES; j++) {
            uint32_t value;
            in >> value;
            reviews[count][j] = static_cast<uint8_t >(value);
        }
    }

    uint8_t userReviews[] = {0, 1, 0, 2, 0, 3};
    std::cout << "Actual reviews: {";
    for (uint8_t review: userReviews) {
        std::cout << " " << (uint32_t)review;
    }
    std::cout << " }" << std::endl;

    predictEmptyReviews(reviews, userReviews, MAX_REVIEWS);
    std::cout << "Predicted reviews: {";
    for (uint8_t review: userReviews) {
        std::cout << " " << (uint32_t)review;
    }
    std::cout << " }" << std::endl;

    return 0;

}
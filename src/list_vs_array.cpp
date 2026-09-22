#include <cstddef>  // size_t
#include <cstdint>  // uint64_t
#include <iostream> // std::cout
#include <list>     // std::list
#include <random>   // std::mt19937_64
#include <vector>   // std::vector

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // Seed your PRNG with 0 before starting to fill each container
    std::mt19937_64 rng(0); // start with seed 0

    // Create the list of uint64
    std::list<uint64_t> list;

    // Create a timer and start it
    Timer timer;
    timer.restart();

    for (size_t i = 0; i < SIZE; ++i) {
        list.push_back(rng());
    }
    // Get the elasped time and stop the timer
    uint64_t listInsertTime = timer.click<Timer::Micros>();
    std::cout<<"List insertion: " << listInsertTime << " microseconds\n";

    //Create a vector
    std::vector<uint64_t> vector;
    rng.seed(0); //re-seed

    // Restart the timer
    timer.restart();

    for (size_t i = 0; i < SIZE; ++i) {
        vector.push_back(rng());
    }
    // Get the elasped time and stop the timer
    uint64_t vectorInsertTime = timer.click<Timer::Micros>();
    std::cout<<"Vector insertion: " << vectorInsertTime << " microseconds\n";

    // Create a vector with reserve
    std::vector<uint64_t> reservedVector;
    reservedVector.reserve(SIZE);
    rng.seed(0); //re-seed

    // Restart the timer
    timer.restart();

    for (size_t i = 0; i < SIZE; ++i) {
        reservedVector.push_back(rng());
    }
    // Get the elasped time and stop the timer
    uint64_t reservedVectorInsertTime = timer.click<Timer::Micros>();
    std::cout<<"Vector with reserve insertion: " << reservedVectorInsertTime << " microseconds\n";

    uint64_t listSum = 0;
    timer.restart();

    for (uint64_t value : list) {
        listSum +=value;
    }
    // Get the elasped time and stop the timer
    uint64_t listSumTime = timer.click<Timer::Micros>();
    std::cout<<"ListSum: " << listSum << "\n";
    std::cout<<"ListSum Time: " << listSumTime << " microseconds\n";

    uint64_t vectorSum = 0;
    timer.restart();

    for (uint64_t value : vector) {
        vectorSum +=value;
    }
    // Get the elasped time and stop the timer
    uint64_t vectorSumTime = timer.click<Timer::Micros>();
    std::cout<<"vectorSum: " << vectorSum << "\n";
    std::cout<<"vectorSum Time: " << vectorSumTime << " microseconds\n";

    // test here...
    return 0;
}

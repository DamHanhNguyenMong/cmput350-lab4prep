#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale>=1); //Check if scale is larger than 1

    uint64_t result = 0;

    //Loop through each 64 bits
    for (size_t i = 0; i<64; ++i) {
        if (input & (1ULL << i)){ //mask to check if bit at position i is equal to 1
            uint64_t newPosition = static_cast<uint64_t>(i) * scale; //new position will be at i*scale
            if (newPosition < 64) { //If the expansion causes the result to be larger than 64 bits, we truncate the leftmost (most significant) bits.
                result |= (1ULL << newPosition); // puts a 1 at that position
            }
        } 
        
    }
    return result;
    
}

int main() {
    // test here...
    assert(expand(0b0101ull, 2) == 0b00010001ull);
    assert(expand(0b10101010ull, 1) == 0b10101010ull);
    assert(expand(0, 5) == 0);

    return 0;
}

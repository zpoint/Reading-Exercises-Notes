#include <iostream>

/*
 * a. List, all insert perform in O(n), vector or queue, u need to sort it after each insertion, fastest comparsion sort perform in O(nlog(n)) times. Slower than O(n)
 *
 * b. Queue is O(n), support sequential access though
 * List, O(1) in each insertion, O(1 + 1) in deletion, O(n), vector should malloc memory in each several push_back operations.
 * If the new malloced memory is different from the origin memory, origin data need to be copied to new memory location.
 * The deletion of vector will cost entire vector to be copied to new memory locations.
 * Both malloc O(n) memory, but the copy operation in vector in heavior than list.
 *
 * c. Deque ===> Don't know how C++ library implement it yet, I will see
 */

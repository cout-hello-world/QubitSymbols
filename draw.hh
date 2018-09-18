#ifndef DRAW_HH
#define DRAW_HH
#include <unordered_set>
#include <cstdint>
#include <ostream>
void draw(std::ostream &out, const std::unordered_set<std::uint16_t> &states);
#endif

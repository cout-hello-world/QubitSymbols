#ifndef PAIR_HH
#define PAIR_HH
#include <cstdint>
enum pair : std::uint16_t {
	AB = (1 << 0),
	AC = (1 << 1),
	AD = (1 << 2),
	AE = (1 << 3),
	AF = (1 << 4),
	BC = (1 << 5),
	BD = (1 << 6),
	BE = (1 << 7),
	BF = (1 << 8),
	CD = (1 << 9),
	CE = (1 << 10),
	CF = (1 << 11),
	DE = (1 << 12),
	DF = (1 << 13),
	EF = (1 << 14)
};
#endif

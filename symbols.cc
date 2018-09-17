#include <cstdint>
#include <unordered_set>
#include <iostream>
#include <string>



namespace {
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
bool has_A(std::uint16_t st) {
	return st & AB || st & AC || st & AD || st & AE || st & AF;
}
bool has_B(std::uint16_t st) {
	return st & AB || st & BC || st & BD || st & BE || st & BF;
}
bool has_C(std::uint16_t st) {
	return st & AC || st & BC || st & CD || st & CE || st & CF;
}
bool has_E(std::uint16_t st) {
	return st & AE || st & BE || st & CE || st & DE || st & EF;
}

void print_state(std::uint16_t state) {
	std::string p = "{";
	if (state & AB) {
		p += "{A,B},";
	}
	if (state & AC) {
		p += "{A,C},";
	}
	if (state & AD) {
		p += "{A,D},";
	}
	if (state & AE) {
		p += "{A,E},";
	}
	if (state & AF) {
		p += "{A,F}";
	}
	if (state & BC) {
		p += "{B,C},";
	}
	if (state & BD) {
		p += "{B,D},";
	}
	if (state & BE) {
		p += "{B,E},";
	}
	if (state & BF) {
		p += "{B,F},";
	}
	if (state & CD) {
		p += "{C,D},";
	}
	if (state & CE) {
		p += "{C,E},";
	}
	if (state & CF) {
		p += "{C,F},";
	}
	if (state & DE) {
		p += "{D,E},";
	}
	if (state & DF) {
		p += "{D,F},";
	}
	if (state & EF) {
		p += "{E,F},";
	}
	p[p.size() - 1] = '}';
	std::cout << p << '\n';
}

// A   B
//
// C   D
//
// E   F

std::uint16_t remove_overlines(std::uint16_t st) {
	if (st & AE) {
		st &= ~AE;
		st |= AC;
		st |= CE;
	}
	if (st & BF) {
		st &= ~BF;
		st |= BD;
		st |= DF;
	}
	return st;
}

std::uint16_t move_up(std::uint16_t st) {
	if (!has_A(st) && !has_B(st)) {
		std::uint16_t result = 0;
		if (st & CD) {
			result |= AB;
		}
		if (st & CE) {
			result |= AC;
		}
		if (st & CF) {
			result |= AD;
		}
		if (st & DE) {
			result |= BC;
		}
		if (st & DF) {
			result |= BD;
		}
		if (st & EF) {
			result |= CD;
		}
		return move_up(result);
	}
	return st;
}

std::uint16_t move_left(std::uint16_t st) {
	if (!has_A(st) && !has_C(st) && !has_E(st)) {
		std::uint16_t result = 0;
		if (st & BD) {
			result |= AC;
		}
		if (st & BF) {
			result |= AE;
		}
		if (st & DF) {
			result |= CE;
		}
		return result;
	}
	return st;
}


std::uint16_t normalize(std::uint16_t st) {
	return remove_overlines(move_left(move_up(st)));
}

}

int main()
{
	std::unordered_set<std::uint16_t> states;
	for (std::uint16_t state = 1; state != (1 << 15); ++state) { // Exclude 0
		states.insert(normalize(state));
	}

	for (const auto s : states) {
		print_state(s);
	}
}

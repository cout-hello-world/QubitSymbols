#include "draw.hh"

#include <ostream>
#include <unordered_set>
#include <string>

#include "pair.hh"

namespace {
void print_state(std::ostream &out, std::uint16_t state) {
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
		p += "{A,F},";
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
	out << p << '\n';
}
}

void draw(std::ostream &out, const std::unordered_set<std::uint16_t> &states)
{
	for (auto state : states) {
		print_state(out, state);
	}
}

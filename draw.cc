#include "draw.hh"

#include <ostream>
#include <unordered_set>
#include <string>

#include "pair.hh"

// A   B
//
// C   D
//
// E   F

namespace {
constexpr auto A = "(0,2)";
constexpr auto B = "(1,2)";
constexpr auto C = "(0,1)";
constexpr auto D = "(1,1)";
constexpr auto E = "(0,0)";
constexpr auto F = "(1,0)";

constexpr auto header = "\\documentclass[letterpaper]{article}\n"
"\\usepackage{tikz}\n\\usepackage[margin=1in]{geometry}\n\\begin{document}\n"
"\\noindent\n";
constexpr auto footer = "\\end{document}\n";

std::string drawstr(const std::string &begin, const std::string &end) {
	return "\\draw " + begin + " -- " + end + ";\n";
}

void print_state(std::ostream &out, std::uint16_t state) {
	std::string p = "\\begin{tikzpicture}\n";
	if (state & AB) {
		p += drawstr(A, B);
	}
	if (state & AC) {
		p += drawstr(A, C);
	}
	if (state & AD) {
		p += drawstr(A, D);
	}
	if (state & AE) {
		p += drawstr(A, E);
	}
	if (state & AF) {
		p += drawstr(A, F);
	}
	if (state & BC) {
		p += drawstr(B, C);
	}
	if (state & BD) {
		p += drawstr(B, D);
	}
	if (state & BE) {
		p += drawstr(B, E);
	}
	if (state & BF) {
		p += drawstr(B, F);
	}
	if (state & CD) {
		p += drawstr(C, D);
	}
	if (state & CE) {
		p += drawstr(C, E);
	}
	if (state & CF) {
		p += drawstr(C, F);
	}
	if (state & DE) {
		p += drawstr(D, E);
	}
	if (state & DF) {
		p += drawstr(D, F);
	}
	if (state & EF) {
		p += drawstr(E, F);
	}
	p += "\\end{tikzpicture}\n";
	out << p;
}
}

void draw(std::ostream &out, const std::unordered_set<std::uint16_t> &states)
{
	out << header;
	for (auto state : states) {
		print_state(out, state);
	}
	out << footer;
}

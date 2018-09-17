CXXFLAGS = -std=c++14 -Wall -Wextra -march=native -O3
CPPFLAGS = -DNDEBUG

symbols: symbols.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) symbols

CXXFLAGS = -std=c++14 -Wall -Wextra -flto -march=native -O3
CPPFLAGS = -DNDEBUG

symbols: symbols.o draw.o
	$(CXX) $(CXXFLAGS) -o $@ $^

symbols.o: symbols.cc draw.hh pair.hh
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

draw.o: draw.cc draw.hh pair.hh
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	$(RM) symbols symbols.o draw.o

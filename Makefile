CXXFLAGS = -std=c++14 -Wall -Wextra -flto -march=native -O3
CPPFLAGS = -DNDEBUG

symbols: symbols.o draw.o
	$(CXX) $(CXXFLAGS) -o $@ $^

symbols.o: symbols.cc draw.hh pair.hh
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

draw.o: draw.cc draw.hh pair.hh
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

symbols.pdf: symbols.tex
	pdflatex $<

symbols.tex: symbols
	./$< > $@

.PHONY: clean
clean:
	git clean -fxd

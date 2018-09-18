# QubitSymbols
This code is to compute and create a PDF for all symbols that can be formed
from the following arrangement of vertices:
```
A    B

C    D

E    F
```
The symbols in the output are unique up to translation in the plane.

To compile the program, run
```
make symbols
```
The above requires a `gcc`-compatible C++14 compiler.

To also create the PDF output, run
```
make symbols.pdf
```
The above further requires a LaTeX installation with `tikz`.
It takes about 2 minutes, 30 seconds on my machine.

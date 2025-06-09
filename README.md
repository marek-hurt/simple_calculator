# simple_calculator

Zkusebni projekt na osahani unit testingu v C pomoci Ceedling. Pro spusteni je potreba Perl, Ceedling, mingw64, gcov, gcovr, doxygen...

odkazy:

https://gcovr.com/en/8.3/index.html

https://github.com/ThrowTheSwitch/Ceedling/blob/master/docs/CeedlingPacket.md

https://www.doxygen.nl/index.html

Dulezite prikazy:

doxygen -g

doxygen Doxyfile

ceedling test:all

ceedling gcov:all report:gcov

gcovr -r . --html --html-details -o coverage.html





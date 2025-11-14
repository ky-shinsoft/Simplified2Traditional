.PHONY: all clean run install uninstall

CXX = g++-15
CXXFLAGS = -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -lopencc -Wall -Wextra -O2

zhconvert: main.cpp
	$(CXX) $(CXXFLAGS) -o zhconvert main.cpp

clean:
	rm -f main

install:
	cp main /usr/local/bin/zhconvert

uninstall:
	rm -f /usr/local/bin/zhconvert

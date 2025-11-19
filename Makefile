.PHONY: all clean run install uninstall

CXX = clang++
CXXFLAGS = -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -lopencc -Wall -Wextra -O2

zhconvert: main.cpp
	$(CXX) $(CXXFLAGS) -o zhconvert main.cpp

clean:
	rm -f zhconvert

install: zhconvert
	cp zhconvert /usr/local/bin/zhconvert

uninstall:
	rm -f /usr/local/bin/zhconvert

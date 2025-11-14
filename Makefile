.PHONY: all clean run install uninstall

CXX = g++-15
CXXFLAGS = -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -lopencc -Wall -Wextra -O2

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp

clean:
	rm -f main



CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

TARGET := Main
SRC := Main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean
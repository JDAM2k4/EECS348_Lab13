# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++17
# Target executable
TARGET = main
# Source files
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

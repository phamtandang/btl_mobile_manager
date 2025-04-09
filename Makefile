CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
SRC_DIR = src
BUILD_DIR = build
TARGET = supermarket

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

all: directory $(TARGET)

directory:
	mkdir -p $(BUILD_DIR)
	mkdir -p data

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run directory
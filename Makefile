# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
FPNG_CXXFLAGS = $(CXXFLAGS) -march=native -mpclmul

# Directories
SRC_DIR = src
FPNG_DIR = fpng
BUILD_DIR = build

# Source files
SRC_FILES = $(SRC_DIR)/bitmap.cpp $(SRC_DIR)/dither.cpp $(SRC_DIR)/main.cpp $(FPNG_DIR)/fpng.cpp

# Object files
OBJ_FILES = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRC_FILES)))

# Output executable
TARGET = main

# Default target
all: $(BUILD_DIR) $(TARGET)

# Build target
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES)

# Build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(FPNG_DIR)/%.cpp
	$(CXX) $(FPNG_CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
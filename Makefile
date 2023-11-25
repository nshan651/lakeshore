CXX := clang++

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

CXXFLAGS := -std=c++20 -Wall -g
CPPFLAGS := -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/spdlog -I$(INCLUDE_DIR)/CLI
LDFLAGS := -lspdlog

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean

# Create the target directory if it doesn't exist
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(CPPFLAGS)

# Final build step
$(BUILD_DIR)/lakeshore: $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)

all: $(BUILD_DIR)/lakeshore

# Run executable
run:
	./$(BUILD_DIR)/lakeshore

# Remove build artifacts
clean:
	rm -rf $(BUILD_DIR)




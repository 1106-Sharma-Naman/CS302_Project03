# ============================================================
# CS302 Project 3 Makefile
# Music Library (Binary Search Tree)
# ============================================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

TARGET = project3

SRCS = $(SRC_DIR)/driver.cpp \
       $(SRC_DIR)/Song.cpp \
       $(SRC_DIR)/MusicLibrary.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

EXECUTABLE = $(BUILD_DIR)/$(TARGET)

.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE)
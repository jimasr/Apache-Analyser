CXX = g++
CXXFLAGS = -std=c++11 -Wall -ansi -pedantic #-DMAP

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

TEST_FILE = $(TEST_DIR)/mktest.sh
MAIN_FILE = $(SRC_DIR)/Main.cpp

SRCS = \
	$(SRC_DIR)/GraphWriter.cpp \
	$(SRC_DIR)/LogHistory.cpp \
	$(MAIN_FILE) \
	$(SRC_DIR)/LogReader.cpp 

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/analog

.PHONY: clean test 

all: directories $(TARGET)

directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@rm -rf $(wildcard *.dot)

test: all
	$(TEST_FILE)




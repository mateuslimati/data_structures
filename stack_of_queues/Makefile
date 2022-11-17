# Makefile

# Project Name
PROJ_NAME := stack_of_queues

# Compiler and linker
CXX := g++

# SOURCE folder
SRC_DIR := src

# MODULES folder
MOD_DIR := modules

# Build folder
BUILD_DIR := build

# Modules files C++
MODSXX := $(wildcard $(MOD_DIR)/*.cpp)

# Source files C++
SRCSXX := $(wildcard $(SRC_DIR)/*.cpp)


# Object files
OBJS := $(patsubst %.cpp,%.o, $(MODSXX))
OBJS += $(patsubst %.cpp,%.o, $(SRCSXX))

# Flags for compiler
CC_FLAGS := -c \
		    -o \

# Project dependences
PROJ_DEP := -std=c++20 \
			-fmodules-ts \
			-lpthread \

all: folders $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	@echo "Linking $^ ..."
	$(CXX) $^ -o $(BUILD_DIR)/$@ $(PROJ_DEP)
	@echo "\033[92mBinary are ready in $(BUILD_DIR)/$@!\033[0m"

%.o: %.cpp
	@echo "Compiling $@ ..."
	$(CXX) $(PROJ_DEP) -O0 -g -c $^ -o $@ -lgtest -lgtest_main
	@echo "\033[94m$@ Compiled!\033[0m"

folders:
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)/* $(SRC_DIR)/*.o $(MOD_DIR)/*.o $(BUILD_DIR) *.deb

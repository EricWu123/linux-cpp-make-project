TOP_DIR ?= $(shell git rev-parse --show-toplevel)
BUILD_DIR ?= $(TOP_DIR)/build

SOURCE_DIR := $(shell pwd)
OBJ_DIR := $(SOURCE_DIR)

# 目标文件的名称
TARGET := $(BUILD_DIR)/$(TARGET)

# 查找所有源文件
CSrcs := $(foreach dir, $(SRC_DIRS), $(shell find $(dir) -name "*.c"))
CppSrcs := $(foreach dir, $(SRC_DIRS), $(shell find $(dir) -name "*.cpp"))

# 保持目录结构的对象文件路径
Objects := $(patsubst %.c, $(OBJ_DIR)/%.o, $(CSrcs))
Objects += $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(CppSrcs))

# 保持目录结构的依赖文件路径
ObjectsDeps := $(patsubst %.c, $(OBJ_DIR)/%.d, $(CSrcs))
ObjectsDeps += $(patsubst %.cpp, $(OBJ_DIR)/%.d, $(CppSrcs))

# 编译器和编译选项
CC := gcc
CXX := g++
CPPFLAGS += -I$(INCLUDE_DIR) $(foreach dir, $(SRC_DIRS), -I$(dir)) -MMD -MP -Wall -Werror -Wextra -O2 -fPIC
CFLAGS += -I$(INCLUDE_DIR) $(foreach dir, $(SRC_DIRS), -I$(dir)) -MMD -MP -Wall -Werror -Wextra -O2 -fPIC

# 链接选项
LDFLAGS += -lpthread -ldl -lrt -lm

.PHONY: all
all: $(TARGET) 

$(TARGET): $(Objects)
	@echo "Objects: "$(Objects)
	@echo "BUILD_DIR: "$(BUILD_DIR)
	@echo "TARGET: "$(TARGET)

	@mkdir -p $(dir $@)
	$(CXX) $(Objects) -o $@ $(LDFLAGS)

# 包含依赖文件
-include $(ObjectsDeps)

# 生成对象文件和依赖文件
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR)
	-rm -f $(Objects) $(ObjectsDeps)

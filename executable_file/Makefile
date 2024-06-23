# Makefile

# 顶层目录
TOP_DIR := $(shell pwd)
# 目标文件的名称
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/.objects
EXEC_FILE := $(BUILD_DIR)/app
SHARED_LIB := $(BUILD_DIR)/libfoo.so

# 指定源文件所在目录
SRC_DIRS := ./src ./src/module_a ./src/module_b ./src/common ./src/libfoo ./src/libfoo/submodule_a
INCLUDE_DIR := ./include

# 查找所有源文件
CSrcs := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
CppSrcs := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))

# 保持目录结构的对象文件路径
Objects := $(patsubst %.c, $(OBJ_DIR)/%.o, $(CSrcs)) $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(CppSrcs))
# 从对象中过滤掉libfoo目录下的所有对象
ExecObjects := $(filter-out $(OBJ_DIR)/./src/libfoo/%, $(Objects))
# 从对象中过滤出libfoo目录下的所有对象
LibObjects := $(filter $(OBJ_DIR)/./src/libfoo/%, $(Objects))

# 保持目录结构的依赖文件路径
CDeps := $(patsubst %.c, $(OBJ_DIR)/%.d, $(CSrcs))
CppDeps := $(patsubst %.cpp, $(OBJ_DIR)/%.d, $(CppSrcs))

# 编译器和编译选项
CC := gcc
CXX := g++
CPPFLAGS := -I$(INCLUDE_DIR) $(foreach dir, $(SRC_DIRS), -I$(dir)) -MMD -MP -Wall -Wextra -O2 -fPIC
CFLAGS := -I$(INCLUDE_DIR) $(foreach dir, $(SRC_DIRS), -I$(dir)) -MMD -MP -Wall -Wextra -O2 -fPIC

# 链接选项
LDFLAGS := -lpthread -ldl -lrt -lm
EXEC_LDFLAGS := $(LDFLAGS) -Wl,-rpath=$(TOP_DIR)/build -L. -L$(TOP_DIR)/$(dir $(SHARED_LIB)) -l$(subst lib,,$(basename $(notdir $(SHARED_LIB))))

.PHONY: all
all: $(EXEC_FILE) $(SHARED_LIB)

$(EXEC_FILE): $(ExecObjects) $(SHARED_LIB)
	@echo $(ExecObjects)
	@mkdir -p $(dir $@)
	$(CXX) $(filter-out $(SHARED_LIB), $^) -o $@ $(EXEC_LDFLAGS) 

$(SHARED_LIB): $(LibObjects)
	@echo $(LibObjects)
	@mkdir -p $(dir $@)
	$(CXX) $^ -o $@ $(LDFLAGS) -shared

# 包含依赖文件
-include $(CDeps) $(CppDeps)

# 生成对象文件和依赖文件
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR)/*

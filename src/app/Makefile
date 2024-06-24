TARGET := app

TOP_DIR ?= $(shell git rev-parse --show-toplevel)
BUILD_DIR ?= $(TOP_DIR)/build

# 指定源文件所在目录
SRC_DIRS := . ../common
INCLUDE_DIR := ../../include

CPPFLAGS := 
CFLAGS := 

# 链接选项
LDFLAGS := -lfoo -L$(BUILD_DIR) -Wl,-rpath=$(BUILD_DIR)

include ../../Makefile.inc

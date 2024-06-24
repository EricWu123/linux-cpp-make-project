# 项目名称

这是一个 Makefile 模板项目，附带了一个示例 C/C++ 项目，包含多个子目录（如 `src`、`tests`）。该项目既可以生成可执行文件，也可以生成动态库，并包含单元测试。

## 项目结构

```
project/
├── Makefile
├── Makefile.inc
├── READMD.md
├── include
│   ├── common.h
│   ├── foo.h
│   ├── main.h
│   ├── module_a.h
│   ├── module_b.h
│   └── sub_module_a.h
├── src
│   ├── Makefile
│   ├── app
│   │   ├── Makefile
│   │   ├── main.cpp
│   │   ├── module_a
│   │   │   └── module_a.c
│   │   └── module_b
│   │       └── module_b.cpp
│   ├── common
│   │   └── common.c
│   └── libfoo
│       ├── Makefile
│       ├── foo.c
│       └── submodule_a
│           └── sub_module_a.c
└── tests
    ├── Makefile
    └── test.cpp
```

### 目录说明

- `include/`：公共头文件目录。
- `src/`：源代码目录
- `src/app`：源代码目录，生成可执行文件。
- `src/libfoo`：源代码目录，生成动态库。
- `src/common`：源代码目录，动态库和可执行文件的公共代码。
- `tests/`：单元测试目录，用于编译和运行测试代码。
- `build/`：编译过程中生成的中间文件（对象文件）目录。
- `Makefile`：顶层 Makefile，管理整个项目的构建。
- `Makefile.inc`：公共 Makefile 规则和变量定义文件。

## 使用说明

### 编译所有目标

在项目根目录下执行以下命令：

```sh
make
```

这将编译所有子目录中的目标，包括可执行文件和动态库。

### 编译特定目标

如果只需要编译某个子目录中的目标，可以进入该目录并执行 `make`：

```sh
cd src/app
make
```

或者直接在项目根目录下指定子目录：

```sh
make -C src/app
```

### 清理编译生成的文件

在项目根目录下执行以下命令：

```sh
make clean
```

这将清理所有子目录中编译生成的文件。

### 运行单元测试

在项目根目录下执行以下命令：

```sh
make test
```

这将在 `tests` 目录中编译并运行测试代码。

## 扩展和自定义

为了扩展和自定义项目的构建过程，可以在各子目录的 Makefile 中调整 `TARGET` 、`SRC_DIRS`、`INCLUDE_DIR`、`CPPFLAGS`、`CFLAGS` 和 `LDFLAGS` 变量。

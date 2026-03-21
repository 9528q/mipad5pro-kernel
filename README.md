# Android Kernel Modules Builder

使用 GitHub Actions 自动编译 Android 内核模块。

## 支持的模块

- `hello_driver` - Hello World 示例驱动

## 自动编译

每次推送代码到 `main` 分支时，GitHub Actions 会自动编译所有内核模块。

### 编译产物

编译完成后，`.ko` 文件会作为 Actions artifacts 保存，可以直接下载使用。

## 手动编译

### 前置要求

- ARM64 交叉编译工具链 (`aarch64-linux-gnu-gcc`)
- Clang/LLVM 编译器
- Linux Kernel 头文件

### 编译步骤

```bash
cd hello_driver
make clean
make
```

### 编译输出

编译后的内核模块文件: `hello_driver.ko`

## 安装到 Android 设备

```bash
# 推送模块到手机
adb push hello_driver.ko /data/local/tmp/

# 加载模块
adb shell insmod /data/local/tmp/hello_driver.ko

# 查看日志
adb shell dmesg | grep hello_driver

# 卸载模块
adb shell rmmod hello_driver
```

## 技术细节

- 目标架构: ARM64 (aarch64)
- 编译器: Clang + GCC
- 内核版本: 4.19.x

## License

GPL

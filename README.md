# 项目运行

1. [安装vcpkg](https://learn.microsoft.com/zh-cn/vcpkg/get_started/get-started?pivots=shell-powershell)
2. 添加 CMakeUserPresets.json
```json
  {
  "version": 2,
  "configurePresets": [
    {
      "name": "default",
      "inherits": "vcpkg",
      "environment": {
        "VCPKG_ROOT": "<path to vcpkg>"
      }
    }
  ]
}
```
3. 运行camke 配置
```bash 
cmake --preset=default
```

4. 运行项目
```bash
# 编译项目
cmake --build build
```
5. 运行项目
```bash
.\build\HelloWorld.exe
```
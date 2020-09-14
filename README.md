# GoldenPlains

An .obj file loader using Vulkan.

## Linux Setup (tested on Ubuntu)

#### Install VulkanSDK from LunarG
Download and install <a href="https://vulkan.lunarg.com" target="_blank">LunarG's Vulkan SDK</a>.

#### Install GLFW
Download and unzip the <a href="https://github.com/glfw/glfw" target="_blank">GLFW source code</a>. In the unzipped source directory, do:
```shell
$ cmake .
$ make
$ sudo cmake -P cmake_install.cmake
```

#### Install GLM
Download and unzip the <a href="https://glm.g-truc.net" target="_blank">GLM source code</a>. In the unzipped source directory, do:
```shell
$ cmake .
$ make
$ sudo cmake -P cmake_install.cmake
```

#### Install TinyObjLoader
Download and unzip the <a href="https://github.com/tinyobjloader/tinyobjloader" target="_blank">tinyobjloader source code</a>. In the unzipped source directory, do:
```shell
$ cmake .
$ make
$ sudo cmake -P cmake_install.cmake
```

#### Install STB
Download and unzip the <a href="https://github.com/nothings/stb" target="_blank">STB source code</a>. Copy the path to this source directory (containing stb_image.h).

#### Install GoldenPlains
Download and unzip GoldenPlains. In the unzipped source directory, do:

```shell
$ cmake -DSTB_IMAGE_DIR=/path/to/stb_image/directory .
$ make
$ sudo cmake -P cmake_install.cmake
```

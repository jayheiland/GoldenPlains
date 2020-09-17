# GoldenPlains

An .obj file loader using Vulkan.

## Setup - Linux (tested on Ubuntu)

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

## Sample programs - Linux (tested on Ubuntu)

#### Download example model and texture

Create a `models` directory and `textures` directory in the GoldenPlains source directory. These example programs will use this <a href="https://sketchfab.com/3d-models/viking-room-a49f1b8e4f5c4ecf9e1fe7d81915ad38" target="_blank">Viking Room</a> model by <a href="https://sketchfab.com/nigelgoh" target="_blank">nigelgoh</a>. Download the <a href="https://vulkan-tutorial.com/resources/viking_room.obj" target="_blank">model</a> and put it in GoldenPlains/models. Download the <a href="https://vulkan-tutorial.com/resources/viking_room.png" target="_blank">texture</a> and put it in GoldenPlains/textures.

#### Compile shaders

In `GoldenPlains/shaders`, create a "compile.sh" shell script using the following guide:

```text
[path to VulkanSDK]/VulkanSDK/[version number]/x86_64/bin/glslc shader.vert -o vert.spv
[path to VulkanSDK]/VulkanSDK/[version number]/x86_64/bin/glslc shader.frag -o frag.spv
```

In `GoldenPlains/shaders`, do:
```shell
$ chmod +x compile.sh
$ ./compile.sh
```

#### Sample - Single object instance

In `GoldenPlains`, do:
```shell
$ ./basic
```

This will load a single instance of the Viking Room. The camera and model positions are set within `GoldenPlains/samples/basic.cpp`. GoldenPlains does not have lighting enabled; this model has lighting baked into the texture.

#### Sample - Multiple object instances

This sample program can work as a "stress test". In `GoldenPlains`, do:
```shell
$ ./stress 100
```

This will load 1 instance of the Viking Room and then create 99 duplicates arrayed along the Y-axis. After 150 frames, half of these duplicates will be deleted. Due to how descriptors are managed within GoldenPlains, the maximum number of object instances is 3000.

VULKAN_SDK_PATH = /home/jay/Loft/VulkanSDK/1.2.135.0/x86_64

CXX = g++ -std=c++17
CFLAGS = -I/home/jay/Loft/stb-master -I/home/jay/Loft/tinyobjloader-master -I$(VULKAN_SDK_PATH)/include 
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan

VulkanTest: main.cpp graphics_layer.cpp vulkan_handler.cpp
	$(CXX) -o VulkanTest $^ $(CFLAGS) $(LDFLAGS)

#main.o: main.cpp
#	$(CXX) -o $@ -c $^ 

#graphics_layer.o: graphics_layer.cpp
#	$(CXX) -o $@ -c $^ 

#vulkan_handler.o: vulkan_handler.cpp
#	$(CXX) -o $@ -c $^

.PHONY: clean

#test: VulkanTest
#	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/vulkan/explicit_layer.d ./VulkanTest

clean:
	rm *.o 


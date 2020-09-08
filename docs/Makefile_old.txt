VULKAN_SDK_INCLUDE_PATH = /usr/include/vulkan
VULKAN_SDK_LIB_PATH = /usr/lib/x86_64-linux-gnu
VULKAN_SDK_VLD_LAYER_PATH = /usr/share/vulkan/explicit_layer.d

LIB = ./lib
INC = ./include
SRC = ./src
CXX = g++ -std=c++17
CFLAGS = -I/home/jay/Loft/stb-master -I/home/jay/Loft/tinyobjloader-master -I$(VULKAN_SDK_INCLUDE_PATH)
LDFLAGS = -L$(VULKAN_SDK_LIB_PATH) `pkg-config --static --libs glfw3` -lvulkan

lib: $(SRC)/golden_plains.cpp $(SRC)/vulkan_handler.cpp
	$(CXX) -c $(SRC)/vulkan_handler.cpp -fpic $(CFLAGS) $(LDFLAGS)
	$(CXX) -c $(SRC)/golden_plains.cpp -fpic $(CFLAGS)
	sudo g++ -shared -o /usr/local/lib/libgoldenplains.so *.o
	sudo ldconfig

lib_debug: $(SRC)/golden_plains.cpp $(SRC)/vulkan_handler.cpp
	$(CXX) -g -c $(SRC)/vulkan_handler.cpp -fpic $(CFLAGS) $(LDFLAGS)
	$(CXX) -g -c $(SRC)/golden_plains.cpp -fpic $(CFLAGS)
	sudo g++ -shared -o /usr/local/lib/libgoldenplains.so *.o
	sudo ldconfig

test: ./test/main.cpp
	$(CXX) -g -o gptest ./test/main.cpp $(CFLAGS) -I$(SRC) -lgoldenplains $(LDFLAGS)

run_test: gptest
	VK_LAYER_PATH=$(VULKAN_SDK_VLD_LAYER_PATH) ./gptest

debug_test: gptest
	VK_LAYER_PATH=$(VULKAN_SDK_VLD_LAYER_PATH) lldb gptest

no_lib:
	$(CXX) -c $(SRC)/vulkan_handler.cpp $(CFLAGS) $(LDFLAGS)
	$(CXX) -c $(SRC)/golden_plains.cpp $(CFLAGS)
	$(CXX) -o gptest ./test/main.cpp vulkan_handler.o golden_plains.o -I$(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o
	rm -f gptest

clean_all:
	rm -f $(LIB)/*.a
	rm -f *.o
	rm -f gptest

.PHONY: test run_test clean lib clean_all debug_test lib_debug
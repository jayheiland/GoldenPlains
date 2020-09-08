cmake_minimum_required(VERSION 3.10)
project(goldenplains)

# Vulkan
find_package(Vulkan REQUIRED)

# GLM
find_package(glm REQUIRED)
message(STATUS "Found GLM in ${glm_CONFIG}")

# GLFW
find_package(glfw3 3.3 REQUIRED)
message(STATUS "Found GLFW3 in ${glfw3_CONFIG}")

# STB_IMAGE
add_library(STB_IMAGE INTERFACE)
target_include_directories(STB_IMAGE INTERFACE /home/jay/Loft/stb-master/) 

# TINY_OBJ_LOADER
add_library(TINY_OBJ_LOADER INTERFACE)
target_include_directories(TINY_OBJ_LOADER INTERFACE /home/jay/Loft/tinyobjloader-master/) 

set(LIBS glfw ${glm_LIBRARIES} ${Vulkan_LIBRARIES} STB_IMAGE TINY_OBJ_LOADER)
set(INC src ${glfw3_INCLUDE_DIR} ${glm_INCLUDE_DIR} ${Vulkan_INCLUDE_DIR} /home/jay/Loft/stb-master/ /home/jay/Loft/tinyobjloader-master/ )

add_library(goldenplains SHARED src/vulkan_handler.cpp src/golden_plains.cpp)
set_property(TARGET goldenplains PROPERTY CXX_STANDARD 17)
target_include_directories(goldenplains PUBLIC ${INC}) 
target_link_libraries(goldenplains ${LIBS})
install(TARGETS goldenplains DESTINATION lib)
install(FILES src/golden_plains.h DESTINATION include)

add_executable(gptest test/main.cpp)
target_include_directories(gptest PUBLIC ${INC}) 
target_link_libraries(gptest goldenplains ${LIBS})
set_property(TARGET gptest PROPERTY CXX_STANDARD 17)
install(TARGETS gptest DESTINATION bin)
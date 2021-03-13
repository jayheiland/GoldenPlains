cmake_minimum_required(VERSION 3.10)
project(goldenplains)

# Vulkan
find_package(Vulkan REQUIRED)
message(STATUS "Found Vulkan libraries in ${Vulkan_LIBRARIES}")

# GLM
find_package(glm REQUIRED)
message(STATUS "Found GLM in ${glm_CONFIG}")

# GLFW
find_package(glfw3 3.3 REQUIRED)
message(STATUS "Found GLFW3 in ${glfw3_CONFIG}")

# STB_IMAGE
set(STB_IMAGE_DIR "ERROR: DIRECTORY NOT FOUND" CACHE STRING "Path to required header-only library stb_image.h")
message(STATUS "The given directory of stb_image is ${STB_IMAGE_DIR}")

# TINY_OBJ_LOADER
find_package(tinyobjloader REQUIRED)
message(STATUS "Found TinyObjLoader in ${tinyobjloader_CONFIG}")

set(LIBS glfw ${glm_LIBRARIES} ${Vulkan_LIBRARIES})
set(INC src ${glfw3_INCLUDE_DIR} ${glm_INCLUDE_DIR} ${Vulkan_INCLUDE_DIR} ${STB_IMAGE_DIR} ${tinyobjloader_INCLUDE_DIR})

add_library(goldenplains SHARED src/vulkan_handler.cpp src/golden_plains.cpp)
set_property(TARGET goldenplains PROPERTY CXX_STANDARD 17)
target_include_directories(goldenplains PUBLIC ${INC}) 
target_link_libraries(goldenplains ${LIBS})
install(TARGETS goldenplains DESTINATION lib)
install(FILES src/golden_plains.h src/vulkan_handler.h ${STB_IMAGE_DIR}/stb_image.h DESTINATION include)

add_executable(basic samples/basic.cpp)
target_link_libraries(basic goldenplains)
set_property(TARGET basic PROPERTY CXX_STANDARD 17)

add_executable(stress samples/stress.cpp)
target_link_libraries(stress goldenplains)
set_property(TARGET stress PROPERTY CXX_STANDARD 17)

add_executable(text samples/text.cpp)
target_link_libraries(text goldenplains)
set_property(TARGET text PROPERTY CXX_STANDARD 17)

add_executable(button samples/button.cpp)
target_link_libraries(button goldenplains)
set_property(TARGET button PROPERTY CXX_STANDARD 17)

add_executable(bounding_box samples/bounding_box.cpp)
target_link_libraries(bounding_box goldenplains)
set_property(TARGET bounding_box PROPERTY CXX_STANDARD 17)

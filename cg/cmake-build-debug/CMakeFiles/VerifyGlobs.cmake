# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 4.0

# MY_SOURCE_FILES at CMakeLists.txt:26 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/cgbv_project/Visual_Computing/cg/src/*.cpp")
set(OLD_GLOB
  "C:/cgbv_project/Visual_Computing/cg/src/GameMainWindow.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/GameRenderer.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/InteractionHandler.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/LightSource.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/Material.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/Mesh.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/Model.cpp"
  "C:/cgbv_project/Visual_Computing/cg/src/ShaderProgram.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/cgbv_project/Visual_Computing/cg/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()

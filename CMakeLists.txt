cmake_minimum_required(VERSION 3.20)
project(File_Viwer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------
# Dependencies: FTXUI
# -------------------------
add_subdirectory(
        /Library/ProgramingDependencies/FTXUI
        ${CMAKE_BINARY_DIR}/_deps/ftxui-build
)

# -------------------------
# Your project library (add .cpp files here as you create them)
# -------------------------
add_library(file_viewer_lib
        src/File.cpp
        # Add your implementation files here:
        # src/FileViewerApp.cpp
        # src/DirectoryLister.cpp
)

target_include_directories(file_viewer_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

target_link_libraries(file_viewer_lib PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
)

# -------------------------
# Main executable
# -------------------------
add_executable(File_Viwer
        src/main.cpp
)

target_link_libraries(File_Viwer PRIVATE file_viewer_lib)

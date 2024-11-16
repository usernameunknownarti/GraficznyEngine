cmake_minimum_required(VERSION 3.28)
project(GraficznyEngine)

set(CMAKE_CXX_STANDARD 14)

include_directories(GraficznyEngine)
include_directories(SFML-2.6.1/examples/shader)
include_directories(SFML-2.6.1/include)
include_directories(SFML-2.6.1/include/SFML)
include_directories(SFML-2.6.1/include/SFML/Audio)
include_directories(SFML-2.6.1/include/SFML/Graphics)
include_directories(SFML-2.6.1/include/SFML/Network)
include_directories(SFML-2.6.1/include/SFML/System)
include_directories(SFML-2.6.1/include/SFML/Window)



add_executable(GraficznyEngine
    GraficznyEngine/Engine.cpp
    GraficznyEngine/Engine.h
    GraficznyEngine/LineSegment.h
    GraficznyEngine/main.cpp
    GraficznyEngine/Point2D.h
    GraficznyEngine/PrimitiveRenderer.cpp
    GraficznyEngine/PrimitiveRenderer.h
    GraficznyEngine/Source1.cpp
    GraficznyEngine/TextureManager.cpp
    GraficznyEngine/TextureManager.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories("C:/SFML-2.6.1/include")


target_link_libraries(GraficznyEngine sfml-system sfml-window sfml-graphics sfml-audio)





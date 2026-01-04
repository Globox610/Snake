cmake_minimum_required(VERSION 3.28)
project(SnakeProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main 
	"src/Game.cpp"
	
  "src/PlayState.cpp" "src/PlayState.cpp" "src/MenuState.cpp" "src/MenuItems.cpp" "src/CellTypes.hpp" "src/GridData.cpp"  "src/Food.cpp" "src/SnakeBody.cpp" "src/Direction.hpp" "src/AssetHolder.hpp")
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)

add_custom_target(run
	COMMAND main
	DEPENDS main
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

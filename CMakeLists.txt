cmake_minimum_required(VERSION 3.24)
project(SDiZO_Project_1)

# set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp)
add_executable(SDiZO_Project_1 main.cpp ListBidirectional.cpp ListBidirectional.h DynamicArray.cpp DynamicArray.h BinaryHeap.cpp BinaryHeap.h BinarySearchTree.cpp BinarySearchTree.h Testing/Tests.cpp Testing/Tests.h RandomDataGenerator/RandomNumberGenerator.cpp RandomDataGenerator/RandomNumberGenerator.h FileUtils/DataFileUtility.cpp FileUtils/DataFileUtility.h Flow/AppController.cpp Flow/AppController.h Flow/ActionResult.cpp Flow/ActionResult.h Flow/ConsoleView.cpp Flow/ConsoleView.h Time/Timer.cpp Time/Timer.h Testing/AutomaticTests.cpp Testing/AutomaticTests.h)

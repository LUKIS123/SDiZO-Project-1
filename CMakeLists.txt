cmake_minimum_required(VERSION 3.24)
project(SDiZO_Project_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDiZO_Project_1 main.cpp ListBidirectional.cpp ListBidirectional.h DynamicArray.cpp DynamicArray.h BinaryHeap.cpp BinaryHeap.h BinarySearchTree.cpp BinarySearchTree.h Testing/Tests.cpp Testing/Tests.h RandomDataGenerator/RandomNumberGenerator.cpp RandomDataGenerator/RandomNumberGenerator.h FileUtils/DataFileUtility.cpp FileUtils/DataFileUtility.h View/AppController.cpp View/AppController.h View/ActionResult.cpp View/ActionResult.h View/ConsoleView.cpp View/ConsoleView.h)

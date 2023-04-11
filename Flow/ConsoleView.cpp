//
// Created by lukas on 02.04.2023.
//

#include "iostream"
#include "ConsoleView.h"
#include "ActionResult.h"

ConsoleView::ConsoleView() = default;

ConsoleView::~ConsoleView() = default;

ActionResult::result ConsoleView::menu() {
    system("CLS");
    std::cout << "Menu: Choose from given options..." << std::endl;
    std::cout << "1 => Load test data file" << std::endl;
    std::cout << "2 => Dynamic Array" << std::endl;
    std::cout << "3 => List" << std::endl;
    std::cout << "4 => Heap" << std::endl;
    std::cout << "5 => BST Tree" << std::endl;
    std::cout << "6 => Generate random data buffer" << std::endl;
    std::cout << "7 => Save random data to file" << std::endl;
    std::cout << "8 => Automatic Tests" << std::endl;
    std::cout << "9 => Deploy Manual Tests" << std::endl;
    std::cout << "0 => Exit" << std::endl << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    switch (next) {
        case 1:
            return ActionResult::result::LOAD_DATA_FILE;
        case 2:
            return ActionResult::result::DYNAMIC_ARRAY;
        case 3:
            return ActionResult::result::LIST_BIDIRECTIONAL;
        case 4:
            return ActionResult::result::BINARY_HEAP;
        case 5:
            return ActionResult::result::BST_TREE;
        case 6:
            return ActionResult::result::GENERATE_RANDOM_DATA;
        case 7:
            return ActionResult::result::SAVE_RANDOM_DATA;
        case 8:
            return ActionResult::result::AUTOMATIC_TEST;
        case 9:
            return ActionResult::MANUAL_TESTS;
        case 0:
            return ActionResult::result::END;
        default:
            return ActionResult::result::MENU;
    }
}

ActionResult::automaticTestResult ConsoleView::testMenu() {
    system("CLS");
    std::cout << "AUTOMATIC TESTS: Automatically test series of operations..." << std::endl;
    std::cout << "Choose from given options..." << std::endl;
    std::cout << "1 => Generate Random Data" << std::endl;
    std::cout << "2 => Array Tests" << std::endl;
    std::cout << "3 => List Tests" << std::endl;
    std::cout << "4 => Heap Tests" << std::endl;
    std::cout << "5 => BST Tests" << std::endl;
    std::cout << "6 => Change number od tests" << std::endl;
    std::cout << "0 => Exit" << std::endl << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    switch (next) {
        case 1:
            return ActionResult::automaticTestResult::GENERATE_DATA_TEST;
        case 2:
            return ActionResult::automaticTestResult::DYNAMIC_ARRAY_TEST;
        case 3:
            return ActionResult::automaticTestResult::LIST_BIDIRECTIONAL_TEST;
        case 4:
            return ActionResult::automaticTestResult::BINARY_HEAP_TEST;
        case 5:
            return ActionResult::automaticTestResult::BST_TREE_TEST;
        case 6:
            return ActionResult::automaticTestResult::CHANGE_TEST_SERIES_NUMBER;
        case 0:
            return ActionResult::automaticTestResult::END_TEST;
        default:
            return ActionResult::automaticTestResult::MENU_TEST;
    }
}

ActionResult::arrayResult ConsoleView::arrayMenu() {
    system("CLS");
    std::cout << "Dynamic Array: Choose from given options..." << std::endl;
    std::cout << "1 => Load Array with test file data" << std::endl;
    std::cout << "2 => Display" << std::endl;
    std::cout << "3 => Push Front" << std::endl;
    std::cout << "4 => Push End" << std::endl;
    std::cout << "5 => Push On Index" << std::endl;
    std::cout << "6 => Pop Front" << std::endl;
    std::cout << "7 => Pop End" << std::endl;
    std::cout << "8 => Pop On Index" << std::endl;
    std::cout << "9 => Set On Index" << std::endl;
    std::cout << "10 => Find By Index" << std::endl;
    std::cout << "11 => Find Index Of Element" << std::endl;
    std::cout << "12 => Remove All" << std::endl;
    std::cout << "13 => Check Size" << std::endl;
    std::cout << "0 => Exit" << std::endl << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    switch (next) {
        case 1:
            return ActionResult::arrayResult::LOAD_ARR;
        case 2:
            return ActionResult::arrayResult::DISPLAY_ARR;
        case 3:
            return ActionResult::arrayResult::PUSH_FRONT_ARR;
        case 4:
            return ActionResult::arrayResult::PUSH_BACK_ARR;
        case 5:
            return ActionResult::arrayResult::PUSH_INDEX_ARR;
        case 6:
            return ActionResult::arrayResult::POP_FRONT_ARR;
        case 7:
            return ActionResult::arrayResult::POP_BACK_ARR;
        case 8:
            return ActionResult::arrayResult::POP_INDEX_ARR;
        case 9:
            return ActionResult::arrayResult::SET_INDEX_ARR;
        case 10:
            return ActionResult::arrayResult::FIND_BY_INDEX_ARR;
        case 11:
            return ActionResult::arrayResult::FIND_BY_VAL_ARR;
        case 12:
            return ActionResult::arrayResult::REMOVE_ALL_ARR;
        case 13:
            return ActionResult::arrayResult::GET_SIZE_ARR;
        case 0:
            return ActionResult::arrayResult::END_ARR;
        default:
            return ActionResult::arrayResult::MENU_ARR;
    }
}

ActionResult::listResult ConsoleView::listMenu() {
    system("CLS");
    std::cout << "Two-Way List: Choose from given options..." << std::endl;
    std::cout << "1 => Load List with test file data" << std::endl;
    std::cout << "2 => Display from Front" << std::endl;
    std::cout << "3 => Display from Back" << std::endl;
    std::cout << "4 => Push Front" << std::endl;
    std::cout << "5 => Push End" << std::endl;
    std::cout << "6 => Push On Index" << std::endl;
    std::cout << "7 => Pop Front" << std::endl;
    std::cout << "8 => Pop End" << std::endl;
    std::cout << "9 => Pop On Index" << std::endl;
    std::cout << "10 => Find By Index" << std::endl;
    std::cout << "11 => Find Index Of Element" << std::endl;
    std::cout << "12 => Remove All" << std::endl;
    std::cout << "13 => Check Size" << std::endl;
    std::cout << "0 => Exit" << std::endl << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    switch (next) {
        case 1:
            return ActionResult::listResult::LOAD_LIST;
        case 2:
            return ActionResult::listResult::DISPLAY_FRONT_LIST;
        case 3:
            return ActionResult::listResult::DISPLAY_BACK_LIST;
        case 4:
            return ActionResult::listResult::PUSH_FRONT_LIST;
        case 5:
            return ActionResult::listResult::PUSH_BACK_LIST;
        case 6:
            return ActionResult::listResult::PUSH_ON_INDEX_LIST;
        case 7:
            return ActionResult::listResult::POP_FRONT_LIST;
        case 8:
            return ActionResult::listResult::POP_BACK_LIST;
        case 9:
            return ActionResult::listResult::POP_INDEX_LIST;
        case 10:
            return ActionResult::listResult::FIND_BY_INDEX_LIST;
        case 11:
            return ActionResult::listResult::FIND_BY_VAL_LIST;
        case 12:
            return ActionResult::listResult::REMOVE_ALL_LIST;
        case 13:
            return ActionResult::listResult::GET_SIZE_LIST;
        case 0:
            return ActionResult::listResult::END_LIST;
        default:
            return ActionResult::listResult::MENU_LIST;
    }
}

ActionResult::heapResult ConsoleView::heapMenu() {
    system("CLS");
    std::cout << "Binary Heap: Choose from given options..." << std::endl;
    std::cout << "1 => Load Heap with test file data" << std::endl;
    std::cout << "2 => Display Heap" << std::endl;
    std::cout << "3 => Push" << std::endl;
    std::cout << "4 => Pop Root" << std::endl;
    std::cout << "5 => Pop Element" << std::endl;
    std::cout << "6 => Find By Index" << std::endl;
    std::cout << "7 => Find Index Of Element" << std::endl;
    std::cout << "8 => Remove All" << std::endl;
    std::cout << "9 => Check Size" << std::endl;
    std::cout << "0 => Exit" << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    switch (next) {
        case 1:
            return ActionResult::heapResult::LOAD_HEAP;
        case 2:
            return ActionResult::heapResult::DISPLAY_HEAP;
        case 3:
            return ActionResult::heapResult::PUSH_HEAP;
        case 4:
            return ActionResult::heapResult::POP_ROOT_HEAP;
        case 5:
            return ActionResult::heapResult::POP_ELEMENT_HEAP;
        case 6:
            return ActionResult::heapResult::FIND_BY_INDEX_HEAP;
        case 7:
            return ActionResult::heapResult::FIND_BY_VAL_HEAP;
        case 8:
            return ActionResult::heapResult::REMOVE_ALL_HEAP;
        case 9:
            return ActionResult::heapResult::GET_SIZE_HEAP;
        case 0:
            return ActionResult::heapResult::END_HEAP;
        default:
            return ActionResult::heapResult::MENU_HEAP;
    }
}

ActionResult::bstResult ConsoleView::bstMenu() {
    system("CLS");
    std::cout << "BST: Choose from given options..." << std::endl;
    std::cout << "1 => Load BST with test file data" << std::endl;
    std::cout << "2 => Display BST" << std::endl;
    std::cout << "3 => Push" << std::endl;
    std::cout << "4 => Pop Node" << std::endl;
    std::cout << "5 => Find Node by Value" << std::endl;
    std::cout << "6 => ..." << std::endl;
    std::cout << "7 => ..." << std::endl;
    std::cout << "8 => ..." << std::endl;
    std::cout << "9 => Remove All" << std::endl;
    std::cout << "10 => Check Size" << std::endl;
    std::cout << "0 => Exit" << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    switch (next) {
        case 1:
            return ActionResult::bstResult::LOAD_BST;
        case 2:
            return ActionResult::bstResult::DISPLAY_BST;
        case 3:
            return ActionResult::bstResult::PUSH_BST;
        case 4:
            return ActionResult::bstResult::POP_NODE;
        case 5:
            return ActionResult::bstResult::FIND_VAL_BST;
        case 6:
            return ActionResult::bstResult::DSW_BST;
        case 7:
            return ActionResult::bstResult::ROTATE_RIGHT_BST;
        case 8:
            return ActionResult::bstResult::ROTATE_LEFT_BST;
        case 9:
            return ActionResult::bstResult::REMOVE_ALL_BST;
        case 10:
            return ActionResult::bstResult::GET_SIZE_BST;
        case 0:
            return ActionResult::bstResult::END_BST;
        default:
            return ActionResult::bstResult::MENU_BST;
    }
}

//void ConsoleView::quit() {
//    system("CLS");
//    std::cout << "Exiting..." << std::endl;
//    exit(0);
//}

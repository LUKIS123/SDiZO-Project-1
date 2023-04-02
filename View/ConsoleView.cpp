//
// Created by lukas on 02.04.2023.
//

#include "iostream"
#include "ConsoleView.h"
#include "ActionResult.h"

ConsoleView::ConsoleView() {
}

ConsoleView::~ConsoleView() {
}

ActionResult::result ConsoleView::menu() {
    system("cls");
    std::cout << "Menu: Choose from given options..." << std::endl;
    std::cout << "1 => Load test data file" << std::endl;
    std::cout << "2 => Dynamic Array" << std::endl;
    std::cout << "3 => List" << std::endl;
    std::cout << "4 => Heap" << std::endl;
    std::cout << "5 => " << std::endl;
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
        case 0:
            return ActionResult::result::END;
        default:
            return ActionResult::result::MENU;
    }
}

ActionResult::result ConsoleView::arrayMenu() {
    return ActionResult::MENU;
}

ActionResult::result ConsoleView::listMenu() {
    return ActionResult::MENU;
}

ActionResult::result ConsoleView::heapMenu() {
    return ActionResult::MENU;
}

//void ConsoleView::quit() {
//    system("CLS");
//    std::cout << "Exiting..." << std::endl;
//    exit(0);
//}

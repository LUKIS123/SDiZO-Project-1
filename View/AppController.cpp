//
// Created by lukas on 02.04.2023.
//

#include "conio.h"
#include "iostream"
#include "AppController.h"
#include "ActionResult.h"
#include "ConsoleView.h"

// TODO: Kontrolery osobne dla kazdej struktury moze

AppController::AppController(const DynamicArray &dynamicArray, const ListBidirectional &listBidirectional)
        : dynamicArray(dynamicArray), listBidirectional(listBidirectional) {
    fileUtility = *new DataFileUtility();
}

AppController::~AppController() {}

void AppController::index() {
    ActionResult::result status = ActionResult::result::MENU;
    while (status != ActionResult::result::END) {
        switch (status) {
            case ActionResult::result::MENU:
                status = ConsoleView::menu();
                break;
            case ActionResult::result::LOAD_DATA_FILE:
                status = loadFileToBufferList();
                break;
            case ActionResult::result::DYNAMIC_ARRAY:
                arrayIndex();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::result::LIST_BIDIRECTIONAL:
                listIndex();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::result::BINARY_HEAP:

                break;
        }
    }
}

ActionResult::result AppController::loadFileToBufferList() {
    std::string fileName;
    std::cout << "Place file in ./Resources and enter file name:" << std::endl;
    std::cin >> fileName;
    std::string directory = "../Resources/";
    std::string fileDirectory = directory + fileName;

    dataList = *fileUtility.readData(fileDirectory);
    if (!dataList.empty()) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU;
}

void AppController::arrayIndex() {
    ActionResult::arrayResult status = ActionResult::arrayResult::MENU_ARR;
    while (status != ActionResult::arrayResult::END_ARR) {
        switch (status) {
            case ActionResult::MENU_ARR:
                status = ConsoleView::arrayMenu();
                break;
            case ActionResult::LOAD_ARR:
                status = loadArrayWithFileData();
                break;
            case ActionResult::DISPLAY_ARR:
                status = displayArray();
                break;
            case ActionResult::PUSH_FRONT_ARR:
                status = pushFrontArray();
                break;
            case ActionResult::PUSH_BACK_ARR:
                status = pushBackArray();
                break;
            case ActionResult::PUSH_INDEX_ARR:
                status = pushOnIndexArray();
                break;
            case ActionResult::POP_FRONT_ARR:
                status = popFrontArray();
                break;
            case ActionResult::POP_BACK_ARR:
                status = popBackArray();
                break;
            case ActionResult::POP_INDEX_ARR:
                status = popOnIndexArray();
                break;
            case ActionResult::SET_INDEX_ARR:
                status = setOnIndexArray();
                break;
            case ActionResult::GET_SIZE_ARR:
                status = displaySizeArray();
                break;
            case ActionResult::REMOVE_ALL_ARR:
                status = removeAllArray();
                break;
            case ActionResult::FIND_BY_INDEX_ARR:
                status = findByIndexArray();
                break;
            case ActionResult::FIND_BY_VAL_ARR:
                status = findIndexOfArray();
                break;
        }
    }
    dynamicArray.~DynamicArray();
}

ActionResult::arrayResult AppController::loadArrayWithFileData() {
    dynamicArray = *new DynamicArray(dataList);
    if (dataList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }
    if (dynamicArray.getSize() != 0) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::displayArray() {
    dynamicArray.display();
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushFrontArray() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    dynamicArray.pushFront(value);
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushBackArray() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    dynamicArray.pushEnd(value);
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushOnIndexArray() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    dynamicArray.pushOnIndex(index, value);
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popFrontArray() {
    int value = dynamicArray.popFront();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popBackArray() {
    int value = dynamicArray.popEnd();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popOnIndexArray() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    int value = dynamicArray.popOnIndex(index);
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::setOnIndexArray() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    dynamicArray.setOnIndex(index, value);
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::displaySizeArray() {
    std::cout << "Array size = " << dynamicArray.getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::removeAllArray() {
    dynamicArray.removeAll();
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::findByIndexArray() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Element on Index = " << dynamicArray.getByIndex(index) << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}


ActionResult::arrayResult AppController::findIndexOfArray() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    std::cout << "Index of Element = " << dynamicArray.getIndexOf(value) << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

void AppController::listIndex() {
    ActionResult::listResult status = ActionResult::listResult::MENU_LIST;
    while (status != ActionResult::listResult::END_LIST) {
        switch (status) {
            case ActionResult::MENU_LIST:
                status = ConsoleView::listMenu();
                break;
            case ActionResult::LOAD_LIST:
                status = loadListWithFileData();
                break;
            case ActionResult::DISPLAY_FRONT_LIST:
                status = displayListFromFront();
                break;
            case ActionResult::DISPLAY_BACK_LIST:
                status = displayListFromBack();
                break;
            case ActionResult::PUSH_FRONT_LIST:
                status = pushFrontList();
                break;
            case ActionResult::PUSH_BACK_LIST:
                status = pushBackList();
                break;
            case ActionResult::PUSH_ON_INDEX_LIST:
                status = pushOnIndexList();
                break;
            case ActionResult::POP_FRONT_LIST:
                status = popFrontList();
                break;
            case ActionResult::POP_BACK_LIST:
                status = popBackList();
                break;
            case ActionResult::POP_INDEX_LIST:
                status = popOnIndexList();
                break;
            case ActionResult::FIND_BY_INDEX_LIST:
                status = findByIndexList();
                break;
            case ActionResult::FIND_BY_VAL_LIST:
                status = findIndexOfList();
                break;
            case ActionResult::REMOVE_ALL_LIST:
                status = removeAllList();
                break;
            case ActionResult::GET_SIZE_LIST:
                status = displaySizeList();
                break;
        }
    }
    listBidirectional.~ListBidirectional();
}

ActionResult::listResult AppController::loadListWithFileData() {
    if (dataList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }

    listBidirectional.loadFileData(dataList);
    if (listBidirectional.getSize() != 0) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::displayListFromFront() {
    listBidirectional.displayFromFront();
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::displayListFromBack() {
    listBidirectional.displayFromBack();
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushFrontList() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    listBidirectional.pushFront(value);
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushBackList() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    listBidirectional.pushEnd(value);
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushOnIndexList() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    listBidirectional.pushOnIndex(index, value);
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popFrontList() {
    int value = listBidirectional.popFront();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popBackList() {
    int value = listBidirectional.popEnd();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popOnIndexList() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    int value = listBidirectional.popOnIndex(index);
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::findByIndexList() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Element on Index = " << listBidirectional.getByIndex(index)->data << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::findIndexOfList() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    std::cout << "Index of Element = " << listBidirectional.getIndexOf(value) << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::removeAllList() {
    listBidirectional.removeAll();
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::displaySizeList() {
    std::cout << "List size = " << listBidirectional.getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

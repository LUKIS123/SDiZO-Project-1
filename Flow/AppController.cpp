//
// Created by lukas on 02.04.2023.
//

#include "iostream"
#include "limits"
#include "AppController.h"
#include "ActionResult.h"
#include "ConsoleView.h"

AppController::AppController() {
    dynamicArray = new DynamicArray();
    listBidirectional = new ListBidirectional();
    heap = new BinaryHeap();
    bst = new BinarySearchTree();

    fileUtility = DataFileUtility();
    numberGenerator = RandomNumberGenerator();
    automaticTests = new AutomaticTests(numberGenerator, fileUtility);
}

AppController::~AppController() {
    delete dynamicArray;
    delete listBidirectional;
    delete heap;
    delete automaticTests;
    std::cout << "App closed!" << std::endl;
}

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
                heapIndex();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::BST_TREE:
                bstIndex();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::GENERATE_RANDOM_DATA:
                generateRandomData();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::SAVE_RANDOM_DATA:
                saveRandomDataToFIle();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::AUTOMATIC_TEST:
                startAutomaticTests();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::MANUAL_TESTS:
                setManualTestsStart();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::BUFFER_INFO:
                showBufferInfo();
                status = ActionResult::result::MENU;
                break;
            case ActionResult::END:
                break;
        }
    }
    std::cout << "Exiting..." << std::endl;
}

void AppController::showBufferInfo() {
    system("CLS");
    std::cout << "Data Buffer has: [ " << dataBufferList.size() << " ] elements" << std::endl;
    if (bufferSourceInfo) {
        std::cout << "Loaded from FILE" << std::endl;
    } else {
        std::cout << "Generated RANDOMLY" << std::endl;
    }
    system("PAUSE");
}

void AppController::generateRandomData() {
    system("CLS");
    std::cout << "Random integer generator..." << std::endl << "Choose from options:" << std::endl;
    std::cout << "1 => Generate with Seed" << std::endl;
    std::cout << "2 => Generate non-deterministic" << std::endl;
    std::cout << "Choice: ";
    int option;
    std::cin >> option;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad entry... Enter a NUMBER: ";
        std::cin >> option;
    }

    int howMuch;
    if (option == 1 || option == 2) {
        std::cout << "Set random buffer size: ";
        std::cin >> howMuch;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> howMuch;
        }
    } else {
        return;
    }

    if (option == 1) {
        int seed;
        std::cout << "Set seed: ";
        std::cin >> seed;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> seed;
        }
        dataBufferList = *numberGenerator.generateWithSeed(seed, howMuch);

    } else if (option == 2) {
        dataBufferList = *numberGenerator.generateNonDeterministic(howMuch);
    }

    if (!dataBufferList.empty()) {
        bufferSourceInfo = false;
        std::cout << "Success!" << std::endl;
        system("PAUSE");
    }
}

void AppController::saveRandomDataToFIle() {
    std::string fileName;
    std::cout << "File will be saved in ./Resources folder..." << std::endl << "Set file name: " << std::endl;
    std::cin >> fileName;
    DataFileUtility::saveData(dataBufferList, "../Resources/" + fileName);
}

void AppController::startAutomaticTests() {
    automaticTests->init();
    std::cout << "Exiting..." << std::endl;
    delete automaticTests;
    automaticTests = new AutomaticTests(numberGenerator, fileUtility);
    system("PAUSE");
}

void AppController::setManualTestsStart() {
    if (manualTests) {
        manualTests = false;
    } else {
        manualTests = true;
    }
    std::cout << "Manual Tests set to: " << std::boolalpha << manualTests << std::endl;
    system("PAUSE");
}

ActionResult::result AppController::loadFileToBufferList() {
    std::string fileName;
    std::cout << "Place file in ./Resources and enter file name:" << std::endl;
    std::cin >> fileName;
    std::string directory = "../Resources/";
    std::string fileDirectory = directory + fileName;

    dataBufferList = *fileUtility.readData(fileDirectory);
    if (!dataBufferList.empty()) {
        bufferSourceInfo = true;
        std::cout << "Test file data loaded to buffer!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU;
}

void AppController::arrayIndex() {
    if (manualTests) {
        std::cout << "Manual Tests Set!" << std::endl;
        std::cout << "Do you want to fill structure with random data?" << std::endl;
        std::cout << "Yes == 1, No == Any key" << std::endl;
        std::cout << "Choice: ";
        char choice;
        std::cin >> choice;
        if (choice == '1') {
            generateRandomData();
            if (!dataBufferList.empty()) {
                dynamicArray = new DynamicArray(dataBufferList);
                if (dynamicArray->getSize() != 0) {
                    std::cout << "Success!" << std::endl;
                    system("PAUSE");
                }
            }
        }
        std::cout << "Set test series count (table size)" << std::endl;
        std::cout << "Count: ";
        int count;
        std::cin >> count;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> count;
        }
        dynamicArray->testCount = count;
        system("PAUSE");
    }
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
            case ActionResult::END_ARR:
                break;
        }
    }
    if (manualTests) {
        dynamicArray->setHeadline(
                "push_front,push_end,push_on_index,find_element,find_index_of,pop_front,pop_end,pop_on_index");
        std::cout << "Saving test results..." << std::endl;
        dynamicArray->saveResults("../Resources/array_tests_manual.csv");
        system("PAUSE");
    }
    delete dynamicArray;
    dynamicArray = new DynamicArray();
}

ActionResult::arrayResult AppController::loadArrayWithFileData() {
    if (dataBufferList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }
    dynamicArray = new DynamicArray(dataBufferList);
    if (dynamicArray->getSize() != 0) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::displayArray() {
    dynamicArray->display();
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushFrontArray() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    dynamicArray->pushFront(value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addPushFront(Timer::getMicroSecondsAndPrint(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushBackArray() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    dynamicArray->pushEnd(value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addPushEnd(Timer::getMicroSecondsAndPrint(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushOnIndexArray() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_ARR;
    }
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    dynamicArray->pushOnIndex(index, value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addPushIndex(Timer::getMicroSecondsAndPrint(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popFrontArray() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = dynamicArray->popFront();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addPopFront(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popBackArray() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = dynamicArray->popEnd();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addPopEnd(Timer::getMicroSecondsAndPrint(start, end));
    }

    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popOnIndexArray() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_ARR;
    }
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = dynamicArray->popOnIndex(index);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addPopIndex(Timer::getMicroSecondsAndPrint(start, end));
    }

    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::setOnIndexArray() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_ARR;
    }
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    dynamicArray->setOnIndex(index, value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        Timer::getMicroSecondsAndPrint(start, end);
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::displaySizeArray() {
    std::cout << "Array size = " << dynamicArray->getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::removeAllArray() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    dynamicArray->removeAll();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        Timer::getMicroSecondsAndPrint(start, end);
    }
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::findByIndexArray() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_ARR;
    }
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = *dynamicArray->getByIndex(index);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addFindByIndex(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Element on Index = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::findIndexOfArray() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int indexValue = dynamicArray->getIndexOf(value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        dynamicArray->addFindIndexOf(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Index of Element = " << indexValue << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

void AppController::listIndex() {
    if (manualTests) {
        std::cout << "Manual Tests Set!" << std::endl;
        std::cout << "Do you want to fill structure with random data?" << std::endl;
        std::cout << "Yes == 1, No == Any key" << std::endl;
        std::cout << "Choice: ";
        char choice;
        std::cin >> choice;
        if (choice == '1') {
            generateRandomData();
            if (!dataBufferList.empty()) {
                listBidirectional->loadFileData(dataBufferList);
                if (listBidirectional->getSize() != 0) {
                    std::cout << "Success!" << std::endl;
                    system("PAUSE");
                }
            }
        }
        std::cout << "Set test series count (table size)" << std::endl;
        std::cout << "Count: ";
        int count;
        std::cin >> count;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> count;
        }
        listBidirectional->testCount = count;
        system("PAUSE");
    }
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
            case ActionResult::END_LIST:
                break;
        }
    }
    if (manualTests) {
        listBidirectional->setHeadline(
                "push_front,push_end,push_on_index,find_element,find_index_of,pop_front,pop_end,pop_on_index");
        std::cout << "Saving test results..." << std::endl;
        listBidirectional->saveResults("../Resources/list_tests_manual.csv");
        system("PAUSE");
    }
    listBidirectional->removeAll();
}

ActionResult::listResult AppController::loadListWithFileData() {
    if (dataBufferList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }

    listBidirectional->loadFileData(dataBufferList);
    if (listBidirectional->getSize() != 0) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::displayListFromFront() {
    listBidirectional->displayFromFront();
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::displayListFromBack() {
    listBidirectional->displayFromBack();
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushFrontList() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    listBidirectional->pushFront(value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addPushFront(Timer::getMicroSecondsAndPrint(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushBackList() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    listBidirectional->pushEnd(value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addPushEnd(Timer::getMicroSecondsAndPrint(start, end));
    }

    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushOnIndexList() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error!" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_LIST;
    }
    std::cout << "Input: " << std::endl;
    std::cin >> value;

    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    listBidirectional->pushOnIndex(index, value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addPushIndex(Timer::getMicroSecondsAndPrint(start, end));
    }

    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popFrontList() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = listBidirectional->popFront();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addPopFront(Timer::getMicroSecondsAndPrint(start, end));
    }

    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popBackList() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = listBidirectional->popEnd();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addPopEnd(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popOnIndexList() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error!" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_LIST;
    }
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int value = listBidirectional->popOnIndex(index);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addPopIndex(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::findByIndexList() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Error!" << std::endl;
        system("PAUSE");
        return ActionResult::MENU_LIST;
    }
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int indexData = listBidirectional->getByIndex(index)->data;
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addFindByIndex(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Element on Index = " << indexData << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::findIndexOfList() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    int foundIndex = listBidirectional->getIndexOf(value);
    if (manualTests) {
        long long int end = Timer::read_QPC();
        listBidirectional->addFindIndexOf(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Index of Element = " << foundIndex << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::removeAllList() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    listBidirectional->removeAll();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        Timer::getMicroSecondsAndPrint(start, end);
    }
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::displaySizeList() {
    std::cout << "List size = " << listBidirectional->getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

void AppController::heapIndex() {
    if (manualTests) {
        std::cout << "Manual Tests Set!" << std::endl;
        std::cout << "Do you want to fill structure with random data?" << std::endl;
        std::cout << "Yes == 1, No == Any key" << std::endl;
        std::cout << "Choice: ";
        char choice;
        std::cin >> choice;
        if (choice == '1') {
            generateRandomData();
            if (!dataBufferList.empty()) {
                int sizeH;
                std::cout << "How much buffer size (extra size)?" << std::endl;
                std::cout << "Input: ";
                std::cin >> sizeH;
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Bad entry... Enter a NUMBER: ";
                    std::cin >> sizeH;
                }
                delete heap;
                heap = new BinaryHeap(dataBufferList.size() + sizeH);
                heap->loadFileDataAndHeapify(dataBufferList);
                if (heap->getSize() != 0) {
                    std::cout << "Success!" << std::endl;
                    system("PAUSE");
                }
            }
        }
        std::cout << "Set test series count (table size)" << std::endl;
        std::cout << "Count: ";
        int count;
        std::cin >> count;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> count;
        }
        heap->testCount = count;
        system("PAUSE");
    } else {
        initHeap();
    }
    ActionResult::heapResult status = ActionResult::heapResult::MENU_HEAP;
    while (status != ActionResult::heapResult::END_HEAP) {
        switch (status) {
            case ActionResult::MENU_HEAP:
                status = ConsoleView::heapMenu();
                break;
            case ActionResult::LOAD_HEAP:
                status = loadHeapWithFileData();
                break;
            case ActionResult::DISPLAY_HEAP:
                status = displayHeap();
                break;
            case ActionResult::PUSH_HEAP:
                status = pushHeap();
                break;
            case ActionResult::POP_ROOT_HEAP:
                status = popRootHeap();
                break;
            case ActionResult::POP_ELEMENT_HEAP:
                status = popElementHeap();
                break;
            case ActionResult::FIND_BY_INDEX_HEAP:
                status = findByIndexHeap();
                break;
            case ActionResult::FIND_BY_VAL_HEAP:
                status = findIndexOfHeap();
                break;
            case ActionResult::REMOVE_ALL_HEAP:
                status = removeAllHeap();
                break;
            case ActionResult::GET_SIZE_HEAP:
                status = displaySizeHeap();
                break;
            case ActionResult::END_HEAP:
                break;
        }
    }
    if (manualTests) {
        heap->setHeadline(
                "-,-,-,find_element,find_index_of,-,-,-,heapify_floyd,push_heap,pop_root_heap,pop_key_heap");
        std::cout << "Saving test results..." << std::endl;
        heap->saveResults("../Resources/heap_tests_manual.csv");
        system("PAUSE");
    }
    delete heap;
    heap = new BinaryHeap();
}

void AppController::initHeap() {
    std::cout << "Heap initialization..." << std::endl;
    std::cout << std::endl << "Would you like to load Heap with test file data?" << std::endl;
    std::cout << "Yes == 1, No == Any Key" << std::endl;

    std::cout << "Choice: ";
    char next;
    std::cin >> next;

    int sizeH;
    if (next == '1') {
        std::cout << "How much buffer size (extra size)?" << std::endl;
        std::cout << "Input: ";
        std::cin >> sizeH;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> sizeH;
        }
        delete heap;
        if (dataBufferList.empty()) {
            std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
            loadFileToBufferList();
        }
        heap = new BinaryHeap(dataBufferList.size() + sizeH);
        heap->loadFileDataAndHeapify(dataBufferList);
    } else {
        std::cout << "Please set Heap size..." << std::endl;
        std::cout << "Input: ";
        std::cin >> sizeH;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry... Enter a NUMBER: ";
            std::cin >> sizeH;
        }
        delete heap;
        heap = new BinaryHeap(sizeH);
        std::cout << "Done..." << std::endl;
    }
    system("PAUSE");
}

ActionResult::heapResult AppController::loadHeapWithFileData() {
    if (dataBufferList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }

    if (manualTests) {
        heap->loadFileData(dataBufferList);
        long long int start;
        start = Timer::read_QPC();
        heap->startHeapifyMoveDownFloyd();
        long long int end = Timer::read_QPC();
        heap->addHeapifyFloyd(Timer::getMicroSecondsAndPrint(start, end));
    } else {
        heap->loadFileDataAndHeapify(dataBufferList);
    }

    if (heap->getSize() != 0) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::displayHeap() {
    heap->display();
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::pushHeap() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;

    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }

    heap->push(value);

    if (manualTests) {
        long long int end = Timer::read_QPC();
        heap->addPushNode(Timer::getMicroSecondsAndPrint(start, end));
    }

    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::popRootHeap() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }

    int value = heap->popRoot();

    if (manualTests) {
        long long int end = Timer::read_QPC();
        heap->addPopRootHeap(Timer::getMicroSecondsAndPrint(start, end));
    }

    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::popElementHeap() {
    int value;
    std::cout << "Key value: ";
    std::cin >> value;

    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }

    heap->pop(value);

    if (manualTests) {
        long long int end = Timer::read_QPC();
        heap->addPopNodeWithKey(Timer::getMicroSecondsAndPrint(start, end));
    }

    std::cout << "Done..." << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::findByIndexHeap() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    while (std::cin.fail()) {
        std::cout << "Error!";
        system("PAUSE");
        return ActionResult::MENU_HEAP;
    }

    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }

    int found = heap->findByIndex(index);

    if (manualTests) {
        long long int end = Timer::read_QPC();
        heap->addFindByIndex(Timer::getMicroSecondsAndPrint(start, end));
    }

    std::cout << "Element on Index = " << found << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::findIndexOfHeap() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;

    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }

    int indexOf = heap->findIndexOf(value);

    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
    }

    if (indexOf != -1) {
        std::cout << "Index of Element = " << heap->findIndexOf(value) << std::endl;
        if (manualTests) {
            heap->addFindIndexOf(Timer::getMicroSecondsAndPrint(start, end));
        }
    } else {
        std::cout << "Element doesn't exist!" << heap->findIndexOf(value) << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::removeAllHeap() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }

    heap->removeAll();

    if (manualTests) {
        long long int end = Timer::read_QPC();
        Timer::getMicroSecondsAndPrint(start, end);
    }

    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::displaySizeHeap() {
    std::cout << "Heap size = " << heap->getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

void AppController::bstIndex() {
    if (manualTests) {
        std::cout << "Manual Tests Set!" << std::endl;
        std::cout << "Do you want to fill structure with random data?" << std::endl;
        std::cout << "Yes == 1, No == Any key" << std::endl;
        std::cout << "Choice: ";
        char choice;
        std::cin >> choice;
        if (choice == '1') {
            generateRandomData();
            if (!dataBufferList.empty()) {
                bst->loadFileData(dataBufferList);
                if (bst->getSize() != 0) {
                    std::cout << "Success!" << std::endl;
                    system("PAUSE");
                }
            }
        }
        std::cout << "Set test series count (table size)" << std::endl;
        std::cout << "Count: ";
        int count;
        std::cin >> count;
        bst->testCount = count;
        system("PAUSE");
    }
    ActionResult::bstResult status = ActionResult::bstResult::MENU_BST;
    while (status != ActionResult::bstResult::END_BST) {
        switch (status) {
            case ActionResult::END_BST:
                break;
            case ActionResult::MENU_BST:
                status = ConsoleView::bstMenu();
                break;
            case ActionResult::LOAD_BST:
                status = loadBSTWithFileData();
                break;
            case ActionResult::DISPLAY_BST:
                status = displayBST();
                break;
            case ActionResult::PUSH_BST:
                status = pushBST();
                break;
            case ActionResult::POP_NODE:
                status = popBST();
                break;
            case ActionResult::FIND_VAL_BST:
                status = findNodeBST();
                break;
            case ActionResult::DSW_BST:
                status = balanceUsingDSWBST();
                break;
            case ActionResult::ROTATE_RIGHT_BST:
                status = rotateRightBST();
                break;
            case ActionResult::ROTATE_LEFT_BST:
                status = rotateLeftBST();
                break;
            case ActionResult::REMOVE_ALL_BST:
                status = removeAllBST();
                break;
            case ActionResult::GET_SIZE_BST:
                status = displaySizeBST();
                break;
        }
    }
    if (manualTests) {
        bst->setHeadline(
                "-,-,-,-,-,-,-,-,-,push_node_bst,-,pop_node_bst,find_element,dsw_algo,rotate_right,rotate_left");
        std::cout << "Saving test results..." << std::endl;
        bst->saveResults("../Resources/bst_tests_manual.csv");
        system("PAUSE");
    }
    bst->removeAll();
}

ActionResult::bstResult AppController::loadBSTWithFileData() {
    if (dataBufferList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }
    bst->loadFileData(dataBufferList);
    if (bst->getSize() != 0) {
        std::cout << "Success!" << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::displayBST() {
    bst->displayBothVariants();
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::pushBST() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;

    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    bst->push(value);
    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
        bst->addPushNode(Timer::getMicroSecondsAndPrint(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::popBST() {
    int value;
    std::cout << "Key value: ";
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    bst->pop(value);
    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
        bst->addPopNodeWithKey(Timer::getMicroSecondsAndPrint(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::findNodeBST() {
    int value;
    std::cout << "Key value: ";
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    BinarySearchTree::BNode *found = bst->findByValue(value);
    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
        bst->addFindNodeBST(Timer::getMicroSecondsAndPrint(start, end));
    }
    if (found == nullptr) {
        std::cout << "Node does not exist!" << std::endl;
    }
    std::cout << "Found Node of Value = " << found->key << std::endl;
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::removeAllBST() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    bst->removeAll();
    if (manualTests) {
        long long int end = Timer::read_QPC();
        Timer::getMicroSecondsAndPrint(start, end);
    }
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::displaySizeBST() {
    std::cout << "BST size = " << bst->getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::balanceUsingDSWBST() {
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    bst->balanceTreeDSW();
    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
        bst->addDSWAlgoBST(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Done!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::rotateRightBST() {
    int value;
    std::cout << "Key value: ";
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    bst->rotateRight(value);
    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
        bst->addRotateRightBST(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Done!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_BST;
}

ActionResult::bstResult AppController::rotateLeftBST() {
    int value;
    std::cout << "Key value: ";
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = Timer::read_QPC();
    }
    bst->rotateLeft(value);
    long long int end;
    if (manualTests) {
        end = Timer::read_QPC();
        bst->addRotateLeftBST(Timer::getMicroSecondsAndPrint(start, end));
    }
    std::cout << "Done!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_BST;
}

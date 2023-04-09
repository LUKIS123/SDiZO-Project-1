//
// Created by lukas on 02.04.2023.
//

#include "conio.h"
#include "iostream"
#include "AppController.h"
#include "ActionResult.h"
#include "ConsoleView.h"

AppController::AppController() {
    dynamicArray = new DynamicArray();
    listBidirectional = new ListBidirectional();
    heap = new BinaryHeap();
    bst = new BinarySearchTree();

    fileUtility = DataFileUtility();
    timer = Timer();
    numberGenerator = RandomNumberGenerator();
    automaticTests = new AutomaticTests(numberGenerator, fileUtility);
}

AppController::~AppController() {
    delete dynamicArray;
    delete listBidirectional;
    delete heap;
    delete automaticTests;
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
        }
    }
    std::cout << "Exiting..." << std::endl;
    exit(0);
}

void AppController::generateRandomData() {
    system("CLS");
    std::cout << "Random integer generator..." << std::endl << "Choose from options:" << std::endl;
    std::cout << "1 => Generate with Seed" << std::endl;
    std::cout << "2 => Generate non-deterministic" << std::endl;
    std::cout << "Choice: ";
    int option;
    std::cin >> option;

    int howMuch;
    if (option == 1 || option == 2) {
        std::cout << "Set random buffer size: ";
        std::cin >> howMuch;
    } else {
        return;
    }

    if (option == 1) {
        int seed;
        std::cout << "Set seed: ";
        std::cin >> seed;
        dataBufferList = *numberGenerator.generateWithSeed(seed, howMuch);

    } else if (option == 2) {
        dataBufferList = *numberGenerator.generateNonDeterministic(howMuch);
    }

    if (!dataBufferList.empty()) {
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
    manualTests = true;
    std::cout << "Manual Tests Set!" << std::endl;
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
        std::cout << "Test file data saved in buffer!" << std::endl;
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
        start = timer.read_QPC();
    }
    dynamicArray->pushFront(value);
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addPushFront(timer.getMicroSeconds(start, end));
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
        start = timer.read_QPC();
    }
    dynamicArray->pushEnd(value);
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addPushEnd(timer.getMicroSeconds(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::pushOnIndexArray() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    long long int start;
    if (manualTests) {
        start = timer.read_QPC();
    }
    dynamicArray->pushOnIndex(index, value);
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addPushIndex(timer.getMicroSeconds(start, end));
    }
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popFrontArray() {
    long long int start;
    if (manualTests) {
        start = timer.read_QPC();
    }
    int value = dynamicArray->popFront();
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addPopFront(timer.getMicroSeconds(start, end));
    }
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popBackArray() {
    long long int start;
    if (manualTests) {
        start = timer.read_QPC();
    }
    int value = dynamicArray->popEnd();
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addPopEnd(timer.getMicroSeconds(start, end));
    }

    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::popOnIndexArray() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    long long int start;
    if (manualTests) {
        start = timer.read_QPC();
    }
    int value = dynamicArray->popOnIndex(index);
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addPopIndex(timer.getMicroSeconds(start, end));
    }

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
    long long int start;
    if (manualTests) {
        start = timer.read_QPC();
    }
    dynamicArray->setOnIndex(index, value);
    if (manualTests) {
        long long int end = timer.read_QPC();
        timer.getMicroSeconds(start, end);
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
        start = timer.read_QPC();
    }
    dynamicArray->removeAll();
    if (manualTests) {
        long long int end = timer.read_QPC();
    }
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_ARR;
}

ActionResult::arrayResult AppController::findByIndexArray() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    long long int start;
    if (manualTests) {
        start = timer.read_QPC();
    }
    int value = *dynamicArray->getByIndex(index);
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addFindByIndex(timer.getMicroSeconds(start, end));
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
        start = timer.read_QPC();
    }
    int indexValue = dynamicArray->getIndexOf(value);
    if (manualTests) {
        long long int end = timer.read_QPC();
        dynamicArray->addFindIndexOf(timer.getMicroSeconds(start, end));
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
        }
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
    listBidirectional->pushFront(value);
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushBackList() {
    int value;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    listBidirectional->pushEnd(value);
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::pushOnIndexList() {
    int value, index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Input: " << std::endl;
    std::cin >> value;
    listBidirectional->pushOnIndex(index, value);
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popFrontList() {
    int value = listBidirectional->popFront();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popBackList() {
    int value = listBidirectional->popEnd();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::popOnIndexList() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    int value = listBidirectional->popOnIndex(index);
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::findByIndexList() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Element on Index = " << listBidirectional->getByIndex(index)->data << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::findIndexOfList() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    std::cout << "Index of Element = " << listBidirectional->getIndexOf(value) << std::endl;
    system("PAUSE");
    return ActionResult::MENU_LIST;
}

ActionResult::listResult AppController::removeAllList() {
    listBidirectional->removeAll();
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
        }
    }
    delete heap;
    heap = nullptr;
}

void AppController::initHeap() {
    std::cout << "Heap initialization..." << std::endl;
    std::cout << std::endl << "Would you like to load Heap with test file data?" << std::endl;
    std::cout << "Yes == 1, No == Any Key" << std::endl;

    std::cout << "Choice: ";
    int next;
    std::cin >> next;

    int sizeH;
    switch (next) {
        case 1:
            std::cout << "How much buffer size (extra size)?" << std::endl;
            std::cout << "Input: ";
            std::cin >> sizeH;
            delete heap;
            if (dataBufferList.empty()) {
                std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
                loadFileToBufferList();
            }
            heap = new BinaryHeap(dataBufferList.size() + sizeH);
            heap->loadFileDataAndHeapify(dataBufferList);
            break;
        default:
            std::cout << "Please set Heap size..." << std::endl;
            std::cout << "Input: ";
            std::cin >> sizeH;
            delete heap;
            heap = new BinaryHeap(sizeH);
            std::cout << "Done..." << std::endl;
            system("PAUSE");
            break;
    }
}

ActionResult::heapResult AppController::loadHeapWithFileData() {
    if (dataBufferList.empty()) {
        std::cout << "Buffer is empty! Test file must be read first!" << std::endl;
        loadFileToBufferList();
    }

    heap->loadFileDataAndHeapify(dataBufferList);
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
    heap->push(value);
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::popRootHeap() {
    int value = heap->popRoot();
    std::cout << "Popped value = " << value << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::popElementHeap() {
    int value;
    std::cout << "Key value: ";
    std::cin >> value;
    heap->pop(value);
    std::cout << "Done..." << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::findByIndexHeap() {
    int index;
    std::cout << "Index: " << std::endl;
    std::cin >> index;
    std::cout << "Element on Index = " << heap->findByIndex(index) << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::findIndexOfHeap() {
    int value;
    std::cout << "Value: " << std::endl;
    std::cin >> value;
    int indexOf = heap->findIndexOf(value);
    if (indexOf != -1) {
        std::cout << "Index of Element = " << heap->findIndexOf(value) << std::endl;
    } else {
        std::cout << "Element doesn't exist!" << heap->findIndexOf(value) << std::endl;
    }
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::removeAllHeap() {
    heap->removeAll();
    std::cout << "All data has been removed!" << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

ActionResult::heapResult AppController::displaySizeHeap() {
    std::cout << "Heap size = " << heap->getSize() << std::endl;
    system("PAUSE");
    return ActionResult::MENU_HEAP;
}

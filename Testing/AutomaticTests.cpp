//
// Created by lukas on 08.04.2023.
//

#include "AutomaticTests.h"
#include "limits"
#include <utility>

AutomaticTests::~AutomaticTests() {
    dataList.clear();
    results.clear();
}

AutomaticTests::AutomaticTests() = default;

AutomaticTests::AutomaticTests(const RandomNumberGenerator &numberGenerator, DataFileUtility fileUtility)
        : numberGenerator(numberGenerator), fileUtility(std::move(fileUtility)) {
    timer = Timer();
}

void AutomaticTests::init() {
    setTestNumber();
    generateRandomData();
    if (dataList.empty()) {
        return;
    }
    menu();
}

void AutomaticTests::setTestNumber() {
    system("CLS");
    std::cout << "AUTOMATIC TESTS Initialization..." << std::endl;
    std::cout << std::endl << "Set number of tests..." << std::endl;

    std::cout << "Tests: ";
    std::cin >> testNumber;
    system("PAUSE");
}

void AutomaticTests::generateRandomData() {
    system("CLS");
    std::cout << std::endl << "Generate Test Data..." << std::endl;
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

    if (option == 1 || option == 2) {
        std::cout << "Set random buffer size: ";
        std::cin >> dataBufferSize;
    } else {
        return;
    }

    if (option == 1) {
        int seed;
        std::cout << "Set seed: ";
        std::cin >> seed;
        dataList = *numberGenerator.generateWithSeed(seed, dataBufferSize);

    } else if (option == 2) {
        dataList = *numberGenerator.generateNonDeterministic(dataBufferSize);
    }

    if (!dataList.empty()) {
        std::cout << "Success!" << std::endl;
        system("PAUSE");
    }
}

void AutomaticTests::menu() {
    ActionResult::automaticTestResult status = ActionResult::automaticTestResult::MENU_TEST;
    while (status != ActionResult::automaticTestResult::END_TEST) {
        switch (status) {
            case ActionResult::END_TEST:
                break;
            case ActionResult::MENU_TEST:
                status = ConsoleView::testMenu();
                break;
            case ActionResult::GENERATE_DATA_TEST:
                generateRandomData();
                status = ActionResult::MENU_TEST;
                break;
            case ActionResult::DYNAMIC_ARRAY_TEST:
                deployArrayTests();
                status = ActionResult::MENU_TEST;
                break;
            case ActionResult::LIST_BIDIRECTIONAL_TEST:
                deployListTests();
                status = ActionResult::MENU_TEST;
                break;
            case ActionResult::BINARY_HEAP_TEST:
                deployHeapTests();
                status = ActionResult::MENU_TEST;
                break;
            case ActionResult::BST_TREE_TEST:
                deployBSTTests();
                status = ActionResult::MENU_TEST;
                break;
            case ActionResult::CHANGE_TEST_SERIES_NUMBER:
                setTestNumber();
                status = ActionResult::MENU_TEST;
                break;
        }
    }
}

void AutomaticTests::deployArrayTests() {
    results = {};
    std::string fileName = "../Resources/array_tests.csv";
    std::string headLine = "push_front,push_end,push_on_index,find_element,find_index_of,pop_front,pop_end,pop_on_index";
    array = new DynamicArray(dataList);

    for (int i = 0; i < testNumber; ++i) {
        std::list<double> iterationResults = {};

        int value = numberGenerator.generateRandomInteger();
        timer.startTimer();
        array->pushFront(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        value = numberGenerator.generateRandomInteger();
        timer.startTimer();
        array->pushEnd(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        value = numberGenerator.generateRandomInteger();
        int index = (int) (dataList.size() / 2);
        timer.startTimer();
        array->pushOnIndex(index, value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        array->getByIndex(index);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        array->getByValue(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        array->popFront();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        array->popEnd();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        index = (int) (dataList.size() / 2);
        timer.startTimer();
        array->popOnIndex(index);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        // Saving results to main list
        results.push_back(iterationResults);
    }
    // Saving results to .csv
    DataFileUtility::saveTimerResults2D(fileName, results, headLine);
    delete array;
    std::cout << "Done!" << std::endl;
    system("PAUSE");
}

void AutomaticTests::deployListTests() {
    results = {};
    std::string fileName = "../Resources/list_tests.csv";
    std::string headLine = "push_front,push_end,push_on_index,find_element_by_index,find_index_of,pop_front,pop_end,pop_on_index";
    list = new ListBidirectional();
    list->loadFileData(dataList);

    for (int i = 0; i < testNumber; ++i) {
        std::list<double> iterationResults = {};

        int value = numberGenerator.generateRandomInteger();
        timer.startTimer();
        list->pushFront(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());


        value = numberGenerator.generateRandomInteger();
        timer.startTimer();
        list->pushEnd(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        value = numberGenerator.generateRandomInteger();
        int index = (int) (dataList.size() / 2);
        timer.startTimer();
        list->pushOnIndex(index, value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        list->getByIndex(index);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        list->getByValue(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        list->popFront();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        list->popEnd();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        index = (int) (dataList.size() / 2);
        timer.startTimer();
        list->popOnIndex(index);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        // Saving results to main list
        results.push_back(iterationResults);
    }
    // Saving results to .csv
    DataFileUtility::saveTimerResults2D(fileName, results, headLine);
    delete list;
    std::cout << "Done!" << std::endl;
    system("PAUSE");
}

void AutomaticTests::deployHeapTests() {
    results = {};
    std::string fileName = "../Resources/heap_tests.csv";
    std::string headLine = "heapify_floyd,push,find_element_by_index,find_index_of,pop_root,pop_key";
    heap = new BinaryHeap(dataList.size() + 10);

    for (int i = 0; i < testNumber; ++i) {
        std::list<double> iterationResults = {};

        heap->removeAll();
        heap->loadFileData(dataList);
        timer.startTimer();
        heap->startHeapifyMoveDownFloyd();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        int value = numberGenerator.generateRandomInteger();
        timer.startTimer();
        heap->push(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        // pushing another key to pop later
        value = numberGenerator.generateRandomInteger();
        heap->push(value);

        int index = (int) (dataList.size() / 2);
        timer.startTimer();
        heap->findByIndex(index);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        heap->findIndexOf(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        heap->popRoot();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        heap->pop(value);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        // Saving results to main list
        results.push_back(iterationResults);
    }
    // Saving results to .csv
    DataFileUtility::saveTimerResults2D(fileName, results, headLine);
    delete heap;
    std::cout << "Done!" << std::endl;
    system("PAUSE");
}

void AutomaticTests::deployBSTTests() {
    results = {};
    std::string fileName = "../Resources/bst_tests.csv";
    std::string headLine = "push_node,pop_node,find_element,dsw_algo,rotate_right,rotate_left";
    bst = new BinarySearchTree();
    bst->loadFileData(dataList);

    int middleNode1;
    auto l_front = dataList.begin();
    int middle = (int) dataList.size() / 2;
    std::advance(l_front, middle);
    middleNode1 = *l_front;

    bst->automaticTests = true;
    for (int i = 0; i < testNumber; ++i) {
        std::list<double> iterationResults = {};

        int value1 = numberGenerator.generateRandomInteger();
        timer.startTimer();
        bst->push(value1);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        bst->pop(value1);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        BinarySearchTree::BNode *nodeBst = bst->findByValue(middleNode1);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        bst->balanceTreeDSW();
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        bst->rotateRight(nodeBst);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        timer.startTimer();
        bst->rotateLeft(nodeBst);
        timer.stopTimer();
        iterationResults.push_back(timer.getMicroSecondsElapsed());

        // Saving results to main list
        results.push_back(iterationResults);
    }
    DataFileUtility::saveTimerResults2D(fileName, results, headLine);
    delete bst;
    std::cout << "Done!" << std::endl;
    system("PAUSE");
}

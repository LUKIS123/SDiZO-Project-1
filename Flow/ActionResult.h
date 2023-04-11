//
// Created by lukas on 02.04.2023.
//

#ifndef SDIZO_PROJECT_1_ACTIONRESULT_H
#define SDIZO_PROJECT_1_ACTIONRESULT_H


class ActionResult {
public:
    enum result {
        END = 0,
        MENU = 10,
        LOAD_DATA_FILE = 1,
        DYNAMIC_ARRAY = 2,
        LIST_BIDIRECTIONAL = 3,
        BINARY_HEAP = 4,
        BST_TREE = 5,
        GENERATE_RANDOM_DATA = 6,
        SAVE_RANDOM_DATA = 7,
        AUTOMATIC_TEST = 8,
        MANUAL_TESTS = 9
    };

    enum automaticTestResult {
        END_TEST = 0,
        MENU_TEST = 6,
        GENERATE_DATA_TEST = 1,
        DYNAMIC_ARRAY_TEST = 2,
        LIST_BIDIRECTIONAL_TEST = 3,
        BINARY_HEAP_TEST = 4,
        BST_TREE_TEST = 5,
        CHANGE_TEST_SERIES_NUMBER = 7
    };

    enum arrayResult {
        END_ARR = 0,
        MENU_ARR = 14,
        LOAD_ARR = 1,
        DISPLAY_ARR = 2,
        PUSH_FRONT_ARR = 3,
        PUSH_BACK_ARR = 4,
        PUSH_INDEX_ARR = 5,
        POP_FRONT_ARR = 6,
        POP_BACK_ARR = 7,
        POP_INDEX_ARR = 8,
        SET_INDEX_ARR = 9,
        FIND_BY_INDEX_ARR = 10,
        FIND_BY_VAL_ARR = 11,
        REMOVE_ALL_ARR = 12,
        GET_SIZE_ARR = 13
    };

    enum listResult {
        END_LIST = 0,
        MENU_LIST = 14,
        LOAD_LIST = 1,
        DISPLAY_FRONT_LIST = 2,
        DISPLAY_BACK_LIST = 3,
        PUSH_FRONT_LIST = 4,
        PUSH_BACK_LIST = 5,
        PUSH_ON_INDEX_LIST = 6,
        POP_FRONT_LIST = 7,
        POP_BACK_LIST = 8,
        POP_INDEX_LIST = 9,
        FIND_BY_INDEX_LIST = 10,
        FIND_BY_VAL_LIST = 11,
        REMOVE_ALL_LIST = 12,
        GET_SIZE_LIST = 13
    };

    enum heapResult {
        END_HEAP = 0,
        MENU_HEAP = 10,
        LOAD_HEAP = 1,
        DISPLAY_HEAP = 2,
        PUSH_HEAP = 3,
        POP_ROOT_HEAP = 4,
        POP_ELEMENT_HEAP = 5,
        FIND_BY_INDEX_HEAP = 6,
        FIND_BY_VAL_HEAP = 7,
        REMOVE_ALL_HEAP = 8,
        GET_SIZE_HEAP = 9
    };

    enum bstResult {
        END_BST = 0,
        MENU_BST = 11,
        LOAD_BST = 1,
        DISPLAY_BST = 2,
        PUSH_BST = 3,
        POP_NODE = 4,
        FIND_VAL_BST = 5,
        DSW_BST = 6,
        ROTATE_RIGHT_BST = 7,
        ROTATE_LEFT_BST = 8,
        REMOVE_ALL_BST = 9,
        GET_SIZE_BST = 10
    };

    ActionResult();

    virtual ~ActionResult();
};


#endif //SDIZO_PROJECT_1_ACTIONRESULT_H

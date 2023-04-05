//
// Created by lukas on 02.04.2023.
//

#ifndef SDIZO_PROJECT_1_ACTIONRESULT_H
#define SDIZO_PROJECT_1_ACTIONRESULT_H


class ActionResult {
public:
    enum result {
        END = 0,
        MENU = 6,
        LOAD_DATA_FILE = 1,
        DYNAMIC_ARRAY = 2,
        LIST_BIDIRECTIONAL = 3,
        BINARY_HEAP = 4,
        BST_TREE = 5
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

    ActionResult();

    virtual ~ActionResult();
};


#endif //SDIZO_PROJECT_1_ACTIONRESULT_H

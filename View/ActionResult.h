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

    ActionResult();

    virtual ~ActionResult() = default;
};


#endif //SDIZO_PROJECT_1_ACTIONRESULT_H

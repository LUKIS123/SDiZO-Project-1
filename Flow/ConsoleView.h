//
// Created by lukas on 02.04.2023.
//

#ifndef SDIZO_PROJECT_1_CONSOLEVIEW_H
#define SDIZO_PROJECT_1_CONSOLEVIEW_H

#include "ActionResult.h"

class ConsoleView {
public:
    ConsoleView();

    virtual ~ConsoleView();

    static ActionResult::result menu();

    static ActionResult::arrayResult arrayMenu();

    static ActionResult::automaticTestResult testMenu();

    static ActionResult::listResult listMenu();

    static ActionResult::heapResult heapMenu();

    static ActionResult::bstResult bstMenu();
};

#endif //SDIZO_PROJECT_1_CONSOLEVIEW_H

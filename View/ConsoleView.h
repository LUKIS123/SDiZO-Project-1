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

    static ActionResult::result arrayMenu();

    static ActionResult::result listMenu();

    static ActionResult::result heapMenu();
};

#endif //SDIZO_PROJECT_1_CONSOLEVIEW_H

//
// Created by lukas on 02.04.2023.
//

#ifndef SDIZO_PROJECT_1_APPCONTROLLER_H
#define SDIZO_PROJECT_1_APPCONTROLLER_H

#include "ConsoleView.h"
#include "ActionResult.h"

class AppController {
private:

public:

    AppController();

    virtual ~AppController();

    void index(const ConsoleView &consoleView);

    ActionResult::result loadFile();
};


#endif //SDIZO_PROJECT_1_APPCONTROLLER_H

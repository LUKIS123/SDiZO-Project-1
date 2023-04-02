//
// Created by lukas on 02.04.2023.
//

#include "conio.h"
#include "iostream"
#include "AppController.h"
#include "ActionResult.h"
#include "ConsoleView.h"

AppController::~AppController() {

}

AppController::AppController() {

}

void AppController::index(const ConsoleView &consoleView) {
    ActionResult::result status = ActionResult::result::MENU;
    while (status != ActionResult::result::END) {
        switch (status) {
            case ActionResult::result::MENU:
                status = ConsoleView::menu();
                break;
            case ActionResult::result::LOAD_DATA_FILE:
                status = loadFile();
                break;
            case ActionResult::result::DYNAMIC_ARRAY:

                break;
            case ActionResult::result::LIST_BIDIRECTIONAL:

                break;
            case ActionResult::result::BINARY_HEAP:

                break;
        }
    }

}

ActionResult::result AppController::loadFile() {
    std::string fileName;
    std::cout << "Place file in ./Resources and enter file name:" << std::endl;
    std::cin >> fileName;
    return ActionResult::MENU;
}

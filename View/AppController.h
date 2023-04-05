//
// Created by lukas on 02.04.2023.
//

#ifndef SDIZO_PROJECT_1_APPCONTROLLER_H
#define SDIZO_PROJECT_1_APPCONTROLLER_H

#include "iostream"
#include "ConsoleView.h"
#include "ActionResult.h"
#include "../FileUtils/DataFileUtility.h"
#include "../DynamicArray.h"
#include "../ListBidirectional.h"

class AppController {
private:
    // Utils
    DataFileUtility fileUtility;
    std::list<int> dataList;

    // Data Structures
    DynamicArray dynamicArray;
    ListBidirectional listBidirectional;

public:
    explicit AppController(const DynamicArray &dynamicArray, const ListBidirectional &listBidirectional);

    virtual ~AppController();

    void index();

    ActionResult::result loadFileToBufferList();

    void arrayIndex();

    ActionResult::arrayResult loadArrayWithFileData();

    ActionResult::arrayResult displayArray();

    ActionResult::arrayResult pushFrontArray();

    ActionResult::arrayResult pushBackArray();

    ActionResult::arrayResult pushOnIndexArray();

    ActionResult::arrayResult popFrontArray();

    ActionResult::arrayResult popBackArray();

    ActionResult::arrayResult popOnIndexArray();

    ActionResult::arrayResult setOnIndexArray();

    ActionResult::arrayResult displaySizeArray();

    ActionResult::arrayResult removeAllArray();

    ActionResult::arrayResult findIndexOfArray();

    ActionResult::arrayResult findByIndexArray();

    void listIndex();

    ActionResult::listResult loadListWithFileData();

    ActionResult::listResult displayListFromFront();

    ActionResult::listResult displayListFromBack();

    ActionResult::listResult pushFrontList();

    ActionResult::listResult pushBackList();

    ActionResult::listResult pushOnIndexList();

    ActionResult::listResult popFrontList();

    ActionResult::listResult popBackList();

    ActionResult::listResult popOnIndexList();

    ActionResult::listResult findByIndexList();

    ActionResult::listResult findIndexOfList();

    ActionResult::listResult removeAllList();

    ActionResult::listResult displaySizeList();
};


#endif //SDIZO_PROJECT_1_APPCONTROLLER_H

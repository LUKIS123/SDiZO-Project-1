#include "iostream"
#include "ListBidirectional.h"
#include "DynamicArray.h"
#include "BinaryHeap.h"
#include "BinarySearchTree.h"

#include "Testing/Tests.h"
#include "RandomDataGenerator/RandomNumberGenerator.h"
#include "FileUtils/DataFileUtility.h"
#include "View/AppController.h"

void testList() {
    ListBidirectional list = *new ListBidirectional();
    if (list.popFront() == NULL) {
        std::cout << "NULL\n";
    }

    list.displayFromBack();

    list.pushFront(1);
    list.pushFront(22);
    list.pushFront(333);
    list.pushEnd(4444);
    list.pushEnd(5);
    list.pushEnd(6);
    list.displayFromFront();

    std::cout << "==========" << std::endl;
    list.pushEnd(99);
    list.displayFromFront();
    std::cout << "==========" << std::endl;
    list.pushOnIndex(1, 0);
    list.displayFromFront();
    std::cout << "==========" << std::endl;
    list.popFront();
    list.displayFromFront();
    std::cout << "==========" << std::endl;
    list.popEnd();
    list.displayFromFront();
    std::cout << "==========" << std::endl;
    std::cout << "==========>>>>>POP ON INDEX" << std::endl;
    list.popOnIndex(1);
    list.displayFromFront();
    std::cout << "==========" << std::endl;
    list.pushOnIndex(1, 55);
    list.displayFromFront();
    std::cout << "==========>> head , tail" << std::endl;
    std::cout << list.getHead()->data << ", " << list.getTail()->data << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << list.getByIndex(2)->data << ", " << list.getByValue(5)->data;

    std::cout << "==========" << std::endl;
    // do sprawdzenia!!!! szczegolowo
    // removeElement()
    list.removeElement(list.getByIndex(2));
    list.displayFromFront();
}

void testArray() {
    DynamicArray array = *new DynamicArray(0);
    array.display();

    array.pushFront(22);
    array.pushFront(92);
    array.pushEnd(33);
    array.display();
    std::cout << "==========" << std::endl;
    array.pushOnIndex(1, 34);
    array.display();
    array.popFront(); // git
    array.display();
    array.pushOnIndex(0, 55);
    array.pushOnIndex(2, 66);
    array.display();
    std::cout << "==========" << std::endl;
    array.popEnd();
    array.display();
    std::cout << "==========>>>" << std::endl;
    array.popOnIndex(2);
    array.display();
    array.pushOnIndex(3, 88);
    array.display();
    array.popOnIndex(0);
    array.display();
    std::cout << "==========>>>" << std::endl;
    array.setOnIndex(1, 4444);
    array.display();
}

void testHeap() {
    BinaryHeap heap = *new BinaryHeap(30000);
    heap.push(11);
    heap.push(22);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;
    heap.push(33);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;
    heap.push(12);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;
    heap.push(35);
    heap.push(66);
    heap.push(44);
    heap.push(77);
    heap.push(55);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;

    heap.pop(22);
    heap.display();
}

void testBST() {
    BinarySearchTree bst = *new BinarySearchTree();
    bst.push(10);
    bst.push(1);
    bst.push(19);
    bst.push(8);
    bst.push(3);
    bst.push(6);
    bst.push(55);
    bst.push(32);
    bst.display();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

//    testList();
//    testArray();



    // TODO kopiec do przemyslenia...
//    testHeap();

    testBST();

    //    TEST t = *new TEST;
    //    t.prnt();
    //RandomNumberGenerator generator = *new RandomNumberGenerator();
    //generator.setTests(100);
    //generator.generateWithSeed(44);
    //generator.generateNonDeterministic();

    DataFileUtility r = *new DataFileUtility;
    std::string s = "../Resources/test_data.txt";
    std::cout << "\n==========>>>\n" << std::endl;
    std::list<int> l = r.readData(s);

    auto l_front = l.begin();
    for (int i = 0; i < l.size(); i++) {
        std::cout << *l_front << std::endl;
        std::advance(l_front, 1);
    }

    std::string s2 = "../Resources/out.txt";
    std::string testS1 = "out.txt";
    std::string testS2 = "../Resources/";
    std::string testS3 = testS2 + testS1;
    r.saveData(l, testS3);


    ConsoleView consoleView = *new ConsoleView();
    AppController controller = *new AppController();
    controller.index(consoleView);

    return 0;
}

// sortowanie kopca ->
// budujemy kopiec typu max, nastepuje zamiana szczytu kopca z ostatnim elementem, obcinamy (traktujemy jako kopiec bez tego ostatniego elementu),
// przywracana jest wlasnosc kopca zmniejszonego, i--, szczyt zamieniany z przedostatnim elemetem
#include "iostream"
#include "ListBidirectional.h"
#include "DynamicArray.h"
#include "BinaryHeap.h"
#include "BinarySearchTree.h"

#include "Testing/Tests.h"
#include "RandomDataGenerator/RandomNumberGenerator.h"
#include "FileUtils/DataFileUtility.h"
#include "Flow/AppController.h"
#include "Time/Timer.h"

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

    list.pushFront(71);
    list.pushFront(72);
    list.pushFront(73);
    list.pushFront(74);
    list.pushFront(75);
    list.pushFront(76);
    list.pushFront(77);
    std::cout << "==========jhhjvvjj>> " << std::endl;
    list.displayFromFront();
    std::cout << "==========>>>>>pushElement ON INDEX" << std::endl;
    list.pushOnIndex(9, 2121);
    std::cout << list.getIndexOf(2121) << std::endl;
    list.displayFromFront();

    std::cout << "==========" << std::endl;
    // do sprawdzenia!!!! szczegolowo
    // removeElement()
    list.removeElement(list.getByIndex(2));
    list.displayFromFront();
}

void testArray() {
    DynamicArray array = *new DynamicArray();
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
    std::cout << *array.getByIndex(3) << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << array.getIndexOf(66) << std::endl;
    std::cout << "==========" << std::endl;
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

//    DataFileUtility r = *new DataFileUtility;
//    std::string s = "../Resources/test.txt";
//    std::cout << "\n==========>>>\n" << std::endl;
//    std::list<int> *l = r.readData(s);
//    std::list<int> list_test = *l;
//    std::cout << list_test.size() << std::endl;
//    heap.loadFileDataAndHeapify(list_test);
//    heap.display();
//    return;

//    heap.pushElement(11);
//    heap.pushElement(22);
//    heap.display();
//    std::cout << "==========>>>\n" << std::endl;
//    heap.pushElement(33);
//    heap.display();
//    std::cout << "==========>>>\n" << std::endl;
//    heap.pushElement(12);
//    heap.display();
//    std::cout << "==========>>>\n" << std::endl;
//    heap.pushElement(35);
//    heap.pushElement(66);
//    heap.pushElement(44);
//    heap.pushElement(77);
//    heap.pushElement(55);
//    heap.pushElement(56);
//    heap.pushElement(57);
//    heap.pushElement(58);
//    heap.pushElement(59);
//    heap.pushElement(60);
//    heap.pushElement(61);
//    heap.pushElement(62);
//    heap.pushElement(63);
//    heap.pushElement(6534);
//    heap.pushElement(6543);
//    heap.pushElement(6354);
//    heap.pushElement(633);

    heap.push(11);
    heap.push(22);
    heap.push(33);
    heap.push(34);
    heap.push(35);
    heap.push(36);
    heap.display();
    heap.pop(34);
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
    heap.push(56);
    heap.push(57);
    heap.push(58);
    heap.push(59);
    heap.push(60);
    heap.push(61);
    heap.push(62);
    heap.push(63);
    heap.push(6534);
    heap.push(6543);
    heap.push(6354);
    heap.push(633);

    heap.display();
    std::cout << "==========>>>\n" << std::endl;

    // TODO; Nie wiem czy popElement dziala poprawnie, raczej zrezygnowac
    //  ewentualnie dodac metode heapyfy rekurencyjna i zastapic tym

    std::cout << heap.getSize() << std::endl;

    heap.pop(60);
    heap.display();
}

void testBST() {
    // 4.0 dodawanie, usuwanie i wyszukiwanie elementów, nie jest wymagane równoważenie drzewa
    BinarySearchTree bst = BinarySearchTree();
    bst.push(10);
    bst.push(1);
    bst.push(19);
    bst.push(8);
    bst.push(3);
    bst.push(6);
    bst.push(55);
    bst.push(32);
    bst.display();
    std::cout << "\n==============================" << std::endl;
    bst.display2D();
    std::cout << "==============================" << std::endl;
    bst.display();
    std::cout << "\n==============================" << std::endl;
    std::cout << "==============================" << std::endl;
    bst.pop(6);
    std::cout << bst.findByValue(32)->key << std::endl;
    bst.display();
    std::cout << "\n==============================" << std::endl;
    std::cout << "==============================" << std::endl;
    bst.rotateRight(10);
    bst.displayBothVariants();
    std::cout << "\n==============================" << std::endl;
    bst.rotateLeft(19);
    bst.displayBothVariants();
    std::cout << "\n==============================" << std::endl;
    bst.balanceTreeDSW();
    bst.displayBothVariants();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

//    testList();
//    testArray();

// TODO kopiec do przemyslenia...
//    testHeap();


//    testBST();
//
//    system("pause");

//======================================================================================================================
//        TEST t = *new TEST;
//        t.prnt();

//    RandomNumberGenerator generator = *new RandomNumberGenerator();
//    auto list_test1 = generator.generateWithSeed(123, 1000000);
//    auto ltest1_front = list_test1->begin();
//    std::advance(ltest1_front, 4);
//    std::cout << *ltest1_front << '\n';
//    std::cout << list_test1->size();

//    DataFileUtility r = *new DataFileUtility;
//    std::string s = "../Resources/test.txt";
//    std::cout << "\n==========>>>\n" << std::endl;
//    std::list<int> *l = r.readData(s);
//    std::list<int> list_test = *l;
//
//    auto l_front = list_test.begin();
//    for (int i = 0; i < list_test.size(); i++) {
//        std::cout << *l_front << std::endl;
//        std::advance(l_front, 1);
//    }
//
//    std::string s2 = "../Resources/out.txt";
//    std::string testS1 = "out.txt";
//    std::string testS2 = "../Resources/";
//    std::string testS3 = testS2 + testS1;
//    r.saveData(list_test, testS3);
//======================================================================================================================

//    long long int time_start_test = Timer::read_QPC();
//    Sleep(1);
//    long long int time_end_test = Timer::read_QPC();
//    Timer::getSeconds(time_start_test, time_end_test);
//    Timer::getMilliSeconds(time_start_test, time_end_test);
//    Timer::getMicroSecondsAndPrint(time_start_test, time_end_test);

    AppController controller = AppController();
    controller.index();

    // TODO: zabezpiczyc program w kontrolerze przed wpisaniem zlych wartosci np ujemny indeks tab
    //  dodac zabezpieczenie w funckjach struktur np ujemny indeks zeby nie przeszedl

    return 0;
}

// sortowanie kopca ->
// budujemy kopiec typu max, nastepuje zamiana szczytu kopca z ostatnim elementem, obcinamy (traktujemy jako kopiec bez tego ostatniego elementu),
// przywracana jest wlasnosc kopca zmniejszonego, i--, szczyt zamieniany z przedostatnim elemetem
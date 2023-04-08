//
// Created by lukas on 01.04.2023.
//

#ifndef SDIZO_PROJECT_1_TESTS_H
#define SDIZO_PROJECT_1_TESTS_H

class Tests {
    //Zmienne
    const static int number = 1000;
    double loading[number];
    double saving[number];
    double deletech[number];
    double deletelast[number];
    double deletefirst[number];
    double deleteall[number];
    double addch[number];
    double addfirst[number];
    double addlast[number];
    double finder[number];

    int ldnumber = 0;
    int svnumber = 0;
    int dchnumber = 0;
    int dlnumber = 0;
    int dfnumber = 0;
    int danumber = 0;
    int achnumber = 0;
    int afnumber = 0;
    int alnumber = 0;
    int fnumber = 0;

    int size = 0;
    bool tests = false;
    bool automatic = false;
    int quantity = 1000;

};


#endif //SDIZO_PROJECT_1_TESTS_H

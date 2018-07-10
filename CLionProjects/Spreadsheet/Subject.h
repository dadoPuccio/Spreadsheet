//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_SUBJECT_H
#define SPREADSHEET_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void addObserver(const Observer* ob) = 0;
    virtual void removeObserver(const Observer* ob) = 0;
    virtual void notify() = 0;
};


#endif //SPREADSHEET_SUBJECT_H
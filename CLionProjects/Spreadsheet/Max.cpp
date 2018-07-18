//
// Created by davide on 17/07/18.
//

#include "Max.h"

Max::Max(MySpreadsheet *s): subjPtr(s) {
    subjPtr->addObserver(this);
}

Max::~Max() {
    subjPtr->removeObserver(this);
}

void Max::compute() {
    double max = 0;
    bool b = true;
    int i = 0;

    while (i < subjPtr->getNumOfCells() && b) {
        if (!subjPtr->getCellsValues()[i].isEmpty) {
            max = subjPtr->getCellsValues()[i].value;
            b = false;
        }
        i++;
    }

    if (b)
        subjPtr->results[2]->ChangeValue(wxT("No values"));

    else {
        while (i < subjPtr->getNumOfCells()) {

            if (!subjPtr->getCellsValues()[i].isEmpty)
                if (subjPtr->getCellsValues()[i].value > max)
                    max = subjPtr->getCellsValues()[i].value;
            i++;
        }

        wxString str = wxString::Format(wxT("%lf"), max);
        subjPtr->results[2]->ChangeValue(str);

    }
}

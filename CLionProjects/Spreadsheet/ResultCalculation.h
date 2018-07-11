//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_DATACALCULATION_H
#define SPREADSHEET_DATACALCULATION_H

#include "MySpreadsheet.h"

class ResultCalculation : public Observer {
public:
    explicit ResultCalculation(MySpreadsheet *su);

    ~ResultCalculation() override;
    void update() override;

    void media();

private:
    MySpreadsheet *subjPtr;
};


#endif //SPREADSHEET_DATACALCULATION_H

//
// Created by davide on 10/07/18.
//

#include <algorithm>
#include "ResultCalculation.h"

ResultCalculation::ResultCalculation(MySpreadsheet* su) : subjPtr(su) {
    cellsValues = new double[subjPtr->getNumOfCells()];
    for(int i = 0; i < subjPtr->getNumOfCells();i++)
        cellsValues[i] = 0;
    subjPtr->addObserver(this);
}

ResultCalculation::~ResultCalculation() {
    subjPtr->removeObserver(this);
    delete[] cellsValues;
}

void ResultCalculation::update() {


    double somma = sum();
    media(somma);
    max();
    min();
    mediana();

}

double ResultCalculation::sum() {


    return sum;
}

void ResultCalculation::media(double sum) {

    int count = 0;

    for (int i = 0; i < subjPtr->getNumOfCells(); i++) {
        if (checkString(i))
            count++;
    }

    if (count != 0) {
        double media = sum / count;
        wxString str = wxString::Format(wxT("%lf"), media);
        subjPtr->results[1]->ChangeValue(str);
    } else
        subjPtr->results[1]->ChangeValue(wxT("No values"));

}

void ResultCalculation::max() {

    double max = 0;
    bool b = true;

    for (int i = 0; i < subjPtr->getNumOfCells() && b; i++) {
        if (checkString(i)) {
            max = cellsValues[i];
            b = false;
        }
    }

    if (!b) {
        for (int i = 0; i < subjPtr->getNumOfCells(); i++) {
            if (checkString(i))
                if (cellsValues[i] > max)
                    max = cellsValues[i];
        }

        wxString str = wxString::Format(wxT("%lf"), max);
        subjPtr->results[2]->ChangeValue(str);

    } else
        subjPtr->results[2]->ChangeValue(wxT("No values"));

}

void ResultCalculation::min() {

    double min = 0;
    bool b = true;

    for (int i = 0; i < subjPtr->getNumOfCells() && b; i++) {
        if (checkString(i)) {
            min = cellsValues[i];
            b = false;
        }
    }

    if (!b) {
        for (int i = 0; i < subjPtr->getNumOfCells(); i++) {
            if (checkString(i)) {
                if (cellsValues[i] < min)
                    min = cellsValues[i];
            }
        }
        wxString str = wxString::Format(wxT("%lf"), min);
        subjPtr->results[3]->ChangeValue(str);

    } else
        subjPtr->results[3]->ChangeValue(wxT("No values"));

}

void ResultCalculation::mediana() {

    double mediana = 0;
    std::vector<double> v;

    for (int i = 0; i < subjPtr->getNumOfCells(); i++)
        if (checkString(i))
            v.push_back(cellsValues[i]);

    std::sort(v.begin(), v.end());
    unsigned long size = v.size();

    if (size == 0)
        subjPtr->results[4]->ChangeValue(wxT("No values"));

    else if (size % 2 == 0) {
        mediana = (v[size / 2 - 1] + v[size / 2]) / 2;
        wxString str = wxString::Format(wxT("%lf"), mediana);
        subjPtr->results[4]->ChangeValue(str);

    } else {
        mediana = v[size / 2];
        wxString str = wxString::Format(wxT("%lf"), mediana);
        subjPtr->results[4]->ChangeValue(str);
    }

}

bool ResultCalculation::checkString(int i) {

    wxString str = subjPtr->cells[i]->GetValue();

    if (!str.IsEmpty() && str != wxT("-"))
        return true;
    else
        return false;
}



#include "main.h"
#include "Sum.h"
#include "Media.h"
#include "Max.h"
#include "Min.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    MySpreadsheet* ptr = new MySpreadsheet(wxT("Spreadsheet"));
    auto sum = new Sum(ptr);
    auto media = new Media(ptr);
    auto max = new Max(ptr);
    auto min = new Min(ptr);
    ptr->Show(true);

    return true;
}

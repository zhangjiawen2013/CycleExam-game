#include"function_1.h"
int main()
{
    system("chcp 65001");
    // Generate log filename: YYYYMMDD_HHMMSS.log (based on program start time)
    time_t now = time(nullptr);                 // get current timestamp
    tm* local_time = localtime(&now);           // convert to local time struct
    char filename[64];
    strftime(filename, sizeof(filename), "%Y%m%d_%H%M%S.log", local_time); // format

    fout.open(filename);                         // open file
    if (!fout.is_open()) 
    {
        cerr << "Warning: Unable to create log file " << filename << endl;
    }
    string current_page = "page_main";
    while(true)
    {
        auto &inf = pageMap[current_page];
        inf.function();
        
        int switchs = getNum(1, inf.jump_pages.size() - 1); // get choice
        if(switchs)
        {
            system("cls");
        }
        current_page = inf.jump_pages[switchs];
    }
}
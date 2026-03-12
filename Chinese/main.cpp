#include"function_1.h"
int main()
{
    system("chcp 65001");
    // 生成日志文件名：YYYYMMDD_HHMMSS.log（以程序启动时间为准）
    time_t now = time(nullptr);                 // 获取当前时间戳
    tm* local_time = localtime(&now);           // 转换为本地时间结构
    char filename[64];
    strftime(filename, sizeof(filename), "%Y%m%d_%H%M%S.log", local_time); // 格式化

    fout.open(filename);                         // 打开文件
    if (!fout.is_open()) 
    {
        cerr << "警告：无法创建日志文件 " << filename << endl;
    }
    string current_page = "page_main";
    while(true)
    {
        auto &inf = pageMap[current_page];
        inf.function();
        
        int switchs = getNum(1, inf.jump_pages.size() - 1);//获取选项
        if(switchs)
        {
            system("cls");
        }
        current_page = inf.jump_pages[switchs];
    }
}
#ifndef FUNCTION_1_H
#define FUNCTION_1_H
//导入库 
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<limits>
#include<string>
#include<map>
#include<vector>
#include<functional>
#include<variant>
#include<ctime>  
//声明命名空间 
using namespace std;
//声明函数
int getNum(int min,int max);//输入校验函数
void page_main();//游戏主菜单
void page_intro();//游戏简介
void page_setting();//游戏设置
void page_changeLog(); //版本更新日志
void page_1();//游戏开始剧情
void page_2();//睡过头了
void page_3();//继续睡觉1
void page_4();//继续睡觉2
void page_5();//结局：不醒人室（Bed End 1）
void page_6();
void page_7();
void page_8();
void page_9();
void page_10();
void page_11();
void page_12();
void page_13();
void page_14();
void page_15();
void page_16();
void page_17();
void page_18();
void page_19();
void page_20();
void page_21();
void page_22();
void page_23();
void page_24();
void page_25();
void page_26();
void page_27();
void page_28();
void page_29();
void page_30();
void page_31();
void page_32();
void page_33();
void page_34();
void page_35();
void page_36();
void page_37();
void page_38();
void page_39();
void page_40();
void page_41();
void page_42();
void page_43();
void page_44();
void page_45();
void page_46();
void page_47();
void page_48();
void page_49();
void page_50();
void page_51();
void page_52();
void page_53();
void page_54();
void page_55();
void page_56();
void page_57();
void page_58();
void page_59();
void page_60();
void page_61();
void page_62();
void page_63();
void page_64();
void page_65();
void page_66();
void page_67();
void page_68();
void page_69();
void page_70();
void page_71();
void page_72();
void page_73();
void page_74();
void page_75();
void page_76();
void page_77();
void page_78();
void page_79();
void page_80();
void page_81();
void page_82();
void page_83();
void page_84();
void page_85();
void page_86();
void page_87();
void page_88();
void page_89();
void page_90();
void page_91();
void page_92();
void page_93();
void page_94();
void page_95();
void page_96();
void page_97();
void page_98();
void page_99();
void page_100();
//定义全局变量 
int switchs;
int sleepSubjects=0;
bool inPageMain=true;
ofstream fout; // 全局文件输出流
//定义函数及结构体
struct PageInformation{
    std::function<void ()> function;
    std::vector<std::string> jump_pages;
};
// 代理类，同时持有 cout 和 fout 两个输出流
class CFOut {
private:
    ostream& os1;
    ostream& os2;
public:
    CFOut(ostream& o1,ostream& o2) : os1(o1), os2(o2) {}

    // 泛型 operator<<，处理所有可输出类型
    template<typename T>
    CFOut& operator<<(const T& val) {
        os1<<val;
        os2<<val;
        return *this;
    }

    // 专门处理 endl 等操纵符
    CFOut& operator<<(ostream& (*manip)(ostream&)) {
        os1<<manip;
        os2<<manip;
        return *this;
    }
};
// 宏定义：cfout 展开为临时 CFOut 对象，绑定 cout 和 fout
#define cfout CFOut(cout, fout)
int getNum(int min,int max) //输入校验函数（参数为可输入的最小值和最大值）
{
    int n;
    // 输入不是数字 或 超出范围 → 重新输入
    if(!(cin>>n)||n<min||n>max)
	{
        cin.clear(); // 重置输入缓冲区
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 丢弃错误输入
        system("cls");
        cfout<<"只能输入"<<min<<"-"<<max<<"的数字！\n\n";
        return 0; // 返回0标记输入错误（执行default）
    }
    return n; // 输入有效则返回选项编号
}
void page_main()//游戏主菜单 
{
	inPageMain=true;
	cfout<<"********************\n";
    cfout<<"*                  *\n";
    cfout<<"*     轮回答卷     *\n";
    cfout<<"*                  *\n";
    cfout<<"*       26w11a pre2*\n";
    cfout<<"********************\n";
    cfout<<"[1]开始游戏[2]游戏简介[3]游戏设置[4]更新日志[5]退出游戏\n";
}
void page_exit()
{
    if(inPageMain)
	{
		cfout<<"游戏已正常退出，退出代码为0";
		exit(0);
	} 
}
void page_intro()//游戏简介 
{
	inPageMain=false;
	cfout<<"我是简介，但作者懒的写简介，嗯对\n";
    cfout<<"[1]回到主菜单\n";
}
void page_setting()//游戏设置 
{
	inPageMain=false;
	cfout<<"我是设置，但作者还没想好怎么做做设置，嗯对\n";
    cfout<<"[1]回到主菜单\n";
}
void page_changeLog()//版本更新日志
{
    inPageMain=false;
	string relativePath="changeLog.md"; 
    char absolutePath[MAX_PATH]={0};
    DWORD pathLen=GetFullPathNameA(relativePath.c_str(),MAX_PATH,absolutePath,NULL);//相对路径->绝对路径
    ifstream logFile(relativePath); //尝试打开日志文件
    string line; 
    if (logFile.is_open()) //判断日志文件是否成功打开
	{ 
        cfout<<"==================== 版本更新日志 ====================\n";
        while (getline(logFile,line)) //逐行读取日志内容
		{
            cfout<<line<<endl; 
        }
        logFile.close(); 
    } 
	else//无法打开日志文件
	{ 
        cfout<<"无法读取更新日志文件！\n";
        if (pathLen>0) 
		{
            cfout<<"文件绝对路径："<<absolutePath<<"\n";
        } 
		else 
		{ 
            cfout<<"文件相对路径："<<relativePath<<"\n";
        }
        cfout<<"请检查更新日志(changeLog.md)是否存在于主程序(main.exe)同目录下或已通过其他途径打开！\n";
    }
    cfout<<"==================================================\n";
    cfout<<"[1]回到主菜单\n";
}
void page_1()//游戏开始剧情 
{
	inPageMain=false;
	cfout<<"叮铃铃铃！\n";
    cfout<<"闹钟响了，你从睡梦中醒来\n";
    cfout<<"你伸了个懒腰，睁开了眼\n";
    cfout<<"一个美丽的早晨，但天阴阴沉沉的，像是要下雨一样\n";
    cfout<<"你突然想起来今天要中考了，但还有半小时就要开考第一科了，你决定\n";
    cfout<<"[1]再睡一会 [2]立刻前往学校\n";
}
void page_2()//睡过头了
{
	sleepSubjects++;
	cfout<<"你已经睡过一个科目了\n";
    cfout<<"趁现在起床去考试也许还能拿一些分数\n";
    cfout<<"但你又想着这床如此舒服，而且就算起床也不会有好的成绩，你决定\n";
    cfout<<"[1]继续睡觉 [2]立刻前往学校\n";
}
void page_3()//继续睡觉1
{
	sleepSubjects++;
	cfout<<"你真是个睡神\n";
    cfout<<"吉尼斯世界纪录都应该给你颁个奖\n";
    cfout<<"但现在说这些又有什么用呢\n";
    cfout<<"你又睡过了一个科目\n";
    cfout<<"现在已经没有什么去考试的意义了，你决定\n";
    cfout<<"[1]继续睡觉 [2]立刻前往学校\n";
}
void page_4()//继续睡觉2
{
	sleepSubjects++;
	cfout<<"睡神，你赢了\n";
    cfout<<"三场考试都已经结束了\n";
    cfout<<"而你却还在床上舒服的躺着\n";
    cfout<<"现在绝对没有再去考试的必要性了，你决定\n";
    cfout<<"[1]继续睡觉 [2]立刻前往学校\n";
}
void page_5()//结局：不醒人室（Bed End 1）
{
	cfout<<"你不禁对自己发问\n";
    cfout<<"这样做有什么意义吗\n";
    cfout<<"与其浪费时间，不如去考场随便蒙两道题\n";
    cfout<<"但现在说什么也没用了\n";
    cfout<<"考试已经结束了，你完全没有做哪怕一题\n";
    cfout<<"你突然想起你之前玩的某个六字游戏的一句话...\n";
    cfout<<"--------------------------------------------------\n";
	cfout<<"----------达成结局Bed End 1 【不醒人室】----------\n";
	cfout<<"--------愿此行，终抵群星，且容我，再睡一会--------\n";
	cfout<<"--------------------------------------------------\n";
	cfout<<"[1]回到主菜单\n";
}
/*void page_6()//前往学校
{
	cfout<<"\n";
}*/

map<string, PageInformation> pageMap=
{
    {"page_main", {page_main, {"page_main", "page_1", "page_intro", "page_setting", "page_changeLog", "page_exit"}}},
	{"page_exit", {page_exit, {"page_exit"}}},
    {"page_intro", {page_intro, {"page_intro", "page_main"}}},
	{"page_setting", {page_setting, {"page_setting", "page_main"}}},
	{"page_changeLog", {page_changeLog, {"page_changeLog", "page_main"}}},
    {"page_1", {page_1, {"page_1", "page_2"/*,"page_6"*/}}},
    {"page_2", {page_2, {"page_2", "page_3"/*,"page_6"*/}}},
    {"page_3", {page_3, {"page_3", "page_4"/*,"page_6"*/}}},
    {"page_4", {page_4, {"page_4", "page_5"/*,"page_6"*/}}},
    {"page_5", {page_5, {"page_5", "page_main"}}},
};
#endif
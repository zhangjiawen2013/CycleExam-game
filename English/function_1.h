#ifndef FUNCTION_1_H
#define FUNCTION_1_H
// include libraries
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
// use namespace
using namespace std;
// function declarations
int getNum(int min,int max); // input validation
void page_main(); // main menu
void page_intro(); // game intro
void page_setting(); // game settings
void page_changeLog(); // changelog display
void page_1(); // start story
void page_2(); // overslept
void page_3(); // keep sleeping 1
void page_4(); // keep sleeping 2
void page_5(); // ending: Bed End 1
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
// define global variables
int switchs;
int sleepSubjects=0;
bool inPageMain=true;
ofstream fout; // global file output stream
// define functions and structs
struct PageInformation{
    std::function<void ()> function;
    std::vector<std::string> jump_pages;
};
// proxy class holding both cout and fout streams
class CFOut {
private:
    ostream& os1;
    ostream& os2;
public:
    CFOut(ostream& o1,ostream& o2) : os1(o1), os2(o2) {}

    // generic operator<< for all output types
    template<typename T>
    CFOut& operator<<(const T& val) {
        os1<<val;
        os2<<val;
        return *this;
    }

    // specifically handle manipulators like endl
    CFOut& operator<<(ostream& (*manip)(ostream&)) {
        os1<<manip;
        os2<<manip;
        return *this;
    }
};
// macro: cfout expands to temporary CFOut object binding cout and fout
#define cfout CFOut(cout, fout)
int getNum(int min,int max) // input validation (min and max allowed)
{
    int n;
    // not a number or out of range -> retry
    if(!(cin>>n)||n<min||n>max)
	{
        cin.clear(); // reset input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // discard bad input
        system("cls");
        cfout<<"Please enter a number between "<<min<<" and "<<max<<"!\n\n";
        return 0; // return 0 to signal error (default case)
    }
    return n; // valid input
}
void page_main() // main menu
{
	inPageMain=true;
	cfout<<"********************\n";
    cfout<<"*                  *\n";
    cfout<<"*    CycleExam     *\n";
    cfout<<"*                  *\n";
    cfout<<"*       26w11a pre2*\n";
    cfout<<"********************\n";
    cfout<<"[1] Start [2] Intro [3] Settings [4] Changelog [5] Exit\n";
}
void page_exit()
{
    if(inPageMain)
	{
		cfout<<"Exiting game normally (code 0)";
		exit(0);
	} 
}
void page_intro() // game intro
{
	inPageMain=false;
	cfout<<"This is the intro, but the author was too lazy to write one. Yeah, really.\n";
    cfout<<"[1] Back to main menu\n";
}
void page_setting() // game settings
{
	inPageMain=false;
	cfout<<"This is the settings page, but the author hasn't figured out any settings yet. Yeah.\n";
    cfout<<"[1] Back to main menu\n";
}
void page_changeLog() // changelog display
{
    inPageMain=false;
	string relativePath="changeLog.md"; 
    char absolutePath[MAX_PATH]={0};
    DWORD pathLen=GetFullPathNameA(relativePath.c_str(),MAX_PATH,absolutePath,NULL); // relative to absolute path
    ifstream logFile(relativePath); // try to open changelog file
    string line; 
    if (logFile.is_open()) // check if file opened successfully
	{ 
        cfout<<"==================== Changelog ====================\n";
        while (getline(logFile,line)) // read lines from file
		{
            cfout<<line<<endl; 
        }
        logFile.close(); 
    } 
	else // failed to open file
	{ 
        cfout<<"Unable to read changelog file!\n";
        if (pathLen>0) 
		{
            cfout<<"Absolute path: "<<absolutePath<<"\n";
        } 
		else 
		{ 
            cfout<<"Relative path: "<<relativePath<<"\n";
        }
        cfout<<"Please check if changeLog.md exists in the same directory as main.exe or has been opened elsewhere!\n";
    }
    cfout<<"==================================================\n";
    cfout<<"[1] Back to main menu\n";
}
void page_1() // start story
{
	inPageMain=false;
	cfout<<"Ring ring ring!\n";
    cfout<<"The alarm clock goes off, waking you from your sleep.\n";
    cfout<<"You stretch and open your eyes.\n";
    cfout<<"It's a beautiful morning, but the sky is overcast, like it's about to rain.\n";
    cfout<<"Suddenly you remember today is the high school entrance exam, and the first subject starts in half an hour. You decide:\n";
    cfout<<"[1] Sleep a bit more [2] Head to school immediately\n";
}
void page_2() // overslept
{
	sleepSubjects++;
	cfout<<"You've already slept through one subject.\n";
    cfout<<"If you get up now, you might still score some points.\n";
    cfout<<"But the bed is so comfortable, and you think you won't do well anyway. You decide:\n";
    cfout<<"[1] Keep sleeping [2] Head to school immediately\n";
}
void page_3() // keep sleeping 1
{
	sleepSubjects++;
	cfout<<"You are truly a sleep god.\n";
    cfout<<"The Guinness World Records should award you a prize.\n";
    cfout<<"But what good does that do now?\n";
    cfout<<"You've slept through another subject.\n";
    cfout<<"Now there's no point in going to the exam. You decide:\n";
    cfout<<"[1] Keep sleeping [2] Head to school immediately\n";
}
void page_4() // keep sleeping 2
{
	sleepSubjects++;
	cfout<<"Sleep god, you win.\n";
    cfout<<"All three exams have ended.\n";
    cfout<<"Yet you're still lying comfortably in bed.\n";
    cfout<<"Now there's absolutely no point in going to the exam. You decide:\n";
    cfout<<"[1] Keep sleeping [2] Head to school immediately\n";
}
void page_5() // ending: Bed End 1
{
	cfout<<"You can't help but question yourself.\n";
    cfout<<"What's the point of this?\n";
    cfout<<"Instead of wasting time, you might as well go to the exam hall and guess a couple answers.\n";
    cfout<<"But it's too late now.\n";
    cfout<<"The exams are over, and you haven't answered a single question.\n";
    cfout<<"Suddenly you recall a line from a story game you played before...\n";
    cfout<<"--------------------------------------------------\n";
	cfout<<"Achieved Ending: Bed End 1 [The Unawakened One]\n";
	cfout<<"May this journey lead us starward, And let me sleep a little longer first.\n";
	cfout<<"--------------------------------------------------\n";
	cfout<<"[1] Back to main menu\n";
}
/*void page_6() // head to school
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
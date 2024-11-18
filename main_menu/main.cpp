/* copyright lc3124 release 2024
 * licence MIT
 * this file is used to boot the fraternityBroad's main_menu 
 */

//include files
//Va
//fr
#include "funs.cpp"

//std
#include <functional>
#include <vector>
#include <string>
#include <cmath>

//C
#include <unistd.h>

/************* pre ********/


int ScreenRows,ScreenCols;

void init_term()
{

    MyTerm->fastOutput(vacc::_cur_hide());
    MyTerm->fastOutput(vacc::_clear());
//MyTerm->disableEcho();
    //Get the size of Terminal size 
    MyTerm->getTerminalSize(ScreenRows,ScreenCols);
    //init the color of text
    Frontcolor = _16color::WHITE; 
    BackGroundcolor = _16color::BLACK; 
}
void reset_term()
{
MyTerm->fastOutput(vacc::_cur_show());
MyTerm->enableConsoleBuffering();
MyTerm->enableEcho();
}

/*********** main logic *************/

class options
{
    public:
        char* title;
        char* description;
        using Callback =std::function<void()>; 
        Callback jumpto;
        void TieUp(char* title,char* des,const Callback &funcAddr)
        {
            this->title =title;
            this->description =des;
            this->jumpto=funcAddr;
        }

};
std::vector<options>OptionsList;
int optionsPtr=0;

void initoptions()
{
    struct options newone;
    newone.TieUp(
            "Ascii Click Funcation",
            "translate dida to character",
            asciiclick
            );
    OptionsList.push_back(newone);
}

void drawer ()
{
    //print the welcome-words 
    mvprintb_color(1,0,_16color::BLUE,BackGroundcolor,"你好，Ts");
    gettime();
    char *nowtime = get_return();
    mvprintb_color(1,20,_16color::RED,BackGroundcolor,nowtime);

    //print the options
    mvprintb(2,0,"你已成功连接，面板尚在开发中");
    //mvprintb(2,0,OptionsList.at(0).title);
    //print other things
    mvprintb_color(3,0,_16color::GREEN,BackGroundcolor,"按下<P>退出   ");
    mvprintb(3,0,"");

    flushb();
}

void chooseer()
{
    while(true)
    {
        char vk=-1;

   vk =  MyTerm->keyPressed();

        usleep(3000);  
        drawer();

        if(vk!=-1)
        {
            if(vk=='p'||vk=='P'){
            break;
            };            
    }
}
}

int main()
{
    init_term();
    initoptions();
    chooseer();
    //drawer();
    reset_term();
    MyTerm->enableEcho();
    delete MyTerm;
    return 0;
}

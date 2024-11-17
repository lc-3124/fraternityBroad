#pragma once
#include "fun_enum.hpp"
#include <vector>

/********************************************/
//the stack of funcations' return varlue
std::vector<char*> funs_return_var;

//push a varlue
void func_return(char* addr)
{
    funs_return_var.clear();
    funs_return_var.push_back(addr);
}

//pop one 
char* get_return()
{
    char *var = funs_return_var.back();
    funs_return_var.pop_back();
    return var;
}

//get the time ,and return a string
#include <ctime>
void gettime()
{
    //get the time
    time_t now = time(0);
    char* dt = ctime(&now);

    //return
    func_return(dt);
}



/********************************************/
#include <VaTermControl.hpp>
#include <VaColorControl.hpp>
//drawing
#include <string>
//the drawing buffer 
std::string ScreenBuffer;
vatc *MyTerm = new vatc();

color256 Frontcolor,BackGroundcolor;
//drawing 
void printb(char *str)
{
    ScreenBuffer+=vacc::_set_color256(Frontcolor,BackGroundcolor);
    ScreenBuffer+=str;
}
void printb_color(color256 front,color256 back,char *str)
{
    ScreenBuffer+=vacc::_set_color256(front,back);
    ScreenBuffer+=*str;
}
void mvprintb(int y,int x,char *str)
{
    ScreenBuffer+=vacc::_cur_moveto(y,x);
    ScreenBuffer+=str;
}
void mvprintb_color(int y,int x,color256 front,color256 back,char *str)
{
    ScreenBuffer+=vacc::_cur_moveto(y,x);
    ScreenBuffer+=vacc::_set_color256(front,back);
    ScreenBuffer+=str;

}
void flushb()
{
    MyTerm->fastOutput(vacc::_set_color256(Frontcolor,BackGroundcolor));
    MyTerm->fastOutput(vacc::_clear());
    MyTerm->fastOutput(vacc::_cur_moveto(0,0));
    MyTerm->fastOutput(ScreenBuffer.c_str());
    ScreenBuffer.clear();
}


/********************************************/
void asciiclick(void)
{
    std::system("~/works/fraternityBroad/build/asciiclick");
}


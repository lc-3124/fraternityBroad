#include <iostream>
#include <string>

#include <VaTermControl.hpp>
#include <VaColorControl.hpp>



int addbit(int index)
{
    int cnt=1;
    for(int i=0;i<index;i++)
    {
        cnt*=2;
    }
    return cnt;
}

std::string str;
vatc *Myterm = new vatc();

int cnt=1;

void drawtext()
{
    Myterm->fastOutput(vacc::_set_color256(_16color::WHITE,_16color::BLACK));
    Myterm->fastOutput(vacc::_clear());
    Myterm->fastOutput(vacc::_cur_moveto(0,0));

    Myterm->fastOutput("\n");
    Myterm->fastOutput(str.c_str());
    Myterm->fastOutput("                      ");

    Myterm->fastOutput(vacc::_set_color256(_16color::BLUE,_16color::BLACK));
    Myterm->fastOutput(vacc::_cur_moveto(0,0));
}

int main()
{
    while(1)
    {
        cnt=0;

        drawtext();

        char vk = Myterm->nonBufferedGetKey();

        if(vk == 'n'){
            cnt += addbit(6);
            Myterm->fastOutput("1");
        }

        else if (vk == 'j'){
            //do no thing
            Myterm->fastOutput("0");
        }
        else{
            str.pop_back();
            Myterm->fastOutput(vacc::_clear());
            continue;
        }
        int i=6;
        for(;i>0;i--)
        {
            vk = Myterm->getCharacter();
            if(vk == 'n')
            {
                Myterm->fastOutput("1");
                cnt+=addbit(i-1);    
            }
            else if(vk == 'j')
            {
                Myterm->fastOutput("0");
            }
            else{
                Myterm->fastOutput(vacc::_clear());
                break;
            }

        }


        if(i==0)
        {
        str.push_back(static_cast<char>(cnt));
        }
    }
    return 0;
}

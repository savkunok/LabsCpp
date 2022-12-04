#pragma once
#include "computer.h"
namespace MySpace {
    class PersonalComp : public computer {
    private:
        int cost;
    public:
        PersonalComp();
        PersonalComp(int cost,string forComputer,string forCPU, string forMemory,string forWinchester,string forProgramme,string ForRAM );
        ~PersonalComp();
        void showInfo();
    };
}
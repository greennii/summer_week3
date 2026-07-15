#pragma once
#include "timeOfDay.h"
#include <string>
namespace JeongYoonha2449101


{
    class alarm

    {
    std::string name;   //alarm name add  
    timeOfDay wakeTime;
    bool inActive;

    public:
    alarm(const std::string& n = "no name yet",
        timeOfDay t = timeOfDay{17,17}, bool a = false)
        :name{n}, wakeTime{t}, inActive{a}{}
    void print() const
    {
       std::cout << name << " " ;
        wakeTime.print(); //timeOfDay's print()
       std::cout << " alarm is " << ((inActive) ? "on" : "off") << std::endl;
       
    }
    friend std::ostream& operator << (std::ostream& os, const alarm& a)
    {
        
        os << a.name << " ";
        os << a.wakeTime; //timeOfDay's output dustkswk
        os << " alarm is " << ((a.inActive) ? "on" : "off") << "\n";
        
        
        return os;
    }



    void input()
    {
        std::cout << "Enter the alarm name: ";
        std::getline(std::cin >> std::ws, name);
        wakeTime.input();  //std::cin >> name;
        std::cout << "Enter 1 or 0(on / off): ";
        std::cin >> inActive;
    }
    friend std::istream& operator >> (std::istream& is, alarm& a)
    { //std::cin --> is
        std::cout << "Enter alarm name: ";
        std::getline(is >> std::ws, a.name);
        is >> a.wakeTime;  //timeofDay's input dustkswk
        std::cout << "Enter 1 or 0 (on/off): ";
        is >> a.inActive;
           //friend part if timeOfDay is added
        
        
        return is;
    }
    
    const std::string& getName() const
    {
        return name;
    }
    const timeOfDay& getWakeTime() const
    {
        return wakeTime;
    }
    bool getActive() const 
    {
        return inActive;
    }

    void setName(const std::string& n){name = n;} 
    
    
    void setWakeTime(const timeOfDay& t)
    {
        
        wakeTime = t;
    }


    void setActive(bool b){inActive = b;}
    };
    

}
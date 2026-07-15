#pragma once
#include <iostream>
#include <iomanip>
namespace JeongYoonha2449101

{
    class timeOfDay
    {
        int hour{};
        int minute{};

        void testHour()
        {
            if ((hour < 0) || (hour > 23))
            {
                std::cout << "Illegal hour value!!\n";
                std::exit(1);
            }
        }
        void testMinute()
        {
            if ((minute < 0) || (minute > 59))
            {
                std::cout << "Illegal minute value!!\n";
                std::exit(1);
            }
        }

    public:
        timeOfDay(int hourValue = 0, int minuteValue = 0)
        :hour{hourValue}, minute{minuteValue}
        {
            testHour();
            testMinute();
        }
        
        void input()
        {
            std::cout << " Enter the hour: ";
            std::cin >> hour;
            testHour();
            std::cout << " Enter the minute: ";
            std::cin >> minute;
            testMinute();
        }

        void setHour( int hourValue) {hour = hourValue; testHour();}
        void setMinute(int minuteValue) { minute = minuteValue; testMinute();}
        void print(std::ostream& os = std::cout) const
    
        {
            os << std::setw(2) <<std::setfill('0') << hour << ':';
            os << std::setw(2) <<std::setfill('0') << minute << ':';
        }
        int getHour() const 
        {
            return hour;
        }
        int getMinute() const
        {
            return minute;
        }

        //void output 

    
        timeOfDay& operator++()   //wjsdnlwmdrkdustkswk
        {
            ++minute; //minute = minute +1; minute += 1;
            if( minute == 60 )
                {
                    minute = 0;
                    ++hour; //hour = hour +1;
                }
    
            if( hour == 24 )
                {
                    hour = 0;
                    
                }
            return *this;  //minute +1 : 0~59 -->minute(0), hour +1
                                 //hour: 0~23 --> hour(0)
         }
        timeOfDay operator++(int)  //chage using 'this'
        {
            
            timeOfDay temp{*this};
            ++(*this); //minute = minute +1; minute += 1;
            
            // if( minute == 60 )
            //     {
            //         minute = 0;
            //         ++hour; //hour = hour +1;
            //     }
    
            // if( hour == 24 )
            //     {
            //         hour = 0;
                    
            //     }  //changed with *this so this section useless
    
            return temp;
         
        }
    
        timeOfDay& operator+=(int m)
        {
           minute += m;
           if(minute >= 60) {hour += minute/60; minute %= 60;}
           if(hour >= 24){hour %= 24;} 
            return *this;
        }
        
        
        friend std::istream& operator>>(std::istream& is, timeOfDay& t)
        {   //input(std::cin) --> is, t.hour, t.minute
            std::cout << " Enter the hour: ";
            is >> t.hour;
            t.testHour();
            std::cout << " Enter the minute: ";
            is >> t.minute;
            t.testMinute();
            return is;
        }
    
        friend std::ostream& operator<<(std::ostream& os, const timeOfDay& t)
        {   
            os.width(2); os.fill('0');
            os << t.hour << ":";
            os << std::setw(2) << std::setfill('0') <<t.minute;       
            return os;
        }
    
        friend bool operator==(const timeOfDay& t1, const timeOfDay& t2)
        {
            return t1.hour == t2.hour && t1.minute == t2.minute;
                       //true or false i choose and make
        }
    
        friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2)
        {   
            int minute1{t1.hour*60 + t1.minute};
            int minute2{t2.hour*60 + t2.minute};
            int totalMinute{minute1 + minute2};
            int newMinute{totalMinute % 60};
            int newHour{totalMinute / 60};
            if (newHour > 23) newHour %= 24; // newHour = newHour % 24;
            return timeOfDay{newHour, newMinute};
        }

    };
}
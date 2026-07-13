#pragma once
#include "timeOfDay.h"

namespace JeongYoonha2449101
{
    class timeArray
    {
        int n;
        timeOfDay* a;
    
    public:
        timeArray(int n0 = 10) : n{n0}, a{ new timeOfDay[n]}{} 
        
        ~timeArray()
        {
            delete[] a;
        }

        timeArray(const timeArray& copy) : n{copy.n}
        {
            if (copy.a != nullptr)
            {
                a = new timeOfDay[n];
                for (int i = 0; i < n; ++i) a[i] = copy.a[i];
                // *(a+1) = *(copy.a+1);
            }else a = nullptr;
        }

        timeArray& operator=(const timeArray& copy)
        {
            if ( this !=&copy)
            {
                n =copy.n;
                delete[] a;
                if(copy.a)
                {
                    a = new timeOfDay[n];
                    for (int i = 0; i < n; ++i) a[i] = copy.a[i];
                    // *(a+1) = *(copy.a+1);
                }
                    else a = nullptr;
            }
            return *this;
        }

        timeArray(timeArray&& move)noexcept 
        {
            n = move.n;
            a=move.a;
            move.n = 0;
            move.a =nullptr;
            
        }

        timeArray& operator=(timeArray&& move)noexcept
        {
            if(this != &move)
            {
                delete[] a;
                n =move.n;
                a = move.a;
                move.n = 0;
                move.a = nullptr;
            }return *this;
        }

        timeOfDay& operator[](int index)
        {
            if(index < n) return a[index];
            else{
                std::cout << "illegal indes\n";
                std::exit(1);
            }
        }   
        
        void printAll() const
        {
            if (a) {//if (a != nullptr) 
                for (int i = 0; i<n; ++i)
                    std::cout << a[i] << " ";
                std::cout << std::endl;
            }
            else
                std::cout << "no time array data\n";

        }
    };
}


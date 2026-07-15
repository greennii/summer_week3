#include "timeArray.h"
#include <vector>
#include <fstream>
#include <string>
#include "alarm.h"
#include <sstream> 


namespace JeongYoonha2449101
{
    void printTimeArrayVector(const std::vector<timeArray>& v)
    {
        for (const auto& vi : v)
            vi.printAll();
        std::cout <<v.size() << "/" <<v.capacity() <<std::endl;
    }

    void readWriteTimeFile(std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<timeOfDay> v;
        timeOfDay t;
        
        std::streambuf* origBuf{ std::cout.rdbuf()};
        std::cout.rdbuf(nullptr);
       
        while (fin >> t) //t is timeOfDay's input dustkswk
            v.push_back(t);
        std::cout.rdbuf(origBuf);


        for (const auto& vi : v)
            fout << /*timeofday's print dustkswk*/ vi << '\n';
    }

    //std::iostream -> std::stringstream
    //                  s

    void parsingAlarm(std::iostream& io)
    {
        alarm a;
        io >> a; //alarm's input dustkswk
        
        std::streambuf* origBuf{std::cout.rdbuf()};
        
        std::cout.rdbuf(nullptr);
        
        std::cout.rdbuf(origBuf);

        io.clear();
        io.seekp(0, std::ios::end);

        io << a;


    }


}

int main()
{

    using namespace JeongYoonha2449101;

    
    
    std::stringstream ss;
    std::string alarmData{"morning\n7 0\n1\n"};
    ss <<alarmData;
    parsingAlarm(ss);
    std::cout <<ss.str() << '\n';
   
    std::fstream fs{"alarmData.txt"};
    if(!fs)
    {
        std::cout << "Input file opening failed\n";
        std::exit(1);
    }
    parsingAlarm(fs);

    // if( fin.fail())
    // {
    //     std::cout << "Input file opening failed\n";
    //     std::exit(1);
    // }

    // std::ofstream fout;
    // std::string filename;
    // std::cout << "Enter the file name: ";
    // std::cin >> filename;
    // fout.open(filename + ".txt");

    // if (!fout)
    // {
    //     std::cout << "Outfile opening failed\n";
    //     std::exit(1);
    // }
    // readWriteTimeFile(fin, fout);

    // fin.close();
    // fout.close();

    // timeOfDay t;
    // fin >> t;
    // fout << t <<std::endl;


    // timeArray ta1{3};
    // ta1[0] =timeOfDay{1,1};
    // ta1[1] =timeOfDay{2,2};
    // ta1[2] =timeOfDay{3,3};
    // ta1.printAll();

    // timeArray ta2; ta2 = ta1;
    // ta2.printAll();

    // timeArray ta3;
    // ta3 = std::move(ta2);
    // ta2.printAll();

    // std::vector<timeArray> v;
    // printTimeArrayVector(v);
    // v.push_back(ta1);
    // printTimeArrayVector(v);
    // v.push_back(std::move(ta1));
    // printTimeArrayVector(v);
    // ta1.printAll();



    return 0;
}
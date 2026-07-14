#include "timeArray.h"
#include <vector>
#include <fstream>
#include <string>
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
        //fin >> t;
       
        while (fin >> t)
            v.push_back(t);

        for (const auto& vi : v)
            fout << vi << '\n';
    }
}
int main()
{

    using namespace JeongYoonha2449101;

    std::ifstream fin{"timeData.txt"};

    if( fin.fail())
    {
        std::cout << "Input file opening failed\n";
        std::exit(1);
    }

    std::ofstream fout;
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;
    fout.open(filename + ".txt");

    if (!fout)
    {
        std::cout << "Outfile opening failed\n";
        std::exit(1);
    }
    readWriteTimeFile(fin, fout);

    fin.close();
    fout.close();

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
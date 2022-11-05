#include "argparse.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::vector;
using argparse::Argument;
using argparse::ArgumentParser;

int main(int argc, char** argv)
{
    try
    {
        ArgumentParser ap;
        
        Argument a("--optionA");
        a.shortName = "-a";
        a.help = "A help message to describe what this option is for";
        ap.addArgument(a);

        Argument b("--optionB");
        b.shortName = "-b";
        b.nargs = 0;
        b.help = "This option is a boolean flag, because nargs=0";
        ap.addArgument(b);

        Argument pos1("positional1");
        pos1.help = "This is a positional argument";
        ap.addArgument(pos1);

        Argument pos2("positional2");
        pos2.help = "This second positional argument will consume the rest of the args";
        pos2.nargs = argparse::NARGS_AT_LEAST_ZERO;
        ap.addArgument(pos2);

        ap.parse({"testProg.exe", "--optionA", "valueA", "-b", "10", "apple", "banana", "strawberry"});

        string aValue = ap.get<string>("--optionA");
        cout << "--optionA value: " << aValue << "\n"; // "valueA"

        bool bValue = ap.get<bool>("--optionB");
        cout << "--optionB value: " << std::boolalpha << bValue << "\n"; // true

        int pos1Value = ap.get<int>("positional1");
        cout << "positional1 value: " << pos1Value << "\n"; // 10

        vector<string> pos2Values;
        ap.get<string>("positional2", pos2Values); // contains {"apple", "banana", "strawberry"}
        cout << "positional2 values:\n";
        for (string& s: pos2Values)
        {
            cout << "\t" << s << "\n";
        }
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}

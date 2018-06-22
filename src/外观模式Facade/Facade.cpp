//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
using namespace std;
/*
 * 外观模式Facade
 */
//写出一个编译器工作的几个阶段
class Scanner {
public:
    void Scan(){cout<<"词法分析"<<endl;};
};

class Parser {
public:
    void Parse(){cout<<"语法分析"<<endl;};
};

class GenMidCode {
public:
    void Gencode(){cout<<"产生中间代码"<<endl;};
};

class GenMachineCode {
public:
    void GenCode(){cout<<"产生机器代码"<<endl;};
};

//为这些复杂的操作提供一个一致的门面（外观）
//高层接口 Facade
class Compiler {
public:
    void Run()
    {
        Scanner scanner;
        Parser parser;
        GenMidCode genMidCode;
        GenMachineCode genMacCode;
        scanner.Scan();
        parser.Parse();
        genMidCode.Gencode();
        genMacCode.GenCode();
    }
};

int main()
{
    Compiler compiler;
    compiler.Run();
    return 0;
}

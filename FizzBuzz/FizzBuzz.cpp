#include <iostream>

// To control size of FizzBuzz variables
#if USE_LONG
typedef long FBValue;
#else
typedef int FBValue;
#endif
//

// For aesthetics
#define PUSH std::cout <<
#define PULL std::cin >>
//

class FizzBuzzProcessor
{
private:
    FBValue start;
    FBValue end;
    FBValue fizz;
    FBValue buzz;
    FizzBuzzProcessor();
public:
    static FizzBuzzProcessor* Create();
    FizzBuzzProcessor(FBValue s, FBValue e, FBValue f, FBValue b);
    void Run();
};


FizzBuzzProcessor* FizzBuzzProcessor::Create()
{
    PUSH "Please enter a number to start at: ";
    FBValue st = 0, en = 0, fi = 0, bu = 0;
    PULL st;
    PUSH "Please enter a number to end at: ";
    PULL en;
    if (en <= st)
        throw std::exception("Start cannot be less than or equal to End!\n");
    PUSH "Please enter a number to Fizz at: ";
    PULL fi;
    PUSH "Please enter a number to Buzz at: ";
    PULL bu;
    if (fi <= 0 || bu <= 0)
        throw std::exception("Fizz and/or Buzz cannot be less than or equal to 0!\n");
    return new FizzBuzzProcessor(st, en, fi, bu);
}

FizzBuzzProcessor::FizzBuzzProcessor(FBValue s, FBValue e, FBValue f, FBValue b)
{
    start = s;
    end = e;
    fizz = f;
    buzz = b;
}

void FizzBuzzProcessor::Run()
{
    for (FBValue i = start; i < end; i++)
    {
        bool buzzed = false;
        if (i % fizz == 0)
        {
            PUSH "Fizz ";
            buzzed = true;
        }
        if (i % buzz == 0)
        {
            PUSH "Buzz";
            buzzed = true;
        }

        if(!buzzed)
            PUSH i;
        PUSH "\n";
    }
}

int main()
{
    PUSH "Hello World!\n";
    FizzBuzzProcessor* fizzbuzz = FizzBuzzProcessor::Create();
    fizzbuzz->Run();
    delete fizzbuzz;
    PUSH "Goodbye World!\n";
}
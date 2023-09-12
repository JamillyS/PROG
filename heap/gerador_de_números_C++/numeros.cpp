#include <iostream>
#include <random>

using namespace std;

int main(int argc, char * argv[])
{
    int quantidade = stoi(argv[1]);
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 1000000); // define the range

    for(int n=0; n < quantidade; ++n)
        std::cout << distr(gen) << ','; // generate numbers
}
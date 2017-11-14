#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
using namespace std;


void Print(const vector<int> &data){
    for (auto iv: data) {
        std::cout << iv << " ";
    }
    std::cout << "\n";
}

void generateRandomInteger(vector<int> &data)
{
    srand(0);
    generate(data.begin(), data.end(), rand);
    
    //Print(data);
}

int main(int argc, const char * argv[]) {
    
    vector<int> data(10000000);
    
    generateRandomInteger(data);
    
    auto start = chrono::steady_clock::now();
    sort(data.begin(), data.end());
    auto end = chrono::steady_clock::now();
    
    auto timeDiff = end - start;
    
    cout << chrono::duration<double,milli> (timeDiff).count() << "ms" << "\n";
    //Print(data);
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

void Print(const vector<int> &data){
    for (auto iv: data) {
        std::cout << iv << " ";
    }
    std::cout << "\n";
}

int interpolationSearch(vector<int> &data, int key)
{
    int low(0), high(static_cast<int>(data.size() - 1));
    
    while (low <= high && data[low] <= key && key <= data[high]){
        int pos = low + static_cast<double>((key - data[low])*(high - low))/(data[high] - data[low]);
        if (data[pos] == key) {
            return pos;
        }
        else if(data[pos] < key){
            low = pos + 1;
        }
        else{
            high = pos - 1;
        }
    }
    
    return -1;
}


int main() {

    vector<int> data{
        929, 901, 486, 943, 400, 725, 753, 731, 428, 278, 726, 968, 769, 168, 408, 762, 891, 780, 206, 409, 881, 551, 778, 528, 764,
        266, 482, 334, 161, 702, 499, 633, 342, 770, 223, 989, 423, 138, 452, 852, 647, 155, 261, 667, 559, 216, 272, 639, 376, 593,
        662, 215, 454, 855, 930, 626, 707, 811, 630, 907, 230, 752, 329, 939, 801, 661, 198, 654, 539, 109, 434, 211, 496, 574, 867,
        170, 889, 300, 768, 291, 169, 225, 743, 829, 255, 437, 617, 289, 108, 958, 479, 564, 610, 478, 256, 623, 590, 202, 122, 137
    };
    
    int key = 661;
    
    auto start = chrono::steady_clock::now();
    sort(data.begin(), data.end());
    auto end = chrono::steady_clock::now();
    auto timediff = end - start;
    cout << "Sorting, Time elapsed :" << chrono::duration<double,micro> (timediff).count() <<"µs\n";
    Print(data);
    
    
    int index(0);
    start = chrono::steady_clock::now();
    index = interpolationSearch(data, key);
    end = chrono::steady_clock::now();
    timediff = end - start;
    cout << "Searching, Time elapsed :" << chrono::duration<double,micro> (timediff).count() <<"µs\n";
    
    if (index != -1)
        cout << "Found at: " <<index<<"\n";
    else
        cout << "Not found ...\n";
    
    return 0;
}

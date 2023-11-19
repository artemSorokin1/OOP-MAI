#include "../lib/vector.h"
#include <map>

using namespace std;

int main() {

    // мапа [x, факториал(x)]
    std::map<int ,int, std::less<int>, lab5::allocator<std::pair<const int, int>>> mp;
    mp[0] = 0;
    mp[1] = 1;
    for (int i = 2; i < 9; ++i) {
        mp[i] = mp[i - 1] * i;
    }

    for (auto & [k, v] : mp) {
        std::cout << "{" << k << ", " << v << "}\n";
    }

    lab5::vector<int> vec(10);

    for (int i = 0; i < 10; ++i) {
        vec[i] = i * i;
    }

    for (auto & elem : vec) {
        cout << elem << ' ';
    }
    cout << endl;


    return 0;
}

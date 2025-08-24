#include <iostream>
#include <cstring>
int main() {
    using namespace std;
    const int ArSize = 5;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: \n";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I hava some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    
    return 0;

}
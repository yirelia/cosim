#include <iostream>
struct inflatable {
    char name [20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    inflatable guest = {
        "Glorious Gloria",
        1.88,
        29.99
    };

    cout << "Expand your guest list with " << guest.name;
    return 0;

}
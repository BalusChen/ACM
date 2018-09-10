#include <iostream>
#include <queue>

int main(void) {
    std::queue<int> iq;
    iq.push(3);
    iq.push(4);
    iq.push(37);
    iq.push(7);

    while (!iq.empty()) {
        std::cout << iq.front() << "  ";
        iq.pop();
    }
    std::cout << '\n';
}

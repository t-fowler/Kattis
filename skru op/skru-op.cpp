#include <iostream>
#include <string>

/*
Volume control starts at 7. Input begins with the number "n" of commands
in the input. Input of "Skru op!" means to increase volume and "Skru ned!"
means to decrease volume. Volume must stay between 0 and 10 inclusively.
Output is the value of volume after all the input.
*/

int main() {
    int volume = 7;
    int n;
    std::string cmd;

    std::cin >> n;
    std::cin.get();
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, cmd);
        std::cerr << cmd << std::endl;

        if (cmd == "Skru op!" && volume < 10) {
            ++volume;
        } else if (cmd == "Skru ned!" && volume > 0) {
            --volume;
        }
    }
    std::cout << volume << std::endl;
}
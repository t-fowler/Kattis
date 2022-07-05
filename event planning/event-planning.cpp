#include <iostream>

#define MAX_BUDGET 500000

int main() {
    int numberOfParticipants, budget, numberOfHotels, numberOfWeeks;
    std::cin >> numberOfParticipants >> budget 
        >> numberOfHotels >> numberOfWeeks;

    int bestPrice = MAX_BUDGET + 1;
    for (int i = 0; i < numberOfHotels; ++i) {
        int price;
        std::cin >> price;
        for (int j = 0; j < numberOfWeeks; ++j) {
            int numberOfBeds;
            std::cin >> numberOfBeds;

            if (numberOfBeds >= numberOfParticipants 
                && numberOfParticipants * price < bestPrice) {
                bestPrice = numberOfParticipants * price;
            }
        }
    }

    if (bestPrice <= budget) {
        std::cout << bestPrice << std::endl;
    }
    else {
        std::cout << "stay home" << std::endl;
    }
}
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>


std::vector<int> getNumbers() {
    std::vector<int> powerball;
    for (int i = 0; i < 5; i++) {
        powerball.push_back((std::rand() % 69) + 1);
    }
    std::sort(powerball.begin(), powerball.end());
    return powerball;
}

void setPowerball(std::vector<int>& v) {
    v.push_back((std::rand() % 26) + 1);
}

void showNumbers(const std::vector<int>& v) {
    for (int i = 0; i < v.size()-1; i++) {
        std::cout << v.at(i) << ' ';
    }
    std::cout << "PB " << v.at(v.size()-1) << std::endl;
}

int main() {
    srand(time(NULL));
    char y_or_n = 'Y';
    while (y_or_n == 'Y') {
        std::cout << "How many numbers do you want to generate? ";
        int number;
        std::cin >> number;
        for (int i = 0; i <= number; i++) {
            std::vector<int> power_ball = getNumbers();
            setPowerball(power_ball);
            showNumbers(power_ball);
        }
        std::cout << "Would you like to see more numbers? (case sensitive 'Y' or 'N') ";
        std::cin >> y_or_n;
    }
    return 0;
}

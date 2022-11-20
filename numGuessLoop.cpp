// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu

// Date: Nov. 19, 2022
// guess the random number


#include <iostream>
#include <random>

int main() {
    // variables
    int randNum, userNumInt;
    std::string userNumString;

    // generating a random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, 10);
    randNum = idist(rgen);

    while (true) {
        // get user input
        std::cout << "Enter an integer from 1 to 10: ";
        std::cin >> userNumString;

        // exception handling
        try {
            userNumInt = stoi(userNumString);

            // user input is out of range
            if (userNumInt < 1 || userNumInt > 10) {
                std::cout << "Input invalid! Please enter"
                          << "an integer within the specified range."
                          << std::endl;

            // user input is within range
            } else {
                // user guessed correctly
                if (userNumInt == randNum) {
                    std::cout << "Correct! " << userNumInt
                              << " is the right number!" << std::endl;
                    break;

                    // user guessed incorrectly
                } else {
                    std::cout << "Incorrect. " << userNumInt
                              << " is the wrong number. Please try again."
                              << std::endl;
                }
            }

        // user didn't input an integer
        } catch (std::invalid_argument) {
            std::cout << "Input invalid! Please enter"
                      << "an integer within the specified range."
                      << std::endl;
        }
    }
}

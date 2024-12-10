//============================================================================
// Name        : CS410Project.cpp
// Author      : Justin Perez
// Version     : 2.0
// Copyright   : N/A
// Description : Client Management Application
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>

// Function prototypes
void performAction(int& result);       // *** Assembly Conversion: First part ***
bool CheckUserPermissionAccess();     // *** Assembly Conversion: Second part ***
void DisplayInfo();                   // *** Assembly Conversion: Third part ***
void ChangeCustomerChoice();          // *** Assembly Conversion: Fourth part ***
void InitializeChoices();
void DisplayChoices();
void GetUserInput();
void ValidateChoice();
int GetCurrentChoice();
// Commented out for debugging purposes
// void __static_initialization_and_destruction_0(int arg1, int arg2); // *** Assembly Conversion: Fifth part ***
// void PerformAdditionalInitialization();
// void _GLOBAL__sub_I_username(); // *** Assembly Conversion: Sixth part ***

// *** Main Function ***
int main() {
    std::cout << "Client Management Application Created by Justin Perez" << std::endl;
    std::cout << "Program Starting..." << std::endl;

    int result = 0;

    performAction(result); // Simulates first function call
    performAction(result); // Simulates second function call

    while (result != 1) {
        performAction(result); // Simulates looped function call
        if (result == 1) {
            break;
        }
    }

    ChangeCustomerChoice(); // Customer choice functionality
    DisplayInfo();          // System information

    return 0;
}

// *** Function Definitions ***

void performAction(int& result) {
    static int count = 0;
    ++count;
    std::cout << "Performing action " << count << std::endl;

    if (count >= 5) {
        result = 1; // Exit loop condition
    }
}

// *** Assembly Conversion: Second part ***
bool CheckUserPermissionAccess() {
    char buffer[5];  // Small buffer to hold permission input
    int result = 0;

    std::cout << "Enter permission level (max 4 characters): ";
    // *** Old Vulnerable Code ***
    // std::cin.getline(buffer, sizeof(buffer)); // This may cause a buffer overflow.

    // *** Updated Code for Vulnerability ***
    std::cin >> std::setw(sizeof(buffer)) >> buffer; // Ensures input fits within buffer size.

    std::cout << "Permission entered: " << buffer << std::endl;

    if (strcmp(buffer, "admin") == 0) {
        result = 1; // "admin" permission
    }
    else if (strcmp(buffer, "user") == 0) {
        result = 2; // "user" permission
    }

    return result != 0;
}

void DisplayInfo() {
    std::cout << "CPU: " << std::setw(20) << std::left << "Intel Core i7" << std::endl;
    std::cout << "Clock Speed: " << std::setw(20) << std::left << "3.6 GHz" << std::endl;
    std::cout << "Cores: " << std::setw(20) << std::left << "6" << std::endl;
    std::cout << "Threads: " << std::setw(20) << std::left << "12" << std::endl;
    std::cout << "Cache: " << std::setw(20) << std::left << "12 MB" << std::endl;
}

// *** Assembly Conversion: Fourth part ***
void ChangeCustomerChoice() {
    int customerChoice;

    InitializeChoices();
    DisplayChoices();
    GetUserInput();
    ValidateChoice();

    customerChoice = GetCurrentChoice();

    // *** Old Vulnerable Code ***
    // if (customerChoice == 1) { ... (Separate if-else statements for all options without validation.)

    // *** Updated Code for Vulnerability ***
    if (customerChoice >= 1 && customerChoice <= 5) {
        std::cout << "Customer chose option " << customerChoice << "." << std::endl;
    }
    else {
        std::cout << "Invalid choice. No action taken." << std::endl;
    }

    std::cout << "Operation completed successfully." << std::endl;
}

void InitializeChoices() {
    std::cout << "Initializing choices..." << std::endl;
}

void DisplayChoices() {
    std::cout << "Displaying choices: 1, 2, 3, 4, 5" << std::endl;
}

void GetUserInput() {
    std::cout << "Waiting for user input..." << std::endl;
}

void ValidateChoice() {
    std::cout << "Validating user input..." << std::endl;
}

int GetCurrentChoice() {
    int choice;

    std::cout << "Please enter your choice (1-5): ";
    while (!(std::cin >> choice) || choice < 1 || choice > 5) {
        std::cin.clear(); // Clear input stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a valid choice (1-5): ";
    }

    return choice;
}

// *** Assembly Conversion: Fifth part ***
// Commented out for debugging
// void __static_initialization_and_destruction_0(int arg1, int arg2) {
//     int local_arg1 = arg1;
//     int local_arg2 = arg2;

//     if (local_arg1 == 1) {
//         if (local_arg2 == 0xffff) {
//             std::cout << "Initializing global or static objects..." << std::endl;
//             PerformAdditionalInitialization(); // Simulates additional initialization
//         }
//     }

//     std::cout << "Static initialization or destruction complete." << std::endl;
// }

// Simulates additional initialization tasks
// void PerformAdditionalInitialization() {
//     std::cout << "Performing additional initialization tasks..." << std::endl;
// }

// *** Assembly Conversion: Sixth part ***
// void _GLOBAL__sub_I_username() {
//     int arg1 = 1;
//     int arg2 = 0xffff;

//     __static_initialization_and_destruction_0(arg1, arg2); // Simulates static initialization function

//     std::cout << "Static initialization for username complete." << std::endl;
// }

// *** End of Program ***


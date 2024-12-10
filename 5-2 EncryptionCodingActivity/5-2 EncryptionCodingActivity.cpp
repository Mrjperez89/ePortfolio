// Encryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// SNHU, Justin D.Perez
// Professor Ahlam Alhweiti
// September 29, 2024

// SNHU, Justin D. Perez
// Professor Mike Alesso
// November 17, 2024

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <stdexcept> 

// *** ENHANCEMENT START: For exception handling ***

// Function to get the current timestamp in YYYY-MM-DD format
std::string get_current_timestamp() {
    time_t now = time(0);
    std::tm time_info{}; // Zero-initialized

    // Use localtime_s for thread-safe conversion
    errno_t err = localtime_s(&time_info, &now);
    if (err != 0) {
        std::cerr << "Error converting time to local time." << std::endl;
        return "";
    }

    std::ostringstream timestamp;
    timestamp << 1900 + time_info.tm_year << "-"
        << std::setw(2) << std::setfill('0') << 1 + time_info.tm_mon << "-"
        << std::setw(2) << std::setfill('0') << time_info.tm_mday;
    return timestamp.str();
}

/// <summary>
/// Encrypt or decrypt a source string using the provided key
/// </summary>
/// <param name="source">input string to process</param>
/// <param name="key">key to use in encryption / decryption</param>
/// <returns>transformed string</returns>
std::string encrypt_decrypt(const std::string& source, const std::string& key) {
    const auto key_length = key.length();
    const auto source_length = source.length();

    // Assert that our input data is good
    assert(key_length > 0);
    assert(source_length > 0);

    std::string output = source;

    // Loop through the source string char by char
    for (size_t i = 0; i < source_length; ++i) {
        output[i] = source[i] ^ key[i % key_length];
    }

    assert(output.length() == source_length);

    return output;
}

// Function to read the contents of a file into a string
std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Read file into buffer
    return buffer.str(); // Return buffer as a string
}

// Function to extract the student's name from the string data
std::string get_student_name(const std::string& string_data) {
    std::string student_name;

    // Find the first newline
    size_t pos = string_data.find('\n');
    if (pos != std::string::npos) {
        student_name = string_data.substr(0, pos); // Extract the name
    }

    return student_name;
}

// *** ENHANCEMENT START: Secure and validated file saving ***
void save_data_file(const std::string& filename, const std::string& student_name, const std::string& key, const std::string& data) {
    std::ofstream outfile(filename, std::ios::trunc); // Open file in truncate mode for safety
    if (!outfile.is_open()) {
        throw std::runtime_error("Error opening file: " + filename); // Use exceptions for better error handling
    }

    // Write the student name
    outfile << student_name << std::endl;

    // Get the current time and format it as a timestamp
    std::time_t t = std::time(nullptr); // Current time
    std::tm time_info{}; // Zero-initialized
    errno_t err = localtime_s(&time_info, &t);
    if (err != 0) {
        throw std::runtime_error("Error converting time to local time.");
    }

    // Format the date as yyyy-mm-dd
    outfile << std::put_time(&time_info, "%Y-%m-%d") << std::endl;

    // Write the key used for encryption
    outfile << key << std::endl;

    // Write the encrypted or decrypted data
    outfile << data << std::endl;

    // Close the file
    outfile.close();
}
// *** ENHANCEMENT END ***

int main() {
    std::cout << "Encryption Decryption Test!" << std::endl;

    const std::string file_name = "inputdatafile.txt";
    const std::string encrypted_file_name = "encrypteddatafile.txt";
    const std::string decrypted_file_name = "decrypteddatafile.txt";
    const std::string key = "password"; // Encryption/decryption key

    // *** ENHANCEMENT START: Improved file reading with error handling ***
    const std::string source_string = read_file(file_name);
    if (source_string.empty()) {
        std::cerr << "Failed to read from " << file_name << ". Exiting." << std::endl;
        return 1; // Exit with error code
    }
    // *** ENHANCEMENT END ***

    // Get the student name from the data file
    const std::string student_name = get_student_name(source_string);

    // Encrypt the source string with the key
    const std::string encrypted_string = encrypt_decrypt(source_string, key);

    // *** ENHANCEMENT START: Enhanced error handling in save function ***
    try {
        save_data_file(encrypted_file_name, student_name, key, encrypted_string);
    }
    catch (const std::exception& e) {
        std::cerr << "Error during file save: " << e.what() << std::endl;
        return 1;
    }
    // *** ENHANCEMENT END ***

    // Decrypt the encrypted string with the key
    const std::string decrypted_string = encrypt_decrypt(encrypted_string, key);

    // Save the decrypted string to a file
    try {
        save_data_file(decrypted_file_name, student_name, key, decrypted_string);
    }
    catch (const std::exception& e) {
        std::cerr << "Error during file save: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Read File: " << file_name << " - Encrypted To: " << encrypted_file_name << " - Decrypted To: " << decrypted_file_name << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

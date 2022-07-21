#include <algorithm>
#include <iostream>
#include <string>

#include "PlayfairCipher.hpp"

int main() {
    std::string alphabet = "abcdefghijklmnoprstuvwxyz"; // The alphabet, excluding 'q'.
    std::string key_phrase;
    std::string key;
    std::string message;
    std::getline(std::cin, key_phrase);
    std::getline(std::cin, message);

    // Initialize the encryption key.
    for (char ch : key_phrase) {
        if (ch == ' ') 
            continue;

        auto position = std::find(alphabet.begin(), alphabet.end(), ch);
        if (position != alphabet.end()) {
            key.push_back(ch);
            alphabet.erase(position);
        }
    }

    for (auto ch : alphabet) {
        key.push_back(ch);
    }
    std::cerr << key << std::endl;
    std::cerr << message << std::endl;

    // Encrypt message.
    PlayfairCipher cipher(key);
    std::cout << cipher.encrypt(message) << std::endl;
}
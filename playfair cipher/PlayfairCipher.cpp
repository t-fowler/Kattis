#include <algorithm>
#include <iostream>

#include "PlayfairCipher.hpp"

int PlayfairCipher::indexOf(char c) {
    for (int i = 0; i < 25; ++i) {
        if (key[i] == c) {
            return i;
        }
    }
    return -1;
}

std::pair<char, char> PlayfairCipher::down(std::pair<char, char> pair) {
    int idx1 = -1, idx2 = -1;
    idx1 = indexOf(pair.first) + 5;
    if (idx1 >= 25)
        idx1 -= 25;

    idx2 = indexOf(pair.second) + 5;
    if (idx2 >= 25)
        idx2 -= 25;

    return std::make_pair(key[idx1], key[idx2]);
}

std::pair<char, char> PlayfairCipher::right(std::pair<char, char> pair) {
    int idx1 = -1, idx2 = -1;
    int i = indexOf(pair.first);
    idx1 = i + 1;
    if (idx1 / 5 != i / 5)
        idx1 -= 5;

    i = indexOf(pair.second);
    idx2 = i + 1;
    if (idx2 / 5 != i / 5) {
        idx2 -= 5;
    }

    return std::make_pair(key[idx1], key[idx2]);
}

std::pair<char, char> PlayfairCipher::corners(std::pair<char, char> pair) {
    int i = indexOf(pair.first), j = indexOf(pair.second);
    int rowDistance = (j % 5) - (i % 5);

    return std::make_pair(key[i + rowDistance], key[j - rowDistance]);
}

PlayfairCipher::PlayfairCipher(std::string key) {
    this->key = key;
}

std::string PlayfairCipher::encrypt(std::string message) {
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    std::string encrypted_message = "";
    for (int idx = 0; idx < message.size(); ++idx) {
        std::pair<char, char> pair;
        char first = message[idx];
        char second;
        if (idx + 1 >= message.size() || message[idx + 1] == first) {
            second = 'x';
        } else {
            second = message[++idx];
        }
        std::cerr << "Pair: first=" << first << " second=" << second << std::endl;
        pair = std::make_pair(first, second);

        std::pair<char, char> encrypted_pair;
        int i = indexOf(pair.first), j = indexOf(pair.second);
        if (i / 5 == j / 5) {
            encrypted_pair = right(pair);
        } else if (i % 5 == j % 5) {
            encrypted_pair = down(pair);
        } else {
            encrypted_pair = corners(pair);
        }
        encrypted_message.push_back(encrypted_pair.first);
        encrypted_message.push_back(encrypted_pair.second);
    }
    std::transform(encrypted_message.begin(), encrypted_message.end(), encrypted_message.begin(), 
        [](unsigned char c){ return std::toupper(c); });
    return encrypted_message;
}
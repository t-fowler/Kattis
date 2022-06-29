#include <array>
#include <iostream>
#include <map>
#include <string>

enum Note {
    G, F, E, D, C, B, A,
    g, f, e, d, c, b, a,
    NO_NOTE
};

void fillLinesOtherThan(std::array<std::string, 14> &sheet_music, Note note) {
    for (int i = 0; i < 14; i++) {
        if (i == note)
            continue;
        if (i == F || i == D || i == B || i == g || i == e || i == a) {
            sheet_music[i].append("-");
        } else {
            sheet_music[i].append(" ");
        }
    }
}

int main () {
    int n = 0;
    std::cin >> n;

    std::map<char, Note> charToNoteMap = {
        {'G', G},
        {'F', F},
        {'E', E},
        {'D', D},
        {'C', C},
        {'B', B},
        {'A', A},
        {'g', g},
        {'f', f},
        {'e', e},
        {'d', d},
        {'c', c},
        {'b', b},
        {'a', a}
    };

    std::array<std::string, 14> output = {
        "G: ",
        "F: ",
        "E: ",
        "D: ",
        "C: ",
        "B: ",
        "A: ",
        "g: ",
        "f: ",
        "e: ",
        "d: ",
        "c: ",
        "b: ",
        "a: "
    };

    for (int i = 0; i < n; i++) {
        char note;
        int length;
        std::cin >> note;

        if (std::cin.peek() == ' ') {
            length = 1;
        } else {
            std::cin >> length;
        }
        std::cin >> std::ws;

        std::cerr << "note: " << note << std::endl 
            << "length: " << length << std::endl << std::endl;
            
        // Add stars for the current note.
        for (int j = 0; j < length; j++) {
            output[charToNoteMap[note]].append("*");
            fillLinesOtherThan(output, charToNoteMap[note]);
        }
        if (i != n-1)
            fillLinesOtherThan(output, NO_NOTE);
        
    }

    for (std::string line : output) {
        std::cout << line << std::endl;
    }
}
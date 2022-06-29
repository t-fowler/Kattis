#include <array>
#include <iostream>
#include <map>
#include <string>

enum Note {
    G, F, E, D, C, B, A,
    g, f, e, d, c, b, a
};

void fillLines(std::array<std::string, 14> &sheet_music) {
    for (int i = 0; i < 14; i++) {
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

    std::array<std::string, 14> sheet_music = {
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
        std::string note;
        std::cin >> std::ws >> note;

        Note currentNote = charToNoteMap[note[0]];
        int length = note[1] - 49;  // Number of extra stars to print.

        fillLines(sheet_music);
        sheet_music[currentNote][sheet_music[0].size()-1] = '*';
        
        if (note.size() > 1) {
            for (int j = 0; j < length; j++) {
                fillLines(sheet_music);
                sheet_music[currentNote][sheet_music[0].size()-1] = '*';
            }   
        }
        
        if (i != n-1)
            fillLines(sheet_music);

        //std::cerr << "note: " << note << std::endl 
        //    << "length: " << length << std::endl << std::endl;
        
    }

    for (std::string line : sheet_music) {
        std::cout << line << std::endl;
    }
}
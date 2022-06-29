#include <array>
#include <iostream>
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

void add_notation(std::array<std::string, 14> &sheet_music, int n) {
    for (int i = 0; i < n; i++) {
        char note;
        int length;
        std::cin >> note;
        
        if (std::cin.peek() == ' ') {
            length = 1;
        } else {
            std::cin >> length;
        }

        for (int j = 0; j < length; j++) {
             switch (note) {
                case 'G':
                    sheet_music[G].append("*");
                    fillLinesOtherThan(sheet_music, G);
                    break;
                case 'F':
                    sheet_music[F].append("*");
                    fillLinesOtherThan(sheet_music, F);
                    break;
                case 'E':
                    sheet_music[E].append("*");
                    fillLinesOtherThan(sheet_music, E);
                    break;
                case 'D':
                    sheet_music[D].append("*");
                    fillLinesOtherThan(sheet_music, D);
                    break;
                case 'C':
                    sheet_music[C].append("*");
                    fillLinesOtherThan(sheet_music, C);
                    break;
                case 'B':
                    sheet_music[B].append("*");
                    fillLinesOtherThan(sheet_music, B);
                    break;
                case 'A':
                    sheet_music[A].append("*");
                    fillLinesOtherThan(sheet_music, A);
                    break;
                case 'g':
                    sheet_music[g].append("*");
                    fillLinesOtherThan(sheet_music, g);
                    break;
                case 'f':
                    sheet_music[f].append("*");
                    fillLinesOtherThan(sheet_music, f);
                    break;
                case 'e':
                    sheet_music[e].append("*");
                    fillLinesOtherThan(sheet_music, e);
                    break;
                case 'd':
                    sheet_music[d].append("*");
                    fillLinesOtherThan(sheet_music, d);
                    break;
                case 'c':
                    sheet_music[c].append("*");
                    fillLinesOtherThan(sheet_music, c);
                    break;
                case 'b':
                    sheet_music[b].append("*");
                    fillLinesOtherThan(sheet_music, b);
                    break;
                case 'a':
                    sheet_music[a].append("*");
                    fillLinesOtherThan(sheet_music, a);
                    break;
            }
        }
        if (i != n-1)
            fillLinesOtherThan(sheet_music, NO_NOTE);
    }
}

int main () {
    int n = 0;
    std::cin >> n;

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

    add_notation(output, n);

    for (std::string line : output) {
        std::cout << line << std::endl;
    }
}
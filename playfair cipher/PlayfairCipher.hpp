#include <string>
#include <utility>

class PlayfairCipher {
  private:
    std::string key;
    int indexOf(char c);
    std::pair<char, char> down(std::pair<char, char> pair);
    std::pair<char, char> right(std::pair<char, char> pair);
    std::pair<char, char> corners(std::pair<char, char> pair);
  public:
    PlayfairCipher(std::string key);
    std::string encrypt(std::string message);
};
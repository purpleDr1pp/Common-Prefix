#include <iostream>
#include <vector>
#include <string>
std::string CommonPrefix(const std::vector<std::string>& words) {
    if (!words.empty()) {
        size_t min = 10000000;
        size_t cnt = 0;
        for (size_t i = 0; i < words.size(); i++) {
            cnt = 0;
            for (size_t j = 0; j < words[i].size(); j++) {
                cnt++;
            }
            if (min > cnt) {
                min = cnt;
            }
        }
        std::string prefix;
        cnt = 0;
        for (size_t i = 0; i < min; i++) {
            char isprefix = words[0].at(i);
            for (size_t j = 0; j < words.size(); j++) {
                if (words[j].at(i) == isprefix) {
                    cnt++;
                }
            }
            if (cnt == words.size()) {
                prefix += words[0].at(i);
            }
            else {
                break;
            }
            cnt = 0;
        }
        return prefix;
    }
    else {
        return("");
    }
}
int main() {
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.push_back(word);
    }
    std::cout << CommonPrefix(words);
}
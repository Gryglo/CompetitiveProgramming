#include <iostream>
#include <unordered_map>

const int MODULO = 1000000007;

int find_keys(const std::string& plain_text, const std::string& encrypted_text) {
    int keys_count = 1;
    std::unordered_map<char, char> key_mapping;

    for (size_t i = 0; i < plain_text.length(); ++i) {
        char plain_char = plain_text[i];
        char encrypted_char = encrypted_text[i];

        if (key_mapping.find(plain_char) == key_mapping.end()) {
            key_mapping[plain_char] = encrypted_char;
        } else if (key_mapping[plain_char] != encrypted_char) {
            keys_count = (keys_count * 2) % MODULO;
        }
    }

    return keys_count;
}

int main() {
    std::string plain_text, encrypted_text;
    std::cin >> plain_text >> encrypted_text;

    int result = find_keys(plain_text, encrypted_text);
    std::cout << result << std::endl;

    return 0;
}

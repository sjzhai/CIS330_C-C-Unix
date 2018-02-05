#include <iostream>
#include "cipher.hpp"
#include "date.hpp"

//Constructor
DateCipher::DateCipher() : Cipher() {
}

// Destructor
DateCipher::~DateCipher() {
}

void DateCipher::setDate(std::string &date){
    this->date = date;
}

int DateCipher::TransitDate(char date){
    std::string num = "0123456789";
    for (int i = 0; i < 10; i++){
        if(date == num[i]){
            return i;
        }
    }
    return 0;
}
// Encrypt method
std::string DateCipher::encrypt( std::string &inputText ) {
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lower = "abcdefghijklmnopqrstuvwxyz";
	std::string text = inputText;
	std::string::size_type len = text.length();
    int num = 0;
    for (int i = 0; i < len; i++){
        if (text[i] != ' '){
            int key = TransitDate(date[num%6]);
            for (int j = 0; j < 26; j++){
                if (text[i] == lower[j]){
                    text[i] = lower[(j+key) % 26];
                    break;
                }
                if (text[i] == upper[j]){
                    text[i] = upper[(j+key) % 26];
                    break;
                }
                
            }
            num += 1;
        }
    }
    return text;
}

// Decrypt method
std::string DateCipher::decrypt( std::string &text ) {
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lower = "abcdefghijklmnopqrstuvwxyz";
	std::string DeText = text;
	std::string::size_type Delen = DeText.length();
	int num = 0;
    for (int i = 0; i < Delen; i++){
        if (DeText[i] != ' '){
            int key = TransitDate(date[num%6]);
            for (int j = 0; j < 26; j++){
                if (DeText[i] == lower[j]){
                    int str = j-key;
                    while(str < 0){
                        str+=26;
                    }
                    DeText[i] = lower[str % 26];
                    break;
                }
                if (DeText[i] == upper[j]){
                    int str = j-key;
                    while(str < 0){
                        str+=26;
                    }
                    DeText[i] = upper[str % 26];
                    break;
                }
                
            }
            num += 1;
        }
    }
    return DeText;

}
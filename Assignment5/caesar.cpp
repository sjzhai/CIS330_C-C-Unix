#include <iostream>
#include "cipher.hpp"
#include "caesar.hpp"

//Constructor
CaesarCipher::CaesarCipher() : Cipher() {
}

// Destructor
CaesarCipher::~CaesarCipher() {
}

// Set the shift keys
void CaesarCipher::setKey(int key){
    this->key = key;
}

// Encrypt method
std::string CaesarCipher::encrypt( std::string &inputText) {
	std::string text = inputText;
	std::string::size_type len = text.length();
	for (int i = 0; i < len; ++i) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            int place = text[i] + key;
            if(place > 'Z'){
                int str = place - 'Z';
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'A' + str - 2;
                }
            }else if(place < 'A'){
                int str = 'A' - place;
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'Z' - str + 2;
                }
            }
            text[i] = place;
        }else if(text[i] >= 'a' && text[i] <= 'z') {
            int place = text[i] + key;
            if(place > 'z'){
                int str = place - 'z';
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'a' + str - 2;
                }
            }else if(place < 'a'){
                int str = 'a' - place;
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'z' - str + 2;
                }
            }
            text[i] = place;
        }else if(text[i] == ' '){
            if(key > 0){
                text[i] = 'a' + key - 1;
            }else{
                text[i] = 'z' + key + 1;
            }
        }
	}
	return text;
}

// Decrypt method
std::string CaesarCipher::decrypt( std::string &text) {
    int negkey = -key;
	std::string DeText = text;
	std::string::size_type Delen = DeText.length();
	for (int i = 0; i < Delen; ++i) {
        if(DeText[i] >= 'A' && DeText[i] <= 'Z') {
            int place = DeText[i] + negkey;
            if(place > 'Z'){
                int str = place - 'Z';
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'A' + str - 2;
                }
            }else if(place < 'A'){
                int str = 'A' - place;
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'Z' - str + 2;
                }
            }
            DeText[i] = place;
        }else if(DeText[i] >= 'a' && DeText[i] <= 'z') {
            int place = DeText[i] + negkey;
            if(place > 'z'){
                int str = place - 'z';
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'a' + str - 2;
                }
            }else if(place < 'a'){
                int str = 'a' - place;
                if(str == 1){
                    place = ' ';
                }else{
                    place = 'z' - str + 2;
                }
            }
            DeText[i] = place;
        }else if(DeText[i] == ' '){
            if(negkey > 0){
                DeText[i] = 'a' + negkey - 1;
            }else{
                DeText[i] = 'z' + negkey + 1;
            }
        }
    }
    return DeText;
}
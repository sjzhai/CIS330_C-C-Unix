#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "date.hpp"

#define DATE 121846
int main(int argc, const char *argv[]) {
	DateCipher Date;
//	std::cout << "Please enter a specific date. For example (mmddyy): ";
//	std::cin >> date;
    std::string date = std::to_string(DATE);
	Date.setDate(date);
	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text:" << std::endl << input;
    
	encrypted = Date.encrypt(input);
	std::cout << "Encrypted text:" << std::endl << encrypted;
    
	decrypted = Date.decrypt(encrypted);
	std::cout << "Decrypted text:" << std::endl << decrypted;

	if (decrypted == input) std::cout << "Decrypted text matches input!" << std::endl;
	else {
		std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
		return 1;   // Make sure to return a non-zero value to indicate failure
	}

	return 0;
}

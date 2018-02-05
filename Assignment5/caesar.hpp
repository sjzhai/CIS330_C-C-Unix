
#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class CaesarCipher : public Cipher {
public:
	CaesarCipher();
	virtual ~CaesarCipher();
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
	virtual void setKey(int key);
private:
	int key;
};

#endif /* CAESAR_HPP_ */
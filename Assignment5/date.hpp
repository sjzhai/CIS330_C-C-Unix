#ifndef DATE_HPP_
#define DATE_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
	DateCipher();
	virtual ~DateCipher();
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
	virtual void setDate(std::string &date);
	virtual int TransitDate(char date);
private:
	std::string date;
};

#endif /* DATE_HPP_ */

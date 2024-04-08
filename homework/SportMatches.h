#pragma once
#include <string>
class SportMatches {
private:
	std::string _teamname;
	std::string _country;
	int _numberofplayers = 0;
public:
	friend std::istream& operator>>(std::istream& in, SportMatches& match);
	friend std::ostream& operator<<(std::ostream& out, const SportMatches& match);
	std::string teamname() const;
	std::string country() const;

	void setName(const std::string teamname);
	void setCountry(const std::string country);

	int numberofplayers();
	void setNumber(int numberofplayers);
};

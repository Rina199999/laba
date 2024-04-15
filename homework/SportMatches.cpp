#pragma once
#include "SportMatches.h"
#include <fstream>
#include <iostream>
using namespace std;
string SportMatches::teamname()
const {
	return _teamname;
}
void SportMatches::setName(string teamname) {
	if (teamname != _teamname)
		_teamname = teamname;
}
string SportMatches::country()
const {
	return _country;
}
void SportMatches::setCountry(string country) {
	if (country != _country)
		_country = country;
}
int SportMatches::numberofplayers() {
	return _numberofplayers;
}
void SportMatches::setNumber(int numberofplayers) {
	if (numberofplayers != _numberofplayers)
		_numberofplayers = numberofplayers;
}
istream& operator>>(std::istream& in, SportMatches& match) {
    cout << "Enter team name: ";
    in >> match._teamname;
    cout << "Enter country: ";
    in >> match._country;
    cout << "Enter number of players: ";
    in >> match._numberofplayers;
    return in;
}

ostream& operator<<(std::ostream& out, const SportMatches& match) {
    out << "Team Name: " << match._teamname << std::endl;
    out << "Country: " << match._country << std::endl;
    out << "Number of Players: " << match._numberofplayers << std::endl;
    return out;
}
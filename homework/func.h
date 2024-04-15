#pragma once

#include "SportMatches.h"

namespace func {
	void save(SportMatches* arr, const int& n);
	SportMatches* load(int& n);
	int ch(int* m);
	void create(SportMatches** arr, int* n);
	void find(SportMatches* arr, int* n, int nn);
	void edit(SportMatches* arr);
	void read(SportMatches** arr, int* n);
	void removeElement(SportMatches*& arr, int& n, int index);
	void addElemement(SportMatches*& arr, int& n, const SportMatches& newMatch);
}

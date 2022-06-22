#include "stdafx.h"
#pragma once

struct Sportsman
{
	std::string name;
	unsigned int height;
	unsigned int weight;
};

template <typename T>
bool LessThan(T const& a, T const& b)
{
	return a < b;
}

template <>
bool LessThan(const char* const& a, const char* const& b)
{
	return strcmp(a, b) < 0;
}

bool ComparatorHeight(Sportsman const& a, Sportsman const& b)
{
	return a.height < b.height;
}

bool ComparatorWeight(Sportsman const& a, Sportsman const& b)
{
	return a.weight < b.weight;
}

template < typename T, typename Less >
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	auto it = std::max_element(std::begin(arr), std::end(arr), less);

	maxValue = *it;

	return true;
}
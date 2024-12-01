#ifndef WAVELET_H
#define WAVELET_H
#include <vector>
#include "bases.h"

class TWavelet
{
protected:
	std::vector<double> Coeffs;
public:
	TWavelet() = default;
	TWavelet(std::vector<double> c) { Coeffs = c; };
	virtual void Transformation(std::vector<float>& data) const = 0;
	virtual void InverseConversation(std::vector<float>& data) const = 0;
	~TWavelet() {};
};
#endif
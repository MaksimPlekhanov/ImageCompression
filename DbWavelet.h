#ifndef DBWAVELET_H
#define DBWAVELET_H
#include "Wavelet.h"

class TDbWavelet : public TWavelet
{
	std::vector<double> LowCoeffs;
	std::vector<float> DecompBase;
	std::vector<float> LowDecompBase;
public:
	TDbWavelet() : TWavelet() {};
	TDbWavelet(int base_num){
		Coeffs.resize(base_num);
		for (size_t i = 0; i < Coeffs.size(); i++) 
			Coeffs[i] = Db_bases[base_num / 2 - 1][i];
		LowCoeffs.resize(Coeffs.size());
		int sign = 1;
		if (base_num == 2)
			sign *= -1;
		for (int i = Coeffs.size() - 1; i >= 0; i--) {
			LowCoeffs[Coeffs.size() - 1 - i] = sign * Coeffs[i];
			sign *= -1;
		}
		sign = 1;
		DecompBase.reserve(base_num);
		LowDecompBase.resize(base_num);
		for (int i = Coeffs.size() - 2; i >= 0; i -= 2) {
			DecompBase.push_back(Coeffs[i]);
			DecompBase.push_back(LowCoeffs[i]);
		}
		for (int i = DecompBase.size() - 1; i >= 0; i--) {
			int ind = DecompBase.size() - 1 - i;
			LowDecompBase[ind] = sign * DecompBase[i];
			sign *= -1;
		}
	};
	int GetBaseSize() { return Coeffs.size(); };
	void ChangeWavelet(std::vector<double> c) { Coeffs = c; };
	virtual void Transformation(std::vector<float>& data) const;
	virtual void InverseConversation(std::vector<float>& data) const;
	~TDbWavelet() {};
};

void TDbWavelet::Transformation(std::vector<float>& data) const {
	std::vector<float> high_val;
	std::vector<float> low_val;
	high_val.reserve(data.size() / 2);
	low_val.reserve(data.size() / 2);
	int buf;
	float fbufh = 0, fbufl = 0;
	for (int i = 0; i < data.size(); i += 2) {
		buf = i;
		for (int c = 0; c < Coeffs.size(); c++) {
			int indl = i % data.size();
			int indh = i % data.size();
			fbufl = fbufl + data[indl] * Coeffs[c];
			fbufh = fbufh + data[indh] * LowCoeffs[c];
			i++;
		}
		low_val.push_back(fbufl);
		high_val.push_back(fbufh);
		i = buf;
		fbufh = 0;
		fbufl = 0;
	}
	data.clear();
	data = low_val;
	for (int i = 0; i < high_val.size(); ++i) 
		data.push_back(high_val[i]);
}

void TDbWavelet::InverseConversation(std::vector<float>& data) const {
	std::vector<float> data_copy;
	data_copy.reserve(data.size());
	for (int i = 0; i < data.size() / 2; i++) {
		data_copy.push_back(data[i]);
		data_copy.push_back(data[i + data.size() / 2]);
	}
	data = data_copy;
	data_copy.clear();
	int buf;
	float fbuf1 = 0, fbuf2 = 0;
	for (int i = -(DecompBase.size()) + 2 + data.size(); i < -(DecompBase.size()) + 2 + 2 * data.size(); i += 2){
		buf = i;
		for (int c = 0; c < DecompBase.size(); c++) {
			int ind1 = i % data.size();
			int ind2 = i % data.size();
			fbuf1 = fbuf1 + data[ind1] * DecompBase[c];
			fbuf2 = fbuf2 + data[ind2] * LowDecompBase[c];
			i++;
		}
		data_copy.push_back(fbuf1);
		data_copy.push_back(fbuf2);
		i = buf;
		fbuf1 = 0;
		fbuf2 = 0;
	}
	data = data_copy;
}

#endif
#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H
#include <vector>
#include <iostream>
#include "DbWavelet.h"

namespace IPr
{
    float Clamp(float px) {
        if (px > 255.0)
            return 255.0;
        if (px < 0.0)
            return 0.0;
        return px;
    }

    void Decimate(std::vector<std::vector<float>>& data, float importance) {
        if (!importance) return;
        for (int i = 0; i < data.size(); i++)
            for (int j = 0; j < data[i].size(); j++)
                if (abs(data[i][j]) <= importance) data[i][j] = 0.0;
    }

    bool DbCompressing(int base_num, std::vector<std::vector<float>>& data) {
        TDbWavelet dw(base_num);
        int nrow = data.size(), ncol = data[0].size();
        while (nrow >= dw.GetBaseSize() && ncol >= dw.GetBaseSize()) { // пока есть возможность сжатия
            if (nrow % 2 == 1 && nrow != 1) nrow++;
            if (ncol % 2 == 1 && ncol != 1) ncol++;
            std::vector<float> datarow;
            datarow.resize(ncol);
            for (int i = 0; i < nrow; i++) { // по всем строкам
                for (int j = 0; j < ncol; ++j)
                    datarow[j] = data[i][j];
                dw.Transformation(datarow);
                for (int j = 0; j < ncol; ++j)
                    data[i][j] = datarow[j];
            }
            std::vector<float> datacol;
            datacol.resize(nrow);
            for (int i = 0; i < ncol; ++i) { // по всем столбцам
                for (int j = 0; j < nrow; j++)
                    datacol[j] = data[j][i];
                dw.Transformation(datacol);
                for (int j = 0; j < nrow; j++)
                    data[j][i] = datacol[j];
            }
            nrow /= 2;
            ncol /= 2;
        }
        return 1;
    }

    bool DbDecompressing(int base_num, std::vector<std::vector<float>>& data) {
        TDbWavelet dw(base_num);
        int nrow = data.size(), ncol = data[0].size();
        std::vector<int> odd_row;
        std::vector<int> odd_col;
        while (nrow >= dw.GetBaseSize() && ncol >= dw.GetBaseSize()) {
            nrow /= 2;
            ncol /= 2;
            if (nrow % 2 == 1 && nrow != 1) odd_row.push_back(nrow);
            if (ncol % 2 == 1 && ncol != 1) odd_col.push_back(ncol);
        }
        
        while (nrow < data.size() && ncol < data.size()) { // пока есть возможность декомпрессии
            nrow *= 2;
            ncol *= 2;
            if (odd_row.size() && nrow - 1 == *(odd_row.end() - 1) && nrow != 1) { nrow--; odd_row.pop_back(); }
            if (odd_col.size() && ncol - 1 == *(odd_col.end() - 1) && ncol != 1) { ncol--; odd_col.pop_back(); }
            std::vector<float> datarow;
            datarow.resize(ncol);
            for (int i = 0; i < nrow; i++) { // по всем строкам
                for (int j = 0; j < ncol; ++j)
                    datarow[j] = data[i][j];
                dw.InverseConversation(datarow);
                for (int j = 0; j < ncol; ++j)
                    data[i][j] = datarow[j];
            }
            std::vector<float> datacol;
            datacol.resize(nrow);
            for (int i = 0; i < ncol; ++i) { // по всем столбцам
                for (int j = 0; j < nrow; j++)
                    datacol[j] = data[j][i];
                dw.InverseConversation(datacol);
                for (int j = 0; j < nrow; j++)
                    data[j][i] = datacol[j];
            }
        }
        return 1;
    }
}
#endif
#include "DilemmaHeader.h"

bool CheckMatrix(int pay_off_matrix[8][6]) {
	for (int i = 0; i < 7; i++) {
		int tmp1[6] = { 0 };
		for (int j = 0; j < 6; j++) {
			if (pay_off_matrix[i][j] == 'D') {
				pay_off_matrix[i][j] = 1;
				tmp1[j] = 1;
			}
			else if (pay_off_matrix[i][j] == 'C') {
				pay_off_matrix[i][j] = 0;
				tmp1[j] = 0;
			}
			else tmp1[j] = pay_off_matrix[i][j];
		}
		int tmp12 = tmp1[0] * 100 + tmp1[1] * 10 + tmp1[2];
		//посчитали первую строку

		for (int j = 1; j < 8; j++) {
			int tmp2[6] = { 0 };
			for (int j2 = 0; j2 < 6; j2++) {
				if (pay_off_matrix[i + 1][j2] == 'D') {
					pay_off_matrix[i + 1][j2] = 1;
					tmp2[j2] = 1;
				}
				else if (pay_off_matrix[i + 1][j2] == 'C') {
					pay_off_matrix[i + 1][j2] = 0;
					tmp2[j2] = 0;
				}
				tmp2[j2] = pay_off_matrix[i + 1][j2];
			}
			int tmp22 = tmp2[0] * 100 + tmp2[1] * 10 + tmp2[2];
			//посчитали вторую


			if (tmp22 < tmp12) {
				int buffer[6];
				for (int k = 1; k < 6; k++) {
					buffer[k] = pay_off_matrix[j][k];
				}
				for (int k = 1; k < 6; k++) {
					tmp2[k] = pay_off_matrix[i][k];
					pay_off_matrix[i][k] = buffer[k];
				}
			}
			//сравнили и заменили
		}
	}

	return true;
}

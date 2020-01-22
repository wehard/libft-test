#include <stdio.h>
#include <curses.h>
#include <math.h>

// This function is to find the determinant value of matrix . . .

float determin(float matrix[4][4], int k) {
	float deter = 0.0, z = 1.0, mt[4][4];
	int a, b, c, x, y;
	if (k == 1) {
		return (matrix[0][0]);
	} else {
		deter = 0;
		for (a = 0; a < k; ++a) {
			x = 0;
			y = 0;
			for (b = 0; b < k; ++b) {
				for (c = 0; c < k; ++c) {
					mt[b][c] = 0;
					if ((b != 0) && (c != a)) {
						mt[x][y] = matrix[b][c];
						if (y < (k - 2))
							y++;
						else {
							y = 0;
							x++;
						}
					}
				}
			}
			deter = deter + z * (matrix[0][a] * determin(mt, k - 1));
			z = -1 * z;
		}
	}
	return (deter);
}

void trans(float matr[4][4], float m1[4][4], int r) {
	float inv_matrix[4][4], tran[4][4], d;
	int a, b;
	for (a = 0; a < r; ++a) {
		for (b = 0; b < r; ++b) {
			tran[a][b] = m1[b][a];
		}
	}
	d = determin(matr, r);
	for (a = 0; a < r; ++a) {
		for (b = 0; b < r; ++b) {
			inv_matrix[a][b] = tran[a][b] / d;
		}
	}
	printf("\n\n\n The Inverse of matrix of  4 x 4 matrix is . . . \n\n");
	for (a = 0; a < r; ++a) {
		for (b = 0; b < r; ++b)
			printf("\t%f", inv_matrix[a][b]);
		printf("\n\n");
	}
}

void cofac(float comatr[4][4], int f) {
	float matr[4][4], cofact[4][4];
	int a, b, c, d, x, y;
	for (c = 0; c < f; ++c) {
		for (d = 0; d < f; ++d) {
			x = 0;
			y = 0;
			for (a = 0; a < f; ++a) {
				for (b = 0; b < f; ++b) {
					if (a != c && b != d) {
						matr[x][y] = comatr[a][b];
						if (y < (f - 2))
							y++;
						else {
							y = 0;
							x++;
						}
					}
				}
			}
			cofact[c][d] = pow(-1, c + d) * determin(matr, f - 1);
		}
	}
	trans(comatr, cofact, f);
}

// This function is to transpose of matrix . . .

int main() {
	float matrix[4][4], deter;
	int a, b, row, col;
	printf("Enter the elements of %d X %d matrix : \n", 4, 4);
	for (a = 0; a < 4; ++a) {
		for (b = 0; b < 4; ++b) {
			scanf("%f", & matrix[a][b]);
		}
	}
	deter = determin(matrix, 4);
	printf("\n The Determinant of the Matrix is : %f", deter);
	if (deter == 0)
		printf("\n Inverse of Matrix is not possible for the matrices having 0 Determinant value !!\n");
	else
		cofac(matrix, 4);
	return (0);
}

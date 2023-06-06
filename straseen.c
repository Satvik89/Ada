#include <stdio.h>

void stressen(int a[10][10], int b[10][10], int c[10][10], int n) {
    int i, j, mid;

    if (n <= 2) {
        c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
        return;
    } else {
        mid = n / 2;

        int a11[10][10], a12[10][10], a21[10][10], a22[10][10];
        int b11[10][10], b12[10][10], b21[10][10], b22[10][10];
        int c11[10][10], c12[10][10], c21[10][10], c22[10][10];
        int p[10][10], q[10][10], r[10][10], s[10][10], t[10][10], u[10][10], v[10][10];

        // Partition input matrices into submatrices
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + mid];
                a21[i][j] = a[i + mid][j];
                a22[i][j] = a[i + mid][j + mid];

                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + mid];
                b21[i][j] = b[i + mid][j];
                b22[i][j] = b[i + mid][j + mid];
            }
        }

        // Recursive calls to calculate intermediate matrices
        stressen(a11, b11, p, mid);
        stressen(a12, b21, q, mid);
        stressen(a11, b12, r, mid);
        stressen(a12, b22, s, mid);
        stressen(a21, b11, t, mid);
        stressen(a22, b21, u, mid);
        stressen(a21, b12, v, mid);

        // Combine intermediate matrices to get the result
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                c11[i][j] = p[i][j] + s[i][j] - t[i][j] + v[i][j];
                c12[i][j] = r[i][j] + t[i][j];
                c21[i][j] = q[i][j] + s[i][j];
                c22[i][j] = p[i][j] + r[i][j] - q[i][j] - u[i][j];
                
            }
        }

        // Combine submatrices to form the result matrix
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                c[i][j] = c11[i][j];
                c[i][j + mid] = c12[i][j];
                c[i + mid][j] = c21[i][j];
                c[i + mid][j + mid] = c22[i][j];
            }
        }
    }
}

int main() {
    int i, j, n, a[10][10], b[10][10], c[10][10];

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    stressen(a, b, c, n);

    printf("The product of the matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

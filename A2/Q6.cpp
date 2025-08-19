#include <bits/stdc++.h>
using namespace std;

struct Triplet {
    int row, col, val;
};

void display(vector<Triplet> &mat) {
    cout << "Row Col Val\n";
    for (auto &t : mat) {
        cout << t.row << "   " << t.col << "   " << t.val << "\n";
    }
}

vector<Triplet> transpose(vector<Triplet> &mat, int rows, int cols) {
    vector<Triplet> trans;
    for (int i = 0; i < cols; i++) {
        for (auto &t : mat) {
            if (t.col == i) {
                trans.push_back({t.col, t.row, t.val});
            }
        }
    }
    return trans;
}


vector<Triplet> add(vector<Triplet> &A, vector<Triplet> &B) {
    vector<Triplet> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result.push_back(A[i++]);
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result.push_back(B[j++]);
        } else { 
            int sum = A[i].val + B[j].val;
            if (sum != 0)
                result.push_back({A[i].row, A[i].col, sum});
            i++; j++;
        }
    }
    while (i < A.size()) result.push_back(A[i++]);
    while (j < B.size()) result.push_back(B[j++]);

    return result;
}


vector<Triplet> multiply(vector<Triplet> &A, vector<Triplet> &B, int n) {
    vector<Triplet> result;
    
    vector<Triplet> B_T = transpose(B, n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (auto &a : A) {
                if (a.row == i) {
                    for (auto &b : B_T) {
                        if (b.row == j && b.col == a.col) {
                            sum += a.val * b.val;
                        }
                    }
                }
            }
            if (sum != 0) result.push_back({i, j, sum});
        }
    }
    return result;
}

int main() {
 
    vector<Triplet> A = {{0,0,1}, {0,2,2}, {1,1,3}, {2,0,4}};
    vector<Triplet> B = {{0,1,5}, {1,1,6}, {2,0,7}, {2,2,8}};

    cout << "Matrix A:\n"; display(A);
    cout << "Matrix B:\n"; display(B);

    cout << "\nTranspose of A:\n";
    vector<Triplet> AT = transpose(A, 3, 3);
    display(AT);

    cout << "\nAddition (A + B):\n";
    vector<Triplet> addRes = add(A, B);
    display(addRes);

    cout << "\nMultiplication (A * B):\n";
    vector<Triplet> mulRes = multiply(A, B, 3);
    display(mulRes);

    return 0;
}

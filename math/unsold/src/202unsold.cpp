/*
** EPITECH PROJECT, 2022
** unsold
** File description:
** 202unsold.cpp
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

void print_help() {
    cout << "USAGE" << endl;
    cout << "\t./202unsold a b" << endl;
    cout << "DESCRIPTION" << endl;
    cout << "\ta constant computed from past results" << endl;
    cout << "\tb constant computed from past results" << endl;
    exit(84);
}

void check_args(int argc, char* argv[], int &a, int &b) {
    if (argc < 2 || argc > 3) {
        cerr << "Error: At least two arguments are required." << endl;
        exit(84);
    }
    if (argc == 2) {
        if (string(argv[1]) != "-h") {
            cerr << "Error: Second argument must be -h." << endl;
            exit(84);
        } else {
            print_help();
        }
    } else {
        try {
            a = stoi(argv[1]);
            b = stoi(argv[2]);
        } catch (invalid_argument& e) {
            print_help();
        }

        if (a <= 50 || b <= 50) {
            cerr << "Error: a and b must be greater than 50." << endl;
            exit(84);
        }
    }
}

void joint_law(int a, int b, double X_Y[][5], double X[], double Y[]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = 10 * (i + 1);
            int y = 10 * (j + 1);
            double prob = ((a - x) * (b - y)) / ((5.0 * a - 150) * (5.0 * b - 150));
            X_Y[i][j] = prob;
            X[i] += prob;
            Y[j] += prob;
        }
    }
}

void z_law(double X_Y[][5], double Z[]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = 10 * (i + 1);
            int y = 10 * (j + 1);
            int z = x + y;
            int index = (z - 20) / 10;
            Z[index] += X_Y[i][j];
        }
    }
}

double expected_value(double law[], int size) {
    double ev = 0;

    for (int i = 0; i < size; i++) {
        ev += (i + 2) * 10 * law[i];
    }

    return ev;
}

double variance(double law[], double ev, int size) {
    double var = 0;

    for (int i = 0; i < size; i++) {
        var += pow((i + 2) * 10 - ev, 2) * law[i];
    }

    return var;
}

void print_laws(double X_Y[][5], double X[], double Y[], double Z[]) {
cout << "--------------------------------------------------------------------------------" << endl;
cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << endl;
for (int j = 0; j < 5; j++) {
    cout << "Y=" << fixed << setprecision(3) << (j + 1) * 10 << "\t";
    for (int i = 0; i < 5; i++) {
        cout << X_Y[i][j] << "\t";
    }
    cout << fixed << setprecision(3) << Y[j] << endl;
}

cout << "X law" << "\t";
for (int i = 0; i < 5; i++) {
    cout << X[i] << "\t";
}
cout << fixed << setprecision(3) << "1.000" << endl;

cout << "--------------------------------------------------------------------------------" << endl;
cout << "z" << "\t";
for (int i = 0; i < 9; i++) {
    cout << fixed << setprecision(3) << 20 + i * 10 << "\t";
}
cout << endl;

cout << "p(Z=z)" << "\t";
for (int i = 0; i < 9; i++) {
    cout << Z[i] << "\t";
}
cout << endl;
}

int main(int argc, char* argv[]) {
    int a, b;
    double X_Y[5][5] = {};
    double X[5] = {};
    double Y[5] = {};
    double Z[9] = {};

    check_args(argc, argv, a, b);
    joint_law(a, b, X_Y, X, Y);
    z_law(X_Y, Z);
    print_laws(X_Y, X, Y, Z);

    double ev_x = expected_value(X, 5);
    double ev_y = expected_value(Y, 5);
    double ev_z = expected_value(Z, 9);
    double var_x = variance(X, ev_x, 5);
    double var_y = variance(Y, ev_y, 5);
    double var_z = variance(Z, ev_z, 9);

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "expected value of X:\t" << fixed << setprecision(1) << ev_x - 10 << endl;
    cout << "variance of X:\t\t" << fixed << setprecision(1) << var_x << endl;
    cout << "expected value of Y:\t" << fixed << setprecision(1) << ev_y - 10 << endl;
    cout << "variance of Y:\t\t" << fixed << setprecision(1) << var_y << endl;
    cout << "expected value of Z:\t" << fixed << setprecision(1) << ev_z << endl;
    cout << "variance of Z:\t\t" << fixed << setprecision(1) << var_z << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    return 0;
}
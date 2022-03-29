#include <iostream>
#include <cmath>

float const pi = 3.1415;

float mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float* x = new (std::nothrow) float[size];
    if (x == nullptr) {
        std::cout << "Error in memory alocation";
        delete[] x;
        return 0;
    }
    for (unsigned i = 0; i < size; i++) {
        x[i] = psi[i] * pdf[i];
    }
    int partition = 1;
    while (1 <= size / partition) {
        for (unsigned i = 0; i < size; i += 2 * partition) {
            if ((i + partition) < size)
                x[i] = x[i] + x[i + partition];
            else
                x[i] = x[i];
        }
        partition *= 2;
    }
    float sum = x[0];
    delete[] x;
    return dv * sum;
}

float recursion(float const psi[], float const pdf[], float const dv, unsigned size, int from, int till) {
    if (from == till) {
        return psi[from] * pdf[from] * dv;
    }
    return (recursion(psi, pdf, dv, size, from, (from + (till - from) / 2)) +
        recursion(psi, pdf, dv, size, (from + 1 + (till - from) / 2), till));
}

float forward_kahan_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    float error = 0.f;
    for (unsigned i = 0; i < size; i++) {
        float y = psi[i] * pdf[i] - error;
        float z = sum + y;
        error = (z - sum) - y;
        sum = z;
    }
    return sum * dv;
}


float fma_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    for (unsigned i = 0; i < size; i++) {
        sum = fma(pdf[i], psi[i], sum);
    }
    return sum * dv;
}

float simple_sum(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    for (unsigned i = 0; i < size; i++) {
        sum += pdf[i] * psi[i];
    }
    return sum * dv;
}

void function_generator(float pdf[], float psi[], float T, unsigned size) {
    for (int i = 0; i < size; i++) {

        pdf[i] = exp(-i * i / T) / sqrt(T * pi);

        psi[i] = 1;
    }
}

void lab() {
    using namespace std;

    unsigned size;
    cin >> size;
    float T;
    cin >> T;
    float* pdf = new float[size];
    float* psi = new float[size];

    function_generator(pdf, psi, T, size);

    cout << simple_sum(psi, pdf, 8 * sqrt(T) / (size - 1), size);
    cout << recursion(psi, pdf, 8 * sqrt(T) / (size - 1), size, 0, size - 1) << "  ";
    cout << mean(psi, pdf, 8 * sqrt(T) / (size - 1), size) << "  ";
    cout << forward_kahan_mean(psi, pdf, 8 * sqrt(T) / (size - 1), size) << "  ";
    cout << fma_mean(psi, pdf, 8 * sqrt(T) / (size - 1), size) << "  ";

    delete[] pdf;
    delete[] psi;

    return;
}

int main() {
    lab();
    return 0;
}

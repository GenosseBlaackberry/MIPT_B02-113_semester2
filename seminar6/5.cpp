#include <iostream>
#include <cmath>

float const T = 100.f;
float const d_pi = 3.1415;

float prob_func(float x, float T) {
    return exp(-x * x / T) / sqrt(T * d_pi);
}

void create_arrays(float pdf[], float psi[], float T, unsigned size) {
    for (unsigned i = 0; i < size; i++) {

        pdf[i] = prob_func(-4 * sqrt(T) + i * 8 * sqrt(T) / (size - 1), T);

        psi[i] = abs(-4 * sqrt(T) + i * 8 * sqrt(T) / (size - 1));
    }
}

float mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float* x = new (std::nothrow) float;
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

float recursion(float const psi[], float const pdf[], float const dv, unsigned from, unsigned till) {
    if (from == till) {
        return psi[from] * pdf[from] * dv;
    }
    float* first = new (std::nothrow) float;
    if (first == nullptr) {
        std::cout << "Error in memory alocation";
        delete first;
        return 0;
    }
    float* second = new (std::nothrow) float;
    if (second == nullptr) {
        std::cout << "Error in memory alocation";
        delete second;
        return 0;
    }
    *first = recursion(psi, pdf, dv, from, (from + (till - from) / 2));
    *second = recursion(psi, pdf, dv, (from + 1 + (from - till) / 2), till);
    float output = *first + *second;
    delete first;
    delete second;
    return output;
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

float naive_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    for (unsigned i = 0; i < size; i++) {
        sum += pdf[i] * psi[i];
    }
    return sum * dv;
}

void lab() {
    using namespace std;

    unsigned size = 1000;
    float* pdf = new float[size];
    float* psi = new float[size];

    create_arrays(pdf, psi, T, size);


    std::cout << recursion(psi, pdf, 8 * sqrt(T) / (size - 1), 0, size - 1) << "  ";
    std::cout << mean(psi, pdf, 8 * sqrt(T) / (size - 1), size) << "  ";
    std::cout << forward_kahan_mean(psi, pdf, 8 * sqrt(T) / (size - 1), size) << "  ";
    std::cout << fma_mean(psi, pdf, 8 * sqrt(T) / (size - 1), size) << "  ";
    std::cout << naive_mean(psi, pdf, 8 * sqrt(T) / (size - 1), size);

    delete[] pdf;
    delete[] psi;

    return;
}

int main() {
    lab();
    return 0;
}

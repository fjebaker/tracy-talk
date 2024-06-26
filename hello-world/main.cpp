#include <iostream>
#include <vector>
#include <random>
#include <tracy/Tracy.hpp>

std::vector<std::vector<float>> random_matrix(int rows, int cols) {
    ZoneScoped;
    std::vector<std::vector<float>> matrix(rows, std::vector<float>(cols));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = dis(gen);
        }
    }

    return matrix;
}

std::vector<std::vector<float>> matrix_multiply(const std::vector<std::vector<float>>& matrix1, const std::vector<std::vector<float>>& matrix2) {
    ZoneScoped;

    int m = matrix1.size();
    int n = matrix1[0].size();
    int p = matrix2[0].size();

    std::vector<std::vector<float>> result(m, std::vector<float>(p, 0));

    for (int i = 0; i < m; ++i) {
        ZoneScoped;
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    std::cout << "Hello World" << std::endl;

    FrameMarkStart("init 1");
    auto matrix1 = random_matrix(1000, 1000);
    FrameMarkEnd("init 1");

    FrameMarkStart("init 2");
    auto matrix2 = random_matrix(1000, 1000);
    FrameMarkEnd("init 2");

    FrameMarkStart("multiply");
    auto result = matrix_multiply(matrix1, matrix2);
    FrameMarkEnd("multiply");

    return 0;
}

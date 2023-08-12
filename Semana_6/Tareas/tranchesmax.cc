#include <iostream>
#include <vector>

int somme_consecutifs_max(const std::vector<int>& arr) {
    int max_sum = 0;
    int current_sum = 0;

    for (int num : arr) {
        if (num != 0) {
            current_sum += num;
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        } else {
            current_sum = 0;
        }
    }

    return max_sum;
}

std::vector<size_t> lignes_max(const std::vector<std::vector<int>>& matrix) {
    std::vector<size_t> result;
    int max_sum = 0;

    for (size_t i = 0; i < matrix.size(); i++) {
        int sum = somme_consecutifs_max(matrix[i]);
        if (sum == max_sum) {
            result.push_back(i);
        } else if (sum > max_sum) {
            result.clear();
            result.push_back(i);
            max_sum = sum;
        }
    }

    return result;
}

std::vector<std::vector<int>> tranches_max(const std::vector<std::vector<int>>& matrix) {
    std::vector<size_t> max_rows = lignes_max(matrix);

    // Extract the rows with maximal consecutive sum
    std::vector<std::vector<int>> result;
    for (size_t i : max_rows) {
        result.push_back(matrix[i]);
    }

    return result;
}

int main()
{
}

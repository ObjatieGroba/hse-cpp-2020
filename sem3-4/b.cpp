#include <iostream>
#include <vector>

int fibb(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return fibb(n-1) + fibb(n-2);
}

int main() {
    std::cout << fibb(3) << std::endl;

    std::vector<std::vector<int>> v2(3, std::vector<int>(2, 4));

//    std::vector<int>(3 * 2, 4);

    std::cout << v2[1][1] << std::endl;

//    i * n + j;
}

int max_ones(const std::vector<int> &nums) {
    size_t prev_ones = 0, cur_ones = 0;
    size_t cur_zeros;
    size_t max;
    for (size_t i = 0; i != nums.size(); ++i) {
        if (nums[i] == 1) {
            cur_zeros = 0;
            ++cur_ones;
        }
        ++cur_zeros;
        if (cur_zeros > 1) {
            continue;
        }
        if (prev_ones + cur_ones > max) {
            max = cur_ones + prev_ones;
        }
        prev_ones = cur_ones;
        cur_ones = 0;
    }
    return max;
}



int max_ones_good(std::vector<int> nums) {
    if (nums.empty()) {
        return 0;
    }
    nums.push_back(0);
    size_t prev_ones = 0, cur_ones = 0;
    bool was_prevs = false, prev_was_one = false;
    size_t cur_zeros = 0;
    size_t max = 0;
    for (size_t i = 0; i != nums.size(); ++i) {
        if (nums[i] == 1) {
            prev_was_one = true;
            if (cur_zeros != 0) {
                prev_ones = cur_ones;
                was_prevs = true;
                cur_ones = 0;
            }
            ++cur_ones;
            continue;
        }
        if (prev_was_one) {
            if (cur_zeros == 1 && was_prevs && prev_ones + cur_ones > max) {
                max = cur_ones + prev_ones;
            }
            cur_zeros = 0;
        }
        prev_was_one = false;
        ++cur_zeros;
    }
    if (cur_ones == nums.size()) {
        return cur_ones - 1;
    }
    return max;
}


#include <iostream>
#include <vector>

using namespace std;

vector<int> common1(const vector<int> &f, const vector<int> &s) {
    vector<int> pref, suf;
    for (size_t i = 0; i < min(f.size(), s.size()); ++i) {
        if (f[i] == s[i]) {
            pref.push_back(f[i]);
        } else {
            break;
        }
    }
    for (size_t i = 0; i < min(f.size(), s.size()); ++i) {
        if (f[f.size() - i - 1] == s[s.size() - i - 1]) {
            suf.push_back(f[f.size() - i - 1]);
        } else {
            break;
        }
    }
    vector<int> ans;
    for (size_t i = 0; i < pref.size(); ++i) {
        ans.push_back(pref[i]);
    }
    for (size_t i = 0; i < suf.size(); ++i) {
        ans.push_back(suf[suf.size() - i - 1]);
    }
    return ans;
}
//size_t save;
//vector<int> common2(const vector<int> &f, const vector<int> &s) {
//    vector<int> ans;
//    // для удобства считаем что первый короче второго
//    size_t len1 = f.size();
//    size_t len2 = s.size();
//    size_t len = min(len1, len2);
//    for (size_t i = 0; i != len; ++i) {
//        if (f[i] == s[i]) {
//            ans.push_back(f[i]);
//        } else {
//            save = i;
//            break;
//        }
//    }
//
//}

vector<int> common3(const vector<int> &f, const vector<int> &s) {
    if (f.size() > s.size()) {
        return common3(s, f);
    }
    size_t pref = 0;
    for (size_t i = 0; i != f.size(); ++i) {
        if (f[i] != s[i]) {
            pref = i;
            break;
        }
        if (i == f.size() - 1) {
            pref = f.size();
        }
    }
    size_t postf = 0;
    for (size_t i = 0; i != f.size(); ++i) {
        if (*(f.rbegin() + i) != *(s.rbegin() + i)) {
            postf = i;
            break;
        }
        if (i == f.size() - 1) {
            postf = f.size();
        }
    }
    std::vector<int> ans;
    std::copy(f.begin(), f.begin() + pref, back_insert_iterator(ans));
    std::copy(f.begin() + f.size() - postf, f.end(), back_insert_iterator(ans));
    return ans;
}


template <class Func>
bool test(const vector<int> &f, const vector<int> &s, const vector<int> &expected, Func func) {
    auto x = func(f, s);
    if (x.size() != expected.size()) {
        return false;
    }
    for (size_t i = 0; i != expected.size(); ++i) {
        if (expected[i] != x[i]) {
            std::cout << x[i] << ' ' << expected[i] << std::endl;
            return false;
        }
    }
    return true;
}

void test(const vector<int> &f, const vector<int> &s, const vector<int> &expected) {
    if (!test(f, s, expected, common1)) {
        std::cout << "Common 1 failed\n";
    }
    if (!test(f, s, expected, common3)) {
        std::cout << "Common 3 failed\n";
    }
}

void test_igr() {
    test({1, 2, 3, 4, 5}, {1, 2, 5}, {1, 2, 5});
    test({1, 2, 3, 4, 5}, {1, 2, 3, 6, 5}, {1, 2, 3, 5});
}
void test_dim() {
    test({1, 0, 2}, {1, 1, 2}, {1, 2});
}


void test_same() {
    test({1, 2, 3}, {1, 2, 3}, {1, 2, 3, 1, 2, 3});
}
void test_empty() {
    test({}, {1, 2, 3}, {});
    test({1, 2, 3}, {}, {});
    test({}, {}, {});
}

int main() {
//    test_igr();
//    test_dim();
//    test_same();
//    test_empty();
}

// you can use includes, for example:
 #include <unordered_set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    unordered_set<int> abs_dist;
    abs_dist.reserve(A.size()*2);
    for (auto a : A) {
        if (a<0) a *= -1;
        abs_dist.emplace(a);
    }
    return abs_dist.size();
}

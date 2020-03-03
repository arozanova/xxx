// you can use includes, for example:
#include <unordered_set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.size()==1) {
        return A[0];
    }
    
    
    std::unordered_set<int> unpaired;
    
    for (auto a : A) {
        // if this value present - remove
        auto search = unpaired.find(a);
        if (search == unpaired.end()) {
            unpaired.insert(a);
        }
        // else - add
        else {
            unpaired.erase(search);   
        }
    }
    
    return *(unpaired.begin());
    
}

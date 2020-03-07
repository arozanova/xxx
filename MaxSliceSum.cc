int solution(vector<int> &A) {
    int m = A[0];
    bool pos = false;
    
    // check if we have only negative numbers
    for (auto a : A ){
        m = min(m,a);
        if (a >= 0) {
            pos = true;
        }
    }
    
    // if we have no positive nubmers we return the maximum number
    if (!pos) {
        int minmax = m;
        for (auto a : A ){
            if (a < 0)
                minmax = max(minmax, a);
        }  
        return minmax;
    }

    // as we have positive numbers, we proceed the usual way
    int maxEnding = 0;
    int maxSlice = maxEnding;
    for (size_t i = 0; i < A.size(); ++i) {
        maxEnding = max(0, maxEnding+A[i]);
        maxSlice = max(maxSlice, maxEnding);
    }
    
    return maxSlice;
}

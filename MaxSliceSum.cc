// you can use includes, for example:
 #include <climits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int m=A[0];
    bool pos = false;
    
    for (auto a : A ){
        m = min(m,a);
        if (a >= 0) {
            pos = true;
        }

    }
    int minmax=m ;
    
    for (auto a : A ){
        if (a < 0)
            minmax = max(minmax,a);
    }
    if (!pos) 
        return minmax;
        
    //cout << m ;
    long  maxEnding  = 0;
    long  maxSlice = maxEnding;
    for (size_t i = 0; i < A.size(); ++i) {
        maxEnding = max(long(0), long(maxEnding+A[i]));
        maxSlice = max(maxSlice, maxEnding);
    }
    return int(maxSlice);
}

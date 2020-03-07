// you can use includes, for example:
  #include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // count number of peaks 
    
    if (A.size() == 1) {
        return 0;
    }
    
    int peaks = 0;
    vector<int> peakIndex;
    // special case for the very first
    if (A[0] > A[1]) {
        ++peaks;
        peakIndex.emplace(peakIndex.end(), 0);
    }
    
    for (size_t i = 1; i < A.size()-1; ++i) {
        if (A[i-1] < A[i] && A[i] > A[i+1]) {
            ++peaks;
            peakIndex.emplace(peakIndex.end(), i);
        }
    }
    // special case for the very last 
    if (A[A.size()-1] > A[A.size()-2]) {
        ++peaks;
        peakIndex.emplace(peakIndex.end(), A.size()-1);
    }
    
    cout << "peaks "  <<peaks<<endl;
    for (auto p : peakIndex) {
        cout << "peakIndex "  <<p<<endl;
    }
    
    int root = sqrt(A.size()-1);
    cout << "root "  <<root<<endl;
    int FLAGS = (peaks > root) ? root : peaks;
    cout << "flags "  <<FLAGS<<endl;
    
    int flags = FLAGS;
    int resFlags = 0;
    while ( flags > 0) {
        int maxFlags = 0;
        for (int i = 0; i < flags; ++i) {
            int tempFlags = 0;
            for (size_t p = 0; p < peakIndex.size(); ++p) {
                if (peakIndex[p]%flags == 0){
                    tempFlags++;
                }
            }
            if (tempFlags <= FLAGS)
                maxFlags = max(tempFlags, maxFlags);
        }
        resFlags = max(maxFlags, resFlags);
        --flags;
    }
    return resFlags;
}

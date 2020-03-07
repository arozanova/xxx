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
    int maxEnding = A[1];
    int maxSlice = 0;
    bool firstSliceDone = false;
    int firstSlice = 0;
    for (size_t i = 2; i < A.size(); ++i) {
        if (maxEnding == 0) continue;
        int maxEndingTemp = maxEnding;
        maxEnding = max(0, maxEnding+A[i]);
        
        if (maxEnding == 0) {
            if( firstSliceDone == false) {
            firstSlice = maxEndingTemp;
            firstSliceDone = true;
            }
            else {
                maxSlice = max(maxSlice, firstSlice + maxEndingTemp);
                firstSlice = 0;
                firstSliceDone = false;
            }
        }
        cout << "maxEnding " << maxEnding << " firstSlice " << firstSlice << " maxSlice "  << maxSlice << endl;
        
        
    }
    
    return maxSlice;
}

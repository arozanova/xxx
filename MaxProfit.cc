int solution(vector<int> &A) {
    
    if (A.size()<2)
        return 0;
    
    vector<int> diffs;
    diffs.reserve(A.size()*2);
    // compute the difference
    diffs.emplace(diffs.end(), 0);
    for (size_t i = 1; i < A.size(); ++i) {
        diffs.emplace(diffs.end(), (A[i]-A[i-1]));
    }
    
    
    
    int maxProfit = 0;
    int maxEnding = 0;
    for (auto d: diffs) {
        maxEnding = max(0, maxEnding + d);
        maxProfit = max(maxProfit, maxEnding);
    }
    
    if (maxProfit > 0) {
        return maxProfit;
    }
    return 0;
}

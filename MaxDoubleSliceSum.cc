
int solution(vector<int> &A) {
    int n = A.size();
    if (n==3) return 0;
    vector<int> leftToRight ( A.size(), 0);
    vector<int> rightToLeft ( A.size(), 0);

    int current = 0;
    for (size_t i = 1; i <A.size()-1; ++i) {
        current  = max (0, current + A[i]);
        leftToRight[i] = current;
    }


    current = 0;
    for (size_t i = A.size()-2; i >= 1; --i) { 
        current  = max (0, current + A[i]);
        rightToLeft[i] = current;

    }


    int m = 0;
    for (size_t i = 1; i <A.size()-1; ++i){
       m = max(leftToRight[i-1] + rightToLeft[i+1], m);
    }
    return m;
}

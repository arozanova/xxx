// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    long int MIN = -2147483648;
    long int maxSlice = MIN;
    long int currentSlice = 0;
    for (long int a : A){
        currentSlice = max(a, currentSlice+a);
        maxSlice = max(currentSlice, maxSlice);
    }
    return maxSlice;
}

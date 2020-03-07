long solution(int N) {
    long i = 1;
    long res = 0;
    while ( i * i <= N) {
        if (i * i ==N){
            ++res;
        }
        else {
            if (N % i == 0) {
                res +=2;
            }
        }
        ++i;
    }
    return res;
}

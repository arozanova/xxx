long solution(int N) {
    long minPerim = (N+1)*2;
    long a = 1;
    while (a*a<=N){
        if (N % a == 0) {
            long b = N/a;
            minPerim = min(minPerim, (a+b)*2) ;
        }
        ++a;   
    }
    return minPerim;
}

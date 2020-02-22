#include <stack>

int solution(vector<int> &A) {
    if (A.size()==0 ) {
        return -1;
    }
    if (A.size() == 1 )
        return 0;
  
    stack<int> leader; 
    for (size_t i = 0; i < A.size(); ++i) {
        if (leader.size() == 0){
            leader.push(A[i]);
        }
        else if (A[i]==leader.top()) {
            leader.push(A[i]);
        }
        else {
            leader.pop();
        }
    }
    if (leader.size()==0)
        return -1;
    int index = -1;
    int n = 0;
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] == leader.top()) {
            index = i;
            ++n;
        }
    }
    if (n < A.size()/2+1)
        index = -1;
    return index;
}

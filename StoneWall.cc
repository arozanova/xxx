#include <stack>

int solution(vector<int> &H ) {
    stack<int> cubes;
    int completeCubes = 0;
    
    for (size_t i = 0; i < H.size(); ++i) {
        while (( cubes.size() > 0 ) && (H[i] < cubes.top()) ) {
            cubes.pop();
            ++completeCubes;
        }
        if (( cubes.size() == 0 ) || (H[i] > cubes.top())) {
            cubes.push(H[i]);
        }
    }
    return completeCubes + cubes.size();
}

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void solution1( int input[], const int n, const int k, int output[] );
void solution2( int input[], const int n, const int k, int output[] );
void solution3( int input[], const int n, const int k, int output[] );

int main() {
    double duration;
    int randomNumber;

    const int n = 1000;
    const int k = 800;

    int *input1 = new int[n];
    int *input2 = new int[n];
    int *input3 = new int[n];

    int *output = new int[k];

    for (int i = 0; i < n; i++){
        randomNumber = rand() % n;
        input1[i] = randomNumber;
        input2[i] = randomNumber;
        input3[i] = randomNumber;
    }

    // TEST FOR SAME NUMBERS FOR DIFFERENT ARRAYS


    // END OF TEST -------------------------

    clock_t startTime = clock();

    solution1(input1, n, k, output);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout << "Execution1 took " << duration << " milliseconds." << std::endl;

    startTime = clock();

    solution2(input2, n, k, output);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout << "Execution2 took " << duration << " milliseconds." << std::endl;

    startTime = clock();

    solution3(input3, n, k, output);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout << "Execution3 took " << duration << " milliseconds." << std::endl;

    delete[] input1;
    delete[] input2;
    delete[] input3;
    delete[] output;

    return 0;
}





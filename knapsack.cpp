#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct KnapsackResult {
    int maxValue;
    vector<int> bestSelection;
};

void exhaustiveKnapsack(
    int index,
    const vector<int>& weights,
    const vector<int>& values,
    int capacity,
    int currentWeight,
    int currentValue,
    vector<int>& currentSelection,
    KnapsackResult& bestResult
) {
    int n = weights.size();

    if (currentWeight > capacity) {
        return;
    }

    if (index == n) {
        if (currentValue > bestResult.maxValue) {
            bestResult.maxValue = currentValue;
            bestResult.bestSelection = currentSelection;
        }
        return;
    }

    currentSelection[index] = 0;
    exhaustiveKnapsack(
        index + 1, weights, values, capacity,
        currentWeight, currentValue,
        currentSelection, bestResult
    );

    currentSelection[index] = 1;
    exhaustiveKnapsack(
        index + 1, weights, values, capacity,
        currentWeight + weights[index],
        currentValue + values[index],
        currentSelection, bestResult
    );
}

KnapsackResult solveKnapsackExhaustive(
    const vector<int>& weights,
    const vector<int>& values,
    int capacity
) {
    int n = weights.size();
    KnapsackResult result;
    result.maxValue = 0;
    result.bestSelection = vector<int>(n, 0);

    vector<int> currentSelection(n, 0);

    exhaustiveKnapsack(
        0, weights, values, capacity,
        0, 0,
        currentSelection, result
    );

    return result;
}

vector<int> generateRandomVector(int n, int minVal, int maxVal, mt19937& rng) {
    uniform_int_distribution<int> dist(minVal, maxVal);
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = dist(rng);
    }
    return vec;
}

int main() {
    mt19937 rng(42);

    cout << left << setw(5) << "n"
         << setw(15) << "Time(ms)"
         << setw(15) << "MaxValue"
         << setw(15) << "Capacity" << endl;

    for (int n = 4; n <= 25; n++) {
        vector<int> weights = generateRandomVector(n, 1, 15, rng);
        vector<int> values = generateRandomVector(n, 10, 100, rng);

        int totalWeight = 0;
        for (int w : weights) totalWeight += w;
        int capacity = totalWeight / 2;

        auto start = high_resolution_clock::now();
        KnapsackResult result = solveKnapsackExhaustive(weights, values, capacity);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        cout << left << setw(5) << n
             << setw(15) << duration.count()
             << setw(15) << result.maxValue
             << setw(15) << capacity << endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct Oasis {
    int water;
    int distanceToNext;
};


bool testOasis(int consumptionRate, queue<Oasis> &queueAux, int w) {
    for (int j = 0; j < queueAux.size(); ++j) {
        Oasis current = queueAux.front();
        queueAux.pop();
        w += current.water;
        int D = 100 * w / consumptionRate;

        if (D < current.distanceToNext) {
            return false;
        }

    }
    return true;
}


int findStartingOasis(queue<Oasis> &queueInit, int consumptionRate) {
    queue<Oasis> queueAux = queueInit;

    for (int i = 0; i < queueInit.size(); ++i) {
        int w = 0;
        if (testOasis(consumptionRate, queueAux, w)) {
            return i;
        }
    }

    return -1;
}

void printQueue(queue<Oasis> q) {
    while (!q.empty()) {
        Oasis o = q.front();
        q.pop();
        cout << "Water: " << o.water << ", Distance to next: " << o.distanceToNext << endl;
    }
}

void runTestCasesFromFile(const string &inputFile, const string &outputFile) {
    ifstream input(inputFile);
    if (!input.is_open()) {
        cout << "Error: Unable to open input file " << inputFile << endl;
        return;
    }

    ofstream output(outputFile);
    if (!output.is_open()) {
        cout << "Error: Unable to open output file " << outputFile << endl;
        input.close();
        return;
    }

    int numTestCases;
    input >> numTestCases;
    cout << numTestCases << endl;

    for (int i = 0; i < numTestCases; ++i) {
        int numOasis, consumptionRate;
        input >> numOasis >> consumptionRate;

        cout << numOasis << " " << consumptionRate << endl;

        queue<Oasis> queueInit;

        for (int j = 0; j < numOasis; ++j) {
            Oasis oasis;
            input >> oasis.water >> oasis.distanceToNext;
            queueInit.push(oasis);
        }

        printQueue(queueInit);
        int startingOasis = findStartingOasis(queueInit, consumptionRate);

        output << "Test " << i << ": ";
        if (startingOasis != -1) {
            output << startingOasis << " is the oasis from where we can start our journey" << endl;
        } else {
            output << "Cannot find a starting oasis. Journey is not possible." << endl;
        }
    }

    input.close();
    output.close();
}




int main() {
    runTestCasesFromFile("oasis.in", "oasis.out");

    int numOasis, consumptionRate;
    cout << "The number of oasis: " << endl;
    cin >> numOasis;
    cout << "The consumption rate: " << endl;
    cin >> consumptionRate;

    queue<Oasis> queueInit;

    cout << "Enter Oasis water and distance to next:" << endl;
    for (int i = 0; i < numOasis; ++i) {
        Oasis oasis{};
        cout << "Oasis " << i << ":" << endl;
        cin >> oasis.water >> oasis.distanceToNext;
        queueInit.push(oasis);
    }

    printQueue(queueInit);
    int startingOasis = findStartingOasis(queueInit, consumptionRate);

    if (startingOasis != -1) {
        cout << startingOasis << " is the oasis from where we can start our journey" << endl;
    } else {
        cout << "Cannot find a starting oasis. Journey is not possible." << endl;
    }

    return 0;
}
# Oasis Journey through Desert

You're embarking on a road trip across a vast desert, but your vehicle can only carry a limited amount of water. Along the route, there are multiple oases, each with a water pump. Your goal is to find the optimal starting oasis from where you can complete the journey without running out of water.

## Oasis Structure
Each oasis is represented by a structure containing two attributes:
- `water`: the total amount of water available at that oasis.
- `distanceToNext`: the distance to the next oasis.

## Algorithm Overview
1. We start by iterating through each oasis to find the optimal starting point.
2. We use a queue to store the oases, arranged in ascending order from the initial point (index 0).
3. We dequeue each oasis one by one, calculating if we can reach the next oasis with the remaining water.
4. If the distance we can travel (computed as a percentage of remaining water) is less than the distance to the next oasis, we cannot continue the journey from this point.
5. If we manage to dequeue all oases without running out of water before reaching the end of the queue, we have found the correct starting point.
6. If not, we move to the next oasis by dequeuing the first oasis and enqueueing it at the end of the queue (creating a circular queue), and repeat the process.

## Code Overview
- The `Oasis` structure represents each oasis with its water capacity and distance to the next oasis.
- `testOasis` function checks if it's possible to complete the journey starting from a particular oasis by simulating the journey using a copy of the original queue.
- `findStartingOasis` function iterates through each oasis to find the optimal starting point.
- `printQueue` function prints the content of the queue.
- `runTestCasesFromFile` function reads test cases from an input file, processes them, and writes the results to an output file.
- In the `main` function, you can either run the algorithm with test cases from a file or input data manually.

## Usage
To use the program:
- Provide input data either through an input file or manually.
- Run the program to find the optimal starting oasis for your journey.


# Friends Flow - Social Network Analysis Tool

## Overview

Friends Flow is a C++ program designed to analyze social network data, allowing users to:

- Identify mutual followers
- Display friends lists
- Recommend new friends
- Evaluate connection strength
- Determine users with the most and least friends
- Calculate the spread time of information
- Analyze user details such as followers, following, and shortest paths
- Compute shortest paths between friends using the Floyd-Warshall algorithm

## Features

- **Check Mutual Followers:** Identify mutual connections between two users.
- **Display Friends List:** View the list of friends for a particular user.
- **Recommend New Friends:** Suggest new friends based on mutual connections.
- **Check Connections Strength:** Determine the strength of a connection between users using Dijkstra's algorithm.
- **Users with Maximum/Minimum Friends:** Find users with the most and least number of connections.
- **Spread Time Analysis:** Calculate how long it takes for information to spread across the network.
- **User Details Analysis:** View follower count, following count, and shortest paths to other users.
- **Shortest Paths Between Friends:** Use the Floyd-Warshall algorithm to compute shortest paths between all friends.

## Installation & Usage

### Prerequisites

- C++ Compiler (GCC, Clang, or MSVC)
- A terminal or command prompt

### Compilation

```sh
g++ -o friends_flow friends_flow.cpp -std=c++11
```

### Running the Program

```sh
./friends_flow
```

## Input Format

### User Input Mode
Enter the number of users and manually input friend connections.

### File Input Mode

- **network.txt**: Contains user names, one per line.
- **friends.txt**: Contains lists of friends for each user, separated by spaces.

### Example Data Format

#### network.txt
```
Alice
Bob
Charlie
David
Eve
```

#### friends.txt
```
Alice Bob Charlie
Bob Alice David
Charlie Alice Eve
David Bob Eve
Eve Charlie David
```

## Algorithms Used

- **Dijkstra's Algorithm:** Computes the shortest paths from a single user.
- **Floyd-Warshall Algorithm:** Finds shortest paths between all users.
- **Greedy Algorithm:** Estimates minimum spread time of information.

## Future Enhancements

- Implementing a graphical user interface (GUI).
- Integrating real-time data from social media platforms.
- Enhancing recommendation algorithms with machine learning.

## Author

Developed by Manan Upmanyu


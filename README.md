# 🚀 Analysis of Algorithms — Lab 04

**Student:** Andres Basantes  
**Instructor:** Israel Pineda  
**University:** Yachay Tech University

---

## 📘 Overview
This lab includes the implementation in **C++** of three classic algorithms:

- 🎒 **0/1 Knapsack** solved with **exhaustive search**
- 🌲 **Depth First Search (DFS)**
- 🌐 **Breadth First Search (BFS)**

The objective was to compare the behavior of an **exponential-time algorithm** with two **graph traversal algorithms**.

---

## 🧠 What was done

### 🎒 1) 0/1 Knapsack
A recursive exhaustive-search solution was implemented to evaluate all possible subsets of items and find the maximum value without exceeding the knapsack capacity.

- Random weights, values, and capacity were generated
- Execution times were measured for increasing values of `n`
- The growth of the running time was analyzed

### 🌲 2) DFS
DFS was implemented using an **adjacency list** and recursion to traverse the graph in depth-first order.

### 🌐 3) BFS
BFS was implemented using an **adjacency list** and a queue to traverse the graph level by level.

---

## 🗂️ Project structure
Based on the project folder:

```text
Lab04/
├── bfs.cpp
├── bfs.exe
├── Bfs.JPG
├── dfs.cpp
├── dfs.exe
├── Dfs.JPG
├── knapsack.cpp
├── knapsack.exe
└── Screen 1.JPG
```

---

## ⚙️ How to compile and run
Use the following commands in **PowerShell / VS Code terminal**:

### 🎒 Knapsack
```powershell
g++ -std=c++17 knapsack.cpp -o knapsack
.\knapsack.exe
```

### 🌲 DFS
```powershell
g++ -std=c++17 dfs.cpp -o dfs
.\dfs.exe
```

### 🌐 BFS
```powershell
g++ -std=c++17 bfs.cpp -o bfs
.\bfs.exe
```

---

## 📊 Sample outputs
- **DFS traversal:** `0 1 3 4 5 2`
- **BFS traversal:** `0 1 2 3 4 5`

For Knapsack, the program prints a table with:
- `n`
- execution time in milliseconds
- maximum value found
- capacity

---

## 📎 Report
The full analysis, discussion, screenshots, and experimental results are included in the lab report.

---

## 🏫 Yachay Tech
Made for **Analysis of Algorithms — Lab 04** at **Yachay Tech University**.

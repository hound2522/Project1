# Homework Assignment IV: Hash Function Design & Observation (C++ Version)

This assignment focuses on the design and observation of hash functions using C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

My execution environment is vs2022 on windows11.
Developer: li yun  
Email: oomayoo2522@gmail.com  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  Formula:index=key%size;
  pseudocode:
  vector<int> intKeys={ 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60 };
  vector<int> sizes={ 10, 11, 37 };
  for(int m:sizes){
  for(int k:intKeys){
  cout<<k<<" "<<intKeys%sizes<<"\n\n";
  }
  }
  ```
- Rationale: Because it code useing vecter, so that will collisions on the repeated elements.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  Formula:index=str[0] - '0';
  pseudocode:
  vector<std::string> strKeys= { "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox" };
  vector<int> sizes = { 10, 11, 37 };
  for(int m:sizes){
  for(const auto s:strKeys){
  cout<<s<<" "<<(strKeys[0]-'0')%sizes<<"\n\n";
  }
  }
  
  ```
- Rationale: If the first letter is same,the index will collisions.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash

  # Build only C++ version
  Make a project and add the hash.h, hash.cpp and main.cpp.
  ```

### Manual Compilation (if needed)
- Command for C++:
  ```bash
  That execution environment doesn't need it command.
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  Just delete all .cpp and .h files.
  ```

### Execution
- Run the compiled binary:
  ```bash
  Click the start bottom.
  ```

### Result Snapshot
- Example output for integers:
  ```
  
  === Hash Function Observation (C++ Version) ===
  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  23      3
  24      4
  25      5
  26      6
  27      7
  28      8
  29      9
  30      0
  51      1
  52      2
  53      3
  54      4
  55      5
  56      6
  57      7
  58      8
  59      9
  60      0

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  23      1
  24      2
  25      3
  26      4
  27      5
  28      6
  29      7
  30      8
  51      7
  52      8
  53      9
  54      10
  55      0
  56      1
  57      2
  58      3
  59      4
  60      5

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      14
  52      15
  53      16
  54      17
  55      18
  56      19
  57      20
  58      21
  59      22
  60      23


  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     1
  dog     2
  bat     0
  cow     1
  ant     9
  owl     3
  bee     0
  hen     6
  pig     4
  fox     4

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     7
  dog     8
  bat     6
  cow     7
  ant     5
  owl     8
  bee     6
  hen     1
  pig     9
  fox     10

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     14
  dog     15
  bat     13
  cow     14
  ant     12
  owl     26
  bee     13
  hen     19
  pig     27
  fox     17
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- That's because prime number doesn't be divided by anothers numbers. So, it method can reduce collisions. Also prime numbers haven't factors, let the prime table sizes can destory the decorrelation, make fewer collisions.

- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Because the composite numbers can segmentation period of hash function due to composite numbers can be divided by anothers numbers. But if the keys have some regular pattern it can be divided by table sizes, the index will collisions. Because all the keys in the same bucket.
  
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.
- 1. Use Division Method: Select a prime number N1, the hash function is index=key%N1;.
  2. Use Multiplicative Hash: Select a prime number N2 and the number A=(sqrt(5)-1)/2 ≈ 0.6180339887, the hash function is index=floor( m *  (k * A-floor(k * A) ));.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.

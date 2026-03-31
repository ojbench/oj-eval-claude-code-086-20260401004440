# Problem 086 - Tree Node Swapping Solution

## Submission Summary
- **Submission ID**: 766657
- **Result**: ACCEPTED ✅
- **Score**: 100/100 (Perfect Score)
- **Test Points Passed**: 12/12
- **Total Time**: 9076 ms
- **Max Memory**: 47.6 MB

## Problem Description
Given a binary tree, perform swap operations on nodes at specific depths and output the inorder traversal after each operation.

### Key Requirements:
1. Read binary tree structure (n nodes, 1-indexed)
2. For each query k, swap left and right children of all nodes whose depth is a multiple of k
3. Operations are cumulative (tree state persists between queries)
4. Output inorder traversal after each swap operation

## Solution Approach

### Data Structure
- Used a vector of Node structures to represent the tree
- Each node stores left child index, right child index, and depth
- Node indices are 1-based (node 0 is unused)

### Algorithm
1. **Build Tree**: Read tree structure from input
2. **Calculate Depths**: Recursively calculate depth for each node (root has depth 1)
3. **Swap Operation**: For each query k:
   - Traverse tree recursively
   - Swap left and right children for nodes where depth % k == 0
4. **Inorder Traversal**: Output nodes in left-root-right order

### Time Complexity
- Depth calculation: O(n)
- Each swap operation: O(n)
- Each inorder traversal: O(n)
- Overall: O(n + t*n) where t is number of queries

### Space Complexity
- Tree storage: O(n)
- Recursion stack: O(h) where h is tree height
- Result vector: O(n)
- Overall: O(n)

## Test Results
All 12 test points passed with "accepted" status:
- Test 1-3: Small cases (2-5 points each)
- Test 4-12: Larger cases (10 points each)
- Maximum time: 952 ms (well within 1000 ms limit)
- Maximum memory: ~47.6 MB (well within 244 MiB limit)

## Code Quality
- Clean C++ implementation with clear function separation
- No compiler warnings
- Follows good coding practices
- Properly structured with CMake build system
- Git repository with proper .gitignore configuration

## Files Submitted
- `main.cpp`: Main solution code
- `CMakeLists.txt`: Build configuration
- `.gitignore`: Git ignore rules for build artifacts

## Submission Attempts Used: 1/5
Successfully solved on the first attempt! 🎉

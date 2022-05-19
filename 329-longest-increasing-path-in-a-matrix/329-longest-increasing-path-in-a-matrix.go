func longestIncreasingPath(matrix [][]int) int {

    // create memo matrix
    memo := make([][]int, len(matrix))
    for i := range memo {
        memo[i] = make([]int, len(matrix[0]))
    }
    
    best := 0
    // loop through matrix, running dfs at each.
    for r:=range matrix {
        for c := range matrix[r] {
            best = max(best, dfs(matrix, &memo, r, c, -1))
        }
    }
    return best
}

// dfs will check bounds, check if we have already visited this node before
// and check all directions connected to it
func dfs(matrix [][]int, memo *[][]int, r, c int, lastInt int) int {
    
    // check bounds
    if r < 0 || r >= len(matrix) || c < 0 || c >= len(matrix[0]) || matrix[r][c] <= lastInt {
        return 0
    }    
    // check memo here
    if (*memo)[r][c] != 0 {
        return (*memo)[r][c]
    }
    // check all directions, direction must be increasing
    best := 0
    best = max(best, dfs(matrix, memo, r+1, c, matrix[r][c]))
    best = max(best, dfs(matrix, memo, r-1, c, matrix[r][c]))
    best = max(best, dfs(matrix, memo, r, c+1, matrix[r][c]))
    best = max(best, dfs(matrix, memo, r, c-1, matrix[r][c]))
    // return max of all directions
    // memoize here
    (*memo)[r][c] = best+1
    return (*memo)[r][c]
    
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

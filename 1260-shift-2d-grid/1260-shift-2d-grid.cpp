class Solution {
public:
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int r=grid.size(), c=grid[0].size();
	vector<int> data(r*c);
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j) {
			data[i*c+j] = grid[i][j];
		}
	}

	k %= (r*c);
	rotate(data.rbegin(), data.rbegin()+k, data.rend());

	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j) {
			grid[i][j] = data[i*c+j];
		}
	}
	return move(grid);
}
};
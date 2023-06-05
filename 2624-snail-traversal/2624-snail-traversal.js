Array.prototype.snail = function(rowsCount, colsCount) {
  // Check for invalid input
  if (this.length !== rowsCount * colsCount) {
    return [];
  }
  
  // Create the result matrix
  const result = new Array(rowsCount).fill().map(() => new Array(colsCount).fill(0));
  
  let index = 0;
  let topRow = 0;
  let bottomRow = rowsCount - 1;
  let leftCol = 0;
  let rightCol = colsCount - 1;
  let rev = false;
  
  while (topRow <= bottomRow && leftCol <= rightCol) {
    if (rev) {
      for (let i = bottomRow; i >= topRow; i--) {
        result[i][leftCol] = this[index++];
      }
    } else {
      for (let i = topRow; i <= bottomRow; i++) {
        result[i][leftCol] = this[index++];
      }
    }
    ++leftCol;
    rev = !rev; 
  }
  
  return result;
};

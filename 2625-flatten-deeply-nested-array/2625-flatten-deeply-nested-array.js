/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if(n==0)
        return arr;
    var res = []
    for(let i=0;i<arr.length;i++)
        {
            if(n>0 && Array.isArray(arr[i])){
                res.push(...flat(arr[i],n-1));
            }
            else
                res.push(arr[i]);
        }
    return res;
};
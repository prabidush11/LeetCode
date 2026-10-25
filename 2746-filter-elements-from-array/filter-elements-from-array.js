/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filtered=[];
    let n=arr.length
    for(let i=0;i<n;i++)
    {
        if(fn(arr[i],i))
        filtered.push(arr[i]);
    }
    return filtered

};
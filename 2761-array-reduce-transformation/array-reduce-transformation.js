/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let acc=init;
    nums.forEach(function(val){
        acc=fn(acc,val);
        //console.log(acc);
    });
    return acc;
};
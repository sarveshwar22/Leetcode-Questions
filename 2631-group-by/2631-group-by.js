/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const grouped = {};
    for(let i=0;i<this.length;i++)
        {
            const item = this[i];
            const key = fn(item);
            if(!grouped.hasOwnProperty(key))
                {
                    grouped[key] = []
                }
            grouped[key].push(item);
        }
    return grouped;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
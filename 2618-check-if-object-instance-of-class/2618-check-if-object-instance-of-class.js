/**
 * @param {any} obj
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj===null || obj ===  undefined || typeof classFunction !== "function")
        return false;
    let currPotentialPrototype = Object.getPrototypeOf(obj);
    while(currPotentialPrototype !== null)
        {
            if(currPotentialPrototype === classFunction.prototype)
                return true;
            currPotentialPrototype = Object.getPrototypeOf(currPotentialPrototype);
        }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
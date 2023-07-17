/**
 * @param {number} millis
 */
async function sleep(millis) {
    
    // function callback(resolve, reject){
    //     setTimeout(resolve,millis);
    // }
    
    //1
    return new Promise((resolve)=> setTimeout(resolve,millis))
    
    //2
    await new Promise((resolve)=> setTimeout(resolve,millis))
    
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
var timeLimit = function(fn, t) {
  return async function(...args) {
      
      
    return new Promise(async(resolve,reject)=>{
        const id = setTimeout(()=>reject("Time Limit Exceeded"),t);
        // fn(...args)
        //     .then((res)=>resolve(res))
        //     .catch((err)=>reject(err))
        //     .finally(() => clearTimeout(id))
        try{
            const res = await fn(...args)
            resolve(res)
        }
        catch(err){
            reject(err)
        }
        finally{
            clearTimeout(id)
        }
        
    })
      
      
  };
};

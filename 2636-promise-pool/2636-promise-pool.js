var promisePool = async function(functions, n) {
  const results = [];
  const promises = [];

  const executeFunction = async (fn, index) => {
    const result = await fn();
    results[index] = result;
    return result;
  };

  for (let i = 0; i < functions.length; i++) {
    const currentFunction = functions[i];
    const currentPromise = executeFunction(currentFunction, i);
    promises.push(currentPromise);

    if (promises.length >= n) {
      const completedPromise = await Promise.race(promises.map((p, index) => p.then(() => index)));
      promises.splice(completedPromise, 1);
    }
  }

  await Promise.all(promises);
  return [results, results[results.length - 1]];
};

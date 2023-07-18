class EventEmitter {
    eventMap = {}; //event-> List of callbacks
    
  subscribe(event, cb) {
    if(!this.eventMap.hasOwnProperty(event))
         this.eventMap[event] = new Set();
    this.eventMap[event].add(cb);
    return {
        unsubscribe: () => {
            this.eventMap[event].delete(cb);
        }
    };
  }

  emit(event, args = []) {
    const res= []
    
   if(this.eventMap[event]){
      for(let fn of this.eventMap[event]){
        res.push(fn(...args));
      }
    }
    return res;
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
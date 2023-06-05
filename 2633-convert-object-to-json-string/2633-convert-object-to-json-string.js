var jsonStringify = function(object) {
  // Handle null case
  if (object === null) {
    return 'null';
  }

  // Handle array case
  if (Array.isArray(object)) {
    const elements = object.map((elem) => jsonStringify(elem));
    return `[${elements.join(',')}]`;
  }

  // Handle object case
  if (typeof object === 'object') {
    const keys = Object.keys(object);
    const pairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
    return `{${pairs.join(',')}}`;
  }

  // Handle primitive types
  if (typeof object === 'string') {
    return `"${object}"`;
  }

  return String(object); // Convert other types to string representation
};

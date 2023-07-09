// @BOJ ------------------------------------------
const read = (() => {
  const stdin = require('fs').readFileSync('/dev/stdin').toString().split('\n');
  let i = 0;
  return () => stdin[i++];
})();
String.prototype.toNumbers = function () {
  return this.split(' ').map(Number);
};

// Solution -----------------------------------
// prettier-ignore
const range = (e, b = 0) => Array(e).fill().map((_, i) => i + b);
const array = v => (Array.isArray(v) ? v : [v]);
const concatSafe = (target, source) => (Array.isArray(target) ? target.concat(array(source)) : array(source));
const size = v => {
  if (typeof v?.length === 'number') return v.length;
  else if (v && typeof v === 'object') return Object.keys(v).length;
  return 0;
};


const solution = function () {
 
};

solution();

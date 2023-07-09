// deps
const range = (e, b = 0) => Array(e).fill().map((_, i) => i + b);
const size = v => {
  if (typeof v?.length === 'number') return v.length;
  else if (v && typeof v === 'object') return Object.keys(v).length;
  return 0;
};

const dfsEffect = (p, chk, pre, post) => {
  chk ??= range(size(p)).fill(false);
  return (dfs = now => {
    if (chk[now]) return chk;
    chk[now] = true;
    pre?.(now);
    p[now].forEach(dfs);
    post?.(now);

    return chk;
  });
};
// deps
const range = (e, b = 0) => Array(e).fill().map((_, i) => i + b);
const array = v => (Array.isArray(v) ? v : [v]);
const concatSafe = (target, source) => (Array.isArray(target) ? target.concat(array(source)) : array(source));
const size = v => {
  if (typeof v?.length === 'number') return v.length;
  else if (v && typeof v === 'object') return Object.keys(v).length;
  return 0;
};

// Strongly Connected Component - https://icpc.me/2150
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

const dfsOrdering = p => {
  const n = size(p);
  const order = [];
  const chk = range(n).fill(false);
  range(n - 1, 1).forEach(dfsEffect(p, chk, null, v => order.push(v)));

  return order.reverse();
};

const dfsSCC = (p, order) => {
  const n = size(p);
  const chk = range(n).fill(false);
  const sccId = range(n).fill(0);
  let cnt = 0;

  const dfs = dfsEffect(p, chk, now => (sccId[now] = cnt));

  order.forEach(now => {
    if (!sccId[now]) {
      ++cnt;
      dfs(now);
    }
  });

  return Object.values(
    sccId.slice(1).reduce((scc, id, index) => {
      scc[id] = concatSafe(scc[id], index + 1);
      return scc;
    }, {}),
  );
};

const solution = function () {
  let n, m;
  let edges = [[], [], ]
  
  const [ori, rev] = edges
    .reduce(
      ([ori, rev], [from, to]) => {
        ori[from].push(to);
        rev[to].push(from);
        return [ori, rev];
      },
      [range(n + 1).map(() => []), range(n + 1).map(() => [])],
    );
  const scc = dfsSCC(rev, dfsOrdering(ori))
    .map(component => component.sort((p, c) => p - c))
    .sort((p, c) => p[0] - c[0]);

  const ans = scc.map(component => concatSafe(component, -1).join(' ')).join('\n');
  console.log(scc.length);
  console.log(ans);
};

solution();

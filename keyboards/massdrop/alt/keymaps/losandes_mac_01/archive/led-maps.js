// keys
// [layer, keyid, flag]
const k = {
  esc: [0, 1],
  n1: [0, 2],
  n2: [0, 3],
  n3: [0, 4],
  n4: [0, 5],
  n5: [0, 6],
  n6: [0, 7],
  n7: [0, 8],
  n8: [0, 9],
  n9: [0, 10],
  n0: [0, 11],
  dash: [0, 12],
  eqal: [0, 13],
  bksp: [0, 14],
  del: [0, 15],
  tab: [0, 16],
  q: [0, 17],
  w: [0, 18],
  e: [0, 19],
  r: [0, 20],
  t: [0, 21],
  y: [0, 22],
  u: [0, 23],
  i: [0, 24],
  o: [0, 25],
  p: [0, 26],
  obrk: [0, 27],
  cbrk: [0, 28],
  bslh: [0, 29],
  home: [0, 30],
  caps: [0, 31],
  a: [0, 32],
  s: [1, 33],
  d: [1, 34],
  f: [1, 35],
  g: [1, 36],
  h: [1, 37],
  j: [1, 38],
  k: [1, 39],
  l: [1, 40],
  coln: [1, 41],
  quot: [1, 42],
  entr: [1, 43],
  pgup: [1, 44],
  lshf: [1, 45],
  z: [1, 46],
  x: [1, 47],
  c: [1, 48],
  v: [1, 49],
  b: [1, 50],
  n: [1, 51],
  m: [1, 52],
  comm: [1, 53],
  perd: [1, 54],
  fslh: [1, 55],
  rshf: [1, 56],
  arru: [1, 57],
  pgdn: [1, 58],
  lfn: [1, 59],
  lalt: [1, 60],
  lcmd: [1, 61],
  spce: [1, 62],
  rcmd: [1, 63],
  rfn: [1, 64],
  arrl: [2, 65],
  arrd: [2, 66],
  arrr: [2, 67],
}


// edges
// [layer, keyid, flag]
const e = {
  // top row
  n01: [3, 100],
  n02: [3, 99],
  n03: [3, 98],
  n04: [3, 97],
  n05: [2, 96],
  n06: [2, 95],
  n07: [2, 94],
  n08: [2, 93],
  n09: [2, 92],
  n10: [2, 91],
  n11: [2, 90],
  n12: [2, 89],
  n13: [2, 88],
  // sides
  n14: [3, 101],
  n15: [2, 87],
  n16: [3, 102],
  n17: [2, 86],
  n18: [3, 103],
  n19: [2, 85],
  n20: [3, 104],
  n21: [2, 84],
  n22: [3, 105],
  n23: [2, 83],
  // bottom row
  n24:  [2, 68],
  n25:  [2, 69],
  n26:  [2, 70],
  n27:  [2, 71],
  n28:  [2, 72],
  n29:  [2, 73],
  n30:  [2, 74],
  n31:  [2, 75],
  n32:  [2, 76],
  n33:  [2, 77],
  n34:  [2, 78],
  n35:  [2, 79],
  n36:  [2, 80],
  n37:  [2, 81],
  n39:  [2, 82],
}

const ______ = null
const e______ = null
const _______ = null
const makeFlag = (val) => Math.pow(2, (val - 1) % 32)

const keymap = [
    k.esc , k.n1  , k.n2  , k.n3  , k.n4  , k.n5  , k.n6  , k.n7  , k.n8  , k.n9  , k.n0  , k.dash, k.eqal, k.bksp, k.del ,
    k.tab , k.q   , k.w   , k.e   , k.r   , k.t   , k.y   , k.u   , k.i   , k.o   , k.p   , k.obrk, k.cbrk, k.bslh, k.home,
    k.caps, k.a   , k.s   , k.d   , k.f   , k.g   , k.h   , k.j   , k.k   , k.l   , k.coln, k.quot,     k.entr    , k.pgup,
    k.lshf, k.z   , k.x   , k.c   , k.v   , k.b   , k.n   , k.m   , k.comm, k.perd, k.fslh,     k.rshf    , k.arru, k.pgdn,
    k.lfn , k.lalt, k.lcmd,                    k.spce,                     k.rcmd, k.rfn  ,         k.arrl, k.arrd, k.arrr,
].map((key) => [key[0], key[1], makeFlag(key[1])])

// const keymap =
// [
//   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
//   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
//   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,     ______    , ______,
//   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,    ______     , ______, ______,
//   ______, ______, ______,                    ______,                    ______, ______  ,         ______, ______, ______,
// ]

const edgemap = [
         e.n01, e.n02, e.n03, e.n04, e.n05, e.n06, e.n07, e.n08, e.n09, e.n10, e.n11, e.n12, e.n13,
  e.n14,                                                                                            e.n15,
  e.n16,                                                                                            e.n17,
  e.n18,                                                                                            e.n19,
  e.n20,                                                                                            e.n21,
  e.n22,                                                                                            e.n23,
  e.n24, e.n25, e.n26, e.n27, e.n28, e.n29, e.n30, e.n31, e.n32, e.n33, e.n34, e.n35, e.n36, e.n37, e.n39
].map((key) => [key[0], key[1], makeFlag(key[1])])

const leds = keymap.concat(edgemap)

const r0Max = leds.filter((led) => led[0] === 0).reduce((total, incr) => total += incr[2], 0);
const r1Max = leds.filter((led) => led[0] === 1).reduce((total, incr) => total += incr[2], 0);
const r2Max = leds.filter((led) => led[0] === 2).reduce((total, incr) => total += incr[2], 0);
const r3Max = leds.filter((led) => led[0] === 3).reduce((total, incr) => total += incr[2], 0);

const makeConfig = (color) => {
  const props = []

  if (typeof color.flags === 'string') {
    props.push(`.flags = ${color.flags}`)
  }

  if (typeof color.layer === 'number') {
    props.push(`.layer = ${color.layer}`)
  }

  const regions = color.regions || { r0: 0, r1: 0, r2: 0, r3: 0 }
  const setFlag = (key) => {
    regions[`r${key[0]}`] += key[2]
  }

  if (Array.isArray(color.keys)) {
    color.keys
      .filter((key) => key)
      .map((key) => [key[0], key[1], makeFlag(key[1])])
      .forEach(setFlag)
  }

  if (Array.isArray(color.edges)) {
    color.edges
      .filter((key) => key)
      .map((key) => [key[0], key[1], makeFlag(key[1])])
      .forEach(setFlag)
  }

  for (i = 0; i < 4; i += 1) {
    if (regions[`r${i}`] > 0) {
      props.push(`.id${i} = ${regions[`r${i}`]}`)
    }
  }

  if (color.rgb) {
    props.push(`.r = ${color.rgb.r}`)
    props.push(`.g = ${color.rgb.g}`)
    props.push(`.b = ${color.rgb.b}`)
  }

  if (typeof color.patternId === 'number') {
    props.push(`.pattern_id = ${color.patternId}`)
  }

  return {
    comment: color.comment,
    config: `{ ${props.join(', ')} }`,
    regions
  }
}

const makeLayer = (layer) => {
  const configs = layer.configs.map((config) => makeConfig({ ...config, ...{ layer: layer.layer } }))

  if (layer.remainder) {
    const regions = { r0: r0Max, r1: r1Max, r2: r2Max, r3: r3Max };

    configs.forEach((made) => {
      regions.r0 -= made.regions.r0;
      regions.r1 -= made.regions.r1;
      regions.r2 -= made.regions.r2;
      regions.r3 -= made.regions.r3;
    })

    configs.push(makeConfig({ ...layer.remainder, ...{ regions, layer: layer.layer } }))
  }

  return { comment: layer.comment, configs }
}

module.exports = {
  k,
  e,
  _____: ______,
  ______,
  makeLayer
}

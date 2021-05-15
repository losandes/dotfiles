const keymap = [
                        100      , 99       , 98       , 97       , 96       , 95       , 94       , 93       , 92       , 91       , 90       , 89       , 88       ,
  101      , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , 14       , 15       , 87     ,
  102      , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 86     ,
  103      , 31       , 32       , 33       , 34       , 35       , 36       , 37       , 38       , 39       , 40       , 41       , 42       ,          43         , 44       , 85     ,
  104      , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 52       , 53       , 54       , 55       ,          56         , 57       , 58       , 84     ,
  105      , 59       , 60       , 61       ,                                  62                                        , 63       , 64       , 65       , 66       , 67       , 83     ,
             68       , 69       , 70       , 71       , 72       , 73       , 74       , 75       , 76       , 77       , 78       , 79       , 80       , 81       , 82
]

/**

 */
const makeFlag = (val) => Math.pow(2, (val - 1) % 32)

/**
 * Gets the range that the key index belongs to
 *
 * The keyboard LEDs are split into 4 ranges (0, 1, 2, 3).
 * Ranges 0, 1, and 2 have a max value of 4294967295, and
 * range 3 has a max value of 511 because it has less LEDs
 */
const getRange = (val) => {
  if (val <= 32) {
    return 0
  } else if (val <= 64) {
    return 1
  } else if (val <= 96) {
    return 2
  }

  return 3
}

const FLAGS_RGB = 'LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB'
const FLAGS_STATIC_PATTERN = 'LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN'
const FLAGS_USER_CHOSEN_PATTERN = 'LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN'
const USER_CHOSEN_PATTERN = '#pppppp'
const STATIC_PATTERN = '#pppp'
const OFF = '#000000'
const SHORTHAND_HEX_EXPRESSION = /^#?([a-f\d])([a-f\d])([a-f\d])$/i
const PARSE_HEX_EXPRESSION = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i

const setConfig = (input, existing) => {
  const { idx, flags, patternId, rgb } = input
  const ranges = existing && Array.isArray(existing.ranges) ? existing.ranges : [0, 0, 0, 0]

  const keyIndex = keymap[idx]
  const rangeId = getRange(keyIndex)
  const flag = makeFlag(keyIndex)

  ranges[rangeId] += flag

  return {
    flags,
    ranges,
    patternId,
    rgb
  }
}

/**
 * Either returns the given hex, or expands it if it's shorthand
 *
 * i.e. '#0034fe' => '#0034fe'
 * i.e. '#03f'    => '#0033ff'
 */
const ensureHexLength = (hex) => hex.replace(SHORTHAND_HEX_EXPRESSION, (m, r, g, b) => {
  return '#' + r + r + g + g + b + b;
})

function RGB (parsed) {
  return parsed ? {
    r: parseInt(parsed[1], 16),
    g: parseInt(parsed[2], 16),
    b: parseInt(parsed[3], 16)
  } : null
}

const hexToRgb = (hex) => new RGB(PARSE_HEX_EXPRESSION.exec(ensureHexLength(hex)))

const byConfigType = (a, b) => {
  // order must be user chosen pattern, then static patterns, then RGB
  // (and I like off being last as personal preference)

  if (
    a === USER_CHOSEN_PATTERN ||
    (a.startsWith(STATIC_PATTERN) && b !== USER_CHOSEN_PATTERN) ||
    b === OFF
  ) {
    return -1
  } else if (
    b === USER_CHOSEN_PATTERN ||
    (b.startsWith(STATIC_PATTERN) && a !== USER_CHOSEN_PATTERN) ||
    a === OFF
  ) {
    return 1
  }

  return 0
}

const hasRegions = (arr) => {
  return arr[0] > 0 || arr[1] > 0 || arr[2] > 0 || arr[3] > 0
}

const makeC = (layer, config) => {
  const parts = []

  parts.push(`.flags = ${config.flags}`)
  parts.push(`.layer = ${layer.layer}`)
  config.ranges.forEach((range, idx) => {
    if (range > 0) {
      parts.push(`.id${idx} = ${range}`)
    }
  })

  if (config.patternId) {
    parts.push(`.pattern_id = ${config.patternId}`)
  }

  if (config.rgb) {
    parts.push(`.r = ${config.rgb.r}`)
    parts.push(`.g = ${config.rgb.g}`)
    parts.push(`.b = ${config.rgb.b}`)
  }

  return `{ ${parts.join(', ')} }`
}


const makeLayer = (layer) => {
  const configs = {}

  layer.leds.forEach((led, idx) => {
    const keyIndex = keymap[idx]
    const range = getRange(keyIndex)
    const flag = makeFlag(keyIndex)

    if (led && led === USER_CHOSEN_PATTERN) {
      configs[led] = setConfig({ idx, flags: FLAGS_USER_CHOSEN_PATTERN }, configs[led])
    } else if (led && led.startsWith(STATIC_PATTERN) && led.length > STATIC_PATTERN.length) {
      const num = parseInt(led.substring(STATIC_PATTERN.length))

      if (!isNaN(num)) {
        configs[led] = setConfig({ idx, flags: FLAGS_STATIC_PATTERN, patternId: num }, configs[led])
      }
    } else if (led) {
      configs[led] = setConfig({ idx, flags: FLAGS_RGB, rgb: hexToRgb(led) }, configs[led])
    }
  })

  return Object.keys(configs)
    .sort(byConfigType)
    .map((key) => {
      // add config string

      const config = { ...configs[key], ...{ key } }
      config.c = makeC(layer, config)

      return config
    })
}

module.exports = { makeLayer }

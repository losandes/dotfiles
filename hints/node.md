Node.js
=======

## Encoding/Decoding base64 without btoa/atob
btoa (encoding), and atob (decoding) are not available in nodejs. We could install packages to use them, but it's really not necessary because we can use buffers to encode and decode UTF8 input.

```JavaScript
const input = 'hello world!'
const encoded = Buffer.from(input)
    .toString('base64')

const decoded = Buffer.from(encoded, 'base64').toString()

assert.strictEquals(decoded, input)
```

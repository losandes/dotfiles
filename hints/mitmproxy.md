mitmproxy
=========

[mitmproxy](https://mitmproxy.org) is a free and open source interactive HTTPS proxy

### Installation
```shell
brew install mitmproxy
```

1. Open the Network preference pane (`cmd + space: network pref`)
2. Choose "Wifi"
3. Click "Advanced"
4. Open the "Proxies" tab
5. Click the "Web Proxy (http)" checkbox
6. Set the host to 127.0.0.1 port 8080

### Getting started (HTTP only)
```shell
mitmproxy --host
```

### Setup
https://medium.com/@maxgreenwald/mitmproxy-your-d-i-y-private-eye-864c08f84736#.d7uloulqq


## tcpdump
You can use tcpdump to view traffic to a given host:
`tcpdump host x.x.x.x -w /path/to/save/raw.dump`

To view the traffic on port 3000 in the terminal:

```Shell
sudo tcpdump -i lo0 'port 3000' -v
```

To save that in a file:

```Shell
sudo tcpdump -i lo0 'port 3000' -v >~/Documents/temp.dump
# ...
vi temp.dump
```


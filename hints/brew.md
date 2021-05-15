
Example: brew install with cleanup
```
brew update

# install Node Version Manager if you don't already have it
brew install nvm
source $(brew --prefix nvm)/nvm.sh
# install node LTE 14.15.1
nvm install 14.15.1
# Use it
nvm use 14.15.1
# And set it as your default (optional)
nvm alias default 14.15.1

# Install pnpm (this is necessary as long as this is a mono-repo)
npm install -g pnpm

# Also install ngrok if you don't already have it
brew cask install ngrok

# cleanup cached brew files
brew cleanup -s
rm -rf "$(brew --cache)"
```

#!/bin/sh
#
# Installs the latest LTE version of node as default for NVM
type nvm >/dev/null 2>&1 || { echo >&2 "I require nvm to be installed."; exit 1; }

CURRENT_VERSION=$(nvm current)
VERSION=$(nvm version-remote --lts)

if $CURRENT_VERSION == $VERSION; then
  # the latest version is already installed
  exit 0
fi

# install the latest LTS version of node
nvm install $VERSION

# use the newly installed version
nvm use $VERSION

# set the default node version for new terminal windows
nvm alias default $VERSION

# if an existing version was found when this script ran
if [ ! -z "$CURRENT_VERSION" ]; then
  # reinstall any global packages that were installed on the previous version
  nvm reinstall-packages $CURRENT_VERSION
  # OR nvm install node --reinstall-packages-from=node
  # See https://github.com/creationix/nvm/issues/668 for more information
fi

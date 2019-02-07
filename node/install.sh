echo "Installing NVM and Node"




#!/usr/bin/env bash                                                                                                               
                                                                                                                                  
echo "Installing NVM and Node"                                                                                                    
brew install nvm                                                                                                                  
source $(brew --prefix nvm)/nvm.sh                                                                                                
                                                                                                                                  
# install some versions of node                                                                                                   
nvm install 8.11.4                                                                                                                
                                                                                                                                  
# use 8.11.4 by default                                                                                                           
nvm use 8.11.4                                                                                                                    
                                                                                                                                  
# Setup an alias, so we use the default in new terminal windows                                                                   
# Otherwise, we would have to nvm use 8.11.4 in every new terminal                                                                
nvm alias default 8.11.4                                                                                                          
                                                                                                                                  
# If you have a pre-existing node installation, you can                                                                           
# reinstall the global packages for the new node version:                                                                         
# nvm reinstall-packages <version>                                                                                                
# OR nvm install node --reinstall-packages-from=node                                                                              
# See https://github.com/creationix/nvm/issues/668 for more information


# Sets my macOS defaults.
#
# A lot is borrowed from:
#   * [https://github.com/mathiasbynens/dotfiles/blob/master/.macos](Mathias Bynens Dotfiles)
#   * [https://github.com/herrbischoff/awesome-macos-command-line/blob/master/README.md](Awesome macos Command Line)
#
# Example Usage:
# 	> ./set-defaults.sh
#
#   > /usr/libexec/PlistBuddy ~/Library/Preferences/com.apple.systemuiserver.plist
#   > Command: ls
#
#		defaults read ~/Library/Preferences/com.apple.Safari.plist

if test ! "$(uname)" = "Darwin"
	then
  exit 0
fi

open /System/Library/PreferencePanes/Security.PrefPane

# In Macos Mojave and onward, Terminal has to be given FullDiskAccess privelages
# to make changes to apps like Safari, Mail, etc.
echo "\n\n\e[5m\e[33mIMPORTANT\n\e[0m\e[33mCheck the Security.PrefPane FullDiskAccess list to make sure Terminal is listed. If it's not, add it, restart terminal, and run $DOT/macos/set-defaults.sh again\e[0m\n\n"

echo "Setting macos defaults"
# Set the timezone (see `sudo systemsetup -listtimezones` for other values)
sudo systemsetup -settimezone "America/New_York" > /dev/null

# Menu bar: show battery percentage
defaults write com.apple.menuextra.battery ShowPercent YES

# ============================================================================
# AIRDROP

echo "- Airdrop"
# Use AirDrop over every interface. srsly this should be a default.
defaults write com.apple.NetworkBrowser BrowseAllInterfaces 1

# ============================================================================
# KEYBOARD & MOUSE
echo "- Keyboard & Mouse"

# Disable automatic capitalization as it’s annoying when typing code
defaults write NSGlobalDomain NSAutomaticCapitalizationEnabled -bool false

# Disable smart dashes as they’re annoying when typing code
defaults write NSGlobalDomain NSAutomaticDashSubstitutionEnabled -bool false

# Disable automatic period substitution as it’s annoying when typing code
defaults write NSGlobalDomain NSAutomaticPeriodSubstitutionEnabled -bool false

# Disable smart quotes as they’re annoying when typing code
defaults write NSGlobalDomain NSAutomaticQuoteSubstitutionEnabled -bool false

# Disable auto-correct
defaults write NSGlobalDomain NSAutomaticSpellingCorrectionEnabled -bool false

# Trackpad: enable tap to click for this user and for the login screen
defaults write com.apple.AppleMultitouchTrackpad Clicking -bool true
defaults write com.apple.driver.AppleBluetoothMultitouch.trackpad Clicking -bool true
defaults -currentHost write NSGlobalDomain com.apple.mouse.tapBehavior -int 1
defaults write NSGlobalDomain com.apple.mouse.tapBehavior -int 1

# Trackpad: enable secondary click
defaults write com.apple.driver.AppleBluetoothMultitouch.trackpad TrackpadRightClick -bool true
defaults -currentHost write NSGlobalDomain com.apple.trackpad.enableSecondaryClick -bool true

# Increase sound quality for Bluetooth headphones/headsets
defaults write com.apple.BluetoothAudioAgent "Apple Bitpool Min (editable)" -int 40

# ============================================================================
# FINDER
echo "- Finder"

# Set the default location for new Finder windows
# For other paths, use `PfLo` and `file:///full/path/here/`
defaults write com.apple.finder NewWindowTarget -string "PfLo"
defaults write com.apple.finder NewWindowTargetPath -string "file://${HOME}/"
# example setting it to desktop:
# defaults write com.apple.finder NewWindowTarget -string "PfDe"
# defaults write com.apple.finder NewWindowTargetPath -string "file://${HOME}/Desktop/"
# example setting it to documents:
# defaults write com.apple.finder NewWindowTarget -string "PfDo"
# defaults write com.apple.finder NewWindowTargetPath -string "file://${HOME}/Documents/"

# Turn off recent items tracking
defaults write -g NSNavRecentPlacesLimit -int 0

# Save screenshots to the desktop
defaults write com.apple.screencapture location -string "${HOME}/Desktop"

# Save screenshots in PNG format (other options: BMP, GIF, JPG, PDF, TIFF)
defaults write com.apple.screencapture type -string "png"

# Finder: show all filename extensions
defaults write NSGlobalDomain AppleShowAllExtensions -bool true

# Finder: show hidden files
defaults write com.apple.Finder AppleShowAllFiles -bool true

# Finder: add quit option to Preferences
# defaults write com.apple.finder QuitMenuItem -bool true;

# Finder: show status bar
# defaults write com.apple.finder ShowStatusBar -bool true

# Finder: show path bar
defaults write com.apple.finder ShowPathbar -bool true

# Show icons for hard drives, servers, and removable media on the desktop
defaults write com.apple.finder ShowExternalHardDrivesOnDesktop -bool true
defaults write com.apple.finder ShowHardDrivesOnDesktop -bool false
defaults write com.apple.finder ShowMountedServersOnDesktop -bool true
defaults write com.apple.finder ShowRemovableMediaOnDesktop -bool true

# Display full POSIX path as Finder window title
defaults write com.apple.finder _FXShowPosixPathInTitle -bool true

# Keep folders on top when sorting by name
defaults write com.apple.finder _FXSortFoldersFirst -bool true

# When performing a search, search the current folder by default
defaults write com.apple.finder FXDefaultSearchScope -string "SCcf"

# Enable snap-to-grid for icons on the desktop and in other icon views
/usr/libexec/PlistBuddy -c "Set :DesktopViewSettings:IconViewSettings:arrangeBy grid" ~/Library/Preferences/com.apple.finder.plist
/usr/libexec/PlistBuddy -c "Set :StandardViewSettings:IconViewSettings:arrangeBy grid" ~/Library/Preferences/com.apple.finder.plist

# Increase grid spacing for icons on the desktop and in other icon views
/usr/libexec/PlistBuddy -c "Set :DesktopViewSettings:IconViewSettings:gridSpacing 100" ~/Library/Preferences/com.apple.finder.plist
/usr/libexec/PlistBuddy -c "Set :StandardViewSettings:IconViewSettings:gridSpacing 100" ~/Library/Preferences/com.apple.finder.plist

# Use column view view in all Finder windows by default
# Four-letter codes for the other view modes: `Nlsv`, `icnv`, `clmv`, `Flwv`
defaults write com.apple.finder FXPreferredViewStyle -string "clmv"

# Show the ~/Library folder
chflags nohidden ~/Library

# Show the /Volumes folder
sudo chflags nohidden /Volumes

# Expand save panel by default
defaults write NSGlobalDomain NSNavPanelExpandedStateForSaveMode -bool true
defaults write NSGlobalDomain NSNavPanelExpandedStateForSaveMode2 -bool true

# Always open everything in Finder's list view. This is important.
# defaults write com.apple.Finder FXPreferredViewStyle Nlsv

# Set the Finder prefs for showing a few different volumes on the Desktop.
# defaults write com.apple.finder ShowExternalHardDrivesOnDesktop -bool true
# defaults write com.apple.finder ShowRemovableMediaOnDesktop -bool true

# ============================================================================
# DOCK
echo "- Dock"

# Set the icon size of Dock items to 44 pixels
defaults write com.apple.dock tilesize -int 44

# Automatically hide and show the Dock
defaults write com.apple.dock autohide -bool true

# ============================================================================
# MENU BAR
defaults write com.apple.systemuiserver menuExtras -array \
	"/System/Library/CoreServices/Menu Extras/Clock.menu", \
  "/System/Library/CoreServices/Menu Extras/Battery.menu", \
  "/System/Library/CoreServices/Menu Extras/AirPort.menu", \
  "/System/Library/CoreServices/Menu Extras/Displays.menu", \
  "/System/Library/CoreServices/Menu Extras/Bluetooth.menu"

# ============================================================================
# SAFARI
echo "- Safari"
# defaults read ~/Library/Preferences/com.apple.Safari.plist

# Set Safari's home page
# Set Safari’s home page to `about:blank` for faster loading
defaults write com.apple.Safari HomePage -string "https://www.startpage.com"

# Use the homepage when opening new Safari windows
defaults write com.apple.Safari NewWindowBehavior -int 0

# Use the homepage when opening new Safari tabs
defaults write com.apple.Safari NewTabBehavior -int 0

# Show the full URL in the address bar (note: this still hides the scheme)
defaults write com.apple.Safari ShowFullURLInSmartSearchField -bool true

# Set up Safari for development.
defaults write com.apple.Safari IncludeInternalDebugMenu -bool true
defaults write com.apple.Safari IncludeDevelopMenu -int 1
defaults write com.apple.Safari "WebKitPreferences.developerExtrasEnabled" -int 1
defaults write com.apple.Safari WebKitDeveloperExtrasEnabledPreferenceKey -bool true
defaults write com.apple.Safari "com.apple.Safari.ContentPageGroupIdentifier.WebKit2DeveloperExtrasEnabled" -bool true
defaults write NSGlobalDomain WebKitDeveloperExtras -bool true

# Disable AutoFill
defaults write com.apple.Safari AutoFillFromAddressBook -bool false
defaults write com.apple.Safari AutoFillPasswords -bool false
defaults write com.apple.Safari AutoFillCreditCardData -bool false
defaults write com.apple.Safari AutoFillMiscellaneousForms -bool false

# Warn about fraudulent websites
defaults write com.apple.Safari WarnAboutFraudulentWebsites -bool true

# Privacy: don’t send search queries to Apple
defaults write com.apple.Safari UniversalSearchEnabled -bool false
defaults write com.apple.Safari SuppressSearchSuggestions -bool true

# Enable “Do Not Track”
defaults write com.apple.Safari SendDoNotTrackHTTPHeader -bool true

# Prevent Safari from opening ‘safe’ files automatically after downloading
defaults write com.apple.Safari AutoOpenSafeDownloads -bool false

# Update extensions automatically
defaults write com.apple.Safari InstallExtensionUpdatesAutomatically -bool true

# ============================================================================
# MAIL
echo "- Mail"

# Disable inline attachments (just show the icons)
defaults write com.apple.mail DisableInlineAttachmentViewing -bool true


# ============================================================================
# APP STORE
echo "- App Store"

# Enable the automatic update check
defaults write com.apple.SoftwareUpdate AutomaticCheckEnabled -bool true

# Check for software updates daily, not just once per week
defaults write com.apple.SoftwareUpdate ScheduleFrequency -int 1

# Download newly available updates in background
defaults write com.apple.SoftwareUpdate AutomaticDownload -int 1

# Install System data files & security updates
defaults write com.apple.SoftwareUpdate CriticalUpdateInstall -int 1

# Turn on app auto-update
defaults write com.apple.commerce AutoUpdate -bool true

# Allow the App Store to reboot machine on macOS updates
# defaults write com.apple.commerce AutoUpdateRestartRequired -bool true

# ============================================================================
# MESSAGES
echo "- Messages"

# Disable smart quotes as it’s annoying for messages that contain code
defaults write com.apple.messageshelper.MessageController SOInputLineSettings -dict-add "automaticQuoteSubstitutionEnabled" -bool false

# Disable continuous spell checking
defaults write com.apple.messageshelper.MessageController SOInputLineSettings -dict-add "continuousSpellCheckingEnabled" -bool false


# ============================================================================
# ALFRED
echo "- Alfred"

defaults write com.alfredapp.Alfred "appearance.themeuid" -string "alfred.theme.light"

# ============================================================================
# TERMINAL

# # Use a modified version of the Solarized Dark theme by default in Terminal.app
# osascript <<EOD
# tell application "Terminal"
# 	local allOpenedWindows
# 	local initialOpenedWindows
# 	local windowID
# 	set themeName to "Solarized Dark xterm-256color"
# 	(* Store the IDs of all the open terminal windows. *)
# 	set initialOpenedWindows to id of every window
# 	(* Open the custom theme so that it gets added to the list
# 	   of available terminal themes (note: this will open two
# 	   additional terminal windows). *)
# 	do shell script "open '$HOME/init/" & themeName & ".terminal'"
# 	(* Wait a little bit to ensure that the custom theme is added. *)
# 	delay 1
# 	(* Set the custom theme as the default terminal theme. *)
# 	set default settings to settings set themeName
# 	(* Get the IDs of all the currently opened terminal windows. *)
# 	set allOpenedWindows to id of every window
# 	repeat with windowID in allOpenedWindows
# 		(* Close the additional windows that were opened in order
# 		   to add the custom theme to the list of terminal themes. *)
# 		if initialOpenedWindows does not contain windowID then
# 			close (every window whose id is windowID)
# 		(* Change the theme for the initial opened terminal windows
# 		   to remove the need to close them in order for the custom
# 		   theme to be applied. *)
# 		else
# 			set current settings of tabs of (every window whose id is windowID) to settings set themeName
# 		end if
# 	end repeat
# end tell
# EOD

# ============================================================================
# SOUNDS

# Turn off trash, and screenshot sound effects
defaults write com.apple.systemsound "com.apple.sound.uiaudio.enabled" -int 0

# ============================================================================
# OTHER
echo "- Other"

# Use plain text mode for new TextEdit documents
defaults write com.apple.TextEdit RichText -int 0

# Prevent Photos from opening automatically when devices are plugged in
defaults -currentHost write com.apple.ImageCapture disableHotPlug -bool true

for app in "Dock" \
	"Finder" \
	"Mail" \
	"Messages" \
	"Safari" \
	"SystemUIServer" ; do
	killall "${app}" &> /dev/null
done

echo "Some of these changes require a logout/restart to take effect."

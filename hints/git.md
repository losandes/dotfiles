## Remotes
https://help.github.com/categories/managing-remotes/

### Getting Someone Else's Branches/Remote
You can add their remote, and fetch their branches, after which they are available to checkout:

```Shell
# Set a new remote
git remote add andes-branches git@github.com:losandes/notes.git
# Verify the new remote
git remote -v
# Fetch the branches at that remote
git fetch andes-branches
# Checkout a branch from that remote
git checkout [branch_name]
```

### Listing The Aliases You've Fetched
When we get someone elses branches, and need to pull them again, to find out what you named the alias:

```Shell
git remote -v
```

OR
```Shell
git config --list | grep ^remote.\.
```

### Renaming a Remote

```Shell
# View existing remotes
$ git remote -v
origin  https://github.com/OWNER/REPOSITORY.git (fetch)
origin  https://github.com/OWNER/REPOSITORY.git (push)
# Change remote name from 'origin' to 'destination'
$ git remote rename origin newname
# Verify the renamed remote
$ git remote -v
newname  https://github.com/OWNER/REPOSITORY.git (fetch)
newname  https://github.com/OWNER/REPOSITORY.git (push)
```

### Removing Someone Else's Branches

```Shell
# View current remotes
$ git remote -v
origin  https://github.com/OWNER/REPOSITORY.git (fetch)
origin  https://github.com/OWNER/REPOSITORY.git (push)
destination  https://github.com/FORKER/REPOSITORY.git (fetch)
destination  https://github.com/FORKER/REPOSITORY.git (push)
# Remove remote
$ git remote rm destination
# Verify it's gone
$ git remote -v
origin  https://github.com/OWNER/REPOSITORY.git (fetch)
origin  https://github.com/OWNER/REPOSITORY.git (push)
```

## Rebasing

### Rebase to Master
```
git fetch origin            # Updates origin/master
git rebase origin/master    # Rebases current branch onto origin/master
```

### Rebasing From a Fork

```Shell
# NOTE:
# These examples rebase to the "somerepo" repository in "someone's" github profile

# Add the remote and give it a name:
git remote add someone https://github.com/someone/somerepo.git

# Fetch all the branches from that remote
git fetch someone

# Make sure you're on master
git checkout master

# **If** you don't want to rewrite the history of your master branch (e.g. if other
# people have clones of it), then merge the fork into yours:
git merge someone/master

# **Otherwise**, if you prefer to rebase, rewrite your master branch so your commits that aren't already in someone/master are replayed on top of that branch:
git rebase someone/master

# If you chose to rebase, you may need to force push it into your forked repo:
# (you only need to use `-f` the first time after you rebase)
git push -f origin master
```

### Rebasing From a Branch On a Fork
```Shell
# NOTE:
# These examples rebase to the "somerepo" repository in "someone's" github profile

# Add the remote and give it a name:
git remote add someone https://github.com/someone/somerepo.git

# Fetch all the branches from that remote
git fetch someone

# Make sure you're on the branch you want to rebase (i.e. master)
git checkout master

# **If** you don't want to rewrite the history of your master branch (e.g. if other
# people have clones of it), then merge the fork into yours:
git merge someone/some-branch

# **Otherwise**, if you prefer to rebase, rewrite your master branch so your commits that aren't already in someone/master are replayed on top of that branch:
git rebase someone/some-branch
```

## Automatically Set Upstream
To default to the current branch when pushing code, so you don't have to set upstream all the time:

```
$ atom ~/.gitconfig
```

Then add:

```
[push]
	default = current
```

If you need to manually set your upstream:

```
git branch --set-upstream-to=origin/`git symbolic-ref --short HEAD`
```

## Delete a Branch
delete a branch:
```
# short for  git branch --delete
git branch -d [BRANCH]
```

force delete a branch:
```
# short for git branch --delete --force
git branch -D [BRANCH]
```

## Stashing
to stash the current work:
```
git add .
git stash
```

if there's just one stash, and we're ready to get back to our work, we can:
```Shell
git status apply
```

if we want to drop that stash from the stash list, we can:
```Shell
git stash drop
```

Or if we want to apply and drop in one fowl swoop, we can:
```Shell
git stash pop
```

if we want to see a list of stashes:
```Shell
git stash list
```

To apply a particular stash, append the `apply` argument with the stash index that you want:
```Shell
git stash apply stash@{2}
```

## Cherry Picking
### Just grabbing changes to a certain folder or file
If you want to cherry pick changes to a folder or file, i.e. to break an MR into smaller/domain driven parts here's how:

> One drawback of this, is that it wipes our your commit history for that folder, and replaces it with the new single commit.

```Shell
$ git checkout master   # starting from master
$ git checkout [source_branch] <paths>... # pull the changes from a given branch, and the given paths into master
$ git checkout -b [new_branch] # we don't commit to master! move this to a new branch
$ git add . # add the files
$ git commit -m "message"   # commit them
$ git push # and push them
```

In example:
```Shell
$ git checkout master   # starting from master
$ git checkout andes-messaging common/flowcontrol # pull the changes from a given branch, and the given paths into master
$ git checkout -b andes-flowcontrol # we don't commit to master! move this to a new branch
$ git add . # add the files
$ git commit -m "adds flow controls to common"   # commit them
$ git push # and push them
```

## SSH
* [Generating a new SSH key and adding it to the ssh-agent]( https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/)

```Shell
cd ~/.ssh
ls
ssh-add ~/.ssh/id_rsa_losandes
ssh-add ~/.ssh/id_rsa_varo
```

### Making this a function for easier repeatability after a restart
Add something like the following to `~./bash_profile`:

```Shell
function addSshKeys() {
  ssh-add ~/.ssh/id_rsa_losandes
  ssh-add ~/.ssh/id_rsa_varo
  ssh-add ~/.ssh/varo_dev1.pem
}
```

### Adding an SSH key from someone else:

```Shell
touch ~/.ssh/varo_dev1.pem
atom varo_dev1.pem
# Manually paste Public key and save
# Set the permissions for this file to read/write only by current user
chmod 600 ~/.ssh/varo_dev1.pem
ssh-add ~/.ssh/varo_dev1.pem
```

## Credentials

### Cacheing Credentials
https://git-scm.com/docs/git-credential-cache

telling the cache to remember our credentials for 1 hour (3600 seconds):
```
git config credential.helper 'cache --timeout=3600'
```

telling the cache to remember our credentials for 1 day (86400 seconds):
```
git config credential.helper 'cache --timeout=86400'
```

telling the cache to remember our credentials for 1 month (2592000 seconds):
```
git config credential.helper 'cache --timeout=2592000'
```

clearing the cache:
```
git config --system --unset credential.helper
```

### Forcing us to set the email on new repos
If you need to commit to multiple repos with different credentials, then it's important to ask git to force you to do this. Otherwise you'll end up committing under weird usernames, like our local mac name [from here](https://orrsella.com/2013/08/10/git-using-different-user-emails-for-different-repositories/).

#### What we want to enforce:
```shell
# clone the repo
$ git clone [URI]

# set the email address
$ git config user.email myname@example.com

# set the username
$ git config user.name myname
```

#### Via Config
To do that, we can tell git to use config only, and make sure the global email is not set:
```shell
# Require setting user.name and email per-repo:
$ git config --global user.useConfigOnly true

# Remove email address from global config:
$ git config --global --unset-all user.email
```

#### Via Hooks
Another is to add a pre-commit hook to `/usr/local/.git/hooks/pre-commit`

```shell
#!/bin/sh
#
# A git hook to make sure user.email exists before committing

EMAIL=$(git config user.email)

if [ -z "$EMAIL" ]; then
    # user.email is empty
    echo "ERROR: [pre-commit hook] Aborting commit because user.email is missing. Configure user.email and user.name for this repository by running: '$ git config user.email name@example.com' and '$ git config user.name losname'. Make sure not to configure globally and use the correct email."
    exit 1
else
    # user.email is not empty
    exit 0
fi
```

## Diffing

```
git difftool --tool=vimdiff
```


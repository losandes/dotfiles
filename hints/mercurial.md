## Installation

https://www.mercurial-scm.org
http://stevelosh.com/blog/2009/08/a-guide-to-branching-in-mercurial/

```Shell
$ brew install mercurial
```

## Creating a branch

```Shell
$ hg branch feature1
# (write some changes)
$ hg commit -m "hello world"
```

## Pulling a branch

```Shell
$ hg update feature1
# (write some changes)
$ hg commit -m "hello world"
```

## Pushing a branch

```Shell
$ hg push --rev branchname
$ hg push --rev bookmarkname
$ hg push --rev 4
```

## Merging into a branch

```Shell
$ hg update default
$ hg update feature1
$ hg merge default
$ hg commit -m "merged default into feature1"
```

## Removing a branch

```Shell
$ hg update feature1
$ hg commit --close-branch -m "finished feature1"
```


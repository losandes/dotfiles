#!/bin/bash

parse_rel_path() {
  # prints out computername ~parent/current $
  echo -n $PWD | sed -Ee 's|(~?/[^/]*/).*(/.{10,})|\.\2|'
}

parse_git_branch() {
  # note the `\1/` at the end of the last sed arg is where the output goes
  # git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/  ⫛ \1/'
  git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/   \1/' 
}

parse_node_version() {
  node --version | echo "  ⬢ $(xargs)"
}

# ------------------------------------------------------------------------------
# GIT STATUS
# Adapted from: https://github.com/denysdovhan/spaceship-prompt/blob/master/sections/git_status.zsh
# ------------------------------------------------------------------------------

LOSANDES_GIT_STATUS_SHOW="${LOSANDES_GIT_STATUS_SHOW=true}"
LOSANDES_GIT_STATUS_PREFIX="${LOSANDES_GIT_STATUS_PREFIX=" ["}"
LOSANDES_GIT_STATUS_SUFFIX="${LOSANDES_GIT_STATUS_SUFFIX="]"}"
LOSANDES_GIT_STATUS_UNTRACKED="${LOSANDES_GIT_STATUS_UNTRACKED="?"}"
LOSANDES_GIT_STATUS_ADDED="${LOSANDES_GIT_STATUS_ADDED="+"}"
LOSANDES_GIT_STATUS_MODIFIED="${LOSANDES_GIT_STATUS_MODIFIED="!"}"
LOSANDES_GIT_STATUS_RENAMED="${LOSANDES_GIT_STATUS_RENAMED="»"}"
LOSANDES_GIT_STATUS_DELETED="${LOSANDES_GIT_STATUS_DELETED="✘"}"
LOSANDES_GIT_STATUS_STASHED="${LOSANDES_GIT_STATUS_STASHED="$"}"
LOSANDES_GIT_STATUS_UNMERGED="${LOSANDES_GIT_STATUS_UNMERGED="="}"
LOSANDES_GIT_STATUS_AHEAD="${LOSANDES_GIT_STATUS_AHEAD="⇡"}"
LOSANDES_GIT_STATUS_BEHIND="${LOSANDES_GIT_STATUS_BEHIND="⇣"}"
LOSANDES_GIT_STATUS_DIVERGED="${LOSANDES_GIT_STATUS_DIVERGED="⇕"}"

parse_git_status() {
  [[ $LOSANDES_GIT_STATUS_SHOW == false ]] && return

  local INDEX git_status=""

  INDEX=$(command git status --porcelain -b 2> /dev/null)

  # Check for untracked files
  if $(echo "$INDEX" | command grep -E '^\?\? ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_UNTRACKED$git_status"
  fi

  # Check for staged files
  if $(echo "$INDEX" | command grep '^A[ MDAU] ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_ADDED$git_status"
  elif $(echo "$INDEX" | command grep '^M[ MD] ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_ADDED$git_status"
  elif $(echo "$INDEX" | command grep '^UA' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_ADDED$git_status"
  fi

  # Check for modified files
  if $(echo "$INDEX" | command grep '^[ MARC]M ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_MODIFIED$git_status"
  fi

  # Check for renamed files
  if $(echo "$INDEX" | command grep '^R[ MD] ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_RENAMED$git_status"
  fi

  # Check for deleted files
  if $(echo "$INDEX" | command grep '^[MARCDU ]D ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_DELETED$git_status"
  elif $(echo "$INDEX" | command grep '^D[ UM] ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_DELETED$git_status"
  fi

  # Check for stashes
  if $(command git rev-parse --verify refs/stash >/dev/null 2>&1); then
    git_status="$LOSANDES_GIT_STATUS_STASHED$git_status"
  fi

  # Check for unmerged files
  if $(echo "$INDEX" | command grep '^U[UDA] ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_UNMERGED$git_status"
  elif $(echo "$INDEX" | command grep '^AA ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_UNMERGED$git_status"
  elif $(echo "$INDEX" | command grep '^DD ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_UNMERGED$git_status"
  elif $(echo "$INDEX" | command grep '^[DA]U ' &> /dev/null); then
    git_status="$LOSANDES_GIT_STATUS_UNMERGED$git_status"
  fi

  # Check whether branch is ahead
  local is_ahead=false
  if $(echo "$INDEX" | command grep '^## [^ ]\+ .*ahead' &> /dev/null); then
    is_ahead=true
  fi

  # Check whether branch is behind
  local is_behind=false
  if $(echo "$INDEX" | command grep '^## [^ ]\+ .*behind' &> /dev/null); then
    is_behind=true
  fi

  # Check wheather branch has diverged
  if [[ "$is_ahead" == true && "$is_behind" == true ]]; then
    git_status="$LOSANDES_GIT_STATUS_DIVERGED$git_status"
  else
    [[ "$is_ahead" == true ]] && git_status="$LOSANDES_GIT_STATUS_AHEAD$git_status"
    [[ "$is_behind" == true ]] && git_status="$LOSANDES_GIT_STATUS_BEHIND$git_status"
  fi

  if [[ -n $git_status ]]; then
    # Status prefixes are colorized
      echo " $LOSANDES_GIT_STATUS_PREFIX$git_status$LOSANDES_GIT_STATUS_SUFFIX"
  fi
}


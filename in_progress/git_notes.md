Commit addressing SHA ~ ^ etc

----------------------------------------------------------

# Github

## Cloning an exiting repo

## Remote repos

## forking

## second upstream

## Pull requests

----------------------------------------------------------

## stash

git reset --hard
git clean -fdx
git reset --soft HEAD~1 (get rid of commit only on local branch)
and if they don't know an explanation of what git add, git commit, git push really mean the fact that git push to remote cannot be undone while git add and git commit can in terms of permanent branch history
git revert
git cherry-pick
git diff and diff tool.  --cached - compare to head - compare between branches

## git hooks - how to prevent big files or enforce a commit message

----------------------------------------------------------

Feedback from dan

* remove path on console examples
   I'm totally with you on the syntax highlighting on the console blocks.  I've removed the
   paths.  The only one where it mattered at all was the first block (where we make the directory
   and changedir into it.  I think that's clear enough with out the paths.

* blank lines around code blocks
   I can't believe I didn't think of this until now, but there's a tool called
   markdownlint which catches things like this.  I've run it and fixed the issues
   it raised (that were appropriate) including this one.

* remove email address!!!
   Thanks for catching this!  Fixed
* Python in the opening section.  "working on your python project". maybe something else
* more detail on 'what we wll learn" second paragraph
* add venv directories
* maybe add what not to add to git repos
* single * for emphasis - not single quotes
* Put : at end when bringing up a console section
* use * or ` for filenames?
* checking out particular SHA - change to it make sense as new user - checking out particular revision - yeah - I like that.  Makes more sense to new user
* NOTE formatting use ** and uppercase properly and block quote - that is SO much better
* maybe make some of the longer paragraphs shorter
* figures for "going back in town" section?  Maybe a screenshot
* first paragraph of staging - break into two
* QUICK TIP of something like that Headline to section on learn git branching double quotes
* HR - that was a leftover from original note taking
* split up push section - look for other long paragraphes
* add emacs tutorial to list of call outs.
* Move alert at end up to section on "what not to put into repo"
* make clone, fetch etc, monospace with `
* fix back linebreak in cherry-pick section - shorten sha
* NO H1s

mention markdownlint


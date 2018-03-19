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

General note: search bar on the site doesn't seem to work very well. 
Another note: I can't believe I didn't think of this earlier, but there's a 'markdownlint' tool which catches several of the formatting issues you mentioned (missing blank lines around code blocks, etc).  Maybe you're already aware, but it worked fairly well. 

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

* HR - that was a leftover from original note taking
   Oops!  Never intended that to be in final version.  

* Python in the opening section.  "working on your python project". maybe something else
   Is the Pep-8 reference good, or just awkward?

* more detail on 'what we wll learn" second paragraph
   Done. 

* NO H1s
   Fixed.  Good catch.  I'll see if I can't add a new rule to the lint tool i'm using to catch this.

* single * for emphasis - not single quotes
   Fixed.
* use ` for filenames
   Fixed.
* Put : at end when bringing up a console section
   Fixed.
* add venv directories - ALSO link this out to virtualenv tutorial on site.
   Fixed.

* maybe add what not to add to git repos
* Move alert at end up to section on "what not to put into repo"
   Fixed.  Added the new section and moved the alert there.

* checking out particular SHA - change to it make sense as new user - checking out particular revision - yeah - I like that.  Makes more sense to new user
   Totally get what you're suggesting here and it makes sense.  It's hard to remember that 'SHA' isn't a normal word for most people. :)

* add emacs tutorial to list of call outs.
   Fixed

* fix bad linebreak in cherry-pick section 
   Fixed this by using a shortened SHA

* NOTE formatting use ** and uppercase properly and block quote 
   Fixed.  THANKS!  that is SO much better than what I had!

* make clone, fetch etc, monospace with `
* QUICK TIP of something like that Headline to section on learn git branching double quotes
* figures for "going back in time" section?  Maybe a screenshot

* split up push section - look for other long paragraphes
* first paragraph of staging - break into two
* maybe make some of the longer paragraphs shorter



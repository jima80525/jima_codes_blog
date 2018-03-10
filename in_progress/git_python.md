Have you ever been working on a project that 'used' to work, but after a change here, a little edit there, it no longer works and you aren't quite sure how to get it back?  Revision control systems can help you solve that and other related problems.  Git is one of the most popular revision control systems today.
Revision control systems have been around since the early 70s


If you're writing Python, you've probably heard about Git and Github.  In this tutorial, I'll walk you through what Git is, how to use it for your personal projects, and how to use it in conjunction with Github to work with others on larger projects.

# what is git
Git is a `distributed revision control system`. Let's break that down a bit and look at what that means.

## revision control 
A `revision control system` (RCS) is a set of tools that track the history of a file (or set of files, in our case) through history. This means that at any point, you can tell your RCS (Git) to save the state of your files.  Then you may continue to edit the files and store that state as well.  Saving the state is similar to creatig a "backup copy" of your working directory.  When using Git we refer to this saving of state as 'making a commit'. 

When you make a commit in git, you can (and should!) add a commit message that tells at a high level what changes you made in this commit.  Git can show you the history of all of the commits and their commit messages.  This provide a very handy history of what work you have done and can really help pinpoint when a bug creeped into the system (more on that later)

In addition to showing you the log of changes you've made, git also allows you to compare files between different commits.  And, as I mentioned earlier, git will allow you to return any file (or all files) to an earlier commit with little effort.

## distributed revision control
OK, so that's a 'revision control system', what's the 'distributed' part?  It's probably easiest to answer that by starting with a little history.  Early revision control systems worked by storing all of those commits locally on your hard drive.  This collection of commits is called a 'repository'.   As larger groups started working (and networking became more common) RCSs changed to store the repository on a central server that was shared by many developers.  

Git, following the lead of a few other products, broke with that model.  Git does not have a 'central' server which has the definitive version of the repository.  All users have a full copy of the repository.  We'll see later how this changes things, both for the worse and the better.

# basic usage
Now that we've talked in general about what git is, let's run through an example and see it in action.  Like our earlier discussion, we'll start by just dealing with git on our local machine.  Once we get the hang of that, then we'll add Github and how to interact with it.



## Creating a new repo
To work with Git, you first need a repo to work in.  Creating one is simple, just use the `git init` command in a directory.  

```console
~/tmp $ mkdir example
~/tmp $ cd example
~/tmp/example $ git init
Initialized empty Git repository in /home/jima/tmp/example/.git/
```
Once you have a repo, you can ask git about it.  The git command you'll use most frequently is `git status`.  Try that now:

```console
~/tmp/example $ git status
On branch master

Initial commit

nothing to commit (create/copy files and use "git add" to track)
```
This shows you a couple of bits of information: which branch you're on, `master` (we'll talk about branches later) and that you have 'nothing to commit'.  This last part means that there are no files in this repo that git doesn't know about.  That's good, as we just created this directory.  

## Adding a new file
Now create a file that git doesn't know.  With your favorite editor, create the file hello.py which just has a print statement in it.

```Python
# hello.py
print('hello git!')
```

If you run `git status` again, you'll see a different result:

```console
~/tmp/example $ git status
On branch master

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	hello.py

nothing added to commit but untracked files present (use "git add" to track)
```

Now git sees the new file and tells you that it's 'untracked'.  That's just git's way of saying that the file is not part of the repo and is not under version control. We can fix that by adding the file to git.

```console
~/tmp/example $ git add hello.py
~/tmp/example $ git status
On branch master

Initial commit

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

	new file:   hello.py
```
Now git knows about hello.py and lists it under 'changes to be committed'.  Adding the file to git moves it into the 'staging area' (discussed below) and means we can commit it to the repo.

## Committing changes 

When you 'commit' changes, you are telling git to make a snapshot of this state in the repo.  Do that now by using the `git commit` command.  The `-m` option tells git to use the following commit message.  If you don't use it, git will bring up an editor for you to create the commit message.  In general you want your commit messages to reflect what has changed in the commit.

```console
~/tmp/example $ git commit -m "creating hello.py"
[master (root-commit) 25b09b9] creating hello.py
 1 file changed, 3 insertions(+)
 create mode 100755 hello.py
 
~/tmp/example $ git status
On branch master
nothing to commit, working directory clean
```

You can see that the commit command returned a bunch of information, most of which isn't that useful, but it does tell you that only 1 file changed (which makes sense as we added one file).  It also tells you the 'SHA' of the commit (`f8af94c`).  We'll have an aside about "SHA"s  a bit later.

Running the `git status` command again shows that we have a 'clean' working directory, meaning that all changes are committed to git. 

At this point we need to stop our tutorial and have a quick chat about the staging area.

## Aside: The staging area
Unlike many revision control systems, Git has a 'staging area' (often referred to as 'the index'). The staging area is how Git keeps track of changes you want to commit next.   When we ran `git add` above, we told Git that we wanted to move the new file 'hello.py' to the staging area.  This change was reflected in the git status, the file when from the 'untracked' section to the 'to be committed' section of the output.  

At any point of working with a file in git (assuming it's already been committed once), there are three versions of the file you can work with:

* the version on your hard drive that you are editing
* a potentially different version that git has stored in your staging area
* the latest version checked in to the repo

All three of these can be different versions of the file.  Moving changes to the staging area and then committing them brings all of these versions back into sync.

When I started with git, I found the staging area a little confusing and a bit annoying, I'll admit.  It seemed that it added extra steps to the process without any benefits.  When you're first learning git, that's actually true.  After a while, there are situations where you come to really appreciate having that functionality.  

If you're interested in more detailed info about the staging area, I can recommend this blog post:
https://alblue.bandlem.com/2011/10/git-tip-of-week-understanding-index.html

## gitignore

The status command is very handy and you'll find yourself using it often.  But sometimes you'll find that there are a bunch of files that show up in the 'untracked' section that you want git to just not see.  That's where the .gitignore file comes in.

Let's walk through an example.  Create a new python file in the same directory called `myname.py`.
```python
# myname.py
def get_name():
    return "Jim"
```

Then modify you hello.py to include `myname` and call its function: 

```python
import myname

name = myname.get_name()
print("hello {}".format(name))
```
When you import a local module, python will compile it to bytecode for you and leave that file on your filesystem.  In Python2, it will leave a file called `myname.pyc`, but we'll assume you're running Python3.  In that case it will create a __pycache__ directory and store a pyc file there.  This is what's shown below.

```console
~/tmp/example $ vi myname.py
~/tmp/example $ ./hello.py
hello Jim!
~/tmp/example $ ls
hello.py  myname.py  __pycache__
```

Now if you run git status, you'll see that directory in the 'untracked' section.  Also note that your new `myname.py` file is untracked while the changes you made to hello.py are in a new section called "Changes not staged for commit".  This just means that those changes have not yet been added to the staging area.  
```console
~/tmp/example $ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   hello.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	__pycache__/
	myname.py

no changes added to commit (use "git add" and/or "git commit -a")
```

Before we move on to the gitingore file, let's clean up the mess we've made a little bit.  First we'll add the myname module, just like we did earlier:

```console
~/tmp/example $ git add myname.py
~/tmp/example $ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	new file:   myname.py

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   hello.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	__pycache__/

```
You can see that we've moved `myname.py` into the staging area.  Now let's do the same thing for `hello.py`.  We use the same command for an existing file that we used for a new file: `git add`.

```console
~/tmp/example $ git add hello.py
~/tmp/example $ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   hello.py
	new file:   myname.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	__pycache__/

```
Let's commit those changes and finish our clean up:

```console
~/tmp/example $ git commit -m "added myname module"
[master 946b99b] added myname module
 2 files changed, 8 insertions(+), 1 deletion(-)
 create mode 100644 myname.py
```

Now when we run status, all we see is that `__pycache__` directory.

```console
~/tmp/example $ git status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)

	__pycache__/

nothing added to commit but untracked files present (use "git add" to track)
```

To get all __pycache__ directories (and their contents) to be ignored, we're going to add a `.gitignore` file to our repo.  This is as simple as it sounds.  Edit the file (remember the 'dot' in front of the name!) in your favorite editor.

```python
# .gitignore
__pycache__
```
Now when we run `git status` we no longer see the `__pycache__` directory.  We do, however, see the new `.gitignore`!

```console
~/tmp/example $ git.status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)

	.gitignore

nothing added to commit but untracked files present (use "git add" to track)
```
That file is just a regular text file and can be added to you repo like anything else.  Do that now.
```console
~/tmp/example $ git add .gitignore
~/tmp/example $ git commit -m "created .gitignore"
[master 1cada8f] created .gitignore
 1 file changed, 1 insertion(+)
 create mode 100644 .gitignore
```

You can have several .gitignore files in a single repo.  A .gitignore in one directory applies to that directory and all of its subdirectories.  Having a file ignored in a subdirectory does not mean that it is ignored in the parent.  

It's also possible to have a 'global' .gitignore file stored in your home directory.  This is very handy if your editor likes to leave temporary or backup files in the local directory. 

### Aside What is a 'SHA'
When git stores things (files, directories, commits, etc) in your repo, it stores them in a complicated way involving a 'hash function'.  We don't need to go into the details here, but a hash function takes "something" (again, a file, a directory, etc) and produces a unique ID for that thing that is much shorter (20 bytes in our case).  These IDs are called "SHA"s in git and, while they not guaranteed to be unique for most practical applications, they are.  

Git uses its hash algorithm to index *everything* in your repo.  Each file has a SHA that reflects the contents of that file. Each directory, in turn, is hashed.  If a file in that directory changes the hash of the directory changes, too.  

So each commit contains the SHA of the top-level directory in your repo along with some [other info](https://gist.github.com/masak/2415865).  That's how a single 20 byte number describes the entire state of your repo.  

You might notice that sometimes git uses the full 20 character value to show you a SHA:
```console
commit 25b09b9ccfe9110aed2d09444f1b50fa2b4c979c
```
and sometimes it shows you a shorter version:
```console
[master (root-commit) 25b09b9] creating hello.py
```
Usually it will show you the full string of characters, but you don't always have to use it.  The rule for git is that you only have to give enough characters to ensure that the SHA is unique in your repo.  Generally 7 characters is more than enough.  


Each time you commit changes to the repo, git creates a new SHA that describes that state.  We'll look at how SHAs are useful in the next section.

## git log

Another very frequently used git command is `git log`.  Git log shows you the history of the commits that got you up to this point.

```console
~/tmp/example $ git log
commit 1cada8f59b43254f621d1984a9ffa0f4b1107a3b
Author: Jim Anderson <jima80525@gmail.com>
Date:	Sat Mar 3 13:23:07 2018 -0700

    created .gitignore

commit 946b99bfe1641102d39f95616ceaab5c3dc960f9
Author: Jim Anderson <jima80525@gmail.com>
Date:	Sat Mar 3 13:22:27 2018 -0700

    added myname module

commit 25b09b9ccfe9110aed2d09444f1b50fa2b4c979c
Author: Jim Anderson <jima80525@gmail.com>
Date:	Sat Mar 3 13:10:12 2018 -0700

    creating hello.py
```
As you can see in the listing above, all of the commit messages are shown, in order, for our repo.  The start of each commit is marked with the word "commit" followed by the SHA of that commit.  `git log` gives you the history of each of the shas.  

## going back in time - checking out a particular SHA

Because git remembers each commit you've made with it's SHA, you can tell git to go to any of those locations and view the repo as it existed then.  Let's try that.

```console
~/tmp/example: git checkout 3749c07559cc2bf181e63f1a264c8615f7ca3524
Note: checking out '3749c07559cc2bf181e63f1a264c8615f7ca3524'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b <new-branch-name>

HEAD is now at 67aaa16... added hello
```

OK, so there's a LOT of information here that's confusing.  Let's start by defining some of those terms.  First off is 'HEAD'.  HEAD is git's name for whatever SHA you happen to be looking at at any time.  It does NOT mean what is on your filesystem or what is in your staging area.  So, if you've  edited a file, the version on your filesystem is different than the version in HEAD (and yes, it's ALL CAPS).

Next up is 'branch'.  The easiest way to think about a branch is that it is a label on a SHA.  It has a few other properties that are useful, but for now, think of a branch as a SHA-label.  NOTE that those of you that have worked with other revision control systems (I'm looking at you, subversion) will have a very different idea of what a branch is.  Git treats branches differently and this is a good thing.

Putting that together, 'detached HEAD' simply means that your HEAD is pointing to a SHA that does not have a branch (or label) associated with it.  Git very nicely tells you how to fix that situation.  There are times you want to do that, and there are times when you can work in that detached HEAD state just fine.  

Getting back to our demo, if you look at the state of the system now, you can see that the .gitignore file is no longer present.  

Alright.  Now, how do we get back to where we were?  There are two ways, one of which you should know already, `git checkout 49f8ed6ebf3ee8845282ffe62cc3d81e016419fa`.  This will take you back to the SHA you were at when you started moving around.  (NOTE: one odd thing, at least in my version of git, is that it still gives you a 'detached HEAD' warning, even though you're back to the SHA associated with a branch.)  

The other, and more common way of getting back is to check out the branch you were on. Git always starts you off with a branch called 'master'.  We'll learn how to make other branches later but for now we'll stick with master.  To get back to where you where, you can simply do `git checkout master`.  This will return you to the latest SHA committed to the 'master' branch, which in our case has the commit message "created .gitignore".

Note that there are several methods for specifying a specific commit.  The SHA is probably the easiest to understand.  The other methods use different symbols and names to specify how to get to a specific commit from a known place, like HEAD.  I won't be going into those details in this tutorial, but if you'd like more details you can find them [here](https://git-scm.com/book/en/v2/Git-Tools-Revision-Selection).

# Branching basics

Let's talk a little more about branches.  Branches provide a way for you to keep separate streams of development apart.  While this can be useful when you're working alone, it's almost essential when you're working on team.  Imagine I'm working in a small team and I've got a feature to add to the project.  While I'm working on it, I don't want to add my changes to `master` as it still doesn't work correctly and might mess up my team members.  So, instead of working on `master`, I'll create a new branch: 

```console
~/tmp/example: git checkout -b my_new_feature
Switched to a new branch 'my_new_feature'
~/tmp/example: git status
On branch my_new_feature
nothing to commit, working directory clean
```
We used the `-b` option on the checkout command to tell git we wanted it to create a new branch.  As you can see above, running `git status` in our branch shows us that the branch name has, indeed, changed.   Let's look at the log.

```console
~/tmp/example: git log
commit 1cada8f59b43254f621d1984a9ffa0f4b1107a3b
Author: Jim Anderson <jima80525@gmail.com>
Date:	Thu Mar 8 20:57:42 2018 -0700

    created .gitignore

commit 946b99bfe1641102d39f95616ceaab5c3dc960f9
Author: Jim Anderson <jima80525@gmail.com>
Date:	Thu Mar 8 20:56:50 2018 -0700

    added myname module

commit 25b09b9ccfe9110aed2d09444f1b50fa2b4c979c
Author: Jim Anderson <jima80525@gmail.com>
Date:	Thu Mar 8 20:53:59 2018 -0700

    creating hello.py
```
As I hope you expected, the log looks exactly the same.  When you create a new branch, the new branch will start at the same location as you were at.  In this case we were at the top of master, `1cada8f59b43254f621d1984a9ffa0f4b1107a3b`, so that's where the new branch starts.  

Now let's work on that feature.  Make a change to the hello.py file and commit it.  I'll show you the commands for review, but I'll stop showing you the output of the commands for things you've alreayd seen:

```console
~/tmp/example: git add hello.py
~/tmp/example: git commit -m "added code for feature x"
```
Now if you do `git log` you'll see that our new commit is present.  In my case it has a SHA 4a4f4492ded256aa7b29bf5176a17f9eda66efbb, but your repo is very likely to be different.


```console
~/tmp/example: git log
commit 4a4f4492ded256aa7b29bf5176a17f9eda66efbb
Author: Jim Anderson <jima80525@gmail.com>
Date:	Thu Mar 8 21:03:09 2018 -0700

    added code for feature x

commit 1cada8f59b43254f621d1984a9ffa0f4b1107a3b
... the rest of the output truncated ...
```

Now switch back to the 'master' branch and look at the log.  
```console
git checkout master
git log
```
Is the new commit for feature x there?

Git has a built-in way to compare the state of two branches so you don't have to work so hard.  It's the `show-branch` command.  Here's what it looks like:

```console
~/tmp/example: git show-branch my_new_feature master
* [my_new_feature] added code for feature x
 ! [master] created .gitignore
--
*  [my_new_feature] added code for feature x
*+ [master] created .gitignore
```
The chart it generates is a little confusing at first, so let's walk though it in detail.  First off, you call the command by giving it the name of two branches.  In our case that was 'my_new_feature' and 'master'.  

The first two lines of the output are the 'key' to decode the rest of the text.  The first line has a `*` in the first column, then the name of the branch, then the commit message for the most recent commit on that branch.   The second line starts with a `!` in the second column followed by the name and the top commit message for that branch.  

The third line is a separator. 

Starting on the fourth line, it starts showing commits that are in one branch but not the other.  In our current case, this is pretty easy.  There's one commit in 'my_new_feature' that's not in master.  You can see that on the fourth line.  Notice how that line starts with a '*' in the first column.  This is to indicate which branch this commit is in.  

Finally, the last line of the output shows the first common commit for the two branches.  

This example is pretty easy. Let's make it more interesting.  Add a few more commits to 'my_new_feature' and a few to 'master'
```console
~/tmp/example $ git show-branch my_new_feature master
* [my_new_feature] commit 4
 ! [master] commit 3
--
*  [my_new_feature] commit 4
*  [my_new_feature^] commit 1
*  [my_new_feature~2] added code for feature x
 + [master] commit 3
 + [master^] commit 2
*+ [my_new_feature~3] created .gitignore
```
Now you can see that there are different commits in each branch.  Note that the '[my_new_feature~2]' text is one of the commit selection methods I mentioned earlier.  You can have it show you the SHAs for those commits by adding the --sha1-name option to the command: 
```console
~/tmp/example $ git show-branch --sha1-name my_new_feature master 
* [my_new_feature] commit 4
 ! [master] commit 3
--
*  [6b6a607] commit 4
*  [12795d2] commit 1
*  [4a4f449] added code for feature x
 + [de7195a] commit 3
 + [580e206] commit 2
*+ [1cada8f] created .gitignore
```
OK, so now you've got a branch with a bunch of different commits on it.  You finally finish that feature and are ready to get it to the rest of your team.  Now what?

There are three main ways to get commits from one branch to another: merging, rebasing, and cherry-picking.  We'll cover each of these in turn in the next sections.

### merging
Merging is the simplest of the three to understand and to use.  When you do a merge, git will create a new commit that combines the top SHAs of two branches if it needs to.  If all of the commits in the other branch are 'ahead' (based on) the top of the current branch, it will just do a 'fast-foward merge' and place those new commits on this branch.  

Let's back up to the point where our show-branch output looked like this:
```console
~/tmp/example $ git show-branch --sha1-name my_new_feature master 
* [my_new_feature] added code for feature x
 ! [master] created .gitignore
--
*  [4a4f449] added code for feature x
*+ [1cada8f] created .gitignore
```
Now, we want to get that commit `4a4f449` to be on master.  So check out master and run the git merge command there.
```console
~/tmp/example $ git checkout master
Switched to branch 'master'

~/tmp/example $ git merge my_new_feature 
Updating 1cada8f..4a4f449
Fast-forward
 hello.py | 1 +
 1 file changed, 1 insertion(+)
```
Since we were on branch master, we did a merge of the my_new_feature branch to us.  You can see it tells you That this is a fast forward merge and what files were changed.  Let's look at the log now.

```console
commit 4a4f4492ded256aa7b29bf5176a17f9eda66efbb
Author: Jim Anderson <jima80525@gmail.com>
Date:   Thu Mar 8 21:03:09 2018 -0700

    added code for feature x

commit 1cada8f59b43254f621d1984a9ffa0f4b1107a3b
Author: Jim Anderson <jima80525@gmail.com>
Date:   Thu Mar 8 20:57:42 2018 -0700

    created .gitignore

```
If we had made changes to master before we merged, git would have created a new commit which was the combination of the changes from the two branches. 

One of the things git is fairly good at is understanding the common ancestors of different branches and automatically merging changes together.  If the same section of code has been modified in both branches, git can't figure out what to do.  When this happens, it stops the merge part-way through and gives you instructions how to fix the issue.  This is called a 'merge conflict'.

### rebasing
Rebasing is similar to merging, but behaves a little differently.  In a merge, if both branches have changes, a new 'merge commit' is created.  In rebasing, git will take the commits from one branch and 'replay' them on the top of a different branch.  

Setting up a demo to show this is a bit tricky in text *and* there is an excellent web page I'll reference at the end of this section that covers the topic graphically and explains it quite well. 

### cherry-picking
Cherry picking is another method for moving commits from one branch to another.  Unlike merging and rebasing, though, in cherry picking you specify exactly which commits you mean.  The easiest form of this is just specifying a single SHA:
```console
git cherry-pick 4a4f4492ded256aa7b29bf5176a17f9eda66efbb
```
This tells git to take the changes that went into `4a4f4492ded256aa7b29bf5176a17f9eda66efbb` and apply them to the current branch.  

This feature can be very handy when you just want a particular change on your branch, but not the entire branch that change was made in.  

I can't leave this topic without recommending an excellent resource for learning about git branches.  The [Learn Git Branching](https://learngitbranching.js.org/) website provides a set of exercises using a git-like language and graphical representations of commits and branches to really, clearly explain the difference between merging, rebasing, and cherry-picking (along with a few other topics).  I *highly* recommend spending some time working through these exercises.


## Working with remote repos
----------------------------------------------------------
All of the commands we've discussed to this point work only with your local repo.  They don't do any communication to a server or anything like that.  It turns out that there are only four major git commands which actually talk to remote repos:
* clone
* fetch 
* pull
* push

That's it.  Everything else is done on your local machine.  (OK, to be complete, there *are* other commands that talk to remotes, but they're don't fall into the 'basic' category.)

Let's look at each of these commands in turn. 

### Clone
Git clone is the command you use when you have the address of a known repository and you want to make a local copy.  For this example let's use a small repo I have on my github account, github-playground.  

The github page for that repo lives [here](https://github.com/jima80525/github-playground).  On that page you will find a "Clone or Download" button which gives you the URI to use with the git clone command.  If you copy that, you can then clone the repo with 
```console
git clone git@github.com:jima80525/github-playground.git
```
Now you have a complete repository of that project on your local machine.  This includes all of the commits and all of the branches ever made on it.  (NOTE: this repo was used by some friends while they were learning git.  I copied or 'forked' it from someone else.)

### Fetch
To explain the fetch command clearly, we need to take a step back and talk about how git manages the relationship between your local repo and a remote repo.  This next part is background and, while it's not something you'll use on a day-to-day basis, it will make the difference between 'fetch' and 'pull' make more sense.

When you clone a new repo, git doesn't just copy down a single version of the files in that project.  It copies the entire repository and uses that to create a new repository on your local machine.  Git does not make local branches for you except for master.  However it does keep track of the branches that were on the server.  To do that, git creates a set of branches that all start with `remotes/origin/<branch_name>`.  You rarely will check these out (almost never), but it's handy to know that they are there.  Remember every branch that existed on the remote *when you cloned the repo* will have a branch in remotes/origin.  

When you create a new branch and the name matches an existing branch on the server, git will mark you local branch as a 'tracking branch' that is associated with a remote branch.  We'll see how that is useful when we get to pull. 

So, now that you know about the remotes/origin branches, understanding `git fetch` is pretty easy.  All fetch does is to update all of the remotes/origin branches.  It does not modify any of your local branches, just the branches stored in remotes/origin.

### Pull
Git pull is simply the combination of two other commands.  First it does a fetch to update the remotes/origin branches.  Then, if the branch you are on is tracking a remote branch, it does a git merge of the corresponding remote/origin branch to your branch.  For example, say you were on the my_new_feature branch and your coworker had just added some code to it on the server.  If you do a `git pull`, git will update ALL of the remotes/origin branches and then do a `git merge remotes/origin/my_new_feature` which will get the new commit onto the branch you're on!

There are some limitations here.  Git won't let you even try to do a git pull if you have modified files on your local system (that can create too much of a mess).  If you have commits on your local branch and the remote also has new commits (this is called "the branches have diverged"), then the git merge portion of the pull will create a merge commit, just like we discussed above.  (For those of you that are reading closely, you can also have git do a rebase instead of a merge by doing `git pull -r`)

### Push
As you probably have guessed, git push is just the opposite of git pull.  Well, almost the opposite.  Push sends the info about the branch you are pushing and asks the remote if it would like to update its version of that branch to match yours.  Generally this amounts to you pushing your new changes up to the server.  (there are a LOT of details and complexity here invovling exactly what a fast-forward commit is.  There is a fantastic write up if you're interesting [here](https://stackoverflow.com/a/26005964/6843734)) 


## putting it all together - simple git workflow

At this point we've reviewed several of the basic git commands and how you might use them.  I'll wrap up with a quick description of a possibly workflow in git.  This workflow assumes you are working on your local repo and have a remote repo to which you will push changes.  It assumes you've already cloned the repo.

1 


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
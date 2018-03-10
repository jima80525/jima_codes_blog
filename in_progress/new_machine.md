I've had lots of practice setting up new Linux machines lately.  My laptop  recently had to be rebuilt and I just got a new desktop!  On top of that, I'll be starting a new job next week and will get yet-another change to install and setup a new machine.  Throughout my career this is the way it seems to go, I won't have to set up a machine for  a long stretch (usually years) and then I'll get to do a couple in short order.

Fortunately I'm able to install Linux on all of these machines, which definitely  makes life a little simpler.  I've found that by using github creatively, I've  streamlined the process reasonably well.

# The 'bin' Directory

Like many long-time linux users, I've come up with a toolbox of scripts, aliases, and tools which I like to have at my fingertips.  Several years ago, a co-worker suggested putting all of these into a separate git repo and storing it on github.  This works tremendously as I have the repo called 'bin' which is the directory it gets cloned into by default.  One of the first installs I do  on a new machine is git.  Once I can clone this repo things get easier.

In addition to the regular list of scripts, I keep a copy of my bashrc file, which, again, is something  that you keep customizing over the years.  I can just copy that from my ~/bin directory to ~/.bashrc and  it not only has my custom aliases and bash functions defined, it also extends my path to point to ~/bin!

# Vim
The other handy repo I've made contains all of my VIM configuration files.  It also has a copy of my vimrc so,  again, I can just copy that into my home dir.  Keeping vim configuration consistent across all of my machines  definitely helps keep me sane, and, because of the way vim stores it's plugins, all of those get installed and  loaded from the git repo.  This makes it trivial to try out a new extension and back it out if you don't like it.

# The checklist
The other handy file I keep in the bin repo is a checklist of things to do and  how to find/install various applications.  This is really handy when I run into distro-specific issues (a previous job required Centos6, which was, let's say, unique) or problems with specific packages (the three steps required to install scudcloud, for instance).

# Wrap up
That's an overview of my process.  It took less than half of a day to get from starting a fresh install  to completely up and running.  Are there any tips or ideas on how you manage this process?  Please leave them  in the comments!

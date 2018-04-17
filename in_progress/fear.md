# We Fear Change

In my previous two positions I've come across some developer behavior that I've found to cause code-rot and compounding technical debt: Fear.

The interesting thing for me was that the two teams came by this fear in very different fashions.  One team (Team A) was fairly incompetent and had a culture of isolation and information hiding.  The other team (Team B) was young, smart and really willing to learn.  

## Team A

Team A had spent years working on a relatively well contained problem but were very adverse to doing any sort of automated testing.  At one point they had to be force by management to add some tests for the system.  They responded by creating something so Byzantine that very few people could figure out how to run it, and it was never clear if the test was actually successful.  

Now, the part of the system that Team A was working on did provide some challenges to testing, but these were surmountable with some effort, and many of the challenges were actually the result of poor design decisions.  

## Team B

Team B, on the other hand, had a very different problem.  They inherited a 'pit of despair' piece of code.  Ansi C (written before C99) with several functions that were each several thousand lines long (complete with multi-level GOTOs).    

To add to the fun, this section of code was part of a cross-platform distributed system, so automated testing of the real use case was prohibitively expensive. 

This led the team to live by the motto "Don't touch that file!"  

I'd like to point out that Team B did a great job of adding unit tests and integration tests to the rest of the system, but this one part was dire. 

## Fear

Both of these situations were bad.  Both were caused by fear.  I'll admit to having more sympathy for Team B, as their fear seems more justified.  Sometimes you end up getting handed a turd like that.  

Team A, on the other hand, had internalized the fear.  They weren't going to test if they could help it, and making simple, sane changes to their code left them flustered.  Getting the code to pass a linter was a horrible experience, much less getting them to think about refactoring to reduce the copy-pasta.  

## ...And Its Opposite

I'm not sure I have a strong point here.  I've just been thinking about these two teams recently and how they ended up in similar places but via very different paths.   Note that I was a member of both teams (though I claim to be only peripherally involved in Team A), so I'm not casting stones here. 

I think what gives me pause is that I tend to lean too far in the other direction.  I'm generally willing to refactor with the risk of breaking code, confident that we can pick up the pieces of what's broken AND have cleaner, more readable code.  

Sometimes that's not the right path, though.  Good things to learn.
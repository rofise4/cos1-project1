Overview

So this week I wanted to get the remainder of the actual chess mechanics done and move onto drafting. I had 3 issues for drafting, the economy and piece placement which I managed to get through. I also did some stuff throughout the week to make the game a little more user friendly since I realized someone who hasnt been developing this game for the last 3 weeks probably has no clue what im expecting them to do.

Checkmate and stalemate

For checkmate I ended up making a function that loops through the pieces on the board belonging to the current player. It generates the possible moves for each piece and saves the locations to a temporary vector. The reason I did this is because running my function for testing check would clear the locations I was trying to test in the first place.

From here I just move the piece, test for check and move it back. I also save a pointer to whatever piece would have been captured so I can return it to the board after testing.

If at any point it finds a legal move it just returns true, theres no reason to continue testing the other pieces.

This made stalemate and checkmate pretty easy to implement since at this point all I really need to know is if the player has any legal moves and if their king is currently in check.

Refactoring

I went back and combined my functions for locating both kings. Not really sure why I originally made 2 seperate functions for this but they were doing the same thing and I could just pass in an int for the player.

I also made a new header and cpp for drafting. I figured this was enough of its own system that there wasnt really any reason to include all of it in my main game logic. I split up generating the pieces, selecting them and the actual purchasing of the pieces.

There is admittedly some pretty repetitive code in drafting right now but I was more concerned with getting it functional and figuring out how I actually wanted the system to work. Ill probably go back through and condense some of this next week.

Drafting and economy

I ended up giving both players a budget of 20 and 5 rounds to purchase pieces. Each round they get 3 randomly generated options to purchase from.

Currently the prices are

Pawn = 1

Knight = 3

Bishop = 3

Rook = 5

Queen = 9

I did something a little weird with the RNG by design. I have it filtering the pieces that can be generated based on the players remaining budget.

At 13 or more points you can get bishops, rooks and queens. From 6-12 you can get anything other than a queen and below 6 you can get pawns, knights and bishops.

I intentionally didnt make it so that everything generated has to be affordable. I wanted to add some rng where overspending could make your last round or 2 of drafting unaffordable and leave you with less pieces. Just another trade off to consider when making selections.

I generate integers 1-5 that correlate to the pieces and push them into a vector until I have 3 options. I then display those options and return the vector so my next function can handle the players selection.

I have another vector containing the prices which I use to compare against the players budget. Before even asking for input I go through all 3 options to make sure there is something they can afford. If there isnt I return a 6 which doesnt actually correlate to a piece, its just there to let my main drafting loop know nothing was purchased.

Otherwise it deducts the cost of the piece and pushes the integer into whichever players vector it belongs to.

I also dont have any restrictions on how many of an individual piece someone can have. If someone wants to spend their budget buying a bunch of bishops thats their decision.

Creating pieces

So something I hadnt really accounted for earlier in development was that I wouldnt know how many of each piece I actually needed. Previously I was just creating all of the pieces I knew I would need which obviously doesnt work very well if someone decides they want 4 knights.

I made a function that takes in the int associated with the piece and creates a new instance of that class using new. I assign it to whichever player is purchasing it and return the pointer.

I also have a vector that I push the pointers into when creating the pieces. This way regardless of where that piece goes or if it gets captured I can still locate it in memory at the end of the game. I just loop through the vector, delete the pieces and clear it when the game ends.

I did have to add a virtual destructor to my Pieces class since im using a Pieces pointer to delete objects of the derived classes.

Piece placement

I decided to just have both kings default to opposite corners of the board and let the players decide where literally everything else goes.

I loop through the vectors from drafting and alternate between players placing a piece. I tell them what piece they are currently placing and have them click a location on the board.

I was able to reuse a lot of my existing functions for this which made it significantly easier than I originally expected. I basically use my existing mouse input to get a location, check that its empty and use placeP to put the piece there. I then run testCheckSelf for both players to make sure neither king is in check.

I intentionally leave the piece in the invalid location and give the player a message as to why its invalid. I figured its probably better for them to actually see what they did wrong rather than just have nothing happen when they click the square. When they select a new location it moves that same piece.

Changes to chess rules

I decided to scrap en passant, pawn promotion and pawns moving 2 squares on their first move.

After looking at drafting and the idea that you could place pieces anywhere that does not put a king in check, mixed with the significantly shorter distance of the overall board, those moves felt like they would ruin the game balence by opening up a lot of opportunities for first move promotions.

Especially considering im charging 1 point for a pawn and 9 for a queen. Whats the point of purchasing a queen if you can just purchase a pawn and accomplish the same thing on your first move.

I did consider the idea that having a pawn placed near the back row could be countered by the next player covering its path with one of their own pieces. However with p2 being able to act last I still think this could ruin the integrety of the game.

I also dont really see much of a reason for a pawn to move 2 squares at once on a board thats only 5 squares long to begin with. Getting rid of that also eliminates the need for en passant.

So I will be leaving those rules out of my game.

Vector usage

I ended up using vectors in quite a few places this week.

Storing possible moves to simulate

Storing the randomly generated drafting options

Storing the prices of pieces

Keeping track of both players purchases

Keeping track of the pointers to dynamically allocated pieces

I didnt really want to just throw a vector somewhere in my code for the sake of using one. Luckily drafting presented quite a few opportunities to use them considering no 2 games necessarily have the same amount or type of pieces.

issues and testing

I had a few moments where I was forgetting that the contents of my vector and the index of my vector were 2 entirely seperate things. Especially when I was using the contents of one vector to locate something in another vector.

When I first got placement working all of my pieces were invisible. After fixing that I had an issue where pieces would leave behind a copy of themselves visually when being moved. They werent actually there, I just wasnt drawing over them which made the board look ridiculous if you kept making invalid placements.

I also had some issues with placeP and realized I forgot to assign player 2s king to player 2 since I got rid of my original setupPieces function which was previously doing that for me.

I got these resolved and everything is working now. I also tested some specific situations with checkmate and stalemate, pawns registering diagonal attacks but not forward movement as check and kings attempting to move adjacent to eachother.

In game message console

I also ended up making what is essentially an in game message console. Kind of like in pokemon where you have a designated box where all of the dialogue and instructions appear.

I wanted to have a designated area underneath the board where I could communicate with the player without continuously printing new lines and having everything scroll off the screen. I made a function that clears that specific area and allows me to display new messages without interfering with the actual board.

Im using this for drafting, displaying budgets, telling players what piece they are placing, explaining invalid placements and just generally letting the players know whats going on throughout the game.

I also made it highlight the players king when they are in check. This was something that occurred to me while playing it myself because obviously not everyone playing my game is going to immediately recognize that they are in check.

Planning and next week

I broke up the 3 issues for this week because I figured it would be significantly easier to get each of these systems working individually and then figure out how to get them all interacting with eachother. Most of my time was spent on functionality with some additional time spent fixing weird issues that came up when incorporating everything into the game.

At this point I have a functional game and I think I want to spend some time actually playing it. Im curious how balenced the economy is and what kind of weird strategies people can come up with when given basically complete freedom over the starting positions of their pieces.

I also want to go back through and clean up some of my code, especially some of the more repetitive sections and improve my input validation.

I still want to incorporate abilities like I originally planned but ill see how much time I have next week and how much I actually want to change after playing around with the game some more.

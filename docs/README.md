Week 1 Milestone update
Overview:

This week I got my piece movement checks functional, updated the board to display as a 5x5 grid, and refactored my code so it is no longer one massive .cpp file.

Accomplishments:

My accomplishments for the week are that I modified the board to be 5x5, added movement checks for the knight, bishop, rook, queen, and king, and fixed the pawn movement.

I also added a switch to toggle between players and integrated it into which moves are available for the selected piece.

I added mouse input that waits until a mouse click happens within the displayed board, calculates which square was clicked, and returns the coordinates to be used for selecting the piece located on that square.

I also refactored my code so it is no longer one giant file.

Challenges:

My biggest challenge was handling mouse input because I had only used the Windows API for changing background and foreground colors and setting the console cursor to write text at fixed coordinates.

This took a lot of research and experimentation with new syntax to get working.

Next Steps:

My next steps are integrating the mouse input into piece selection and movement, then connecting my existing player switch so turns automatically change after a move.

That should make the base chess game almost fully functional and allow me to work on the drafting systems and abilities that make it unique.# Docs.

This folder is for miscellaneous documentation. 

It's common for repositories to contain documentation provided by the developers or team working on projects together.   

In this class you may be asked to work on documentation that can be stored in this folder. 

## Changelog

### Week 2
**Added**
- Main menu
- Legal move highlighting

**Fixed**
- Selecting pieces with no available moves

**Improved**
- Separated piece classes into individual files
- Organized console graphics functions
- Removed using namespace std
So far this week I have reviewed the instructor and classmate feedback and updated my project board and issues to include removing using namespace std and breaking down my larger functions into their own files. 
    I just made a usability improvement by adding a loading menu prompting for input from the user, before I just had a blank console window waiting for input in place for testing purposes. Moving forward in the week I would like to add instructions and feedback for invalid piece selection.
    Currently a function I can demonstrate is legal move checking on my pieces. It works by taking the board coordinates of the store piece object, then based on the type of piece that is selected it checks coordinates based on normal chess movement rules. At each coordinate it checks to see if the space is empty, and if another object is stored at those coordinates it checks to see if it is the same player piece or an enemy piece and highlights spaces accordingly. For pieces like bishops it uses a loop to be able to stop searching once encountering another object. (see attached photo)
    Next steps for this week are, removing using namespace std and adding std::  to my existing code base, separating my larger functions into their own files to improve readability, and then using the mouse input to finally make the base chess functionality playable before moving on to adding the extra features.
    My Level Up goal is to get my code more organized with the separation into different files and continuation of that style. And increase the user friendliness of my application so it is closer to a working demo by the end of the week by having a more refined menu and visual indicators of what is happening.
  1.Progress Update: 
    This week I have made pretty substantial changes to my project, I reorganized my code and split it down into many smaller header and source files, removed using namespace, and connected most of my systems together. So far this has had a noticeable benefit to making modifications to my code without having to jump up and down constantly trying to keep track of what line number I need to go back and reference.
2.Project Progress: 
    Probably the biggest accomplishments of this week was connecting the mouse input to piece selection, adding an alternating turn system, getting captures working and check and move validation. 
    Putting together these systems allow players to take turns selecting a piece, having it highlight the piece and its legal move destinations, and then execute the turn and switch back to the next player. It also accounts for check and requires the player to block, capture, or move their king to safety as in standard chess rules. Also the framework for check should be most of the heavy lifting for checkmate which I'm hoping to add tonight.
3.Usability Improvements:
    One of the biggest user improvements I have made this week is allowing players to deselect a piece if they decide they no longer want to move that piece or had a misclick. This improves the game by being more forgiving and safeguarding against potential frustrations from accidental input that could ruin their piece development. Additionally I added safe guards to verify the piece selected belongs to the current player (would like to add a display at the top to tell you whose turn it is), and limit piece selection during situations where there may be no legal moves.
4.Level Up Goals: 
    My next goals in the project are to start with user experience things such as when in check scanning for pieces that have legal moves and limiting selection of other pieces. Currently it will not allow the moves but someone who may not realize they are in check may get frustrated, alongside this I also want to highlight your king as an additional visual cue. Then I plan on reusing most of the framework to add checkmate and be able to tie a full game loop into the game. 
    One thing I would like to work on this week is not getting sidetracked with small changes. Over the course of this week I have thought of or noticed things and shifted to doing these tasks before even having a chance to put them on my project board. I would like to update the project board first and add a couple notes and focus on not getting distracted from what I am currently working on.












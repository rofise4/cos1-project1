> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:** 
→   Chess Wars
  
**What does your program currently do? (1–3 sentences)**   
→ Currently the program displays a 5x5 grid and chess pieces for both players, allows players to take turns selecting a piece, highlights legal moves and allows them to select a legal move. It also prevents most illegal moves and scans for check.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   turn switching, movements, mouse input for selection, highlighting pieces, check and legal move validation.
  
**What is NOT working or incomplete?**   
→   
  checkmate, piece drafting, ability cards, custom piece placement
**What feels confusing or messy in your code?**   
→ locations of ownership within my documents, like what belongs in gameLoop as appossed to gameLogic and constantly requires reference when I am trying to call funcitons.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   
  legalmoves
**What does this feature do?**   
→   scans all legal moves available for a player in question
  
**Why is this feature important?**   
→   
  it will give me information needed to determine if checkmate or stalemate conditions are true.
---
### Feature 2  
**Name:**   
→   Checkmate
  
**What does this feature do?**   
→   determines if no legal moves are available, if the king is under check and should result in checkmate
  
**Why is this feature important?**   
→   it will give the result as checkmate or stalemate and complete the base chessgame.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  Highlight king in check
**What does this feature do?**   
→   Highlights king currently under check.
  
**Why is this feature important?**   
→   
  Adds visual cue to the player to reduce frustration of trying to select moves that are not being allowed and let them know they are in check in case they have not realized.
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   NO
  
**Will you modify any existing classes? How?**   
→   
  I will add a checkmate function to game logic, and modify my turn loop to use move scanning differently.
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   
    I will be reusing existing [][] [] arrays
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   displays board with pieces
2. User chooses →   piece desired to move
3. Program responds →   legal moves
4. Loop/next step →   user chooses out of available moves
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   highlighting king and giving more visual cues while the game runs
  
- Better error handling:   
→   adding conditions to end game and not get stuck when no moves remain
  
- Improved menu/navigation:   
→   instructions for how the game works in the menu screen, with a tutorial for new players
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   
  Piece drafting system
**What is your plan if you get stuck?**   
→   
  Follow troubleshooting and track execution of program, or take a some time to clear my mind and get fresh eyes.
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Consistent documentation
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Adding to my changelog and readme as I make commits throughout the week.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Checkmate
- [ ]   Stalemate
- [ ]   Piece drafting
- [ ]   Custom piece placement
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.
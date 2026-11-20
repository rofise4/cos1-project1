Milestone 4: Final Development

Completed Features

For my final project, I made Chess Wars, a 5x5 variation of chess where players can purchase their own pieces and choose their starting positions. The idea was to take traditional chess and add some more strategy by allowing players to build their own armies before starting the game.

I finished the main gameplay features including movement, capturing, turn switching, and highlighting legal moves. I also got the drafting system working, which gives players a limited budget and different prices for each piece.

Refactoring and Code Improvements

This week I mostly focused on cleaning up what I already had instead of trying to add more features.

One of the bigger things I changed was the purchasing system. Originally I had written basically the same code twice for both players, which worked but was pretty unnecessary. I ended up moving it into its own function and using references with a ternary operator to handle the differences between players. It made the code a lot shorter and easier to work with.

Bugs Resolved

One problem I had was with the drafting input. If someone entered letters instead of a number, the program could get stuck in a loop. I changed how the input was handled so it could recognize invalid entries and ask the player to try again.

I also had an annoying issue where entering incorrect selections would cause the console to keep scrolling down and eventually start writing over the other text. I had to mess around with the positioning and how the messages were displayed, but I eventually got it working the way I wanted.

Usability Improvements

Most of the improvements I made were just to make the game easier to use and avoid problems with incorrect inputs.

The drafting system now tells players when they've entered something incorrectly or can't afford a piece. I also cleaned up how the information is displayed so the menu doesn't get cluttered when someone makes a mistake.

Final Testing

I went back through and tested all of the features before finishing the project. I checked the drafting system, piece placement, movement, capturing, turn switching, and check detection.

I also tried different invalid inputs and purchasing situations to see if I could get anything to break. After making the final changes, I tested everything again to make sure I hadn't accidentally messed up something that was already working.

Future Improvements

If I keep working on Chess Wars, I'd like to add the skill cards I originally had planned. I think having abilities like freezing an opponent's piece could make the game a lot more interesting.

I'd also like to expand the drafting system and eventually move away from the console into a proper graphical interface. There's definitely more I could do with it, but I think I've gotten it to a pretty good point for the time I had.

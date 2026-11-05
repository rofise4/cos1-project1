# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119-O ]

- **[ Corbin Marquez ]**
- **[ 11/01-2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [CLS ]: Clear the Screen
- [ CD/PWD]: Print the "Working Director
- [ dir]: List files and folders
- [ dir /a]: List files and folders, including invisible files
- [la -lah]: List all files and folders, in human readable form
- [cd]: Change directory
- [ cd /]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../.. ]: Change directory, go up two folder levels
- [cd~/Desktop]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ I attempted two different files in different folders and got an error cannot find path because *file name.path* does not exist.  ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local version control system is the first method, it involves saving all incremented control on a local system. The downside is it doesn't allow for easy collaboration and does not contain backups so a hard drive failure or other issues could cause significant data loss. The second is the Centralized version control system where each person commits to a server that stores the full copy of each rollout making it easier to collaborate and offers more security, but still has associated risks if the server runs into issues and say a team member no longer is employed and you do not have the copy they uploaded from. The third and safest method of version control is the Distributed version control system that involves saving each change to a server for storage while every team member also keeps a copy of the latest roll out on there local system. This offers the most protection and flexibility for working on the project. But has the trade off of requiring safety rails in place to make sure everyone is staying up to date when testing there code. ]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone www.exampleurl.com]: Clone a repository
- [ git config --global user.name "username"]: Set-up a global user name
- [ git config --global user.email "email"]: Set-up a global email address (to match my GitHub account email)
- [ git status]: Shows the current state of your directory and staging area
- [ git add -u]: Add modified files to the next commit
- [ git commit -m "message"]: Make a commit with a new message
- [ git log]: Show my commit history
- [ git help]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ git remote add origin <repository-URL> to set the connection. Then use git remote -v to verify a successful connection.]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [It is used to filter out unwanted files, reduce bloat and  protect sensitive information that is not necessary to the project]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [.DS Store is a file that contains display preferences for icons, layouts, etc. And we want to ignore it because it does not have a purpose to the project file and creates unessasary bloat and clutter for clean orginization.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [.exe, when compiling they are created automatically and not needed in the project.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

I used google because its auto generated response contained all the information needed for these questions. I find its most convenient for looking up syntax in a hurry especially simple things that I can test in my terminal. For more in depth things such as the three types of distribution I used the provided material in the course module for this week.

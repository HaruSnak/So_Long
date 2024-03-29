# **So_Long**

<img src="https://velog.velcdn.com/images/tamagoyakii/post/320771ca-6476-4d97-b05c-13653557ddfb/image.png" align="right"
     alt="libft" width="200" height="200">

The **So_Long** project is an introduction to *2D game development* for students at **42**. Using the **Minilibx library**, you will create a 2D game that includes:<br>

*4-way character movement (W, S, A, D)*<br>
*A move counter*<br>
*A map that must be a rectangle with a valid path*<br>
*A variety of restrictions/conditions to complete the project*<br>

**Here are some additional details about the project:**

*The game must be developed using the C programming language.*<br>
*The game must use the Minilibx library for graphics and input handling.*<br>
*The game must have a start and end point.*<br>
*The player must be able to move around the map.*<br>
*The player must be able to collect objects on the map.*<br>
*The player must avoid obstacles on the map.*<br>
*The game must have a win condition and a lose condition.*<br>

### **My approach:**

From the start, I wanted to move away from the original project and explore a different path. My ambition was to create a top-down hack'n slash game that promised a fluid and enjoyable gameplay loop for the user. However, the time constraints forced me to favor a more familiar approach, while still keeping the two key points mentioned above.<br>

This is how this *"remastered Mario"* was born, taking up the iconic gameplay loop of this legendary game. You start on one of the game's maps, with the mission of collecting as many coins as possible. But be careful, you may not be alone on this treasure-filled path!<br>

![player](readme/player.gif)

I opted for a **2D oblique view**, *offering a dynamic and immersive perspective*. The graphic elements were recovered from the **Kenney website (free assets)** and then reworked in *Photoshop* to integrate perfectly with **the Minilibx environment**.<br>

In order to enrich the gameplay and bring an additional challenge, I introduced high structures and enemies. The player will thus be able to jump to overcome obstacles or dodge hostile monsters.<br>

![monster](readme/monster.gif)

*(The UI outlines (heart, coins, and step counter) are in black because my WSL has transparency issues with Minilibx, which will work correctly once on MacOS. I'm sorry again for this inconvenience, which bothers me slightly.)*<br>

![game](readme/game.png)

### **Features**

**Breadth-First Search (BFS) algorithm:** *Used to determine if an exit is possible from the player's position on the map.*<br>

**Jumping ability:** *The player can now jump and descend more quickly by pressing the down arrow while in the air.*<br>

**Various animations:** *Added animations for monsters, coins, and the player.*<br>

**Player HUD:** *Displays information such as health, coins collected, and move count.*<br>

**Basic AI for monsters:** *Monsters follow a simple path and have a hitbox that can damage the player.*<br>

### **Features to be added:**

**Player-centered camera:** *To create a sense of progression in the game.*<br>

**Improved hitboxes and asset clipping:** *To prevent collision issues and improve the overall look of the game.*<br>

**Win and lose screens:** *To indicate the end of the game and provide feedback to the player.*<br>

**Scaling assets to 100x100:** *To reduce the player's X-axis and provide a better sense of movement.*<br>

## How To Use

### **Compilation**

```bash
# Clone this repository
$ git clone https://github.com/HaruSnak/So_Long.git

# Go into the repository
$ cd So_Long

# To compile the program
$ make

# Allows you to do a complete cleaning of your construction environment
$ make fclean
```

## Notes

### SOON

## Credits

Below you will find the links used for this project:

- [Norm 42](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)
- [Docs Libs Minilibx | Harm-Smits](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#installation)
- [Docs Libs Minilibx | Reactive](https://reactive.so/post/42-a-comprehensive-guide-to-so_long)
- [Events ARGS | Minilibx](https://tronche.com/gui/x/xlib/events/types.html)
- [Convertio | Format XPML](https://convertio.co/fr/png-xpm/)
- [AnyConv | Format XPM](https://anyconv.com/fr/convertisseur-de-png-en-xpm/)
- [Assets free | Kenney](https://kenney.nl/assets/pixel-platformer)



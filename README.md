##Summary
This application will allow you to hold down the Caps Lock key and mirror the right side of your keyboard to your left, allowing for you to type one handed.

![oht keyboard layout](https://cloud.githubusercontent.com/assets/10111341/19418832/52328d00-939a-11e6-969e-542ee74ee85a.jpg)


##How to setup and run?

1. Download [Karabiner Elements Github](https://github.com/tekezo/Karabiner-Elements) ([dmg](https://pqrs.org/latest/karabiner-elements-latest.dmg)).

      This application will allow you to do simple key modifications. In my example, I modified the Caps Lock key to the F19 key.

2. Disable the Caps Lock key.

      Go to System Preferences -> Keyboard -> Modifier Keys... (Keyboard Tab). Change the Caps Lock Key drop down menu to No Action.

3. Follow the directions [here](https://github.com/tekezo/Karabiner-Elements/blob/master/usage/README.md#how-to-configure-karabiner-elements) to create a configuration file - use my configuration file to swap the Caps Lock key with the F19 key (Version 0.90.46 of Karabiner).

      You can customize the key you map to, but you will need to edit the oht.c file to reflect the changes.

4. Compile the oht.c file.

      `gcc -Wall -o oht oht.c -framework ApplicationServices`

5. Run the out file with root privileges.

      `sudo ./oht`

6. TIP: Terminal associates the F19 key (the new key Caps Lock is mapped to in my implementation) to the ~ character. To fix this go to Terminal -> Preferences... -> Keyboard Tab (Profiles Header Tab) -> Select the F19 Key binding and set the action to nothing (clear the text box under action)

##Compatibility
macOS Sierra (10.12)

Karabiner Elements (0.90.46)


##Sources
The source code used as the base for this application can be found [here](http://osxbook.com/book/bonus/chapter2/alterkeys).


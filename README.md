##Summary
This application will allow you to hold down the Caps Lock and mirror the right side of you keyboard to your left.


##How to setup and run?

1. Download [Karabiner Elements](https://github.com/tekezo/Karabiner-Elements)

...This application will allow you to do simple key modifications. In my example I modified the Caps Lock key to the F19 key.

2. Create the configuration file at ~/.karabiner.d/configuration/karabiner.json (Version 0.90.46)

...You are more than welcome to use my configuration file.

3. Compile the oht.c file

...gcc -Wall -o oht oht.c -framework ApplicationServices


##Compatibility
OSX Sierra (10.12)
Karabiner Elements (0.90.46)


##Sources
The source code used as the base for this application can be found [here](http://osxbook.com/book/bonus/chapter2/alterkeys).


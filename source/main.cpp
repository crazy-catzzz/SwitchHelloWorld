#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>

int main(int argc, char* argv[]) {
    consoleInit(NULL); //Initialize console

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

    // Other initialization goes here. As a demonstration, we print hello world.
    printf("Hello World!\n");

    // Main loop
    while (appletMainLoop()) {
        padUpdate(&pad); //Scan the gamepad. This should be done once for each frame

        u64 kDown = padGetButtonsDown(&pad); //Get button inputs by comparing which buttons were pressed in the current and previous frames

        if(kDown & HidNpadButton_Plus)
            break; //break in order to return to hbmenu
        
        if(kDown & HidNpadButton_A)
            printf("You pressed A!\n");
        if(kDown & HidNpadButton_B)
            printf("You pressed B!\n");


        consoleUpdate(NULL); //Update the console, sending a new frame to the screen
    }

    
    consoleExit(NULL); //Deinitialize and clean up resources used by the console (important!)
    return 0;
}
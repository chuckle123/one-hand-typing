/**
 * Complile using the following command line:
 * gcc -Wall -o oht oht.c -framework ApplicationServices
 *
 * The source code used as the base for this application can be found at
 * http://osxbook.com/book/bonus/chapter2/alterkeys/
 */

#include "oht.h"

int main(void) {
  CFMachPortRef eventTap;
  CGEventMask eventMask;
  CFRunLoopSourceRef runLoopSource;

  // Create an event tap. We are interested in key presses.
  eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventKeyUp));
  eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, myCGEventCallback, NULL);
  if (!eventTap) {
    fprintf(stderr, "failed to create event tap\n");
    exit(1);
  }

  // Create a run loop source.
  runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);

  // Add to the current run loop.
  CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);

  // Enable the event tap.
  CGEventTapEnable(eventTap, true);

  // Set it all running.
  CFRunLoopRun();

  exit(0);
}

CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
  // The incoming keycode.
  CGKeyCode keycode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

  // Caps lock is mapped to f19 which has the key code 80
  if (keycode == 80) isCapsPressed = (type == kCGEventKeyDown);

  if (isCapsPressed) {
    keycode = swapKeys(keycode);
  }

  // Set the modified keycode field in the event.
  CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) keycode);

  return event;
}

// TODO: record which keys I use most and place them towards the top of the if else chain
CGKeyCode swapKeys(CGKeyCode keycode) {
  if (isCapsPressed) {
    // asdfg row
    if      (keycode == _A) keycode =  _COLON;
    else if (keycode == _S) keycode =  _L;
    else if (keycode == _D) keycode =  _K;
    else if (keycode == _F) keycode = _J;
    else if (keycode == _G) keycode = _H;
    // qwerty row
    else if (keycode == _Q) keycode = _P;
    else if (keycode == _W) keycode = _O;
    else if (keycode == _E) keycode = _I;
    else if (keycode == _R) keycode = _U;
    else if (keycode == _T) keycode = _Y;
    // zxcvb row
    else if (keycode == _Z) keycode = _PERIOD;
    else if (keycode == _X) keycode = _COMMA;
    else if (keycode == _C) keycode = _M;
    else if (keycode == _V) keycode = _N;
    // 12345 row
    else if (keycode == _1) keycode = _0;
    else if (keycode == _2) keycode = _9;
    else if (keycode == _3) keycode = _8;
    else if (keycode == _4) keycode = _7;
    else if (keycode == _5) keycode = _6;
    // Special keys
    else if (keycode == _SPACE) keycode = _RETURN;
    else if (keycode == _TAB) keycode = _SINGLE_QUOTE;
    else if (keycode == _GRAVE_ACCENT)  keycode = _DELETE;
  }

  return keycode;
}


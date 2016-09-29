// Complile using the following command line:
//    gcc -Wall -o oht oht.c -framework ApplicationServices

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

  // Caps lock is mapped to f19 which has the key code 50
  if (type == kCGEventKeyUp && keycode == (CGKeyCode) 0x50) {
    isCapsPressed = false;
  } else if (type == kCGEventKeyDown && keycode == (CGKeyCode) 0x50) {
    isCapsPressed = true;
  }

  if (isCapsPressed) {
    // asdfg row
    // a -> ;
    if (keycode == (CGKeyCode) _a) {
      keycode = (CGKeyCode) _COLON;
    }
    // s -> l
    else if (keycode == (CGKeyCode) _s) {
      keycode = (CGKeyCode) _l;
    }
    // d -> k
    else if (keycode == (CGKeyCode) _d) {
      keycode = (CGKeyCode) _k;
    }
    // f -> j
    else if (keycode == (CGKeyCode) _f) {
      keycode = (CGKeyCode) _j;
    }
    // g -> h
    else if (keycode == (CGKeyCode) _g) {
      keycode = (CGKeyCode) _h;
    }

    // qwerty row
    // q -> p
    if (keycode == (CGKeyCode) _q) {
      keycode = (CGKeyCode) _p;
    }
    // w -> o
    else if (keycode == (CGKeyCode) _w) {
      keycode = (CGKeyCode) _o;
    }
    // e -> i
    else if (keycode == (CGKeyCode) _e) {
      keycode = (CGKeyCode) _i;
    }
    // r -> u
    else if (keycode == (CGKeyCode) _r) {
      keycode = (CGKeyCode) _u;
    }
    // t -> y
    else if (keycode == (CGKeyCode) _t) {
      keycode = (CGKeyCode) _y;
    }

    // zxcvb row
    // z -> .
    if (keycode == (CGKeyCode) _z) {
      keycode = (CGKeyCode) _PERIOD;
    }
    // x -> ,
    else if (keycode == (CGKeyCode) _x) {
      keycode = (CGKeyCode) _COMMA;
    }
    // c -> m
    else if (keycode == (CGKeyCode) _c) {
      keycode = (CGKeyCode) _m;
    }
    // v -> n
    else if (keycode == (CGKeyCode) _v) {
      keycode = (CGKeyCode) _n;
    }

    // 12345 row
    // 1 -> 0
    if (keycode == (CGKeyCode) _1) {
      keycode = (CGKeyCode) _0;
    }
    // 2 -> 9
    else if (keycode == (CGKeyCode) _2) {
      keycode = (CGKeyCode) _9;
    }
    // 3 -> 8
    else if (keycode == (CGKeyCode) _3) {
      keycode = (CGKeyCode) _8;
    }
    // 4 -> 7
    else if (keycode == (CGKeyCode) _4) {
      keycode = (CGKeyCode) _7;
    }
    // 5 -> 6
    else if (keycode == (CGKeyCode) _5) {
      keycode = (CGKeyCode) _6;
    }

    // Special keys
    // ` -> DELETE
    else if (keycode == (CGKeyCode) _GRAVE_ACCENT) {
      keycode = (CGKeyCode) _DELETE;
    }
    // SPACE -> RETURN
    else if (keycode == (CGKeyCode) _SPACE) {
      keycode = (CGKeyCode) _RETURN;
    }
    // TAB -> '
    else if (keycode == (CGKeyCode) _TAB) {
      keycode = (CGKeyCode) _SINGLE_QUOTE;
    }
  }

  // Set the modified keycode field in the event.
  CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) keycode);

  return event;
}


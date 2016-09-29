#ifndef OHT_H_
#define OHT_H_

#include <ApplicationServices/ApplicationServices.h>

static const CGKeyCode _A             = (CGKeyCode) 0;
static const CGKeyCode _S             = (CGKeyCode) 1;
static const CGKeyCode _D             = (CGKeyCode) 2;
static const CGKeyCode _F             = (CGKeyCode) 3;
static const CGKeyCode _H             = (CGKeyCode) 4;
static const CGKeyCode _G             = (CGKeyCode) 5;
static const CGKeyCode _Z             = (CGKeyCode) 6;
static const CGKeyCode _X             = (CGKeyCode) 7;
static const CGKeyCode _C             = (CGKeyCode) 8;
static const CGKeyCode _V             = (CGKeyCode) 9;
static const CGKeyCode _B             = (CGKeyCode) 11;
static const CGKeyCode _Q             = (CGKeyCode) 12;
static const CGKeyCode _W             = (CGKeyCode) 13;
static const CGKeyCode _E             = (CGKeyCode) 14;
static const CGKeyCode _R             = (CGKeyCode) 15;
static const CGKeyCode _Y             = (CGKeyCode) 16;
static const CGKeyCode _T             = (CGKeyCode) 17;
static const CGKeyCode _1             = (CGKeyCode) 18;
static const CGKeyCode _2             = (CGKeyCode) 19;
static const CGKeyCode _3             = (CGKeyCode) 20;
static const CGKeyCode _4             = (CGKeyCode) 21;
static const CGKeyCode _6             = (CGKeyCode) 22;
static const CGKeyCode _5             = (CGKeyCode) 23;
static const CGKeyCode _EQUAL         = (CGKeyCode) 24;
static const CGKeyCode _9             = (CGKeyCode) 25;
static const CGKeyCode _7             = (CGKeyCode) 26;
static const CGKeyCode _DASH          = (CGKeyCode) 27;
static const CGKeyCode _8             = (CGKeyCode) 28;
static const CGKeyCode _0             = (CGKeyCode) 29;
static const CGKeyCode _RIGHT_BRACKET = (CGKeyCode) 30;
static const CGKeyCode _O             = (CGKeyCode) 31;
static const CGKeyCode _U             = (CGKeyCode) 32;
static const CGKeyCode _LEFT_BRACKET  = (CGKeyCode) 33;
static const CGKeyCode _I             = (CGKeyCode) 34;
static const CGKeyCode _P             = (CGKeyCode) 35;
static const CGKeyCode _RETURN        = (CGKeyCode) 36;
static const CGKeyCode _L             = (CGKeyCode) 37;
static const CGKeyCode _J             = (CGKeyCode) 38;
static const CGKeyCode _SINGLE_QUOTE  = (CGKeyCode) 39;
static const CGKeyCode _K             = (CGKeyCode) 40;
static const CGKeyCode _COLON         = (CGKeyCode) 41;
static const CGKeyCode _BACK_SLASH    = (CGKeyCode) 42;
static const CGKeyCode _COMMA         = (CGKeyCode) 43;
static const CGKeyCode _FORWARD_SLASH = (CGKeyCode) 44;
static const CGKeyCode _N             = (CGKeyCode) 45;
static const CGKeyCode _M             = (CGKeyCode) 46;
static const CGKeyCode _PERIOD        = (CGKeyCode) 47;
static const CGKeyCode _TAB           = (CGKeyCode) 48;
static const CGKeyCode _SPACE         = (CGKeyCode) 49;
static const CGKeyCode _GRAVE_ACCENT  = (CGKeyCode) 50;
static const CGKeyCode _DELETE        = (CGKeyCode) 51;
static const CGKeyCode _ENTER         = (CGKeyCode) 52;
static const CGKeyCode _ESCAPE        = (CGKeyCode) 53;
bool isCapsPressed = false;

int main(void);
CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon);
CGKeyCode swapKeys(CGKeyCode keycode);

#endif


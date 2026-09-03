#include "TouchControllerWS.h"

TouchControllerWS::TouchControllerWS(XPT2046_Touchscreen *touchScreen) {
  this->touchScreen = touchScreen;
}

bool TouchControllerWS::isTouched() {
  touchScreen->touched();
}

bool TouchControllerWS::isTouched(int16_t debounceMillis) {
  if (touchScreen->touched() && millis() - lastTouched > debounceMillis) {
    lastTouched = millis();
    return true;
  }
  return false;
}
TS_Point TouchControllerWS::getPoint() {
    TS_Point p = touchScreen->getPoint();
    /*
    int x = (p.y - ax) * dx;
    int y = 320 - (p.x - ay) * dy;
    p.x = x;
    p.y = y;*/
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
    p.y = map(p.y, TS_MINY, TS_MAXY, 240, 0);

    return p;
}

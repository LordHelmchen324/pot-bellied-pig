#include "gameobject.h"

GameObject nullObject() {
    GameObject o;
    o.type = NULL; o.self = NULL; o.update = NULL; o.draw = NULL;
    return o;
}
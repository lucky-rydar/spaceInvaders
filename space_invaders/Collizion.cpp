#include "Collizion.h"

bool Collizion::isCollizion(GameObject obj1, GameObject obj2)
{
    if (int(obj1.position[0]) == int(obj2.position[0]) && int(obj1.position[1]) == int(obj2.position[1]))
        return true;
    else
        return false;
    
}

#pragma once

#include "../../common/Vec2.h"
#include "../core/Layer.h"

namespace Engine {

class Camera {
public:
  static void Move(Layer& reference, const Common::Vec2& position, const Common::Vec2& offset = { 0, 0 });
  static void Zoom(Layer& reference, int value);
};

}

#include "glm/glm.hpp"
#include "slt/core/core.h"
#include "slt/render/render.h"
#include "slt/runtime/runtime.h"

// This needs to match the uniform block defined in the shader.
struct ObjectData {
  glm::vec4 object_color;
};

slt::render::ProgramRef prog;

void initRender() {
  slt::render::loadProgram("object",
                           [](slt::render::ProgramRef r) { prog = r; });
}

void render() {}

int main(int argc, const char *argv[]) {
  // Create a slt core, common to all slt apps.
  slt::Core core{argc, argv};

  // We'll be using a runtime.
  // This will create the main view, load the base assets and wait until the
  // minimum set of assets has finished loading.
  slt::Runtime runtime{slt::render::RenderTargetConfig{1280, 720}, "SampleApp"};

  initRender();
  // This is not exactly great...
  //  runtime.render.waitForAllPendingResources();

  while (runtime.keepRunning()) {
    core.update();
    runtime.update();

    render();
  }

  return 0;
}
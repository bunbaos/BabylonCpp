#include <babylon/cameras/arc_rotate_camera.h>
#include <babylon/engines/scene.h>
#include <babylon/interfaces/irenderable_scene.h>
#include <babylon/lights/directional_light.h>
#include <babylon/materials/standard_material.h>
#include <babylon/meshes/instanced_mesh.h>
#include <babylon/meshes/mesh.h>
#include <babylon/samples/babylon_register_sample.h>

namespace BABYLON {
namespace Samples {

/**
 * @brief Many box Instances Scene. Example demonstrating how to create instances.
 */
struct ManyBoxInstancesScene : public IRenderableScene {

  ManyBoxInstancesScene(ICanvas* iCanvas) : IRenderableScene(iCanvas)
  {
  }

  ~ManyBoxInstancesScene() override = default;

  const char* getName() override
  {
    return "Many Box Instances Scene";
  }

  void initializeScene(ICanvas* canvas, Scene* scene) override
  {
    float gridSize = 10;

    auto camera = ArcRotateCamera::New("camera", 0.f, 0.f, gridSize * 1.5f, Vector3::Zero(), scene);
    camera->fov = 60.f / 180.f * Math::PI;
    camera->minZ = 0.01f;
    camera->maxZ = 1e10f;
    camera->setPosition(Vector3(0.f, 0.f, -gridSize * 1.7f));
    camera->attachControl(canvas, true);

    auto light1       = DirectionalLight::New("light1", Vector3(1, 2, 3), scene);
    light1->intensity = 0.8f;

    scene->ambientColor = Color3(0.25f, 0.25f, 0.25f);

    auto material           = StandardMaterial::New("mat", scene);
    material->diffuseColor  = Color3(0.9f, 0.9f, 0.9f);
    material->specularColor = Color3(0.f, 0.f, 0.f);
    material->ambientColor  = Color3(1.f, 1.f, 1.f);
    material->freeze();

    auto boxMesh = Mesh::CreateBox("root", 0.8f, scene);
    boxMesh->setEnabled(false);

    boxMesh->material = material;

    for (size_t x = 0; x < gridSize; ++x) {
      auto xStr = std::to_string(x);
      for (size_t y = 0; y < gridSize; ++y) {
        auto yStr = std::to_string(y);
        for (size_t z = 0; z < gridSize; ++z) {
          auto zStr     = std::to_string(z);
          auto boxMesh2 = boxMesh->createInstance("box_" + xStr + "_" + yStr + "_" + zStr);
          boxMesh2->position
            = Vector3(-gridSize / 2.f + x, -gridSize / 2.f + y, -gridSize / 2.f + z);
          boxMesh2->freezeWorldMatrix();
        }
      }
    }
  }

}; // end of struct ManyBoxInstancesScene

BABYLON_REGISTER_SAMPLE("Optimizations", ManyBoxInstancesScene)

} // end of namespace Samples
} // end of namespace BABYLON

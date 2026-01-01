#include "entity.h"
#include "application.h"
#include "scene.h"

namespace InterstellarX {
    Entity *Instantiate(Mesh *primitive)
    {
        // Primitive
        Entity *e = new Entity();
        e->mesh = primitive;
        Application::scene->add(e);

        return e;
    }

    Entity *Instantiate(Entity *prefab, Transform &transform)
    {
        // Prefabs
        Entity *e = new Entity();
        e->transform = Transform(transform.position, transform.rotation, transform.scale);
        e->mesh = prefab->mesh;
        Application::scene->add(e);

        return e;
    }

    Entity *Instantiate()
    {
        // Empty Gameobject
        Entity *e = new Entity();
        Application::scene->add(e);

        return e;
    }
}
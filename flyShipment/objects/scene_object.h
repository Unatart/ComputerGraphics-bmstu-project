#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

class scene_object {
    public:
        explicit scene_object() = default;
        scene_object(scene_object&) = delete;
        scene_object(const scene_object&) = delete;
        virtual ~scene_object() = default;

        virtual bool visible() = 0;
};

#endif // SCENE_OBJECT_H

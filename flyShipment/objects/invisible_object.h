#ifndef INVISIBLE_OBJECT_H
#define INVISIBLE_OBJECT_H

#include "scene_object.h"

class invisible_object : public scene_object {
    public:
        explicit invisible_object() = default;
        invisible_object(invisible_object&) = delete;
        invisible_object(const invisible_object&) = delete;
        virtual ~invisible_object() = default;

        bool visible() override {
            return false;
        }
};

#endif // INVISIBLE_OBJECT_H

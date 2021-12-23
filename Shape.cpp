#include "Shape.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Shape::Cuboid(float x, float y, float size, float width = 0, bool fill) {
    return Get().ICuboid(x, y, size, width, fill);
}

void Shape::ICuboid(float x, float y, float size, float width = 0, bool fill) {
    GLfloat halfSideLength = size * 0.5f;

    GLfloat vertices[] =
    {
        // front face 

        x - width, y + halfSideLength, -500 + halfSideLength, // top left
        x + width, y + halfSideLength, -500 + halfSideLength, // top right
        x + width, y - halfSideLength, -500 + halfSideLength, // bottom right
        x - width, y - halfSideLength, -500 + halfSideLength, // bottom left

        // back face
        x - width, y + halfSideLength, -500 - halfSideLength, // top left
        x + width, y + halfSideLength, -500 - halfSideLength, // top right
        x + width, y - halfSideLength, -500 - halfSideLength, // bottom right
        x - width, y - halfSideLength, -500 - halfSideLength, // bottom left

        // left face
        x - width, y + halfSideLength, -500 + halfSideLength, // top left
        x - width, y + halfSideLength, -500 - halfSideLength, // top right
        x - width, y - halfSideLength, -500 - halfSideLength, // bottom right
        x - width, y - halfSideLength, -500 + halfSideLength, // bottom left

        // right face
        x + width, y + halfSideLength, -500 + halfSideLength, // top left
        x + width, y + halfSideLength, -500 - halfSideLength, // top right
        x + width, y - halfSideLength, -500 - halfSideLength, // bottom right
        x + width, y - halfSideLength, -500 + halfSideLength, // bottom left

        // top face
        x - width, y + halfSideLength, -500 + halfSideLength, // top left
        x - width, y + halfSideLength, -500 - halfSideLength, // top right
        x + width, y + halfSideLength, -500 - halfSideLength, // bottom right
        x + width, y + halfSideLength, -500 + halfSideLength, // bottom left

        // top face
        x - width, y - halfSideLength, -500 + halfSideLength, // top left
        x - width, y - halfSideLength, -500 - halfSideLength, // top right
        x + width, y - halfSideLength, -500 - halfSideLength, // bottom right
        x + width, y - halfSideLength, -500 + halfSideLength  // bottom left
    };
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if (fill) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    glEnableClientState(GL_VERTEX_ARRAY); 
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    if (fill) {
        GLfloat color[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; 
        glColorPointer(3, GL_FLOAT, 0, color);
    }
    else {
        GLfloat color[] = { 255, 0, 0, 255, 0, 0, 255, 0, 0 }; 
        glColorPointer(3, GL_FLOAT, 0, color );
    }
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
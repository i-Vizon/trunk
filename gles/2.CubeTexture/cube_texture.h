#include <iostream>
#include <GLESWrapper.h>
#include <MatrixOperations.h>

/***
 *  Let us break our head by doing rotating a cube.
 */

/*********************************
 *  To render a Rotationg Cube,
 *  we need
 *  1. Model View Projection Matrix mvp
 *  2. Cube Vertices
 *  3. Cube Indices
 *
 **/

class CubeTexture : public iv::GLESWrapper
{
    // GLESWrapper interface
public:
    CubeTexture()
    {
        _rotatingAngle = 60.0f;
    }

    GLint initGLES();
    GLint updateMVP();
    void drawFrames();
protected:

private:
    GLuint      _programObject;
    GLuint      _locPosition;
    GLuint      _locMVPMatrix;
    GLfloat     _rotatingAngle;
    iv::Matrix  _mvpMatrix;
    GLfloat*    _vertices;
    GLuint*    _indices;
};


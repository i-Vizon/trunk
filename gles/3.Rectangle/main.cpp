#include <GLESWrapper.h>

//We will try to learn the 3D Maths of Projection and Tranformation
class Rectangle : public GLESWrapper
{
    // GLESWrapper interface
public:
    GLint initGLES();
    void drawFrames();
protected:

private:
    GLuint _locAPosition;

};

GLint Rectangle::initGLES()
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_BITS);
}

void Rectangle::drawFrames()
{

}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


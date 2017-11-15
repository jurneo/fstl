#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>

class GLMesh;
class Mesh;
class Backdrop;

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Canvas(QWidget* parent=0);

    void initializeGL();
    void paintEvent(QPaintEvent* event);
    ~Canvas();

    void view_orthographic();
    void view_perspective();

public slots:
    void set_status(const QString& s);
    void clear_status();
    void load_mesh(Mesh* m, bool is_reload);


protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void resizeGL(int width, int height);
    void set_perspective(float p);
    void view_anim(float v);


private:
    void draw_mesh();

    QMatrix4x4 transform_matrix() const;
    QMatrix4x4 view_matrix() const;

    QOpenGLShaderProgram mesh_shader;
    QOpenGLShaderProgram quad_shader;

    GLMesh* mesh;
    Backdrop* backdrop;

    QVector3D center;
    float scale;
    float zoom;
    float tilt;
    float yaw;

    float perspective;
    Q_PROPERTY(float perspective WRITE set_perspective)
    QPropertyAnimation anim;

    QPoint mouse_pos;
    QString status;
};

#endif // CANVAS_H

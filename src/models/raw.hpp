#ifndef _MODEL_RAW_HPP_
#define _MODEL_RAW_HPP_

#include "model.hpp"
#include "../meshes/mesh.hpp"
#include "../executable.hpp"

namespace Models
{
  struct Raw:
    Model,
    protected Mesh
  {
    RESOURCE(Raw)

  public:
    void draw(const Scene &scene, const glm::mat4 &mvp, const glm::mat4 &transformation) const;

  private:
    GLuint positions_id;
    GLuint normals_id;

    GLuint id;

    const Executable *exe;

    enum Attrib : GLuint
    {
      position,
      normal,

      __attrib_count
    };

    enum Uniform : unsigned
    {
      mvp,
      local_modelview,

      __uniform_count
    };

    static const GLchar *const attribs[];
    static const GLchar *const uniforms[];
  };
};

#endif // _MODEL_RAW_HPP_

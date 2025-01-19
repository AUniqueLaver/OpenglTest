*GLSL is shading language to write shader programs that implement special effects.
*The model matrix represents a transofrmation from object space to world space, and the view matrix is a transformation from
world space to camera space. So the matrix that transforms from object to camera space, we want the model matrix to apply first. Therefore
the model matrix is multiplied on the right-hand side of the view matrix.

We can laod our shader in one of three ways:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1) Compile and load our shader normally
2) Load a binary pre-compiled shader program   (file: "shader/program.bin")
3) Load a SPIR-V shade program  (file: "shader/vert.spv" and "shader/frag.spv")


layout (location=0) in vec3 vertexPosition;
layout (location=1) in vec3 vertexColor;

layout (location=0) out vec3 Color;

Note: When glsl says "version not found", it means it can't find video subsystem and
telling us the first line of the file. Not an actual error message indicating not finding
he version.

SPIR-V stands for Standard, Portable, Intermediate Representation - V. It is a intermediate language
designed for shaders. It is intended to be a compiler target for a number of different languages.

The indexees within the vertex buffer binding point need not be the same as the attribute locations ( Opengl 4.3 )

A diffuse reflection is a simple reflection model that makes the assumption that the surface
exhibits purely diffuse reflection. That is to say the surface scatters light in all
direction equally, regardless of direction.

The diffuse reflection involves two vectors: The direction of the surface point to the
light source(s), and the normal vector at the surface point(n).

The amount of radiance per unit area that strikes a surface is dependent
on the orientation of the surface with respect to the light source.
The physics situation tells us that the amount of radiation per unit area
is maximal when the light arrives along the direction of the normal vector.
In between, it is porportional to the cosine of the angle between the
direction towards the light source and the normal vector. So, since
the dot product is porportional to the consine of the angle between two
vectors, we can express the amount of radiation striking the surface as the
product of the light intensity and the dot product
of s and n:

      Ld(s . n)

    Ld is the intensity of the light source, and the vectors are assumed to be normalized.

    The dot product of the two vectors is equal to the cosine of the angle between them.

Some of the incoming light is absorbed before being reemitted. We can model
this interaction by using a reflection coefficient (Kd), which represents the fraction
of the incoming light that is scattered. This is sometimes called diffuse reflectivity,
or the diffucse reflection coefficient. The diffuse reflectivity becomes a scaling factor,
so the intensity of the outgoing light can be expressed as follows.

   L = KdLd(s . n)

Light intensities and material reflectivity coefficients are represented by three-component(RGB)
vectors. Therefore, the equations should be treated as component wise operations, applied
to each of the three components seperately.

          //   std::map<std::string, std::string> AvailScenes = 
          // {
          //     {"Scene1", "Basic scene -triangle"},
          //     {"Torus", "Scene: Torus"},
          //     {"Triangle", "Scene: Triangle"},
          //     {"Transforms", "Scene: Triangle"}
          // };
          //
          //  std::string renderScene = Runner::parseCLArgs(AvailScenes, "Transforms");
          //  // std::string renderScene = Runner::parseCLArgs(AvailScenes);
          //
          // std::unique_ptr<IScene> scene;
          //   Runner runner(renderScene);
          //     if(renderScene == "Scene1") 
          //       scene = std::make_unique<Scene>();
          //     else if(renderScene == "Torus") 
          //       scene = std::make_unique<TorusScene>();
          //     else if(renderScene == "Triangle") 
          //       scene = std::make_unique<SceneTriangle>();
          //     else if(renderScene == "Transforms") 
          //       scene = std::make_unique<SceneTransforms>();
          //
          //      runner.run(std::move(scene));  

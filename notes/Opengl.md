*GLSL is shading language to write shader programs that implement special effects.
*The model matrix represents a transofrmation from object space to world space, and the view matrix is a transformation from
world space to camera space. So the matrix that transforms from object to camera space, we want the model matrix to apply first. Therefore
the model matrix is multiplied on the right-hand side of the view matrix.

*We can laod our shader in one of three ways:
1) Compile and load our shader normally
2) Load a binary pre-compiled shader program   (file: "shader/program.bin")
3) Load a SPIR-V shade program  (file: "shader/vert.spv" and "shader/frag.spv")


layout (location=0) in vec3 vertexPosition;
layout (location=1) in vec3 vertexColor;

layout (location=0) out vec3 Color;

Note: When glsl says "version not found", it means it can't find video subsystem and
telling us the first line of the file. Not an actual error message indicating not finding
the version.

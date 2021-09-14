#version 410 core

layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec3 v_color;
layout (location = 2) in vec2 v_uv;
layout (location = 3) in vec3 v_normal;

uniform float time;
uniform mat4  projection;
uniform mat4  view;
uniform mat4  model;

out vec3    vertex_color;
out vec2    UV;

void        main()
{
    gl_Position = projection * view * model * vec4(v_pos, 1.0);
  //  vertex_color = v_normal;//vec3(abs(v_normal.x), abs(v_normal.y), abs(v_normal.z)) ;
   // vertex_color = v_pos;//vec3(abs(v_pos.x), abs(v_pos.y), abs(v_pos.z)) ;
    vertex_color = v_color;
    //vertex_color = v_pos + vec3(sin(time) * v_color.x, cos(time) * v_color.y, v_color.z);
    UV = v_uv;
}
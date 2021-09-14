#version 410 core
out vec4    frag_color;

in  vec3    vertex_color;
in  vec2     UV;

uniform float c_time;
uniform sampler2D CC_Texture0;


void    main()
{
  vec4 c1 = vec4(vertex_color, 1.0);
  vec4 c2 = texture(CC_Texture0, UV);
  
  frag_color = mix(c1, c2, c_time);

}
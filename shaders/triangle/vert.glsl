#version 460 core
layout(location = 0) in vec3 loc;
layout(location = 1) in vec3 color;
out vec4 colorOut;
void main(){
    gl_Position = vec4(loc.x, loc.y, loc.z, 1.0);
    colorOut = color.xyzx;
}
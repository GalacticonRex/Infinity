#version 150

uniform mat4 transform;
uniform mat4 viewport;

in vec3 position;
in vec2 texcoord;
in vec3 normal;

out vec2 v_texcoord;
out vec3 v_normal;

void main() {
	gl_Position = viewport * transform * vec4( position, 1 );
	v_texcoord = texcoord;
	v_normal = normal;
}
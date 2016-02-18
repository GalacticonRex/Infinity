#version 150

uniform mat4 transform;
uniform mat4 viewport;
uniform vec2 texture_shift = vec2(0,0);
uniform vec2 texture_scale = vec2(1,1);

in vec2 position;
in vec2 texcoord;

out vec2 Vtexcoord;

void main() {
	gl_Position = viewport * transform * vec4( position, 1,1 );
	Vtexcoord = ( texcoord * texture_scale ) + texture_shift;
}
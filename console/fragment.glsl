#version 150

uniform sampler2D teximage1;
uniform vec4 color = vec4(1,1,1,1);

in vec2 v_texcoord;
in vec3 v_normal;

out vec4 fragout;

void main() {
	fragout = color * texture2D( teximage1, v_texcoord );
}
#version 150

uniform float use = 0;
uniform float miximg = 0;
uniform sampler2D teximage1;
uniform sampler2D teximage2;
uniform sampler2D teximage3;
uniform vec4 color = vec4(1,1,1,1);

in vec2 Vtexcoord;
out vec4 fragout;
void main() {
	vec4 c1 = texture2D( teximage1, Vtexcoord );
	vec4 c2 = texture2D( teximage2, Vtexcoord );
	vec4 c3 = texture2D( teximage3, Vtexcoord );
	vec4 imgc = c1.r*( (miximg)*c2 + (1-miximg)*c3 ) +
				(1-c1.r)*( (miximg)*c3 + (1-miximg)*c2 );
	fragout = color * ( use * imgc + (1-use) * vec4(1,1,1,1) );
}
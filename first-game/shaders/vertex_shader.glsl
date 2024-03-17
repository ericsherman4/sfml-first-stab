#version 460
// use https://www.realtech-vr.com/home/?page_id=1402 to get the version you have ^

// this looks like a crazy good resource https://thebookofshaders.com/
// this especially looks sick https://thebookofshaders.com/13/

// inigo quilez is apparently a shader god and has a very good youtube channel on shaders.

// mainly following the video https://www.youtube.com/watch?v=3mfvZ-mdtZQ
// but be careful because the syntax is very out of date. see first comment.

// a place for sharing shader code https://www.shadertoy.com/

// to better understand shaders in the context of sfml, read the game dev book.




in vec3 aPos;


out vec4 vertexColor; 

void main()
{
	// contains the position of the current vertex
	gl_Position = vec4(aPos, 1.0);
	vertexColor = vec4(.23, .45, .8, 1.);


	// this is the output of the vertex shader
}
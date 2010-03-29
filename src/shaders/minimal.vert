void main()
{
	vec4 clipCoord = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_Position = clipCoord;
	gl_FrontColor = gl_Color;
	
	vec4 ndc = vec4(clipCoord.xyz, 0) / clipCoord.w;
	
	gl_FrontSecondaryColor = (ndc * 0.5) + 0.5;
} 
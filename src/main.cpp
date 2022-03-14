#include "settings.hpp"
#include "image.hpp"
#include "math.hpp"

using std::cout;

int main()
{
    vec3 v1 = vec3();
    v1.x = 3;
    v1.y = 4;
    v1.z = 5;

    cout << sizeof(v1) << "\n";
    
    vec3 v2 = vec3(2.0f, 2.0f, 2.0f);
    cout << v1.x << ", " << v1.y << ", " << v1.z << "\n";
    cout << v2.x << ", " << v2.y << ", " << v2.z << "\n";

    f32 lensq = lengthSquared(v1);
    f32 lensq2 = lengthSquared(v2);
    
    cout << lensq << "\n";
    cout << lensq2 << "\n";

    vec3 av = v2 / 2.0f;
    cout << av.x << ", " << av.y << ", " << av.z << "\n";

    vec3 v1N = normalize(v1);
    cout << v1N.x << ", " << v1N.y << ", " << v1N.z << "\n";

#if 0
    
    image32 theImage(480, 270);
    
    // Write the pixel data
    // -------------------------------------------------------
    u32 alpha = 0;
    u32 blue = 0;
    u16 count = theImage.width;
    
    for(u16 y = 0; y < theImage.height; ++y)
    {
	u32 green = ((float)y / (float)theImage.height) * 255.0f;

	for(u16 x = 0; x < theImage.width; ++x)
	{
	    u32 red = ((float)x / (float)theImage.width) * 255.0f;

	    u32 aPixel = 0;
	    aPixel |= alpha  << 24;
	    aPixel |= red    << 16;
	    aPixel |= green  << 8;
	    aPixel |= blue;	   

	    // don't forget, this is accounting for row offset
	    theImage.pixels.at(y * theImage.width + x) = aPixel;
	}
    }

    writeBmpImage(theImage);
    
#endif
    
    return (0);
}

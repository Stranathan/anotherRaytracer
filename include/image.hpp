#ifndef IMAGE_H
#define IMAGE_H

#pragma pack(push, 1)
struct bitmapHeader
{
    // header is 14 bytes
    u16 fileType; // 'B', 'M' == 0x4D42
    u32 fileSize; // this is the total size of the file --> header + pixels
    u16 reserved1;// Idk --> 0
    u16 reserved2;// idk --> 0
    u32 bitmapOffset; // offest in file to the pixel data

    // information header is 40 bytes
    u32 informationHeaderSize; // this is the information header size (total header - 14 bytes)
    s32 width; // in pixels
    s32 height;// in pixels
    u16 planes;// idk --> 1
    u16 bitsPerPixel; // Note: Each row of image must be a multiple of 4 bytes; this isn't a problem if we're writing 32 bits per pixel, but will need to be accounted for if just say rgb (24 bits per pixel) --> padding amount = ((4 -(numPixelsX * 3)) % 4) % 4;
    u32 compression;    // idk --> 0
    u32 sizeOfBitmap;    // Image size (no compression), so the size of pixel data
    s32 pixelsPerMeterX; // idk --> 0
    s32 pixelsPerMeterY; // idk --> 0
    u32 colsUsed;        // idk --> 0
    u32 colsImportant;   // idk --> 0
};
#pragma pack(pop)

// pixel data is 32 bits per pixel
#ifdef CSTYLE
    // struct image32
    // {
    //     u16 height;
    //     u16 width;
    //     u32* pixels;
    // };
#endif

#ifdef CPPSTYLE
    struct image32
    {
	// u16 is a unsigned short --> 0 to 65,535, a monitor will not have more pixels than this
        u16 height;
        u16 width;
	std::vector<u32> pixels;

	// we just need heap memory for (h * w) pixels that are each 32 bits wide
	image32(u16 w, u16 h)
	    :  width(w), height(h), pixels(sizeof(u32) * h * w, 0)
	{
	}
    };
#endif

void writeBmpImage(image32& theImage)
{
    // Reference Bitmap file to check how bmp memory is correctly laid out
    //-------------------------------------------------------
    // FILE* fp = fopen("testReference.bmp", "rb");
    // bitmapHeader referenceHeader = {};
    // fread(&referenceHeader, sizeof(referenceHeader), 1, fp);
    // fclose(fp);
    //-------------------------------------------------------
    
    bitmapHeader h = {};

    h.fileType = 0x4D42;
    // each pixel is a 4 byte wide rgba
    h.fileSize = sizeof(h) + (sizeof(u32) * theImage.width * theImage.height);
    h.reserved1 = 0;
    h.reserved2 = 0;
    h.bitmapOffset = sizeof(h);
    h.informationHeaderSize = sizeof(h) - 14;
    h.width = theImage.width;
    h.height = theImage.height;
    h.planes = 1;
    h.bitsPerPixel = 32;
    h.compression = 0;
    h.sizeOfBitmap = sizeof(u32) * theImage.width * theImage.height;
    h.pixelsPerMeterX = 0;
    h.pixelsPerMeterX = 0;
    h.colsUsed = 0;
    h.colsImportant = 0;
    
    std::ofstream theFile;
    theFile.open("theTest.bmp", std::ios::out | std::ios::binary);
    if( !theFile.is_open() )
    {
	std::cout << "File was unable to be opened, sorry\n" ;
    }

    // write header
    theFile.write((char*)&h, sizeof(h));
    // write pixel data
    theFile.write((char*)(&(theImage.pixels[0]) ), theImage.pixels.size() );
    theFile.close();
    std::cout <<  "bmp file created succesfully\n";
}

#endif

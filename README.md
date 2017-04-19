# KNOWN BUGS

**You must regenerate textures from the png/jpgs to tga (git corrupts them for some reason)**

use `convert -type TrueColor in.png out.tga` when you see the error "texture has incomplete image"


```
cd texture
convert -type TrueColor sky_texture.jpg sky_texture.tga
convert -type TrueColor gazon.jpg gazon.tga
convert -type TrueColor snitch.png snitch.tga
convert -type TrueColor tex_char.png tex_char.tga
convert -type TrueColor over.png over.tga
convert -type TrueColor arrow.png arrow.tga

```
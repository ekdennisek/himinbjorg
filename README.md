# himinbjorg
Minimalistic game engine written exclusively in order to learn OpenGL.

# Dependencies
https://github.com/nlohmann/json
http://rapidxml.sourceforge.net/

# Building

Prepare the project for libtool

    libtoolize

Generate `aclocal.m4`

    aclocal

Create a template header

    autoheader

Add any missing standard files

    automake --add-missing

Generate configuration scripts

    autoconf

Run configuration scripts

    ./configure

Finally, build and install

    make && make install

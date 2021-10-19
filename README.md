# himinbjorg
Minimalistic game engine written exclusively in order to learn OpenGL.

# Building

Clone the repository and the submodules

```
git clone git@github.com:ekdennisek/himinbjorg.git
git submodule update --init --recursive
```

Also, make sure you have the necessary dependencies. On Ubuntu, simply install them using apt

```
apt install libicu-dev libbullet-dev libglfw3-dev libglew-dev libfreetype-dev libsoil-dev
```

Then compile it using Meson

```
meson build && cd build
meson compile
```

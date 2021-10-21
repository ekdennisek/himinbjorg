project(
    'himinbjorg',
    'cpp',
    version: '0.1.0',
)

bullet_lib = dependency('bullet')
freetype_lib = dependency('freetype2')
glew_lib = dependency('glew')
glfw_lib = dependency('glfw3')
icu_lib = dependency('icu-uc')
if build_machine.system() == 'linux'
    soil_lib = declare_dependency(
        include_directories: ['/usr/include/SOIL'],
        link_args: ['-L/usr/lib', '-lSOIL'],
    )
elif build_machine.system() == 'windows'
    soil_lib = declare_dependency(
        include_directories: ['C:\msys64\mingw64\include\SOIL'],
        link_args: ['-LC:\msys64\mingw64\include\SOIL', '-lSOIL'],
    )
else
    error('Unsupported operating system. Edit the meson.build if you want to try it anyway.')
endif

subdir('src')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
    description: 'Himinbjorg 3D engine',
    filebase: 'himinbjorg',
    libraries: himinbjorglib,
    name: 'libhiminbjorg',
    version: '0.1.0',
)

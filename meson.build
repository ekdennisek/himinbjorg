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
soil_lib = declare_dependency(
    include_directories: ['/usr/include/SOIL'],
    link_args: ['-L/usr/lib', '-lSOIL'],
)

subdir('src')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
    description: 'Himinbjorg 3D engine',
    filebase: 'himinbjorg',
    libraries: himinbjorglib,
    name: 'libhiminbjorg',
    version: '0.1.0',
)

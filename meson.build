project('Mazeophobia', 'cpp',
  default_options: ['cpp_std=c++17', 'buildtype=release']
)

executable('Mazeophobia', 'src/main.cpp',
  dependencies: [
    dependency('glfw3', required: true),
    dependency('vulkan', required: true)
  ],
  link_args: ['-ldl', '-lpthread', '-lX11', '-lXxf86vm', '-lXrandr', '-lXi']
)

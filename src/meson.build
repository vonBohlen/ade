project(
  'ade',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)
add_project_arguments('-DWLR_USE_UNSTABLE', language : 'c')


dependencies = [
  dependency('wlroots-0.19'),
  dependency('pixman-1'),
  dependency('wayland-server'),
  dependency('xkbcommon'),
]

exe = executable(
  'ade',
  'main.c',
  dependencies : dependencies,
  install : false,
)

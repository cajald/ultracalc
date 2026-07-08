# -*- python -*-
#
# meson.build -- build system
#

project(
    'ultracalc', 'c',
    version : '0.1.0',
    default_options: [
        'warning_level=3',
        'c_std=c99'
    ])

srcs = files('lib/app.c')
inc = include_directories('include')
gtk = dependency('gtk+-3.0')

# Common application code (lib/)
app = static_library(
    'app',
    srcs,
    include_directories : inc,
    dependencies : gtk
)

# Hotwrap plugin
shared_library(
    'ultracalc_hotwrap',
    'bin/plugin.c',
    include_directories : inc,
    link_with : app,
    dependencies : gtk,
    install : false,
    name_prefix : 'lib'
)

# Standalone executable
executable(
    'ultracalc',
    'bin/main.c',
    link_with : app,
    include_directories: inc,
    dependencies: gtk,
    install: false
)

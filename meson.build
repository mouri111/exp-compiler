project('exp-compiler','c')

srcs = ['src/dummy.c',
       ]

incdir = include_directories('include')

warning_flags = ['-Wall',
                 '-Wextra',
                 '-Wshadow',
                 '-Werror',
                ]

opt_flags = ['-O2',
            ]

test_flags = ['-g3',
              '-fsanitize=address',
             ]

exe = executable('exp-compiler',
                 'app/exp-compiler.c',
                 srcs,
                 include_directories: incdir,
                 c_args: warning_flags + opt_flags
                )

test_dummy = executable('test_dummy',
                        'test/test_dummy.c',
                        srcs,
                        include_directories: incdir,
                        c_args: warning_flags + test_flags,
                        link_args: test_flags + ['-fuse-ld=gold']
                       )

test('test_dummy', test_dummy)

project('exp-compiler','c')

srcs = ['src/dummy.c',
        'src/memory.c',
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
                        c_args: warning_flags + test_flags + ['-coverage'],
                        link_args: test_flags + ['-fuse-ld=gold'] + ['-coverage']
                       )

test_memory = executable('test_memory',
                         'test/test_memory.c',
                         srcs,
                         include_directories: incdir,
                         c_args: warning_flags + test_flags + ['-coverage'],
                         link_args: test_flags + ['-fuse-ld=gold'] + ['-coverage']
                        )

test('test_dummy', test_dummy)

test('test_memory char_one failure',
     test_memory,
     args: ['char_one', 'failure'],
     should_fail: true
    )
test('test_memory char_one',
     test_memory,
     args: ['char_one'],
    )
test('test_memory char_many failure',
     test_memory,
     args: ['char_many', 'failure'],
     should_fail: true
    )
test('test_memory char_many',
     test_memory,
     args: ['char_many'],
    )
test('test_memory int_one failure',
     test_memory,
     args: ['int_one', 'failure'],
     should_fail: true
    )
test('test_memory int_one',
     test_memory,
     args: ['int_one'],
    )
test('test_memory int_many failure',
     test_memory,
     args: ['int_many', 'failure'],
     should_fail: true
    )
test('test_memory int_many',
     test_memory,
     args: ['int_many'],
    )
